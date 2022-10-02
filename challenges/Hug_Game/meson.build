# challenge_Hug_Game
challenge_Hug_Game_inc = include_directories('include')
challenge_Hug_Game_src = [
    'src/coinflip.c',
    'src/dicegame.c',
    'src/hangman.c',
    'src/service.c',
    'src/utility.c',
    'src/war.c',
    'src/lib/libc.c',
]
challenge_Hug_Game = executable(
    'Hug_Game',
    challenge_Hug_Game_src,
    include_directories: [challenge_Hug_Game_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie
)
