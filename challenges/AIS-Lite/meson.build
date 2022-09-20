# challenge_AIS_Lite
challenge_AIS_Lite_inc = include_directories('include')
challenge_AIS_Lite_src = [
    'src/message.c',
    'src/sentence.c',
    'src/service.c',
    'src/sixer.c',
    'src/lib/hex.c',
    'src/lib/int2str.c',
    'src/lib/malloc.c',
    'src/lib/memcpy.c',
    'src/lib/memset.c',
    'src/lib/recv_until_delim.c',
    'src/lib/send.c',
    'src/lib/sendall.c',
    'src/lib/strlen.c',
    'src/lib/strncmp.c',
    'src/lib/strncpy.c',
    'src/lib/xxprintf.c',
]
challenge_AIS_Lite = executable(
    'AIS-Lite',
    challenge_AIS_Lite_src,
    include_directories: [challenge_AIS_Lite_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true
)

if not get_option('no_polls')
    src_dir = meson.current_source_dir()
    poller_dir = src_dir / 'poller' / 'for-release'
    support_dir = src_dir / 'support'
    machine_py_file = poller_dir / 'machine.py'
    state_py_file = poller_dir / 'state-graph.yaml'

    targets = []

    foreach i : range(POLLS_COUNT_PER_BIN)
        poll_name = 'POLL_AIS-Lite_' + i.to_string() + '.raw'
        targets += poll_name
    endforeach

    challenge_AIS_Lite_polls = custom_target(
        'AIS_Lite_polls',
        output: targets,
        input: poll_gen_file,
        command: [
            'env',
            'PYTHONPATH=' + poll_gen_lib + ':' + support_dir,
            python_3,
            '@INPUT@',
            '--name',
            'AIS-Lite',
            '--count',
            POLLS_COUNT_PER_BIN.to_string(),
            machine_py_file,
            state_py_file,
            '.'
        ],
        install_dir: install_path / 'share' / 'polls' / 'AIS-Lite',
        install: true
    )
endif