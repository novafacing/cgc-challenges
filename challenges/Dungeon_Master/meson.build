# challenge_Dungeon_Master
challenge_Dungeon_Master_inc = include_directories('include')
challenge_Dungeon_Master_src = [
    'src/dungeon.c',
    'src/service.c',
    'src/lib/atoi.c',
    'src/lib/atox.c',
    'src/lib/bzero.c',
    'src/lib/comms.c',
    'src/lib/malloc.c',
    'src/lib/memcpy.c',
    'src/lib/sprintf.c',
    'src/lib/strlen.c',
    'src/lib/strncmp.c',
    'src/lib/strtok.c',
]
challenge_Dungeon_Master = executable(
    'Dungeon_Master',
    challenge_Dungeon_Master_src,
    include_directories: [challenge_Dungeon_Master_inc, libcgc_inc],
    link_with: [libcgc]
)
