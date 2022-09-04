# challenge_No_Paper__Not_Ever__NOPE
challenge_No_Paper__Not_Ever__NOPE_inc = include_directories('include')
challenge_No_Paper__Not_Ever__NOPE_src = [
    'src/comms.c',
    'src/service.c',
    'src/taxpayer.c',
    'src/lib/char.c',
    'src/lib/hex.c',
    'src/lib/int2str.c',
    'src/lib/malloc.c',
    'src/lib/memcmp.c',
    'src/lib/memcpy.c',
    'src/lib/memset.c',
    'src/lib/read_all.c',
    'src/lib/recv_all.c',
    'src/lib/send.c',
    'src/lib/sendall.c',
    'src/lib/strlen.c',
    'src/lib/strncmp.c',
    'src/lib/strncpy.c',
    'src/lib/xxprintf.c',
]
challenge_No_Paper__Not_Ever__NOPE = executable(
    'No_Paper._Not_Ever._NOPE',
    challenge_No_Paper__Not_Ever__NOPE_src,
    include_directories: [challenge_No_Paper__Not_Ever__NOPE_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true
)
