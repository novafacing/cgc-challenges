# challenge_ValveChecks
challenge_ValveChecks_inc = include_directories('include')
challenge_ValveChecks_src = [
    'src/csum.c',
    'src/service.c',
    'src/lib/libc.c',
]
challenge_ValveChecks = executable(
    'ValveChecks',
    challenge_ValveChecks_src,
    include_directories: [challenge_ValveChecks_inc, libcgc_inc],
    link_with: [libcgc]
)
