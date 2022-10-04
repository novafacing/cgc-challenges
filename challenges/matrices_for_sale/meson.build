# challenge_matrices_for_sale
challenge_matrices_for_sale_inc = include_directories('include')
challenge_matrices_for_sale_src = [
    'src/service.c',
    'src/lib/lib.c',
]
challenge_matrices_for_sale = executable(
    'matrices_for_sale',
    challenge_matrices_for_sale_src,
    include_directories: [challenge_matrices_for_sale_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    link_args: challenges_extra_link_args
)
