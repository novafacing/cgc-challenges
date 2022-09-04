# challenge_SOLFEDGE
challenge_SOLFEDGE_inc = include_directories('include')
challenge_SOLFEDGE_src = [
    'src/operation.c',
    'src/service.c',
    'src/lib/libc.c',
]
challenge_SOLFEDGE = executable(
    'SOLFEDGE',
    challenge_SOLFEDGE_src,
    include_directories: [challenge_SOLFEDGE_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true
)
