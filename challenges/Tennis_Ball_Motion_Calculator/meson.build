# challenge_Tennis_Ball_Motion_Calculator
challenge_Tennis_Ball_Motion_Calculator_inc = include_directories('include')
challenge_Tennis_Ball_Motion_Calculator_src = [
    'src/tennisball.c',
    'src/lib/mylibc.c',
]
challenge_Tennis_Ball_Motion_Calculator = executable(
    'Tennis_Ball_Motion_Calculator',
    challenge_Tennis_Ball_Motion_Calculator_src,
    include_directories: [challenge_Tennis_Ball_Motion_Calculator_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args,
    link_args: challenges_extra_link_args
)
