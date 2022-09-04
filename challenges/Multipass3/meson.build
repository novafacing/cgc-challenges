# challenge_Multipass3
challenge_Multipass3_inc = include_directories('include')
challenge_Multipass3_src = [
    'src/account.c',
    'src/multipass.c',
    'src/service.c',
    'src/lib/libc.c',
    'src/lib/ll.c',
    'src/lib/sheap.c',
]
challenge_Multipass3 = executable(
    'Multipass3',
    challenge_Multipass3_src,
    include_directories: [challenge_Multipass3_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true
)
