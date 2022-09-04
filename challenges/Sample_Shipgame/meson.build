# challenge_Sample_Shipgame
challenge_Sample_Shipgame_inc = include_directories('include')
challenge_Sample_Shipgame_src = [
    'src/sample_shipgame.c',
    'src/lib/mylibc.c',
]
challenge_Sample_Shipgame = executable(
    'Sample_Shipgame',
    challenge_Sample_Shipgame_src,
    include_directories: [challenge_Sample_Shipgame_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path
)
