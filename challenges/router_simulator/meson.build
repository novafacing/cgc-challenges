# challenge_router_simulator
challenge_router_simulator_inc = include_directories('include')
challenge_router_simulator_src = [
    'src/main.c',
    'src/lib/calloc.c',
    'src/lib/ctype.c',
    'src/lib/free.c',
    'src/lib/malloc.c',
    'src/lib/malloc_common.c',
    'src/lib/memchr.c',
    'src/lib/memcpy.c',
    'src/lib/memset.c',
    'src/lib/printf.c',
    'src/lib/realloc.c',
    'src/lib/strchr.c',
    'src/lib/strcmp.c',
    'src/lib/strcpy.c',
    'src/lib/strlen.c',
    'src/lib/strncpy.c',
    'src/lib/strsep.c',
    'src/lib/strtol.c',
]
challenge_router_simulator = executable(
    'router_simulator',
    challenge_router_simulator_src,
    include_directories: [challenge_router_simulator_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path,
    install: true
)
