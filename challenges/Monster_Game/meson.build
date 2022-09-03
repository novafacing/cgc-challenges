# challenge_Monster_Game
challenge_Monster_Game_inc = include_directories('include')
challenge_Monster_Game_src = [
    'src/service.c',
    'src/lib/ctype.c',
    'src/lib/fs.c',
    'src/lib/malloc.c',
    'src/lib/math.c',
    'src/lib/prng.c',
    'src/lib/stdio.c',
    'src/lib/stdlib.c',
    'src/lib/string.c',
]
challenge_Monster_Game = executable(
    'Monster_Game',
    challenge_Monster_Game_src,
    include_directories: [challenge_Monster_Game_inc, libcgc_inc],
    link_with: [libcgc]
)
