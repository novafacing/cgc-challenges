# challenge_UTF_late
challenge_UTF_late_inc = include_directories('include')
challenge_UTF_late_src = [
    'src/service.c',
    'src/lib/libc.c',
    'src/lib/malloc.c',
    'src/lib/utf8.c',
    'src/lib/vfs.c',
]
challenge_UTF_late = executable(
    'UTF-late',
    challenge_UTF_late_src,
    include_directories: [challenge_UTF_late_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path
)
