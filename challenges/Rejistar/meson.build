# challenge_Rejistar
challenge_Rejistar_inc = include_directories('include')
challenge_Rejistar_src = [
    'src/certificate.c',
    'src/service.c',
    'src/token.c',
    'src/util.c',
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
challenge_Rejistar = executable(
    'Rejistar',
    challenge_Rejistar_src,
    include_directories: [challenge_Rejistar_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args,
    link_args: challenges_extra_link_args
)
