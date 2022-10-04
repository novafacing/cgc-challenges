# challenge_Overflow_Parking
challenge_Overflow_Parking_inc = include_directories('include')
challenge_Overflow_Parking_src = [
    'src/malloc.c',
    'src/service.c',
    'src/lib/libc.c',
    'src/lib/list.c',
    'src/lib/prng.c',
]
challenge_Overflow_Parking = executable(
    'Overflow_Parking',
    challenge_Overflow_Parking_src,
    include_directories: [challenge_Overflow_Parking_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args,
    link_args: challenges_extra_link_args
)
