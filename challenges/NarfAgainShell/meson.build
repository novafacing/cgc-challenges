# challenge_NarfAgainShell
challenge_NarfAgainShell_inc = include_directories('include')
challenge_NarfAgainShell_src = [
    'src/service.c',
    'src/lib/libc.c',
    'src/lib/malloc.c',
    'src/lib/vfs.c',
]
challenge_NarfAgainShell = executable(
    'NarfAgainShell',
    challenge_NarfAgainShell_src,
    include_directories: [challenge_NarfAgainShell_inc, libcgc_inc],
    link_with: [libcgc]
)
