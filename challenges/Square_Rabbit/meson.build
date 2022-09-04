# challenge_Square_Rabbit
challenge_Square_Rabbit_inc = include_directories('include')
challenge_Square_Rabbit_src = [
    'src/deck.c',
    'src/game_sultan.c',
    'src/hand.c',
    'src/squarerabbit.c',
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
challenge_Square_Rabbit = executable(
    'Square_Rabbit',
    challenge_Square_Rabbit_src,
    include_directories: [challenge_Square_Rabbit_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path,
    install: true
)
