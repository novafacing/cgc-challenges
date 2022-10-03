# challenge_String_Info_Calculator
challenge_String_Info_Calculator_inc = include_directories('include')
challenge_String_Info_Calculator_src = [
    'src/service.c',
    'src/strinfo.c',
    'src/lib/char.c',
    'src/lib/e_libc.c',
    'src/lib/memset.c',
    'src/lib/rand.c',
    'src/lib/recv_until_delim_n.c',
    'src/lib/send_bytes.c',
]
challenge_String_Info_Calculator = executable(
    'String_Info_Calculator',
    challenge_String_Info_Calculator_src,
    include_directories: [challenge_String_Info_Calculator_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args
)
