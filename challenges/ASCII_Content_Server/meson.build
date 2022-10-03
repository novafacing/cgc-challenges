# challenge_ASCII_Content_Server
challenge_ASCII_Content_Server_inc = include_directories('include')
challenge_ASCII_Content_Server_src = [
    'src/command.c',
    'src/error.c',
    'src/page.c',
    'src/service.c',
    'src/tree.c',
    'src/lib/malloc.c',
    'src/lib/mymath.c',
    'src/lib/new_printf.c',
    'src/lib/stdlib.c',
]
challenge_ASCII_Content_Server = executable(
    'ASCII_Content_Server',
    challenge_ASCII_Content_Server_src,
    include_directories: [challenge_ASCII_Content_Server_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args
)
