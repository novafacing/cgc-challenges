# challenge_Eddy
challenge_Eddy_inc = include_directories('include')
challenge_Eddy_src = [
    'src/editor.c',
    'src/regex.c',
    'src/service.c',
    'src/lib/libc.c',
    'src/lib/malloc.c',
]
challenge_Eddy = executable(
    'Eddy',
    challenge_Eddy_src,
    include_directories: [challenge_Eddy_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path,
    install: true
)
