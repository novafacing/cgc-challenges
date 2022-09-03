# challenge_NarfRPN
challenge_NarfRPN_inc = include_directories('include')
challenge_NarfRPN_src = [
    'src/rpncalc.c',
    'src/service.c',
    'src/lib/libc.c',
    'src/lib/malloc.c',
]
challenge_NarfRPN = executable(
    'NarfRPN',
    challenge_NarfRPN_src,
    include_directories: [challenge_NarfRPN_inc, libcgc_inc],
    link_with: [libcgc]
)
