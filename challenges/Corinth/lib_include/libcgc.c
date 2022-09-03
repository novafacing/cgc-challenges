/* Copyright 2015 Peter Goodman (peter@trailofbits.com), all rights reserved. */

#define LIBCGC_IMPL
#include "libcgc.h"
#include "ansi_x931_aes128.h"

#include <err.h>
#include <errno.h>
#include <fcntl.h>
#include <math.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/select.h>
#include <sys/types.h>
#include <unistd.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

/* Terminates the process. */
void cgc__terminate(unsigned int status) {
    exit(status);
    __builtin_unreachable();
}

/* Transmits data from one CGC process to another. */
int cgc_transmit(int fd, const void *buf, cgc_size_t count,
                 cgc_size_t *tx_bytes) {
    const cgc_ssize_t ret = write(fd, buf, count);

    if (ret < 0) {
        return errno;
    } else if (tx_bytes != NULL) {
        *tx_bytes = ret;
    }

    return 0;
}

/* Receives data from another CGC process. */
int cgc_receive(int fd, void *buf, cgc_size_t count, cgc_size_t *rx_bytes) {
    const cgc_ssize_t ret = read(fd, buf, count);

    if (ret < 0) {
        return errno;
    } else if (rx_bytes != NULL) {
        *rx_bytes = ret;
    }

    return 0;
}

/* Marshal a CGC fd set into an OS fd set. */
static int cgc_copy_cgc_fd_set(const cgc_fd_set *cgc_fds, fd_set *os_fds,
                               int *num_fds) {
    for (unsigned fd = 0; fd < CGC__NFDBITS; ++fd) {
        if (CGC_FD_ISSET(fd, cgc_fds)) {
            // Shouldn't be using an fd greater than the allowed values
            if (fd >= EXPECTED_MAX_FDS) {
                return CGC_EBADF;
            }

            if (fd > NFDBITS) {
                continue; /* OS set size is too small. */
            }
            FD_SET(fd, os_fds);
            ++*num_fds;
        }
    }
    return 0;
}

/* Marshal an OS fd set into a CGC fd set. */
static void cgc_copy_os_fd_set(const fd_set *os_fds, cgc_fd_set *cgc_fds) {
    for (unsigned fd = 0; fd < MIN(NFDBITS, CGC__NFDBITS); ++fd) {
        if (FD_ISSET(fd, os_fds)) {
            CGC_FD_SET(fd, cgc_fds);
        }
    }
}
int cgc_fdwait(int nfds, cgc_fd_set *readfds, cgc_fd_set *writefds,
               const struct cgc_timeval *timeout, int *readyfds) {

    int ret = cgc_check_timeout(timeout);
    int actual_num_fds = 0;
    struct timeval max_wait_time = {0, 0};
    fd_set read_fds;
    fd_set write_fds;

    if (ret) {
        return ret;
    } else if (0 > nfds || CGC__NFDBITS < nfds) {
        return CGC_EINVAL;
    }

    FD_ZERO(&read_fds);
    FD_ZERO(&write_fds);

    if (readfds) {
        if (0 !=
            (ret = cgc_copy_cgc_fd_set(readfds, &read_fds, &actual_num_fds))) {
            return ret;
        }
    }

    if (writefds) {
        if (0 != (ret = cgc_copy_cgc_fd_set(writefds, &write_fds,
                                            &actual_num_fds))) {
            return ret;
        }
    }

    if (actual_num_fds != nfds) {
        return EINVAL; /* Not actually specified, but oh well. */
    }

    if (readfds)
        CGC_FD_ZERO(readfds);
    if (writefds)
        CGC_FD_ZERO(writefds);

    if (timeout) {
        max_wait_time.tv_sec = timeout->tv_sec;
        max_wait_time.tv_usec = timeout->tv_usec;
    }

    int num_selected_fds = select(nfds, (readfds ? &read_fds : NULL),
                                  (writefds ? &write_fds : NULL), NULL,
                                  (timeout ? &max_wait_time : NULL));

    if (num_selected_fds < 0)
        return errno;

    if (readfds) {
        cgc_copy_os_fd_set(&read_fds, readfds);
    }

    if (writefds) {
        cgc_copy_os_fd_set(&write_fds, writefds);
    }

    if (readyfds) {
        *readyfds = num_selected_fds;
    }

    return 0;
}

/* Going to ignore `is_executable`. It's not really used in the official CGC
 * challenges, and if it were used, then JITed code would likely be 32-bit, and
 * ideally, this code will also work on 64-bit.
 */
int cgc_allocate(cgc_size_t length, int is_executable, void **addr) {
    int page_perms = PROT_READ | PROT_WRITE;
    if (is_executable)
        page_perms |= PROT_EXEC;

    void *return_address =
        mmap(NULL, length, page_perms, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);

    if (return_address == MAP_FAILED) {
        return errno;
    }

    if (addr)
        *addr = return_address;

    memset(return_address, 0, length);

    return 0;
}

/* Deallocate some range of memory and mark the pages as free. */
int cgc_deallocate(void *addr, cgc_size_t length) {

    const int ret = munmap(addr, length);

    if (ret < 0) {
        return errno;
    }

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

static void __attribute__((constructor)) cgc_initialize_flag_page(void) {
    void *mmap_addr =
        mmap(CGC_FLAG_PAGE_ADDRESS, PAGE_SIZE, PROT_READ | PROT_WRITE,
             MAP_FIXED | MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (mmap_addr != CGC_FLAG_PAGE_ADDRESS) {
        err(1, "[!] Failed to map the flag page");
    }

    // Fill the flag page with bytes from the prng
    cgc_try_init_prng();
    cgc_aes_get_bytes(cgc_internal_prng, PAGE_SIZE, mmap_addr);
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
