# challenge_online_job_application
challenge_online_job_application_inc = include_directories('include')
challenge_online_job_application_src = [
    'src/main.c',
    'src/utils.c',
    'src/lib/calloc.c',
    'src/lib/ctype.c',
    'src/lib/free.c',
    'src/lib/malloc.c',
    'src/lib/malloc_common.c',
    'src/lib/memchr.c',
    'src/lib/memcmp.c',
    'src/lib/memcpy.c',
    'src/lib/memset.c',
    'src/lib/printf.c',
    'src/lib/realloc.c',
    'src/lib/strchr.c',
    'src/lib/strcmp.c',
    'src/lib/strcpy.c',
    'src/lib/strlen.c',
    'src/lib/strsep.c',
    'src/lib/strtol.c',
]
challenge_online_job_application = executable(
    'online_job_application',
    challenge_online_job_application_src,
    include_directories: [challenge_online_job_application_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path,
    install: true
)
