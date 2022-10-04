# challenge_CNMP
challenge_CNMP_inc = include_directories('include')
challenge_CNMP_src = [
    'src/joke.c',
    'src/service.c',
    'src/lib/libc.c',
]
challenge_CNMP = executable(
    'CNMP',
    challenge_CNMP_src,
    include_directories: [challenge_CNMP_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args,
    link_args: challenges_extra_link_args
)
