bash = find_program('bash')

foreach challenge, polls : poller_targets
    foreach pollnum : range(POLLS_COUNT_PER_BIN)
        test(
            'test ' + challenge + ' ' + pollnum.to_string(),
            bash,
            args: [
                '-c',
                meson.build_root() / 'challenges' / challenge / challenge
                + ' < '
                + polls.full_path() / 'poll_' + challenge + '_' + pollnum.to_string() + '.poll'
            ],
            env: {
                'LD_LIBRARY_PATH': meson.build_root() / 'lib'
            },
            timeout: 3,
        )
    endforeach
endforeach