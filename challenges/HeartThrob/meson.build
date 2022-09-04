# challenge_HeartThrob
challenge_HeartThrob_inc = include_directories('include')
challenge_HeartThrob_src = [
    'src/check.c',
    'src/members.c',
    'src/service.c',
    'src/lib/libc.c',
]
challenge_HeartThrob = executable(
    'HeartThrob',
    challenge_HeartThrob_src,
    include_directories: [challenge_HeartThrob_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true
)
