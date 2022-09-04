# challenge_stream_vm
challenge_stream_vm_inc = include_directories('include')
challenge_stream_vm_src = [
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
challenge_stream_vm = executable(
    'stream_vm',
    challenge_stream_vm_src,
    include_directories: [challenge_stream_vm_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path
)
