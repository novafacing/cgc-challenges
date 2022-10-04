# challenge_Message_Service
challenge_Message_Service_inc = include_directories('include')
challenge_Message_Service_src = [
    'src/admin.c',
    'src/loggedin.c',
    'src/notloggedin.c',
    'src/service.c',
    'src/sort.c',
    'src/lib/jlib.c',
]
challenge_Message_Service = executable(
    'Message_Service',
    challenge_Message_Service_src,
    include_directories: [challenge_Message_Service_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    link_args: challenges_extra_link_args
)
