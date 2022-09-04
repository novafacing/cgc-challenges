# challenge_CGC_File_System
challenge_CGC_File_System_inc = include_directories('include')
challenge_CGC_File_System_src = [
    'src/command.c',
    'src/file.c',
    'src/recv.c',
    'src/service.c',
    'src/lib/malloc.c',
    'src/lib/mymath.c',
    'src/lib/printf.c',
    'src/lib/stdlib.c',
]
challenge_CGC_File_System = executable(
    'CGC_File_System',
    challenge_CGC_File_System_src,
    include_directories: [challenge_CGC_File_System_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path
)
