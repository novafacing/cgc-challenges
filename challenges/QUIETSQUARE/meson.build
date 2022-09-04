# challenge_QUIETSQUARE
challenge_QUIETSQUARE_inc = include_directories('include')
challenge_QUIETSQUARE_src = [
    'src/service.c',
    'src/lib/libc.c',
]
challenge_QUIETSQUARE = executable(
    'QUIETSQUARE',
    challenge_QUIETSQUARE_src,
    include_directories: [challenge_QUIETSQUARE_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path,
    install: true
)
