# challenge_Palindrome
challenge_Palindrome_inc = include_directories('include')
challenge_Palindrome_src = [
    'src/service.c',
    'src/lib/libc.c',
]
challenge_Palindrome = executable(
    'Palindrome',
    challenge_Palindrome_src,
    include_directories: [challenge_Palindrome_inc, libcgc_inc],
    link_with: [libcgc]
)
