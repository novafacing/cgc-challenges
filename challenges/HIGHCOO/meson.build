# challenge_HIGHCOO
challenge_HIGHCOO_inc = include_directories('include')
challenge_HIGHCOO_src = [
    'src/operation.c',
    'src/service.c',
    'src/lib/libc.c',
]
challenge_HIGHCOO = executable(
    'HIGHCOO',
    challenge_HIGHCOO_src,
    include_directories: [challenge_HIGHCOO_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie
)
