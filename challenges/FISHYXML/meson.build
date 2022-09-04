# challenge_FISHYXML
challenge_FISHYXML_inc = include_directories('include')
challenge_FISHYXML_src = [
    'src/card.c',
    'src/deck.c',
    'src/fishyxml.c',
    'src/gofish.c',
    'src/hand.c',
    'src/operation.c',
    'src/player.c',
    'src/rxtx.c',
    'src/service.c',
    'src/lib/malloc.c',
    'src/lib/memcpy.c',
    'src/lib/memset.c',
    'src/lib/pi_prng.c',
    'src/lib/recv_until_delim.c',
    'src/lib/send.c',
    'src/lib/sendall.c',
    'src/lib/strncpy.c',
]
challenge_FISHYXML = executable(
    'FISHYXML',
    challenge_FISHYXML_src,
    include_directories: [challenge_FISHYXML_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path,
    install: true
)
