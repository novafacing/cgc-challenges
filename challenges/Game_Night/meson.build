# challenge_Game_Night
challenge_Game_Night_inc = include_directories('include')
challenge_Game_Night_src = [
    'src/chance_of_survival.c',
    'src/chess.c',
    'src/gallon_challenge.c',
    'src/games.c',
    'src/hugman.c',
    'src/lesson_in_futility.c',
    'src/safari_zone.c',
    'src/service.c',
    'src/sudoku.c',
    'src/lib/bitset.c',
    'src/lib/conv.c',
    'src/lib/math.c',
    'src/lib/pool.c',
    'src/lib/stdio.c',
    'src/lib/stdlib.c',
    'src/lib/string.c',
]
challenge_Game_Night = executable(
    'Game_Night',
    challenge_Game_Night_src,
    include_directories: [challenge_Game_Night_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    link_args: challenges_extra_link_args
)
