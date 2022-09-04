# challenge_Estadio
challenge_Estadio_inc = include_directories('include')
challenge_Estadio_src = [
    'src/churn.c',
    'src/handler.c',
    'src/messages.c',
    'src/protocol.c',
    'src/service.c',
    'src/lib/libc.c',
]
challenge_Estadio = executable(
    'Estadio',
    challenge_Estadio_src,
    include_directories: [challenge_Estadio_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path,
    install: true
)
