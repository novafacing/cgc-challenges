# challenge_virtual_pet
challenge_virtual_pet_inc = include_directories('include')
challenge_virtual_pet_src = [
    'src/main.cc',
    'src/lib/cgc_libc.c',
    'src/lib/cgc_malloc.c',
    'src/lib/printf.c',
]
challenge_virtual_pet = executable(
    'virtual_pet',
    challenge_virtual_pet_src,
    include_directories: [challenge_virtual_pet_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie
)
