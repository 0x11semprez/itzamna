enable_language(CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Each test is one C++ file linked against the stdlib and registered with CTest.
function(itz_add_test name)
    add_executable(${name} ${name}.cpp)
    target_link_libraries(${name} PRIVATE itzamna_stdlib)
    target_include_directories(${name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    add_test(NAME ${name} COMMAND ${name})
endfunction()

itz_add_test(test_unistd)
itz_add_test(test_string)
