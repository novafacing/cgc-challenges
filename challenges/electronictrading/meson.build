# challenge_electronictrading
challenge_electronictrading_inc = include_directories('include')
challenge_electronictrading_src = [
    'src/service.c',
    'src/stock.c',
    'src/lib/libc.c',
    'src/lib/pool.c',
]
challenge_electronictrading = executable(
    'electronictrading',
    challenge_electronictrading_src,
    include_directories: [challenge_electronictrading_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    link_args: challenges_extra_link_args
)
