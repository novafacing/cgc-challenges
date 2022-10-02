# challenge_One_Vote
challenge_One_Vote_inc = include_directories('include')
challenge_One_Vote_src = [
    'src/election.c',
    'src/service.c',
    'src/lib/conv.c',
    'src/lib/hash_table.c',
    'src/lib/list.c',
    'src/lib/malloc.c',
    'src/lib/memcpy.c',
    'src/lib/memset.c',
    'src/lib/rand.c',
    'src/lib/recv_bytes.c',
    'src/lib/recv_until_delim_n.c',
    'src/lib/send_bytes.c',
    'src/lib/streq.c',
    'src/lib/strlen.c',
    'src/lib/xxprintf.c',
]
challenge_One_Vote = executable(
    'One_Vote',
    challenge_One_Vote_src,
    include_directories: [challenge_One_Vote_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args
)
