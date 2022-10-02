# challenge_Shortest_Path_Tree_Calculator
challenge_Shortest_Path_Tree_Calculator_inc = include_directories('include')
challenge_Shortest_Path_Tree_Calculator_src = [
    'src/graph.c',
    'src/io.c',
    'src/ll.c',
    'src/service.c',
    'src/lib/ctype.c',
    'src/lib/malloc.c',
    'src/lib/math.c',
    'src/lib/prng.c',
    'src/lib/stdio.c',
    'src/lib/stdlib.c',
    'src/lib/string.c',
]
challenge_Shortest_Path_Tree_Calculator = executable(
    'Shortest_Path_Tree_Calculator',
    challenge_Shortest_Path_Tree_Calculator_src,
    include_directories: [challenge_Shortest_Path_Tree_Calculator_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie
)
