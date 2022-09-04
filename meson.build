project('cb-multios-meson', 'c', 'cpp')

fs = import('fs')

install_path = get_option('install_path')
if install_path == 'output'
    if meson.version().version_compare('>=0.56.0')
        install_path = meson.project_source_root() / install_path
    else
        install_path = meson.source_root() / install_path
    endif
endif

if not fs.is_dir(install_path)
    error('Install directory', install_path, 'does not exist!')
endif

subdir('lib')
subdir('challenges')