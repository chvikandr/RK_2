cmake_minimum_required(VERSION 3.22)
project(RK2)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/third-party/gtest" "gtest")


add_library(tree STATIC reverse.cpp)

add_executable(test ${CMAKE_CURRENT_SOURCE_DIR}/tests/test.cpp)

if (COVERAGE)
    target_compile_options(test PRIVATE --coverage)
    target_link_libraries(test PRIVATE --coverage)
endif()

target_link_libraries(test PRIVATE gtest gtest_main tree)

