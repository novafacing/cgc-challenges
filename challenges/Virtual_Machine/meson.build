# challenge_Virtual_Machine
challenge_Virtual_Machine_inc = include_directories('include')
challenge_Virtual_Machine_src = [
    'src/clf.cc',
    'src/common.cc',
    'src/cpu.cc',
    'src/dma.cc',
    'src/mmu.cc',
    'src/peripheral.cc',
    'src/service.cc',
    'src/vm.cc',
    'src/lib/ctype.c',
    'src/lib/cutil_string.cc',
    'src/lib/malloc.c',
    'src/lib/math.c',
    'src/lib/prng.c',
    'src/lib/stdio.c',
    'src/lib/stdlib.c',
    'src/lib/string.c',
]
challenge_Virtual_Machine = executable(
    'Virtual_Machine',
    challenge_Virtual_Machine_src,
    include_directories: [challenge_Virtual_Machine_inc, libcgc_inc],
    link_with: [libcgc]
)
