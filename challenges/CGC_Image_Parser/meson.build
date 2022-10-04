# challenge_CGC_Image_Parser
challenge_CGC_Image_Parser_inc = include_directories('include')
challenge_CGC_Image_Parser_src = [
    'src/fpai_image_data.c',
    'src/fpti_image_data.c',
    'src/rpti_image_data.c',
    'src/service.c',
    'src/tbir_image_data.c',
    'src/tpai_image_data.c',
    'src/lib/mymath.c',
    'src/lib/printf.c',
    'src/lib/stdlib.c',
]
challenge_CGC_Image_Parser = executable(
    'CGC_Image_Parser',
    challenge_CGC_Image_Parser_src,
    include_directories: [challenge_CGC_Image_Parser_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    link_args: challenges_extra_link_args
)
