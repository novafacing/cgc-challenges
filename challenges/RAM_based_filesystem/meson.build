# challenge_RAM_based_filesystem
challenge_RAM_based_filesystem_inc = include_directories('include')
challenge_RAM_based_filesystem_src = [
    'src/cmd.c',
    'src/fs.c',
    'src/service.c',
    'src/lib/mymath.c',
    'src/lib/printf.c',
    'src/lib/stdlib.c',
]
challenge_RAM_based_filesystem = executable(
    'RAM_based_filesystem',
    challenge_RAM_based_filesystem_src,
    include_directories: [challenge_RAM_based_filesystem_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true
)
