# challenge_Multipass2
challenge_Multipass2_inc = include_directories('include')
challenge_Multipass2_src = [
    'src/mp.c',
    'src/service.c',
    'src/lib/libc.c',
]
challenge_Multipass2 = executable(
    'Multipass2',
    challenge_Multipass2_src,
    include_directories: [challenge_Multipass2_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args
)
