# challenge_Email_System_2
challenge_Email_System_2_inc = include_directories('include')
challenge_Email_System_2_src = [
    'src/message.c',
    'src/service.c',
    'src/user.c',
    'src/lib/mymath.c',
    'src/lib/new_printf.c',
    'src/lib/prng.c',
    'src/lib/stdlib.c',
]
challenge_Email_System_2 = executable(
    'Email_System_2',
    challenge_Email_System_2_src,
    include_directories: [challenge_Email_System_2_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args,
    link_args: challenges_extra_link_args
)
