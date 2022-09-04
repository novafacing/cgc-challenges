# challenge_simple_integer_calculator
challenge_simple_integer_calculator_inc = include_directories('include')
challenge_simple_integer_calculator_src = [
    'src/ltypes.c',
    'src/service.c',
    'src/stack.c',
    'src/trie.c',
    'src/lib/malloc.c',
    'src/lib/mymath.c',
    'src/lib/new_printf.c',
    'src/lib/stdlib.c',
]
challenge_simple_integer_calculator = executable(
    'simple_integer_calculator',
    challenge_simple_integer_calculator_src,
    include_directories: [challenge_simple_integer_calculator_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path,
    install: true
)
