# challenge_FSK_Messaging_Service
challenge_FSK_Messaging_Service_inc = include_directories('include')
challenge_FSK_Messaging_Service_src = [
    'src/baseband.c',
    'src/packet.c',
    'src/rx.c',
    'src/service.c',
    'src/lib/ctype.c',
    'src/lib/malloc.c',
    'src/lib/math.c',
    'src/lib/prng.c',
    'src/lib/stdio.c',
    'src/lib/stdlib.c',
    'src/lib/string.c',
]
challenge_FSK_Messaging_Service = executable(
    'FSK_Messaging_Service',
    challenge_FSK_Messaging_Service_src,
    include_directories: [challenge_FSK_Messaging_Service_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true
)
