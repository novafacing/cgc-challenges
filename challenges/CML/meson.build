# challenge_CML
challenge_CML_inc = include_directories('include')
challenge_CML_src = [
    'src/attribute.cc',
    'src/cmlnode.cc',
    'src/interface.cc',
    'src/node.cc',
    'src/parser.cc',
    'src/query.cc',
    'src/service.cc',
    'src/string.cc',
    'src/stringmanager.cc',
    'src/textnode.cc',
]
challenge_CML = executable(
    'CML',
    challenge_CML_src,
    include_directories: [challenge_CML_inc, libcgc_inc],
    link_with: [libcgc]
)
