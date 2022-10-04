# challenge_basic_messaging
challenge_basic_messaging_inc = include_directories('include')
challenge_basic_messaging_src = [
    'src/service.c',
    'src/lib/mymath.c',
    'src/lib/printf.c',
    'src/lib/stdlib.c',
]
challenge_basic_messaging = executable(
    'basic_messaging',
    challenge_basic_messaging_src,
    include_directories: [challenge_basic_messaging_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args,
    link_args: challenges_extra_link_args
)
