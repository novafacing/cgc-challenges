# challenge_Thermal_Controller_v2
challenge_Thermal_Controller_v2_inc = include_directories('include')
challenge_Thermal_Controller_v2_src = [
    'src/common.cc',
    'src/comms.cc',
    'src/controller.cc',
    'src/sensor.cc',
    'src/service.cc',
    'src/lib/ctype.c',
    'src/lib/cutil_string.cc',
    'src/lib/malloc.c',
    'src/lib/math.c',
    'src/lib/prng.c',
    'src/lib/stdio.c',
    'src/lib/stdlib.c',
    'src/lib/string.c',
]
challenge_Thermal_Controller_v2 = executable(
    'Thermal_Controller_v2',
    challenge_Thermal_Controller_v2_src,
    include_directories: [challenge_Thermal_Controller_v2_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args,
    link_args: challenges_extra_link_args
)
