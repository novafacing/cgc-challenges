# challenge_Estadio
challenge_Estadio_inc = include_directories('include')
challenge_Estadio_lib_src = [
    'src/lib/libc.c',
]
challenge_Estadio_src = [
    'src/churn.c',
    'src/handler.c',
    'src/messages.c',
    'src/protocol.c',
    'src/service.c',
] + challenge_Estadio_lib_src

challenge_Estadio = executable(
    'Estadio',
    challenge_Estadio_src,
    include_directories: [challenge_Estadio_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie
)

challenge_lib_Estadio = library(
    'Estadio',
    challenge_Estadio_lib_src,
    include_directories: [challenge_Estadio_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'lib',
    install: true,
    pie: challenges_pie
)
