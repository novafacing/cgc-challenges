# challenge_NoHiC
challenge_NoHiC_inc = include_directories('include')
challenge_NoHiC_src = [
    'src/math_fun.c',
    'src/operation.c',
    'src/service.c',
    'src/lib/libc.c',
]
challenge_NoHiC = executable(
    'NoHiC',
    challenge_NoHiC_src,
    include_directories: [challenge_NoHiC_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args
)
