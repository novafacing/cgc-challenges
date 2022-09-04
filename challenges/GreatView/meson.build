# challenge_GreatView
challenge_GreatView_inc = include_directories('include')
challenge_GreatView_src = [
    'src/service.c',
    'src/viewscript.c',
    'src/lib/libc.c',
]
challenge_GreatView = executable(
    'GreatView',
    challenge_GreatView_src,
    include_directories: [challenge_GreatView_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path,
    install: true
)
