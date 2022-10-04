# challenge_Cereal_Mixup__A_Cereal_Vending_Machine_Controller
challenge_Cereal_Mixup__A_Cereal_Vending_Machine_Controller_inc = include_directories('include')
challenge_Cereal_Mixup__A_Cereal_Vending_Machine_Controller_src = [
    'src/actuators.c',
    'src/breakfast.c',
    'src/breakfast_objects.c',
    'src/service.c',
    'src/lib/char.c',
    'src/lib/hex.c',
    'src/lib/int2str.c',
    'src/lib/malloc.c',
    'src/lib/memcmp.c',
    'src/lib/memcpy.c',
    'src/lib/memset.c',
    'src/lib/read_all.c',
    'src/lib/recv_all.c',
    'src/lib/send.c',
    'src/lib/sendall.c',
    'src/lib/strlen.c',
    'src/lib/strncmp.c',
    'src/lib/strncpy.c',
    'src/lib/xxprintf.c',
]
challenge_Cereal_Mixup__A_Cereal_Vending_Machine_Controller = executable(
    'Cereal_Mixup__A_Cereal_Vending_Machine_Controller',
    challenge_Cereal_Mixup__A_Cereal_Vending_Machine_Controller_src,
    include_directories: [challenge_Cereal_Mixup__A_Cereal_Vending_Machine_Controller_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    link_args: challenges_extra_link_args
)
