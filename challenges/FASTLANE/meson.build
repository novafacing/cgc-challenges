# challenge_FASTLANE
challenge_FASTLANE_inc = include_directories('include')
challenge_FASTLANE_src = [
    'src/service.c',
    'src/verbs.c',
    'src/lib/libc.c',
]
challenge_FASTLANE = executable(
    'FASTLANE',
    challenge_FASTLANE_src,
    include_directories: [challenge_FASTLANE_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path,
    install: true
)
