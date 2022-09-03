# challenge_Matchmaker
challenge_Matchmaker_inc = include_directories('include')
challenge_Matchmaker_src = [
    'src/dfa.c',
    'src/service.c',
    'src/lib/bitset.c',
    'src/lib/conv.c',
    'src/lib/math.c',
    'src/lib/pool.c',
    'src/lib/stdio.c',
    'src/lib/stdlib.c',
    'src/lib/string.c',
]
challenge_Matchmaker = executable(
    'Matchmaker',
    challenge_Matchmaker_src,
    include_directories: [challenge_Matchmaker_inc, libcgc_inc],
    link_with: [libcgc]
)
