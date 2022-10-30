# cb-multios-meson libraries

# libpov

libpov_src = [
    'libpov/src/ctype.c',
    'libpov/src/getenv.c',
    'libpov/src/malloc.c',
    'libpov/src/memcpy.c',
    'libpov/src/memset.c',
    'libpov/src/pcre_byte_order.c',
    'libpov/src/pcre_chartables.c',
    'libpov/src/pcre_compile.c',
    'libpov/src/pcre_config.c',
    'libpov/src/pcre_dfa_exec.c',
    'libpov/src/pcre_exec.c',
    'libpov/src/pcre_fullinfo.c',
    'libpov/src/pcre_get.c',
    'libpov/src/pcre_globals.c',
    'libpov/src/pcre_jit_compile.c',
    'libpov/src/pcre_maketables.c',
    'libpov/src/pcre_newline.c',
    'libpov/src/pcre_ord2utf8.c',
    'libpov/src/pcre_refcount.c',
    'libpov/src/pcre_string_utils.c',
    'libpov/src/pcre_study.c',
    'libpov/src/pcre_tables.c',
    'libpov/src/pcre_ucd.c',
    'libpov/src/pcre_valid_utf8.c',
    'libpov/src/pcre_version.c',
    'libpov/src/pcre_xclass.c',
    'libpov/src/pov.c',
    'libpov/src/strchr.c',
    'libpov/src/strcmp.c',
    'libpov/src/strcpy.c',
    'libpov/src/strlen.c',
    'libpov/src/strtol.c',
    'libpov/src/toupper.c',
]
libpov_inc = include_directories('libpov/include')

# libcgc

libcgc_src = [
    'libcgc/src/ansi_x931_aes128.c',
    'libcgc/src/libcgc.c',
    'libcgc/src/libcgc_win.c',
]

libcgc_inc = include_directories('libcgc/include')


# libtiny-aes
libtiny_AES128_C_inc = include_directories('libtiny-AES128-C/include')
libtiny_AES128_C = library(
    'tiny-AES128-C',
    'libtiny-AES128-C/aes.c',
    include_directories: libtiny_AES128_C_inc,
    install_dir: install_path / 'lib',
    install: true
)

cc = meson.get_compiler('c')
libm_dep = cc.find_library('m', required: true)

libcgc = library(
    'cgc',
    libcgc_src,
    include_directories: [libcgc_inc, libtiny_AES128_C_inc],
    link_with: [libtiny_AES128_C],
    dependencies: [libm_dep],
    install_dir: install_path / 'lib',
    install: true
)

libpov = library(
    'pov',
    libpov_src,
    c_args: ['-pedantic', '-fno-builtin', '-O0'],
    include_directories: [libpov_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'lib',
    install: true
)
