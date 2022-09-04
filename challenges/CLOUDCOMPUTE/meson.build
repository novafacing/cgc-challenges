# challenge_CLOUDCOMPUTE
challenge_CLOUDCOMPUTE_inc = include_directories('include')
challenge_CLOUDCOMPUTE_src = [
    'src/bytecode.c',
    'src/service.c',
    'src/lib/char.c',
    'src/lib/debug.c',
    'src/lib/list.c',
    'src/lib/malloc.c',
    'src/lib/memcpy.c',
    'src/lib/memset.c',
    'src/lib/recv_bytes.c',
    'src/lib/recv_until_delim_n.c',
    'src/lib/send_bytes.c',
    'src/lib/streq.c',
    'src/lib/strlen.c',
]
challenge_CLOUDCOMPUTE = executable(
    'CLOUDCOMPUTE',
    challenge_CLOUDCOMPUTE_src,
    include_directories: [challenge_CLOUDCOMPUTE_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true
)
