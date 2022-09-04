# challenge_Charter
challenge_Charter_inc = include_directories('include')
challenge_Charter_src = [
    'src/bars.c',
    'src/block.c',
    'src/data.c',
    'src/rand.c',
    'src/service.c',
    'src/sparks.c',
]
challenge_Charter = executable(
    'Charter',
    challenge_Charter_src,
    include_directories: [challenge_Charter_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path
)
