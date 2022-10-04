# challenge_Query_Calculator
challenge_Query_Calculator_inc = include_directories('include')
challenge_Query_Calculator_src = [
    'src/block.c',
    'src/char.c',
    'src/compiler.c',
    'src/eval.c',
    'src/func.c',
    'src/lexer.c',
    'src/protocol.c',
    'src/service.c',
    'src/stack.c',
    'src/types.c',
]
challenge_Query_Calculator = executable(
    'Query_Calculator',
    challenge_Query_Calculator_src,
    include_directories: [challenge_Query_Calculator_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    link_args: challenges_extra_link_args
)
