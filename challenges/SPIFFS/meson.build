# challenge_SPIFFS
challenge_SPIFFS_inc = include_directories('include')
challenge_SPIFFS_src = [
    'src/service.c',
    'src/ui.c',
    'src/lib/malloc.c',
    'src/lib/mymath.c',
    'src/lib/stdlib.c',
]
challenge_SPIFFS = executable(
    'SPIFFS',
    challenge_SPIFFS_src,
    include_directories: [challenge_SPIFFS_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path,
    install: true
)
