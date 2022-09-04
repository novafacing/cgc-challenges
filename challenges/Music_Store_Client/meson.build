# challenge_Music_Store_Client
challenge_Music_Store_Client_inc = include_directories('include')
challenge_Music_Store_Client_src = [
    'src/service.c',
    'src/lib/libc.c',
]
challenge_Music_Store_Client = executable(
    'Music_Store_Client',
    challenge_Music_Store_Client_src,
    include_directories: [challenge_Music_Store_Client_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true
)
