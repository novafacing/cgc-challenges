poller_targets = []
foreach challenge : challenges_to_build
    challenge_dir = challenges_directory / challenge
    poller_dir = challenge_dir / 'poller'
    for_release = poller_dir / 'for-release'
    for_testing = poller_dir / 'for-testing'
    poll_names = []
    foreach i : range(POLLS_COUNT_PER_BIN)
        poll_names += 'poll_' + challenge + '_' + i.to_string() + '.poll'
    endforeach

    if fs.is_dir(for_release) and fs.is_file(for_release / 'machine.py')
        machine_file = for_release / 'machine.py'
        state_file = for_release / 'state-graph.yaml'
    elif fs.is_dir(for_testing) and fs.is_file(for_testing / 'machine.py')
        machine_file = for_testing / 'machine.py'
        state_file = for_testing / 'state-graph.yaml'
    else
        continue
    endif

    poller_targets += custom_target(
        challenge + '_polls',
        output: poll_names,
        input: [machine_file, state_file],
        command : [
            'env',
            'PYTHONPATH=' + polls_dir,
            python_2,
            generate_polls,
            challenge,
            '@INPUT@',
            '.'
        ],
        install_dir : install_path / 'share' / 'polls' / challenge,
        install : true
    )
endforeach