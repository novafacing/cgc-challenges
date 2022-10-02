# challenge_yolodex
challenge_yolodex_inc = include_directories('include')
challenge_yolodex_src = [
    'src/yolodex.c',
    'src/lib/malloc.c',
    'src/lib/mymath.c',
    'src/lib/printf.c',
    'src/lib/stdlib.c',
]
challenge_yolodex = executable(
    'yolodex',
    challenge_yolodex_src,
    include_directories: [challenge_yolodex_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie
)
