# challenge_HighFrequencyTradingAlgo
challenge_HighFrequencyTradingAlgo_inc = include_directories('include')
challenge_HighFrequencyTradingAlgo_src = [
    'src/service.c',
    'src/lib/lib.c',
]
challenge_HighFrequencyTradingAlgo = executable(
    'HighFrequencyTradingAlgo',
    challenge_HighFrequencyTradingAlgo_src,
    include_directories: [challenge_HighFrequencyTradingAlgo_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    link_args: challenges_extra_link_args
)
