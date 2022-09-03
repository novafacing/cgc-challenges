#define LIBCGC_IMPL
#include "ansi_x931_aes128.h"
#include "libcgc.h"

#define WIN32_LEAN_AND_MEAN
#include <fcntl.h>
#include <stdio.h>
#include <windows.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

/* Terminates the process. */
void cgc__terminate(unsigned int status) {
    exit(status);
}

int cgc_transmit(int fd, const void *buf, cgc_size_t count,
                 cgc_size_t *tx_bytes) {
    cgc_ssize_t ret = _write(fd, buf, count);

    if (ret < 0) {
        return errno;
    } else if (tx_bytes != NULL) {
        *tx_bytes = ret;
    }

    return 0;
}

int cgc_receive(int fd, void *buf, cgc_size_t count, cgc_size_t *rx_bytes) {
    cgc_ssize_t ret = _read(fd, buf, count);

    if (ret < 0) {
        return errno;
    } else if (rx_bytes != NULL) {
        // Reading a single newline returns a count of 0
        // check if that's the case and say we read 1 instead
        if (ret == 0 && *((char *)buf) == '\n') {
            ++ret;
        }

        *rx_bytes = ret;
    }

    return 0;
}

/* Poll HANDLEs with no timeout to check if they are signaled */
void cgc_poll_fd_set(cgc_fd_set *fd_set, int *num_ready, BOOL read) {
    for (unsigned int fd = 0; fd < EXPECTED_MAX_FDS; ++fd) {
        if (CGC_FD_ISSET(fd, fd_set)) {
            // Setup a read/write call with an event we can watch
            HANDLE hndl = _get_osfhandle(fd);
            OVERLAPPED ov = {0};
            ov.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
            read ? ReadFile(hndl, NULL, 0, NULL, &ov)
                 : WriteFile(hndl, NULL, 0, NULL, &ov);

            // This event will signal if the HANDLE is available for r/w
            if (WAIT_OBJECT_0 == WaitForSingleObject(ov.hEvent, 0)) {
                // The HANDLE for this fd was signaled, leave the bit set
                ++*num_ready;
            } else {
                // This fd hasn't changed state
                CGC_FD_CLR(fd, fd_set);
            }
        }
    }
}

int cgc_fdwait(int nfds, cgc_fd_set *readfds, cgc_fd_set *writefds,
               const struct cgc_timeval *timeout, int *readyfds) {
    int ret;
    if (0 != (ret = cgc_check_timeout(timeout))) {
        return ret;
    } else if (0 > nfds || nfds > CGC__NFDBITS) {
        return CGC_EINVAL;
    }

    // Don't store any more than the max # fds allowed
    // Only one copy of every HANDLE will be stored
    HANDLE fd_handles[EXPECTED_MAX_FDS];
    DWORD num_handles = 0;

    // Copy over fd HANDLEs from the sets
    for (unsigned int fd = 0; fd < CGC__NFDBITS; ++fd) {
        if ((readfds && CGC_FD_ISSET(fd, readfds)) ||
            (writefds && CGC_FD_ISSET(fd, writefds))) {
            if (fd >= EXPECTED_MAX_FDS) {
                return CGC_EBADF;
            }

            fd_handles[num_handles++] = _get_osfhandle(fd);
        }
    }

    // Get the total wait time in milliseconds
    DWORD wait_time = 0;
    if (timeout) {
        wait_time = timeout->tv_sec * 1000 + timeout->tv_usec / 1000;
    }

    // Wait for any of the HANDLEs to be signaled
    if (WAIT_FAILED ==
        WaitForMultipleObjects(num_handles, fd_handles, FALSE, wait_time)) {
        return GetLastError();
    }

    // Pass over all of the fds again and poll the corresponding HANDLEs
    int num_ready = 0;
    if (readfds)
        cgc_poll_fd_set(readfds, &num_ready, TRUE);
    if (writefds)
        cgc_poll_fd_set(writefds, &num_ready, FALSE);

    if (readyfds)
        *readyfds = num_ready;
    return 0;
}

int cgc_allocate(cgc_size_t length, int is_executable, void **addr) {
    DWORD prot = is_executable ? PAGE_EXECUTE_READWRITE : PAGE_READWRITE;

    LPVOID ret_addr =
        VirtualAlloc(NULL, length, MEM_COMMIT | MEM_RESERVE, prot);
    if (ret_addr == NULL)
        return GetLastError();

    if (addr != NULL)
        *addr = ret_addr;

    return 0;
}

int cgc_deallocate(void *addr, cgc_size_t length) {
    if (VirtualFree(addr, 0, MEM_RELEASE) == 0)
        return GetLastError();
    return 0;
}

static cgc_prng *cgc_internal_prng = NULL;
/**
 * Initializes the prng for use with cgc_random and the flag page
 */
static void cgc_try_init_prng() {
    // Don't reinitialize
    if (cgc_internal_prng != NULL)
        return;

    uint8_t prng_seed[BLOCK_SIZE * 3] = {
        0x73, 0x65, 0x65, 0x64, 0x73, 0x65, 0x65, 0x64, 0x73, 0x65,
        0x65, 0x64, 0x73, 0x65, 0x65, 0x64, 0x30, 0x31, 0x32, 0x33,
        0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x61, 0x62, 0x63, 0x64,
        0x65, 0x66, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}; // Default seed,
                                                         // definitely not
                                                         // random

    // This will be hex encoded
    const char *prng_seed_hex = getenv("seed");
    if (prng_seed_hex != NULL &&
        strlen(prng_seed_hex) == (BLOCK_SIZE * 3) * 2) {
        // Convert the hex encoded seed to a normal string
        const char *pos = prng_seed_hex;
        for (int i = 0; i < BLOCK_SIZE * 3; ++i) {
            sscanf(pos, "%2hhx", &prng_seed[i]);
            pos += 2;
        }
    }

    // Create the prng
    cgc_internal_prng = (cgc_prng *)malloc(sizeof(cgc_prng));
    cgc_aes_state *seed = (cgc_aes_state *)prng_seed;
    cgc_init_prng(cgc_internal_prng, seed);
}

int cgc_random(void *buf, cgc_size_t count, cgc_size_t *rnd_bytes) {
    // Get random bytes from the prng
    cgc_try_init_prng();
    cgc_aes_get_bytes(cgc_internal_prng, count, buf);

    if (rnd_bytes)
        *rnd_bytes = count;

    return 0;
}

static void cgc_initialize_flag_page(void) {
    // Initially reserve the flag page to see where it ends up
    LPVOID flag_addr, rsrv_addr = VirtualAlloc(CGC_FLAG_PAGE_ADDRESS, PAGE_SIZE,
                                               MEM_RESERVE, PAGE_READWRITE);

    if (rsrv_addr != CGC_FLAG_PAGE_ADDRESS) {
        // Address was rounded down
        // Figure out how much more space we need to reserve
        intptr_t padding = CGC_FLAG_PAGE_ADDRESS - (intptr_t)rsrv_addr;

        // Free the old space and reserve the correct size
        VirtualFree(rsrv_addr, 0, MEM_RELEASE);
        rsrv_addr = VirtualAlloc(rsrv_addr, PAGE_SIZE + padding, MEM_RESERVE,
                                 PAGE_READWRITE);
    }

    // Allocate the flag page
    flag_addr = VirtualAlloc(CGC_FLAG_PAGE_ADDRESS, PAGE_SIZE, MEM_COMMIT,
                             PAGE_READWRITE);

    // Make sure it worked
    if (flag_addr != CGC_FLAG_PAGE_ADDRESS) {
        fprintf(stderr, "[!] Failed to map the flag page");
        exit(1);
    }

    // Fill the flag page with bytes from the prng
    cgc_try_init_prng();
    cgc_aes_get_bytes(cgc_internal_prng, PAGE_SIZE, flag_addr);
}

/**
 * Helper to parse values out of the env
 * All values are expected to be positive + nonzero
 * Returns 0 on any error
 */
unsigned int cgc_getenv_uint(char *varname) {
    char *val = getenv(varname);
    if (val) {
        int res = atoi(val);
        if (res > 0)
            return res;
    }
    return 0;
}

// Up to 2 digits, should really never go past ~20 anyway
#define MAX_IPC_PIPES 99
#define MAX_NAME_LEN 8 // "PIPE_##\0"

/**
 * Initialize all the pipes necessary for IPC
 */
void cgc_init_ipc_pipes() {
    char name_buf[MAX_NAME_LEN] = {0};
    HANDLE pipe_hndl = NULL;
    int pipe_fd = 0;

    // Get the number of pipes we need to set up
    int numpipes = cgc_getenv_uint("PIPE_COUNT");
    if (numpipes > MAX_IPC_PIPES)
        numpipes = MAX_IPC_PIPES;

    // Open all pipe HANDLEs in the correct fds
    for (unsigned int i = 0; i < numpipes; ++i) {
        // Get the next HANDLE from the env
        snprintf(name_buf, MAX_NAME_LEN, "PIPE_%d", i);
        pipe_hndl = (HANDLE)cgc_getenv_uint(name_buf);

        if (pipe_hndl) {
            // Assign the pipe to the correct fd
            pipe_fd = _open_osfhandle(pipe_hndl, O_RDONLY | O_APPEND);
            if (pipe_fd != 3 + i) { // First pipe is at fd 3
                _dup2(pipe_fd, 3 + i);
            }
        }
    }
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    if (fdwReason == DLL_PROCESS_ATTACH) { // __attribute__((constructor))
        setvbuf(stdout, NULL, _IONBF,
                0); // We *may* not need this, not sure yet
        cgc_initialize_flag_page();
        cgc_init_ipc_pipes();
    }
    return TRUE;
}

// Math functions
float cgc_sinf(float f) {
    return sinf(f);
}

double cgc_sin(double d) {
    return sin(d);
}

long double cgc_sinl(long double d) {
    return sinl(d);
}

float cgc_cosf(float f) {
    return cosf(f);
}

double cgc_cos(double d) {
    return cos(d);
}

long double cgc_cosl(long double d) {
    return cosl(d);
}

float cgc_tanf(float f) {
    return tanf(f);
}

double cgc_tan(double d) {
    return tan(d);
}

long double cgc_tanl(long double d) {
    return tanl(d);
}

float cgc_logf(float f) {
    return logf(f);
}

double cgc_log(double d) {
    return log(d);
}

long double cgc_logl(long double d) {
    return logl(d);
}

float cgc_rintf(float f) {
    return rintf(f);
}

double cgc_rint(double d) {
    return rint(d);
}

long double cgc_rintl(long double d) {
    return rintl(d);
}

float cgc_sqrtf(float f) {
    return sqrtf(f);
}

double cgc_sqrt(double d) {
    return sqrt(d);
}

long double cgc_sqrtl(long double d) {
    return sqrtl(d);
}

float cgc_fabsf(float f) {
    return fabsf(f);
}

double cgc_fabs(double d) {
    return fabs(d);
}

long double cgc_fabsl(long double d) {
    return fabsl(d);
}

float cgc_log2f(float f) {
    return log2f(f);
}

double cgc_log2(double d) {
    return log2(d);
}

long double cgc_log2l(long double d) {
    return log2l(d);
}

float cgc_exp2f(float f) {
    return exp2f(f);
}

double cgc_exp2(double d) {
    return exp2(d);
}

long double cgc_exp2l(long double d) {
    return exp2l(d);
}

float cgc_expf(float f) {
    return expf(f);
}

double cgc_exp(double d) {
    return exp(d);
}

long double cgc_expl(long double d) {
    return expl(d);
}

float cgc_log10f(float f) {
    return log10f(f);
}

double cgc_log10(double d) {
    return log10(d);
}

long double cgc_log10l(long double d) {
    return log10l(d);
}

float cgc_powf(float f1, float f2) {
    return powf(f1, f2);
}

double cgc_pow(double d1, double d2) {
    return pow(d1, d2);
}

long double cgc_powl(long double d1, long double d2) {
    return powl(d1, d2);
}

float cgc_atan2f(float f1, float f2) {
    return atan2f(f1, f2);
}

double cgc_atan2(double d1, double d2) {
    return atan2(d1, d2);
}

long double cgc_atan2l(long double d1, long double d2) {
    return atan2l(d1, d2);
}

float cgc_remainderf(float f1, float f2) {
    return remainderf(f1, f2);
}

double cgc_remainder(double d1, double d2) {
    return remainder(d1, d2);
}

long double cgc_remainderl(long double d1, long double d2) {
    return remainderl(d1, d2);
}

float cgc_scalbnf(float f, int i) {
    return scalbnf(f, i);
}

double cgc_scalbn(double d, int i) {
    return scalbn(d, i);
}

long double cgc_scalbnl(long double d, int i) {
    return scalbnl(d, i);
}

float cgc_scalblnf(float f, long int i) {
    return scalblnf(f, i);
}

double cgc_scalbln(double d, long int i) {
    return scalbln(d, i);
}

long double cgc_scalblnl(long double d, long int i) {
    return scalblnl(d, i);
}

float cgc_significandf(float f) {
    return significandf(f);
}

double cgc_significand(double d) {
    return significand(d);
}

long double cgc_significandl(long double d) {
    return significandl(d);
}