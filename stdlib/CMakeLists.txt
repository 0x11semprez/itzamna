# Minimal libc replacement: raw Linux syscalls, no glibc wrappers.
add_library(
    itzamna_stdlib STATIC

    src/syscstd/read.c
    src/syscstd/write.c
    src/string/string.c
)

target_include_directories(
    itzamna_stdlib

    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(
        itzamna_stdlib

        PRIVATE
            -Wall
            -Wextra
            -Wpedantic
    )
endif()
