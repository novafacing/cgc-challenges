# challenge_Casino_Games
challenge_Casino_Games_inc = include_directories('include')
challenge_Casino_Games_src = [
    'src/blackjack.c',
    'src/casino.c',
    'src/deck.c',
    'src/poker.c',
    'src/slots.c',
    'src/lib/mymath.c',
    'src/lib/printf.c',
    'src/lib/prng.c',
    'src/lib/stdlib.c',
]
challenge_Casino_Games = executable(
    'Casino_Games',
    challenge_Casino_Games_src,
    include_directories: [challenge_Casino_Games_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path,
    install: true
)
