# challenge_CableGrindLlama
challenge_CableGrindLlama_inc = include_directories('include')
challenge_CableGrindLlama_src = [
    'src/cablegrind.c',
    'src/cablegrindprotos.c',
    'src/service.c',
    'src/lib/libc.c',
    'src/lib/libdupe.c',
]
challenge_CableGrindLlama = executable(
    'CableGrindLlama',
    challenge_CableGrindLlama_src,
    include_directories: [challenge_CableGrindLlama_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path
)
