# challenge_Griswold
challenge_Griswold_inc = include_directories('include')
challenge_Griswold_src = [
    'src/assemble.c',
    'src/components.c',
    'src/examine.c',
    'src/operation.c',
    'src/service.c',
    'src/lib/libc.c',
]
challenge_Griswold = executable(
    'Griswold',
    challenge_Griswold_src,
    include_directories: [challenge_Griswold_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    link_args: challenges_extra_link_args
)
