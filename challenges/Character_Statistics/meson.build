# challenge_Character_Statistics
challenge_Character_Statistics_inc = include_directories('include')
challenge_Character_Statistics_src = [
    'src/charstats.c',
]
challenge_Character_Statistics = executable(
    'Character_Statistics',
    challenge_Character_Statistics_src,
    include_directories: [challenge_Character_Statistics_inc, libcgc_inc],
    link_with: [libcgc]
)
