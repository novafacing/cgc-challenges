# challenge_Thermal_Controller_v3
challenge_Thermal_Controller_v3_inc = include_directories('include')
challenge_Thermal_Controller_v3_src = [
    'src/service.c',
    'src/ui.c',
    'src/lib/ctype.c',
    'src/lib/fs.c',
    'src/lib/input.c',
    'src/lib/malloc.c',
    'src/lib/math.c',
    'src/lib/prng.c',
    'src/lib/stdio.c',
    'src/lib/stdlib.c',
    'src/lib/string.c',
]
challenge_Thermal_Controller_v3 = executable(
    'Thermal_Controller_v3',
    challenge_Thermal_Controller_v3_src,
    include_directories: [challenge_Thermal_Controller_v3_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path,
    install: true
)
