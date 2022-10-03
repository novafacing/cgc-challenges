# challenge_Filesystem_Command_Shell
challenge_Filesystem_Command_Shell_inc = include_directories('include')
challenge_Filesystem_Command_Shell_src = [
    'src/auth.c',
    'src/commands.c',
    'src/filesystem.c',
    'src/service.c',
    'src/tokenizer.c',
    'src/wildcardsearch.c',
    'src/lib/ctype.c',
    'src/lib/input.c',
    'src/lib/malloc.c',
    'src/lib/math.c',
    'src/lib/prng.c',
    'src/lib/stdio.c',
    'src/lib/stdlib.c',
    'src/lib/string.c',
]
challenge_Filesystem_Command_Shell = executable(
    'Filesystem_Command_Shell',
    challenge_Filesystem_Command_Shell_src,
    include_directories: [challenge_Filesystem_Command_Shell_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args
)
