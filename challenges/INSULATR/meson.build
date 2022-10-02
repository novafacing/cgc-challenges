# challenge_INSULATR
challenge_INSULATR_inc = include_directories('include')
challenge_INSULATR_src = [
    'src/service.c',
    'src/lib/libc.c',
]
challenge_INSULATR = executable(
    'INSULATR',
    challenge_INSULATR_src,
    include_directories: [challenge_INSULATR_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie
)
