# challenge_hawaii_sets
challenge_hawaii_sets_inc = include_directories('include')
challenge_hawaii_sets_src = [
    'src/service.c',
    'src/struct_inits.c',
    'src/lib/mymath.c',
    'src/lib/printf.c',
    'src/lib/stdlib.c',
]
challenge_hawaii_sets = executable(
    'hawaii_sets',
    challenge_hawaii_sets_src,
    include_directories: [challenge_hawaii_sets_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path,
    install: true
)
