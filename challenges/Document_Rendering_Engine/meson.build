# challenge_Document_Rendering_Engine
challenge_Document_Rendering_Engine_inc = include_directories('include')
challenge_Document_Rendering_Engine_src = [
    'src/service.c',
    'src/lib/libc.c',
    'src/lib/malloc.c',
]
challenge_Document_Rendering_Engine = executable(
    'Document_Rendering_Engine',
    challenge_Document_Rendering_Engine_src,
    include_directories: [challenge_Document_Rendering_Engine_inc, libcgc_inc],
    link_with: [libcgc]
)
