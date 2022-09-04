# challenge_Stock_Exchange_Simulator
challenge_Stock_Exchange_Simulator_inc = include_directories('include')
challenge_Stock_Exchange_Simulator_src = [
    'src/account.c',
    'src/hashtime.c',
    'src/option.c',
    'src/service.c',
    'src/lib/libc.c',
]
challenge_Stock_Exchange_Simulator = executable(
    'Stock_Exchange_Simulator',
    challenge_Stock_Exchange_Simulator_src,
    include_directories: [challenge_Stock_Exchange_Simulator_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path
)
