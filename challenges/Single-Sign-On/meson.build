# challenge_Single_Sign_On
challenge_Single_Sign_On_inc = include_directories('include')
challenge_Single_Sign_On_src = [
    'src/service.c',
    'src/lib/libc.c',
]
challenge_Single_Sign_On = executable(
    'Single-Sign-On',
    challenge_Single_Sign_On_src,
    include_directories: [challenge_Single_Sign_On_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path,
    install: true
)
