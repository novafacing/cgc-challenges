# challenge_cotton_swab_arithmetic
challenge_cotton_swab_arithmetic_inc = include_directories('include')
challenge_cotton_swab_arithmetic_src = [
    'src/service.c',
    'src/lib/libc.c',
]
challenge_cotton_swab_arithmetic = executable(
    'cotton_swab_arithmetic',
    challenge_cotton_swab_arithmetic_src,
    include_directories: [challenge_cotton_swab_arithmetic_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true
)
