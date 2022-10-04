# challenge_Flash_File_System
challenge_Flash_File_System_inc = include_directories('include')
challenge_Flash_File_System_src = [
    'src/comms.cc',
    'src/flash_fs.cc',
    'src/nor_flash.cc',
    'src/service.cc',
    'src/lib/ctype.c',
    'src/lib/cutil_string.cc',
    'src/lib/fs.c',
    'src/lib/malloc.c',
    'src/lib/math.c',
    'src/lib/prng.c',
    'src/lib/stdio.c',
    'src/lib/stdlib.c',
    'src/lib/string.c',
]
challenge_Flash_File_System = executable(
    'Flash_File_System',
    challenge_Flash_File_System_src,
    include_directories: [challenge_Flash_File_System_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args,
    link_args: challenges_extra_link_args
)
