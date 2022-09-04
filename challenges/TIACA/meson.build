# challenge_TIACA
challenge_TIACA_inc = include_directories('include')
challenge_TIACA_src = [
    'src/asan.c',
    'src/service.c',
    'src/string.c',
    'src/lib/libc.c',
    'src/lib/mymath.c',
    'src/lib/printf.c',
    'src/lib/stdlib.c',
]
challenge_TIACA = executable(
    'TIACA',
    challenge_TIACA_src,
    include_directories: [challenge_TIACA_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true
)
