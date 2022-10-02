# challenge_Cromulence_All_Service
challenge_Cromulence_All_Service_inc = include_directories('include')
challenge_Cromulence_All_Service_src = [
    'src/commandhandler.cc',
    'src/common.cc',
    'src/encode_data.c',
    'src/matrix.c',
    'src/service.cc',
    'src/simon.c',
    'src/sort.c',
    'src/lib/malloc.c',
    'src/lib/mymath.c',
    'src/lib/new_printf.c',
    'src/lib/prng.c',
    'src/lib/stdlib.c',
]
challenge_Cromulence_All_Service = executable(
    'Cromulence_All_Service',
    challenge_Cromulence_All_Service_src,
    include_directories: [challenge_Cromulence_All_Service_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie
)
