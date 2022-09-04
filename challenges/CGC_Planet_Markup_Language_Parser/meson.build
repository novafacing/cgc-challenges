# challenge_CGC_Planet_Markup_Language_Parser
challenge_CGC_Planet_Markup_Language_Parser_inc = include_directories('include')
challenge_CGC_Planet_Markup_Language_Parser_src = [
    'src/cityParsers.c',
    'src/countryParsers.c',
    'src/countyParsers.c',
    'src/genericParsers.c',
    'src/helper.c',
    'src/planetParsers.c',
    'src/service.c',
    'src/string.c',
    'src/territoryParsers.c',
    'src/lib/mymath.c',
    'src/lib/printf.c',
    'src/lib/stdlib.c',
]
challenge_CGC_Planet_Markup_Language_Parser = executable(
    'CGC_Planet_Markup_Language_Parser',
    challenge_CGC_Planet_Markup_Language_Parser_src,
    include_directories: [challenge_CGC_Planet_Markup_Language_Parser_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path
)
