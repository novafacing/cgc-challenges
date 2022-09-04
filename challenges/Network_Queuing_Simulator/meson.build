# challenge_Network_Queuing_Simulator
challenge_Network_Queuing_Simulator_inc = include_directories('include')
challenge_Network_Queuing_Simulator_src = [
    'src/generator.c',
    'src/input.c',
    'src/mt.c',
    'src/queue.c',
    'src/receive.c',
    'src/service.c',
    'src/transmit.c',
    'src/lib/mymath.c',
    'src/lib/printf.c',
    'src/lib/stdlib.c',
]
challenge_Network_Queuing_Simulator = executable(
    'Network_Queuing_Simulator',
    challenge_Network_Queuing_Simulator_src,
    include_directories: [challenge_Network_Queuing_Simulator_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path
)
