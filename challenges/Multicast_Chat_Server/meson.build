# challenge_Multicast_Chat_Server
challenge_Multicast_Chat_Server_inc = include_directories('include')
challenge_Multicast_Chat_Server_src = [
    'src/auth.c',
    'src/service.c',
    'src/subscription.c',
    'src/lib/libc.c',
    'src/lib/malloc.c',
]
challenge_Multicast_Chat_Server = executable(
    'Multicast_Chat_Server',
    challenge_Multicast_Chat_Server_src,
    include_directories: [challenge_Multicast_Chat_Server_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args
)
