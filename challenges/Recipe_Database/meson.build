# challenge_Recipe_Database
challenge_Recipe_Database_inc = include_directories('include')
challenge_Recipe_Database_src = [
    'src/compare_strings.c',
    'src/find_recipe.c',
    'src/get_ingredients.c',
    'src/get_instructions.c',
    'src/match_str.c',
    'src/new_recipe.c',
    'src/print_main_menu.c',
    'src/print_recipe.c',
    'src/print_shopping_list.c',
    'src/service.c',
    'src/sort_shopping_list.c',
    'src/split_ingredients.c',
    'src/lib/malloc.c',
    'src/lib/mymath.c',
    'src/lib/new_printf.c',
    'src/lib/stdlib.c',
]
challenge_Recipe_Database = executable(
    'Recipe_Database',
    challenge_Recipe_Database_src,
    include_directories: [challenge_Recipe_Database_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args,
    link_args: challenges_extra_link_args
)
