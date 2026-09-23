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

include(CTest)

add_subdirectory(stdlib)
