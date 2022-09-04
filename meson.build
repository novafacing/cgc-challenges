project('cb-multios-meson', 'c', 'cpp')

fs = import('fs')

install_path = get_option('install_path')
if install_path == 'output'
    install_path = meson.get_project_source_root() / install_path
endif

if not fs.is_dir(install_path)
    error('Install directory', install_path, 'does not exist!')
endif

subdir('lib')
subdir('challenges')