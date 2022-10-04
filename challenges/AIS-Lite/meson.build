# challenge_AIS_Lite
challenge_AIS_Lite_inc = include_directories('include')
challenge_AIS_Lite_src = [
    'src/message.c',
    'src/sentence.c',
    'src/service.c',
    'src/sixer.c',
    'src/lib/hex.c',
    'src/lib/int2str.c',
    'src/lib/malloc.c',
    'src/lib/memcpy.c',
    'src/lib/memset.c',
    'src/lib/recv_until_delim.c',
    'src/lib/send.c',
    'src/lib/sendall.c',
    'src/lib/strlen.c',
    'src/lib/strncmp.c',
    'src/lib/strncpy.c',
    'src/lib/xxprintf.c',
]
challenge_AIS_Lite = executable(
    'AIS-Lite',
    challenge_AIS_Lite_src,
    include_directories: [challenge_AIS_Lite_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args,
    link_args: challenges_extra_link_args
)
