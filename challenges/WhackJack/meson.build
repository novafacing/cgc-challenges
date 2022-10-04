# challenge_WhackJack
challenge_WhackJack_inc = include_directories('include')
challenge_WhackJack_src = [
    'src/algorithms.c',
    'src/player.c',
    'src/playround.c',
    'src/service.c',
    'src/lib/ctype.c',
    'src/lib/input.c',
    'src/lib/malloc.c',
    'src/lib/math.c',
    'src/lib/prng.c',
    'src/lib/stdio.c',
    'src/lib/stdlib.c',
    'src/lib/string.c',
]
challenge_WhackJack = executable(
    'WhackJack',
    challenge_WhackJack_src,
    include_directories: [challenge_WhackJack_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    link_args: challenges_extra_link_args
)
