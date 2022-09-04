# challenge_Checkmate
challenge_Checkmate_inc = include_directories('include')
challenge_Checkmate_src = [
    'src/ai.c',
    'src/bitboard.c',
    'src/service.c',
    'src/lib/bitset.c',
    'src/lib/conv.c',
    'src/lib/math.c',
    'src/lib/pool.c',
    'src/lib/stdio.c',
    'src/lib/stdlib.c',
    'src/lib/string.c',
]
challenge_Checkmate = executable(
    'Checkmate',
    challenge_Checkmate_src,
    include_directories: [challenge_Checkmate_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path,
    install: true
)
