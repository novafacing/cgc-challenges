# challenge_reallystream
challenge_reallystream_inc = include_directories('include')
challenge_reallystream_src = [
    'src/actions.c',
    'src/rle.c',
    'src/service.c',
    'src/lib/libc.c',
]
challenge_reallystream = executable(
    'reallystream',
    challenge_reallystream_src,
    include_directories: [challenge_reallystream_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args,
    link_args: challenges_extra_link_args
)
