# challenge_Palindrome2
challenge_Palindrome2_inc = include_directories('include')
challenge_Palindrome2_src = [
    'src/service.c',
    'src/lib/libc.c',
]
challenge_Palindrome2 = executable(
    'Palindrome2',
    challenge_Palindrome2_src,
    include_directories: [challenge_Palindrome2_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true
)
