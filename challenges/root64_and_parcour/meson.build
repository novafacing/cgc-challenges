# challenge_root64_and_parcour
challenge_root64_and_parcour_inc = include_directories('include')
challenge_root64_and_parcour_src = [
    'src/main.c',
    'src/parcour.c',
    'src/root64.c',
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
    'src/lib/readuntil.c',
    'src/lib/realloc.c',
    'src/lib/strchr.c',
    'src/lib/strcmp.c',
    'src/lib/strcpy.c',
    'src/lib/strlen.c',
    'src/lib/strsep.c',
    'src/lib/strtol.c',
]
challenge_root64_and_parcour = executable(
    'root64_and_parcour',
    challenge_root64_and_parcour_src,
    include_directories: [challenge_root64_and_parcour_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path
)
