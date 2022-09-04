# challenge_stack_vm
challenge_stack_vm_inc = include_directories('include')
challenge_stack_vm_src = [
    'src/service.c',
    'src/stack.c',
    'src/vm.c',
    'src/lib/lib.c',
]
challenge_stack_vm = executable(
    'stack_vm',
    challenge_stack_vm_src,
    include_directories: [challenge_stack_vm_inc, libcgc_inc],
    link_with: [libcgc],
    install_dir: install_path,
    install: true
)
