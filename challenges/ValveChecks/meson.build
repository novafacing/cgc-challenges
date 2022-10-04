# challenge_ValveChecks
challenge_ValveChecks_inc = include_directories('include')
challenge_ValveChecks_src = [
    'src/csum.c',
    'src/service.c',
    'src/lib/libc.c',
]
challenge_ValveChecks = executable(
    'ValveChecks',
    challenge_ValveChecks_src,
    include_directories: [challenge_ValveChecks_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args,
    link_args: challenges_extra_link_args
)
