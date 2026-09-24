# Minimal libc replacement: raw Linux syscalls, no glibc wrappers.
add_library(
    itzamna_stdlib STATIC

    src/unistd/read.c
    src/unistd/write.c
    src/string/strlen.c
    src/io/putnbr.c
)

target_include_directories(
    itzamna_stdlib

    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
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

add_subdirectory(tests)
