# challenge_LMS
challenge_LMS_inc = include_directories('include')
challenge_LMS_src = [
    'src/service.c',
    'src/lib/libc.c',
]
challenge_LMS = executable(
    'LMS',
    challenge_LMS_src,
    include_directories: [challenge_LMS_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie
)
