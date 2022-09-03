# challenge_Mixology
challenge_Mixology_inc = include_directories('include')
challenge_Mixology_src = [
    'src/service.c',
]
challenge_Mixology = executable(
    'Mixology',
    challenge_Mixology_src,
    include_directories: [challenge_Mixology_inc, libcgc_inc],
    link_with: [libcgc]
)
