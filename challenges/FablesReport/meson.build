# challenge_FablesReport
challenge_FablesReport_inc = include_directories('include')
challenge_FablesReport_src = [
    'src/service.c',
    'src/lib/libc.c',
]
challenge_FablesReport = executable(
    'FablesReport',
    challenge_FablesReport_src,
    include_directories: [challenge_FablesReport_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args
)
