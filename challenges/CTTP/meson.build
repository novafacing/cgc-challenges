# challenge_CTTP
challenge_CTTP_inc = include_directories('include')
challenge_CTTP_src = [
    'src/cttp.c',
    'src/prng.c',
    'src/service.c',
    'src/lib/libc.c',
]
challenge_CTTP = executable(
    'CTTP',
    challenge_CTTP_src,
    include_directories: [challenge_CTTP_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args,
    link_args: challenges_extra_link_args
)
