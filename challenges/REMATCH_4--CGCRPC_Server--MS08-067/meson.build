# challenge_REMATCH_4__CGCRPC_Server__MS08_067
challenge_REMATCH_4__CGCRPC_Server__MS08_067_inc = include_directories('include')
challenge_REMATCH_4__CGCRPC_Server__MS08_067_src = [
    'src/cgcmb.c',
    'src/cgcrpc.c',
    'src/fs.c',
    'src/netstuff.c',
    'src/service.c',
    'src/transport.c',
    'src/user.c',
    'src/lib/ctype.c',
    'src/lib/fs.c',
    'src/lib/malloc.c',
    'src/lib/math.c',
    'src/lib/stdio.c',
    'src/lib/stdlib.c',
    'src/lib/string.c',
]
challenge_REMATCH_4__CGCRPC_Server__MS08_067 = executable(
    'REMATCH_4--CGCRPC_Server--MS08-067',
    challenge_REMATCH_4__CGCRPC_Server__MS08_067_src,
    include_directories: [challenge_REMATCH_4__CGCRPC_Server__MS08_067_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path,
    install: true
)
