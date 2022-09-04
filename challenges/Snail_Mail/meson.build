# challenge_Snail_Mail
challenge_Snail_Mail_inc = include_directories('include')
challenge_Snail_Mail_src = [
    'src/mail.c',
    'src/postage.c',
    'src/service.c',
    'src/lib/bst.c',
    'src/lib/list.c',
    'src/lib/malloc.c',
    'src/lib/memcmp.c',
    'src/lib/memcpy.c',
    'src/lib/memset.c',
    'src/lib/rand.c',
    'src/lib/recv_bytes.c',
    'src/lib/send_bytes.c',
]
challenge_Snail_Mail = executable(
    'Snail_Mail',
    challenge_Snail_Mail_src,
    include_directories: [challenge_Snail_Mail_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path
)
