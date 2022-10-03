# challenge_Recipe_and_Pantry_Manager
challenge_Recipe_and_Pantry_Manager_inc = include_directories('include')
challenge_Recipe_and_Pantry_Manager_src = [
    'src/service.c',
    'src/lib/ctype.c',
    'src/lib/fs.c',
    'src/lib/malloc.c',
    'src/lib/math.c',
    'src/lib/prng.c',
    'src/lib/stdio.c',
    'src/lib/stdlib.c',
    'src/lib/string.c',
]
challenge_Recipe_and_Pantry_Manager = executable(
    'Recipe_and_Pantry_Manager',
    challenge_Recipe_and_Pantry_Manager_src,
    include_directories: [challenge_Recipe_and_Pantry_Manager_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args
)
