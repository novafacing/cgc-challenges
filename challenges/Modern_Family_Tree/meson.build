# challenge_Modern_Family_Tree
challenge_Modern_Family_Tree_inc = include_directories('include')
challenge_Modern_Family_Tree_src = [
    'src/people.c',
    'src/service.c',
    'src/lib/char.c',
    'src/lib/hex.c',
    'src/lib/int2str.c',
    'src/lib/malloc.c',
    'src/lib/memcmp.c',
    'src/lib/memcpy.c',
    'src/lib/memset.c',
    'src/lib/read_all.c',
    'src/lib/recv_all.c',
    'src/lib/send.c',
    'src/lib/sendall.c',
    'src/lib/strlen.c',
    'src/lib/strncmp.c',
    'src/lib/strncpy.c',
    'src/lib/xxprintf.c',
]
challenge_Modern_Family_Tree = executable(
    'Modern_Family_Tree',
    challenge_Modern_Family_Tree_src,
    include_directories: [challenge_Modern_Family_Tree_inc, libcgc_inc],
    link_with: [libcgc]
)
