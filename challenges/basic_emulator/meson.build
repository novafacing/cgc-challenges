# challenge_basic_emulator
challenge_basic_emulator_inc = include_directories('include')
challenge_basic_emulator_src = [
    'src/cpu.c',
    'src/gb.c',
    'src/lcd.c',
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
    'src/lib/strsep.c',
    'src/lib/strtol.c',
]
challenge_basic_emulator = executable(
    'basic_emulator',
    challenge_basic_emulator_src,
    include_directories: [challenge_basic_emulator_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path,
    install: true
)
