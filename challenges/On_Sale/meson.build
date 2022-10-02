# challenge_On_Sale
challenge_On_Sale_inc = include_directories('include')
challenge_On_Sale_src = [
    'src/inventory.c',
    'src/products.c',
    'src/sale.c',
    'src/service.c',
    'src/lib/list.c',
    'src/lib/malloc.c',
    'src/lib/memcmp.c',
    'src/lib/memcpy.c',
    'src/lib/memset.c',
    'src/lib/recv_bytes.c',
    'src/lib/recv_until_delim_n.c',
    'src/lib/send_bytes.c',
    'src/lib/string.c',
]
challenge_On_Sale = executable(
    'On_Sale',
    challenge_On_Sale_src,
    include_directories: [challenge_On_Sale_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args
)
