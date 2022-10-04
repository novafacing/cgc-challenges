# challenge_WordCompletion
challenge_WordCompletion_inc = include_directories('include')
challenge_WordCompletion_src = [
    'src/main.c',
]
challenge_WordCompletion = executable(
    'WordCompletion',
    challenge_WordCompletion_src,
    include_directories: [challenge_WordCompletion_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    link_args: challenges_extra_link_args
)
