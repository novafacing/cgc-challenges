# challenge_CGC_Video_Format_Parser_and_Viewer
challenge_CGC_Video_Format_Parser_and_Viewer_inc = include_directories('include')
challenge_CGC_Video_Format_Parser_and_Viewer_src = [
    'src/bitstream.c',
    'src/parseCVF.c',
    'src/service.c',
    'src/lib/malloc.c',
    'src/lib/mymath.c',
    'src/lib/printf.c',
    'src/lib/stdlib.c',
]
challenge_CGC_Video_Format_Parser_and_Viewer = executable(
    'CGC_Video_Format_Parser_and_Viewer',
    challenge_CGC_Video_Format_Parser_and_Viewer_src,
    include_directories: [challenge_CGC_Video_Format_Parser_and_Viewer_inc, libcgc_inc],
    link_with: [libcgc]
)
