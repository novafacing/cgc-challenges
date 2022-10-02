# challenge_chess_mimic
challenge_chess_mimic_inc = include_directories('include')
challenge_chess_mimic_src = [
    'src/service.c',
    'src/lib/mymath.c',
    'src/lib/printf.c',
    'src/lib/stdlib.c',
]
challenge_chess_mimic = executable(
    'chess_mimic',
    challenge_chess_mimic_src,
    include_directories: [challenge_chess_mimic_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie
)
