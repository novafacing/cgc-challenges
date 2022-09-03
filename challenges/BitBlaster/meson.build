# challenge_BitBlaster
challenge_BitBlaster_inc = include_directories('include')
challenge_BitBlaster_src = [
    'src/main.c',
]
challenge_BitBlaster = executable(
    'BitBlaster',
    challenge_BitBlaster_src,
    include_directories: [challenge_BitBlaster_inc, libcgc_inc],
    link_with: [libcgc]
)
