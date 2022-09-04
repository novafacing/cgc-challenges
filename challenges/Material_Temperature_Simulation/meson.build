# challenge_Material_Temperature_Simulation
challenge_Material_Temperature_Simulation_inc = include_directories('include')
challenge_Material_Temperature_Simulation_src = [
    'src/input.c',
    'src/room.c',
    'src/service.c',
    'src/tsim.c',
    'src/tvis.c',
    'src/lib/malloc.c',
    'src/lib/mymath.c',
    'src/lib/printf.c',
    'src/lib/prng.c',
    'src/lib/stdlib.c',
]
challenge_Material_Temperature_Simulation = executable(
    'Material_Temperature_Simulation',
    challenge_Material_Temperature_Simulation_src,
    include_directories: [challenge_Material_Temperature_Simulation_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true
)
