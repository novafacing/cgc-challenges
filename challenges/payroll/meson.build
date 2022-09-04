# challenge_payroll
challenge_payroll_inc = include_directories('include')
challenge_payroll_src = [
    'src/service.c',
    'src/timecard.c',
    'src/lib/libc.c',
]
challenge_payroll = executable(
    'payroll',
    challenge_payroll_src,
    include_directories: [challenge_payroll_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true
)
