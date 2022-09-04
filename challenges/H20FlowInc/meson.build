# challenge_H20FlowInc
challenge_H20FlowInc_inc = include_directories('include')
challenge_H20FlowInc_src = [
    'src/h2o.c',
    'src/operation.c',
    'src/service.c',
    'src/tank.c',
    'src/lib/int2str.c',
    'src/lib/malloc.c',
    'src/lib/memcpy.c',
    'src/lib/memset.c',
    'src/lib/pi_prng.c',
    'src/lib/read_all.c',
    'src/lib/recv_all.c',
    'src/lib/send.c',
    'src/lib/sendall.c',
    'src/lib/sleep.c',
    'src/lib/strlen.c',
    'src/lib/strncpy.c',
    'src/lib/syslog.c',
    'src/lib/xxprintf.c',
]
challenge_H20FlowInc = executable(
    'H20FlowInc',
    challenge_H20FlowInc_src,
    include_directories: [challenge_H20FlowInc_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path
)
