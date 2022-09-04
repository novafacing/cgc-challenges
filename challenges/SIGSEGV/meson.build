# challenge_SIGSEGV
challenge_SIGSEGV_inc = include_directories('include')
challenge_SIGSEGV_src = [
    'src/service.c',
    'src/lib/libc.c',
]
challenge_SIGSEGV = executable(
    'SIGSEGV',
    challenge_SIGSEGV_src,
    include_directories: [challenge_SIGSEGV_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path
)
