# challenge_BitBlaster
challenge_BitBlaster_src = [
    'src/main.c',
]
challenge_BitBlaster = executable(
    'BitBlaster',
    challenge_BitBlaster_src,
    include_directories: [libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie
)
