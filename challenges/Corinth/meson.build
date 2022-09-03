# challenge_Corinth
challenge_Corinth_inc = include_directories('include')
challenge_Corinth_src = [
    'src/block.c',
    'src/handler.c',
    'src/messages.c',
    'src/monte.c',
    'src/protocol.c',
    'src/service.c',
    'src/types.c',
]
challenge_Corinth = executable(
    'Corinth',
    challenge_Corinth_src,
    include_directories: [challenge_Corinth_inc, libcgc_inc],
    link_with: [libcgc]
)
