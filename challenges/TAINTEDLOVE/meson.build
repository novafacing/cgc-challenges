# challenge_TAINTEDLOVE
challenge_TAINTEDLOVE_inc = include_directories('include')
challenge_TAINTEDLOVE_src = [
    'src/service.c',
    'src/lib/libc.c',
]
challenge_TAINTEDLOVE = executable(
    'TAINTEDLOVE',
    challenge_TAINTEDLOVE_src,
    include_directories: [challenge_TAINTEDLOVE_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie
)
