# challenge_Divelogger2
challenge_Divelogger2_inc = include_directories('include')
challenge_Divelogger2_src = [
    'src/commandhandler.cc',
    'src/common.cc',
    'src/datetime.cc',
    'src/datetime_helper.cc',
    'src/dive.cc',
    'src/dlqueue.cc',
    'src/service.cc',
    'src/lib/malloc.c',
    'src/lib/mymath.c',
    'src/lib/new_printf.c',
    'src/lib/stdlib.c',
    'src/lib/string.cc',
]
challenge_Divelogger2 = executable(
    'Divelogger2',
    challenge_Divelogger2_src,
    include_directories: [challenge_Divelogger2_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    link_args: challenges_extra_link_args
)
