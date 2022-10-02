# challenge_Simple_Stack_Machine
challenge_Simple_Stack_Machine_src = [
    'src/main.c',
]
challenge_Simple_Stack_Machine = executable(
    'Simple_Stack_Machine',
    challenge_Simple_Stack_Machine_src,
    include_directories: [libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args
)
