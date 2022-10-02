# challenge_The_Longest_Road
challenge_The_Longest_Road_inc = include_directories('include')
challenge_The_Longest_Road_src = [
    'src/game.c',
    'src/math_lib.c',
    'src/packet.c',
    'src/service.c',
    'src/lib/mymath.c',
    'src/lib/printf.c',
    'src/lib/prng.c',
    'src/lib/stdlib.c',
]
challenge_The_Longest_Road = executable(
    'The_Longest_Road',
    challenge_The_Longest_Road_src,
    include_directories: [challenge_The_Longest_Road_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args
)
