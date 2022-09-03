# challenge_greeter
challenge_greeter_inc = include_directories('include')
challenge_greeter_src = [
    'src/service.c',
    'src/lib/adler32.c',
    'src/lib/libc.c',
    'src/lib/malloc.c',
    'src/lib/md5.c',
]
challenge_greeter = executable(
    'greeter',
    challenge_greeter_src,
    include_directories: [challenge_greeter_inc, libcgc_inc],
    link_with: [libcgc]
)
