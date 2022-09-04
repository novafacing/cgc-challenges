# challenge_Network_File_System_v3
challenge_Network_File_System_v3_inc = include_directories('include')
challenge_Network_File_System_v3_src = [
    'src/comms.cc',
    'src/databasefs.cc',
    'src/networkfs.cc',
    'src/service.cc',
    'src/timegen.cc',
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
challenge_Network_File_System_v3 = executable(
    'Network_File_System_v3',
    challenge_Network_File_System_v3_src,
    include_directories: [challenge_Network_File_System_v3_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true
)
