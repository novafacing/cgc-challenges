# challenge_Board_Game
challenge_Board_Game_inc = include_directories('include')
challenge_Board_Game_src = [
    'src/board.c',
    'src/moves.c',
    'src/service.c',
    'src/lib/mymath.c',
    'src/lib/printf.c',
    'src/lib/prng.c',
    'src/lib/stdlib.c',
]
challenge_Board_Game = executable(
    'Board_Game',
    challenge_Board_Game_src,
    include_directories: [challenge_Board_Game_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    link_args: challenges_extra_link_args
)
