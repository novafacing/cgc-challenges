# libpov

libpov_src = [
    'src/ctype.c',
    'src/getenv.c',
    'src/malloc.c',
    'src/memcpy.c',
    'src/memset.c',
    'src/pcre_byte_order.c',
    'src/pcre_chartables.c',
    'src/pcre_compile.c',
    'src/pcre_config.c',
    'src/pcre_dfa_exec.c',
    'src/pcre_exec.c',
    'src/pcre_fullinfo.c',
    'src/pcre_get.c',
    'src/pcre_globals.c',
    'src/pcre_jit_compile.c',
    'src/pcre_maketables.c',
    'src/pcre_newline.c',
    'src/pcre_ord2utf8.c',
    'src/pcre_refcount.c',
    'src/pcre_string_utils.c',
    'src/pcre_study.c',
    'src/pcre_tables.c',
    'src/pcre_ucd.c',
    'src/pcre_valid_utf8.c',
    'src/pcre_version.c',
    'src/pcre_xclass.c',
    'src/pov.c',
    'src/strchr.c',
    'src/strcmp.c',
    'src/strcpy.c',
    'src/strlen.c',
    'src/strtol.c',
    'src/toupper.c',
]

libpov_inc = include_directories('include')

libpov = library(
    'pov',
    libpov_src,
    c_args: ['-pedantic', '-fno-builtin', '-O0'],
    include_directories: [libpov_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path,
    install: true
)