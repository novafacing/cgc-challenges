# challenge_REMATCH_3__Address_Resolution_Service__SQL_Slammer
challenge_REMATCH_3__Address_Resolution_Service__SQL_Slammer_inc = include_directories('include')
challenge_REMATCH_3__Address_Resolution_Service__SQL_Slammer_src = [
    'src/linkedlist.c',
    'src/query.c',
    'src/response.c',
    'src/service.c',
    'src/lib/ctype.c',
    'src/lib/libc.c',
    'src/lib/malloc.c',
    'src/lib/math.c',
    'src/lib/stdio.c',
    'src/lib/stdlib.c',
    'src/lib/string.c',
]
challenge_REMATCH_3__Address_Resolution_Service__SQL_Slammer = executable(
    'REMATCH_3--Address_Resolution_Service--SQL_Slammer',
    challenge_REMATCH_3__Address_Resolution_Service__SQL_Slammer_src,
    include_directories: [challenge_REMATCH_3__Address_Resolution_Service__SQL_Slammer_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path,
    install: true
)
