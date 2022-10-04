# challenge_NarfRPN
challenge_NarfRPN_inc = include_directories('include')
challenge_NarfRPN_src = [
    'src/rpncalc.c',
    'src/service.c',
    'src/lib/libc.c',
    'src/lib/malloc.c',
]
challenge_NarfRPN = executable(
    'NarfRPN',
    challenge_NarfRPN_src,
    include_directories: [challenge_NarfRPN_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args,
    link_args: challenges_extra_link_args
)
