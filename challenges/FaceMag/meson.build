# challenge_FaceMag
challenge_FaceMag_inc = include_directories('include')
challenge_FaceMag_src = [
    'src/auth.c',
    'src/comms.c',
    'src/posts.c',
    'src/service.c',
    'src/stickyposts.c',
]
challenge_FaceMag = executable(
    'FaceMag',
    challenge_FaceMag_src,
    include_directories: [challenge_FaceMag_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args
)
