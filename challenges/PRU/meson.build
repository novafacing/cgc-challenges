# challenge_PRU
challenge_PRU_inc = include_directories('include')
challenge_PRU_src = [
    'src/alu.c',
    'src/fmt2.c',
    'src/pru.c',
    'src/lib/ctype.c',
    'src/lib/malloc.c',
    'src/lib/math.c',
    'src/lib/prng.c',
    'src/lib/stdio.c',
    'src/lib/stdlib.c',
    'src/lib/string.c',
]
challenge_PRU = executable(
    'PRU',
    challenge_PRU_src,
    include_directories: [challenge_PRU_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path
)
