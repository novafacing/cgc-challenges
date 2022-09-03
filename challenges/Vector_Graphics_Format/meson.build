# challenge_Vector_Graphics_Format
challenge_Vector_Graphics_Format_inc = include_directories('include')
challenge_Vector_Graphics_Format_src = [
    'src/io.c',
    'src/pixelmap.c',
    'src/service.c',
    'src/vgf.c',
    'src/lib/malloc.c',
    'src/lib/printf.c',
    'src/lib/stdlib.c',
]
challenge_Vector_Graphics_Format = executable(
    'Vector_Graphics_Format',
    challenge_Vector_Graphics_Format_src,
    include_directories: [challenge_Vector_Graphics_Format_inc, libcgc_inc],
    link_with: [libcgc]
)
