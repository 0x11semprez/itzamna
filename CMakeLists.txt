cmake_minimum_required(VERSION 3.25)

project(
    itzamna
    VERSION 0.1.0
    DESCRIPTION "System VM for safely executing critical or potentially dangerous code"
    LANGUAGES C
)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Minimal libc replacement: raw Linux syscalls, no glibc wrappers.
add_library(
    itzamna_stdlib STATIC

    stdlib/src/linuxsys/write.c
)

target_include_directories(
    itzamna_stdlib

    PUBLIC
        ${PROJECT_SOURCE_DIR}/stdlib/include
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
