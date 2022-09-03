# challenge_Resort_Modeller
challenge_Resort_Modeller_inc = include_directories('include')
challenge_Resort_Modeller_src = [
    'src/decider.c',
    'src/lift.c',
    'src/resort.c',
    'src/rider.c',
    'src/service.c',
    'src/trail.c',
    'src/lib/char.c',
    'src/lib/hex.c',
    'src/lib/int2str.c',
    'src/lib/malloc.c',
    'src/lib/memcmp.c',
    'src/lib/memcpy.c',
    'src/lib/memset.c',
    'src/lib/read_all.c',
    'src/lib/recv_all.c',
    'src/lib/send.c',
    'src/lib/sendall.c',
    'src/lib/strlen.c',
    'src/lib/strncmp.c',
    'src/lib/strncpy.c',
    'src/lib/xxprintf.c',
]
challenge_Resort_Modeller = executable(
    'Resort_Modeller',
    challenge_Resort_Modeller_src,
    include_directories: [challenge_Resort_Modeller_inc, libcgc_inc],
    link_with: [libcgc]
)
