# challenge_CableGrind
challenge_CableGrind_inc = include_directories('include')
challenge_CableGrind_src = [
    'src/cablegrind.c',
    'src/cablegrindprotos.c',
    'src/customprotos.c',
    'src/service.c',
    'src/lib/libc.c',
    'src/lib/libdupe.c',
]
challenge_CableGrind = executable(
    'CableGrind',
    challenge_CableGrind_src,
    include_directories: [challenge_CableGrind_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args,
    link_args: challenges_extra_link_args
)
