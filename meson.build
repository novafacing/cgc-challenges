project('cb-multios-meson', 'c', 'cpp')


# There are a lot of uninit errors in the code that this fixes
add_project_arguments('-ftrivial-auto-var-init=zero', language: 'c')
add_project_arguments('-ftrivial-auto-var-init=zero', language: 'cpp')

# Set up install directory
fs = import('fs')

install_path = get_option('install_path')
if install_path == 'output'
    if meson.version().version_compare('>=0.56.0')
        install_path = meson.project_source_root() / install_path
    else
        install_path = meson.source_root() / install_path
    endif
endif

if not get_option('no_polls')
    message(
        'Generating polls...if you wanted to skip this, run with '
        + '`meson builddir -Dno_polls=true`'
    )
    python_2 = import('python').find_installation('python2.7', required: true)

    get_pip = meson.project_source_root() / 'scripts' / 'get-pip.py'

    test_pip = run_command(python_2, '-m', 'pip', '--version', check: false)

    if test_pip.returncode() != 0 and not get_option('install_pip_modules')
        error(
            'Python2.7 is missing pip. Please install pip or set '
            + '`meson builddir -Dinstall_pip_modules=true`'
        )
    elif test_pip.returncode() != 0
        message('Installing pip...')
        run_command(python_2, get_pip, check: true)
    endif

    python_2_withmods = import('python').find_installation(
        'python2.7',
        required: false,
        modules: ['Crypto', 'yaml', 'matplotlib']
    )

    if not python_2_withmods.found() and not get_option('install_pip_modules')
        error(
            'Python 2.7 with pycryptodome, pyyaml, and matplotlib is required to '
            + 'generate polls. Please install them or set '
            + '`meson builddir -Dinstall_pip_modules=true`'
        )
    elif not python_2_withmods.found() and get_option('install_pip_modules')
        message('Installing pycryptodome, pyyaml, and matplotlib...')
        run_command(
            python_2,
            '-m',
            'pip',
            'install',
            'pycryptodome',
            'pyyaml',
            'matplotlib',
            check: true
        )
    endif

    python_2_withmods = import('python').find_installation(
        'python2.7',
        required: true,
        modules: ['Crypto', 'yaml', 'matplotlib']
    )

    python_2 = python_2_withmods

    # Settings for poll generation
    POLLS_COUNT_PER_BIN = 20
    POLLS_DUPLICATE_PER_BIN = 1
    POLLS_REPEAT_PER_BIN = 1
    polls_dir = meson.project_source_root() / 'polls'
    generate_polls = polls_dir / 'generate-polls'
endif

subdir('lib')
subdir('challenges')

if not get_option('no_polls')
    subdir('polls')
endif

subdir('test')