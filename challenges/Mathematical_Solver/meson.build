# challenge_Mathematical_Solver
challenge_Mathematical_Solver_inc = include_directories('include')
challenge_Mathematical_Solver_src = [
    'src/math_lib.c',
    'src/service.c',
    'src/shapes.c',
    'src/solver.c',
    'src/stack.c',
    'src/string.c',
    'src/lib/mymath.c',
    'src/lib/printf.c',
    'src/lib/prng.c',
    'src/lib/stdlib.c',
]
challenge_Mathematical_Solver = executable(
    'Mathematical_Solver',
    challenge_Mathematical_Solver_src,
    include_directories: [challenge_Mathematical_Solver_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie
)
