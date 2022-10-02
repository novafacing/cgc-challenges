# challenge_REMATCH_5__File_Explorer__LNK_Bug
challenge_REMATCH_5__File_Explorer__LNK_Bug_inc = include_directories('include')
challenge_REMATCH_5__File_Explorer__LNK_Bug_src = [
    'src/cstring.c',
    'src/filesystem.c',
    'src/loader.c',
    'src/osfiles.c',
    'src/shell.c',
    'src/lib/ctype.c',
    'src/lib/malloc.c',
    'src/lib/math.c',
    'src/lib/stdio.c',
    'src/lib/stdlib.c',
    'src/lib/string.c',
]
challenge_REMATCH_5__File_Explorer__LNK_Bug = executable(
    'REMATCH_5--File_Explorer--LNK_Bug',
    challenge_REMATCH_5__File_Explorer__LNK_Bug_src,
    include_directories: [challenge_REMATCH_5__File_Explorer__LNK_Bug_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie
)
