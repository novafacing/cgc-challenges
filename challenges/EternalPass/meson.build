# challenge_EternalPass
challenge_EternalPass_inc = include_directories('include')
challenge_EternalPass_src = [
    'src/adjectives.c',
    'src/adverbs.c',
    'src/nouns.c',
    'src/service.c',
    'src/verbs.c',
    'src/lib/crc32.c',
    'src/lib/libc.c',
    'src/lib/list.c',
    'src/lib/malloc.c',
    'src/lib/prng.c',
]
challenge_EternalPass = executable(
    'EternalPass',
    challenge_EternalPass_src,
    include_directories: [challenge_EternalPass_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args
)
