# challenge_Image_Compressor
challenge_Image_Compressor_inc = include_directories('include')
challenge_Image_Compressor_src = [
    'src/bitwriter.c',
    'src/dct.c',
    'src/huffman.c',
    'src/main.c',
    'src/tables.c',
    'src/lib/calloc.c',
    'src/lib/ctype.c',
    'src/lib/free.c',
    'src/lib/malloc.c',
    'src/lib/malloc_init.c',
    'src/lib/malloc_size.c',
    'src/lib/memchr.c',
    'src/lib/memcpy.c',
    'src/lib/memset.c',
    'src/lib/printf.c',
    'src/lib/realloc.c',
    'src/lib/strchr.c',
    'src/lib/strcmp.c',
    'src/lib/strcpy.c',
    'src/lib/strlen.c',
    'src/lib/strsep.c',
    'src/lib/strtol.c',
]
challenge_Image_Compressor = executable(
    'Image_Compressor',
    challenge_Image_Compressor_src,
    include_directories: [challenge_Image_Compressor_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    link_args: challenges_extra_link_args
)
