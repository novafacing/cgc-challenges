# challenge_DFARS_Sample_Service
challenge_DFARS_Sample_Service_inc = include_directories('include')
challenge_DFARS_Sample_Service_src = [
    'src/service.c',
    'src/lib/cgc_libc.c',
    'src/lib/cgc_malloc.c',
    'src/lib/printf.c',
]
challenge_DFARS_Sample_Service = executable(
    'DFARS_Sample_Service',
    challenge_DFARS_Sample_Service_src,
    include_directories: [challenge_DFARS_Sample_Service_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    link_args: challenges_extra_link_args
)
