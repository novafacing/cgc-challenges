# challenge_PCM_Message_decoder
challenge_PCM_Message_decoder_inc = include_directories('include')
challenge_PCM_Message_decoder_src = [
    'src/common.c',
    'src/service.c',
    'src/lib/mymath.c',
    'src/lib/printf.c',
    'src/lib/prng.c',
    'src/lib/stdlib.c',
]
challenge_PCM_Message_decoder = executable(
    'PCM_Message_decoder',
    challenge_PCM_Message_decoder_src,
    include_directories: [challenge_PCM_Message_decoder_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args,
    link_args: challenges_extra_link_args
)
