# challenge_Lazybox
challenge_Lazybox_inc = include_directories('include')
challenge_Lazybox_src = [
    'src/fs.c',
    'src/io.c',
    'src/screen.c',
    'src/service.c',
    'src/shell.c',
    'src/user.c',
    'src/lib/ctype.c',
    'src/lib/malloc.c',
    'src/lib/math.c',
    'src/lib/prng.c',
    'src/lib/stdio.c',
    'src/lib/stdlib.c',
    'src/lib/string.c',
]
challenge_Lazybox = executable(
    'Lazybox',
    challenge_Lazybox_src,
    include_directories: [challenge_Lazybox_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    link_args: challenges_extra_link_args
)
