# challenge_GPS_Tracker
challenge_GPS_Tracker_inc = include_directories('include')
challenge_GPS_Tracker_src = [
    'src/comms.cc',
    'src/geofence.cc',
    'src/gps.cc',
    'src/packagetracker.cc',
    'src/service.cc',
    'src/workerprng.cc',
    'src/lib/malloc.c',
    'src/lib/mymath.c',
    'src/lib/new_printf.c',
    'src/lib/stdlib.c',
]
challenge_GPS_Tracker = executable(
    'GPS_Tracker',
    challenge_GPS_Tracker_src,
    include_directories: [challenge_GPS_Tracker_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true
)
