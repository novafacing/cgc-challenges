# challenge_Dive_Logger
challenge_Dive_Logger_inc = include_directories('include')
challenge_Dive_Logger_src = [
    'src/service.c',
    'src/ui.c',
    'src/lib/malloc.c',
    'src/lib/mymath.c',
    'src/lib/stdlib.c',
]
challenge_Dive_Logger = executable(
    'Dive_Logger',
    challenge_Dive_Logger_src,
    include_directories: [challenge_Dive_Logger_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    link_args: challenges_extra_link_args
)
