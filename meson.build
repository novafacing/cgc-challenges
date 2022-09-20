project('cb-multios-meson', 'c', 'cpp')

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

# Poll generation paths
python_3 = import('python').find_installation('python3')
poll_gen_file = meson.project_source_root() / 'scripts' / 'generate-polls.py'
poll_gen_lib = meson.project_source_root() / 'scripts' / 'lib'

# Settings for poll generation
POLLS_COUNT_PER_BIN = 20
POLLS_DUPLICATE_PER_BIN = 1
POLLS_REPEAT_PER_BIN = 1

subdir('lib')
subdir('challenges')