# challenge_CGC_Board
challenge_CGC_Board_inc = include_directories('include')
challenge_CGC_Board_src = [
    'src/engine.c',
    'src/io.c',
    'src/main.c',
    'src/lib/calloc.c',
    'src/lib/ctype.c',
    'src/lib/free.c',
    'src/lib/malloc.c',
    'src/lib/malloc_common.c',
    'src/lib/memchr.c',
    'src/lib/memcmp.c',
    'src/lib/memcpy.c',
    'src/lib/memmove.c',
    'src/lib/memset.c',
    'src/lib/printf.c',
    'src/lib/realloc.c',
    'src/lib/strcasecmp.c',
    'src/lib/strcat.c',
    'src/lib/strchr.c',
    'src/lib/strcmp.c',
    'src/lib/strcpy.c',
    'src/lib/strdup.c',
    'src/lib/strlen.c',
    'src/lib/strncasecmp.c',
    'src/lib/strncmp.c',
    'src/lib/strncpy.c',
    'src/lib/strsep.c',
    'src/lib/strtol.c',
]
challenge_CGC_Board = executable(
    'CGC_Board',
    challenge_CGC_Board_src,
    include_directories: [challenge_CGC_Board_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    link_args: challenges_extra_link_args
)
