# challenge_REMATCH_6__Secure_Server__Heartbleed
challenge_REMATCH_6__Secure_Server__Heartbleed_inc = include_directories('include')
challenge_REMATCH_6__Secure_Server__Heartbleed_src = [
    'src/application.c',
    'src/msls.c',
    'src/msls_handlers.c',
    'src/msls_handshake.c',
    'src/service.c',
    'src/lib/ctype.c',
    'src/lib/malloc.c',
    'src/lib/math.c',
    'src/lib/stdio.c',
    'src/lib/stdlib.c',
    'src/lib/string.c',
]
challenge_REMATCH_6__Secure_Server__Heartbleed = executable(
    'REMATCH_6--Secure_Server--Heartbleed',
    challenge_REMATCH_6__Secure_Server__Heartbleed_src,
    include_directories: [challenge_REMATCH_6__Secure_Server__Heartbleed_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path,
    install: true
)
