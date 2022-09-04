# challenge_Water_Treatment_Facility_Simulator
challenge_Water_Treatment_Facility_Simulator_inc = include_directories('include')
challenge_Water_Treatment_Facility_Simulator_src = [
    'src/menu.c',
    'src/plant.c',
    'src/service.c',
    'src/sim.c',
]
challenge_Water_Treatment_Facility_Simulator = executable(
    'Water_Treatment_Facility_Simulator',
    challenge_Water_Treatment_Facility_Simulator_src,
    include_directories: [challenge_Water_Treatment_Facility_Simulator_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path
)
