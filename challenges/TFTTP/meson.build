# challenge_TFTTP
challenge_TFTTP_inc = include_directories('include')
challenge_TFTTP_src = [
    'src/process.c',
    'src/proto.c',
    'src/service.c',
    'src/lib/libc.c',
]
challenge_TFTTP = executable(
    'TFTTP',
    challenge_TFTTP_src,
    include_directories: [challenge_TFTTP_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args
)
