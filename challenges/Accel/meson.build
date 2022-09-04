# challenge_Accel
challenge_Accel_inc = include_directories('include')
challenge_Accel_src = [
    'src/accel.c',
    'src/accelfunc.c',
    'src/accelio.c',
    'src/atof.c',
    'src/ftoa.c',
    'src/itoa.c',
    'src/main.c',
    'src/queue.c',
    'src/stack.c',
    'src/lib/calloc.c',
    'src/lib/ctype.c',
    'src/lib/free.c',
    'src/lib/malloc.c',
    'src/lib/malloc_common.c',
    'src/lib/memchr.c',
    'src/lib/memcmp.c',
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
challenge_Accel = executable(
    'Accel',
    challenge_Accel_src,
    include_directories: [challenge_Accel_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path
)
