# libcgc

libcgc_src = [
    'src/ansi_x931_aes128.c',
    'src/libcgc.c',
    'src/libcgc_win.c',
]

libcgc_inc = include_directories('include')

cc = meson.get_compiler('c')
libm_dep = cc.find_library('m', required: true)

libcgc = library(
    'cgc',
    libcgc_src,
    include_directories: [libcgc_inc, libtiny_AES128_C_inc],
    link_with: [libtiny_AES128_C],
    dependencies: [libm_dep],
    install_dir: install_path
)