# challenge_GREYMATTER
challenge_GREYMATTER_inc = include_directories('include')
challenge_GREYMATTER_src = [
    'src/service.c',
    'src/lib/libc.c',
]
challenge_GREYMATTER = executable(
    'GREYMATTER',
    challenge_GREYMATTER_src,
    include_directories: [challenge_GREYMATTER_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path
)
