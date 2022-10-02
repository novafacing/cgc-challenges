# challenge_SCUBA_Dive_Logging
challenge_SCUBA_Dive_Logging_inc = include_directories('include')
challenge_SCUBA_Dive_Logging_src = [
    'src/dates.c',
    'src/dive_statistics.c',
    'src/download_dive.c',
    'src/edit_diver.c',
    'src/edit_dives.c',
    'src/log_dive.c',
    'src/menu.c',
    'src/print_dives.c',
    'src/remove_dives.c',
    'src/service.c',
    'src/lib/malloc.c',
    'src/lib/mymath.c',
    'src/lib/new_printf.c',
    'src/lib/stdlib.c',
]
challenge_SCUBA_Dive_Logging = executable(
    'SCUBA_Dive_Logging',
    challenge_SCUBA_Dive_Logging_src,
    include_directories: [challenge_SCUBA_Dive_Logging_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie
)
