# challenge_SFTSCBSISS
challenge_SFTSCBSISS_inc = include_directories('include')
challenge_SFTSCBSISS_src = [
    'src/packet.c',
    'src/service.c',
    'src/vars.c',
    'src/lib/malloc.c',
    'src/lib/mymath.c',
    'src/lib/printf.c',
    'src/lib/prng.c',
    'src/lib/stdlib.c',
]
challenge_SFTSCBSISS = executable(
    'SFTSCBSISS',
    challenge_SFTSCBSISS_src,
    include_directories: [challenge_SFTSCBSISS_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args
)
