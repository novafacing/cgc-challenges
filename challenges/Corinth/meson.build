# challenge_Corinth
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
    include_directories: [libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args,
    link_args: challenges_extra_link_args
)
