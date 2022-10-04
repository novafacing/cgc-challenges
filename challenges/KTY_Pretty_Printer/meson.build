# challenge_KTY_Pretty_Printer
challenge_KTY_Pretty_Printer_inc = include_directories('include')
challenge_KTY_Pretty_Printer_src = [
    'src/array.c',
    'src/hashtable.c',
    'src/kty.c',
    'src/main.c',
    'src/strdup.c',
    'src/strncmp.c',
    'src/strtod.c',
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
challenge_KTY_Pretty_Printer = executable(
    'KTY_Pretty_Printer',
    challenge_KTY_Pretty_Printer_src,
    include_directories: [challenge_KTY_Pretty_Printer_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    link_args: challenges_extra_link_args
)
