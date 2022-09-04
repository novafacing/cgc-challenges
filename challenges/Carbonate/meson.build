# challenge_Carbonate
challenge_Carbonate_inc = include_directories('include')
challenge_Carbonate_src = [
    'src/block.c',
    'src/carbonate.c',
    'src/handler.c',
    'src/messages.c',
    'src/protocol.c',
    'src/scramble.c',
    'src/scramble_gen.c',
    'src/set.c',
]
challenge_Carbonate = executable(
    'Carbonate',
    challenge_Carbonate_src,
    include_directories: [challenge_Carbonate_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path
)
