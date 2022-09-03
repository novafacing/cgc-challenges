# challenge_Scrum_Database
challenge_Scrum_Database_inc = include_directories('include')
challenge_Scrum_Database_src = [
    'src/backlogitems.c',
    'src/commands.c',
    'src/init_database.c',
    'src/obf_strings.c',
    'src/product.c',
    'src/service.c',
    'src/sprints.c',
    'src/utility.c',
    'src/lib/ctype.c',
    'src/lib/input.c',
    'src/lib/malloc.c',
    'src/lib/math.c',
    'src/lib/prng.c',
    'src/lib/stdio.c',
    'src/lib/stdlib.c',
    'src/lib/string.c',
]
challenge_Scrum_Database = executable(
    'Scrum_Database',
    challenge_Scrum_Database_src,
    include_directories: [challenge_Scrum_Database_inc, libcgc_inc],
    link_with: [libcgc]
)
