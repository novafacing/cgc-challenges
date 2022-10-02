# challenge_Personal_Fitness_Manager
challenge_Personal_Fitness_Manager_inc = include_directories('include')
challenge_Personal_Fitness_Manager_src = [
    'src/common.cc',
    'src/sensor.cc',
    'src/sensor_manager.cc',
    'src/service.cc',
    'src/user.cc',
    'src/lib/ctype.c',
    'src/lib/cutil_string.cc',
    'src/lib/malloc.c',
    'src/lib/math.c',
    'src/lib/prng.c',
    'src/lib/stdio.c',
    'src/lib/stdlib.c',
    'src/lib/string.c',
]
challenge_Personal_Fitness_Manager = executable(
    'Personal_Fitness_Manager',
    challenge_Personal_Fitness_Manager_src,
    include_directories: [challenge_Personal_Fitness_Manager_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie
)
