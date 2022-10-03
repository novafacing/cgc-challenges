# challenge_String_Storage_and_Retrieval
challenge_String_Storage_and_Retrieval_inc = include_directories('include')
challenge_String_Storage_and_Retrieval_src = [
    'src/bst.c',
    'src/delete_matches.c',
    'src/find_matches.c',
    'src/parse.c',
    'src/service.c',
    'src/string_token.c',
    'src/lib/malloc.c',
    'src/lib/mymath.c',
    'src/lib/new_printf.c',
    'src/lib/stdlib.c',
]
challenge_String_Storage_and_Retrieval = executable(
    'String_Storage_and_Retrieval',
    challenge_String_Storage_and_Retrieval_src,
    include_directories: [challenge_String_Storage_and_Retrieval_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args
)
