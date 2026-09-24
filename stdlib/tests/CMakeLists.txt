enable_language(CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test_write test_write.cpp)
target_link_libraries(test_write PRIVATE itzamna_stdlib)

add_executable(test_read test_read.cpp)
target_link_libraries(test_read PRIVATE itzamna_stdlib)
