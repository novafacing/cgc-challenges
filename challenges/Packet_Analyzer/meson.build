# challenge_Packet_Analyzer
challenge_Packet_Analyzer_inc = include_directories('include')
challenge_Packet_Analyzer_src = [
    'src/io.c',
    'src/packet_analysis.c',
    'src/packet_io.c',
    'src/service.c',
    'src/lib/stdlib.c',
]
challenge_Packet_Analyzer = executable(
    'Packet_Analyzer',
    challenge_Packet_Analyzer_src,
    include_directories: [challenge_Packet_Analyzer_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    link_args: challenges_extra_link_args
)
