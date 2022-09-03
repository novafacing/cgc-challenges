# challenge_ECM_TCM_Simulator
challenge_ECM_TCM_Simulator_inc = include_directories('include')
challenge_ECM_TCM_Simulator_src = [
    'src/common.cc',
    'src/ecm.cc',
    'src/lanbus.cc',
    'src/response.cc',
    'src/service.cc',
    'src/simulation.cc',
    'src/tcm.cc',
    'src/lib/ctype.c',
    'src/lib/cutil_string.cc',
    'src/lib/malloc.c',
    'src/lib/math.c',
    'src/lib/prng.c',
    'src/lib/stdio.c',
    'src/lib/stdlib.c',
    'src/lib/string.c',
]
challenge_ECM_TCM_Simulator = executable(
    'ECM_TCM_Simulator',
    challenge_ECM_TCM_Simulator_src,
    include_directories: [challenge_ECM_TCM_Simulator_inc, libcgc_inc],
    link_with: [libcgc]
)
