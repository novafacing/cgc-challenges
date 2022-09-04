# challenge_PTaaS
challenge_PTaaS_inc = include_directories('include')
challenge_PTaaS_src = [
    'src/pathtrace.c',
    'src/plane.c',
    'src/service.c',
    'src/shape.c',
    'src/sphere.c',
    'src/trunc.c',
    'src/lib/bitset.c',
    'src/lib/conv.c',
    'src/lib/image.c',
    'src/lib/math.c',
    'src/lib/pool.c',
    'src/lib/ray.c',
    'src/lib/stdio.c',
    'src/lib/stdlib.c',
    'src/lib/string.c',
    'src/lib/vector.c',
]
challenge_PTaaS = executable(
    'PTaaS',
    challenge_PTaaS_src,
    include_directories: [challenge_PTaaS_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path,
    install: true
)
