# challenge_CGC_Hangman_Game
challenge_CGC_Hangman_Game_inc = include_directories('include')
challenge_CGC_Hangman_Game_src = [
    'src/service.c',
    'src/words.c',
    'src/lib/libc.c',
]
challenge_CGC_Hangman_Game = executable(
    'CGC_Hangman_Game',
    challenge_CGC_Hangman_Game_src,
    include_directories: [challenge_CGC_Hangman_Game_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args
)
