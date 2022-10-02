# challenge_BudgIT
challenge_BudgIT_inc = include_directories('include')
challenge_BudgIT_src = [
    'src/map.c',
    'src/service.c',
    'src/lib/libc.c',
]
challenge_BudgIT = executable(
    'BudgIT',
    challenge_BudgIT_src,
    include_directories: [challenge_BudgIT_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args
)
