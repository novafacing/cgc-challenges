# challenge_Particle_Simulator
challenge_Particle_Simulator_inc = include_directories('include')
challenge_Particle_Simulator_src = [
    'src/render.c',
    'src/service.c',
    'src/simulation.c',
    'src/lib/mymath.c',
    'src/lib/printf.c',
    'src/lib/stdlib.c',
]
challenge_Particle_Simulator = executable(
    'Particle_Simulator',
    challenge_Particle_Simulator_src,
    include_directories: [challenge_Particle_Simulator_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie
)
