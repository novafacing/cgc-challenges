# challenge_Diophantine_Password_Wallet
challenge_Diophantine_Password_Wallet_inc = include_directories('include')
challenge_Diophantine_Password_Wallet_src = [
    'src/main.c',
    'src/lib/mylibc.c',
]
challenge_Diophantine_Password_Wallet = executable(
    'Diophantine_Password_Wallet',
    challenge_Diophantine_Password_Wallet_src,
    include_directories: [challenge_Diophantine_Password_Wallet_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie
)
