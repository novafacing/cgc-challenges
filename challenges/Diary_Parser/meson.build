# challenge_Diary_Parser
challenge_Diary_Parser_inc = include_directories('include')
challenge_Diary_Parser_src = [
    'src/service.c',
    'src/lib/mymath.c',
    'src/lib/new_printf.c',
    'src/lib/prng.c',
    'src/lib/stdlib.c',
]
challenge_Diary_Parser = executable(
    'Diary_Parser',
    challenge_Diary_Parser_src,
    include_directories: [challenge_Diary_Parser_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path
)
