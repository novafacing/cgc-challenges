# challenge_3D_Image_Toolkit
challenge_3D_Image_Toolkit_inc = include_directories('include')
challenge_3D_Image_Toolkit_src = [
    'src/3dc.c',
    'src/compress.c',
    'src/main.c',
    'src/lib/ctype.c',
    'src/lib/input.c',
    'src/lib/malloc.c',
    'src/lib/math.c',
    'src/lib/prng.c',
    'src/lib/stdio.c',
    'src/lib/stdlib.c',
    'src/lib/string.c',
]
challenge_3D_Image_Toolkit = executable(
    '3D_Image_Toolkit',
    challenge_3D_Image_Toolkit_src,
    include_directories: [challenge_3D_Image_Toolkit_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path
)
