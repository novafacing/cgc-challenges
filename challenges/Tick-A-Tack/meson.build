# challenge_Tick_A_Tack
challenge_Tick_A_Tack_inc = include_directories('include')
challenge_Tick_A_Tack_src = [
    'src/service.c',
    'src/lib/libc.c',
    'src/lib/tt.c',
]
challenge_Tick_A_Tack = executable(
    'Tick-A-Tack',
    challenge_Tick_A_Tack_src,
    include_directories: [challenge_Tick_A_Tack_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie
)
