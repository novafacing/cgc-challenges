cmake_minimum_required(VERSION 3.19)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
set(cgc_src libcgc.c)
if(WIN32)
    set(cgc_src libcgc_win.c)
    set_source_files_properties(maths_win.asm PROPERTIES COMPILE_FLAGS "/safeseh")
endif()

add_library(cgc SHARED ${cgc_src} ansi_x931_aes128.c)
target_include_directories(cgc PUBLIC tiny-AES128-C .)
target_link_libraries(cgc LINK_PUBLIC tiny-AES128-C m)

# Build tiny-AES128-C
add_subdirectory(tiny-AES128-C)

# Build libpov
add_subdirectory(libpov)
