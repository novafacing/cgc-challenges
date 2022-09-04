# challenge_COLLIDEOSCOPE
challenge_COLLIDEOSCOPE_inc = include_directories('include')
challenge_COLLIDEOSCOPE_src = [
    'src/interpreter.c',
    'src/namespace.c',
    'src/parser.c',
    'src/prettyprinter.c',
    'src/service.c',
    'src/tokenizer.c',
    'src/lib/bitset.c',
    'src/lib/conv.c',
    'src/lib/math.c',
    'src/lib/pool.c',
    'src/lib/stdio.c',
    'src/lib/stdlib.c',
    'src/lib/string.c',
]
challenge_COLLIDEOSCOPE = executable(
    'COLLIDEOSCOPE',
    challenge_COLLIDEOSCOPE_src,
    include_directories: [challenge_COLLIDEOSCOPE_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path
)
