# challenge_REMATCH_2__Mail_Server__Crackaddr
challenge_REMATCH_2__Mail_Server__Crackaddr_inc = include_directories('include')
challenge_REMATCH_2__Mail_Server__Crackaddr_src = [
    'src/crackaddr.c',
    'src/sendmail.c',
    'src/lib/ctype.c',
    'src/lib/libc.c',
    'src/lib/malloc.c',
    'src/lib/math.c',
    'src/lib/prng.c',
    'src/lib/shell.c',
    'src/lib/stdio.c',
    'src/lib/stdlib.c',
    'src/lib/string.c',
]
challenge_REMATCH_2__Mail_Server__Crackaddr = executable(
    'REMATCH_2--Mail_Server--Crackaddr',
    challenge_REMATCH_2__Mail_Server__Crackaddr_src,
    include_directories: [challenge_REMATCH_2__Mail_Server__Crackaddr_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path
)
