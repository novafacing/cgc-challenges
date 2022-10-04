# challenge_Facilities_Access_Control_System
challenge_Facilities_Access_Control_System_inc = include_directories('include')
challenge_Facilities_Access_Control_System_src = [
    'src/alarm.c',
    'src/device.c',
    'src/io.c',
    'src/service.c',
    'src/user.c',
    'src/lib/ctype.c',
    'src/lib/malloc.c',
    'src/lib/math.c',
    'src/lib/prng.c',
    'src/lib/stdio.c',
    'src/lib/stdlib.c',
    'src/lib/string.c',
]
challenge_Facilities_Access_Control_System = executable(
    'Facilities_Access_Control_System',
    challenge_Facilities_Access_Control_System_src,
    include_directories: [challenge_Facilities_Access_Control_System_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args,
    link_args: challenges_extra_link_args
)
