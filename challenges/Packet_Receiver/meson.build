# challenge_Packet_Receiver
challenge_Packet_Receiver_inc = include_directories('include')
challenge_Packet_Receiver_src = [
    'src/datastream.cc',
    'src/doublelist.cc',
    'src/messagehandler.cc',
    'src/messagepacket.cc',
    'src/messagerenderer.cc',
    'src/service.cc',
    'src/lib/malloc.c',
    'src/lib/mymath.c',
    'src/lib/new_printf.c',
    'src/lib/stdlib.c',
    'src/lib/string.cc',
]
challenge_Packet_Receiver = executable(
    'Packet_Receiver',
    challenge_Packet_Receiver_src,
    include_directories: [challenge_Packet_Receiver_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path,
    install: true
)
