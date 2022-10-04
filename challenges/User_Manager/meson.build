# challenge_User_Manager
challenge_User_Manager_inc = include_directories('include')
challenge_User_Manager_src = [
    'src/common.cc',
    'src/doublequeue.cc',
    'src/service.cc',
    'src/userdatabase.cc',
    'src/usermanager.cc',
    'src/usermessage.cc',
    'src/lib/malloc.c',
    'src/lib/mymath.c',
    'src/lib/new_printf.c',
    'src/lib/stdlib.c',
    'src/lib/string.cc',
]
challenge_User_Manager = executable(
    'User_Manager',
    challenge_User_Manager_src,
    include_directories: [challenge_User_Manager_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args,
    link_args: challenges_extra_link_args
)
