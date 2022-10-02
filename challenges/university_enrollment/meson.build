# challenge_university_enrollment
challenge_university_enrollment_inc = include_directories('include')
challenge_university_enrollment_src = [
    'src/course.c',
    'src/data_gen.c',
    'src/department.c',
    'src/main.c',
    'src/professor.c',
    'src/ptrlist.c',
    'src/read.c',
    'src/student.c',
    'src/time.c',
]
challenge_university_enrollment = executable(
    'university_enrollment',
    challenge_university_enrollment_src,
    include_directories: [challenge_university_enrollment_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path / 'bin',
    install: true,
    pie: challenges_pie,
    c_args: challenges_extra_c_args
)
