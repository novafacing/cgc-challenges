# challenge_Street_map_service
challenge_Street_map_service_inc = include_directories('include')
challenge_Street_map_service_src = [
    'src/llist.c',
    'src/map.c',
    'src/service.c',
    'src/ui.c',
    'src/lib/mymath.c',
    'src/lib/printf.c',
    'src/lib/stdlib.c',
]
challenge_Street_map_service = executable(
    'Street_map_service',
    challenge_Street_map_service_src,
    include_directories: [challenge_Street_map_service_inc, libcgc_inc],
    link_with: [libcgc]
)
