# challenge_Flight_Routes
challenge_Flight_Routes_inc = include_directories('include')
challenge_Flight_Routes_src = [
    'src/airports.c',
    'src/commands.c',
    'src/findroute.c',
    'src/load_database.c',
    'src/service.c',
    'src/utility.c',
    'src/lib/malloc.c',
    'src/lib/mymath.c',
    'src/lib/new_printf.c',
    'src/lib/stdlib.c',
]
challenge_Flight_Routes = executable(
    'Flight_Routes',
    challenge_Flight_Routes_src,
    include_directories: [challenge_Flight_Routes_inc, libcgc_inc],
    link_with: [libcgc]
)
