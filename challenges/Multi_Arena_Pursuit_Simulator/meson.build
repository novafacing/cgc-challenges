# challenge_Multi_Arena_Pursuit_Simulator
challenge_Multi_Arena_Pursuit_Simulator_inc = include_directories('include')
challenge_Multi_Arena_Pursuit_Simulator_src = [
    'src/map.c',
    'src/service.c',
    'src/lib/atoi.c',
    'src/lib/atox.c',
    'src/lib/bzero.c',
    'src/lib/comms.c',
    'src/lib/malloc.c',
    'src/lib/math.c',
    'src/lib/memcpy.c',
    'src/lib/memset.c',
    'src/lib/sprintf.c',
    'src/lib/strlen.c',
    'src/lib/strncmp.c',
    'src/lib/strtok.c',
]
challenge_Multi_Arena_Pursuit_Simulator = executable(
    'Multi_Arena_Pursuit_Simulator',
    challenge_Multi_Arena_Pursuit_Simulator_src,
    include_directories: [challenge_Multi_Arena_Pursuit_Simulator_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true
)
