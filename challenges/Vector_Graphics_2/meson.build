# challenge_Vector_Graphics_2
challenge_Vector_Graphics_2_inc = include_directories('include')
challenge_Vector_Graphics_2_src = [
    'src/canvas.c',
    'src/io.c',
    'src/paint.c',
    'src/pmp.c',
    'src/service.c',
    'src/vgf.c',
    'src/lib/printf.c',
    'src/lib/stdlib.c',
]
challenge_Vector_Graphics_2 = executable(
    'Vector_Graphics_2',
    challenge_Vector_Graphics_2_src,
    include_directories: [challenge_Vector_Graphics_2_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie
)
