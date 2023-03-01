cmake_minimum_required(VERSION 3.22)
project(with_tests)

set(CMAKE_CXX_STANDARD 17)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


add_executable(with_tests tests.cpp gallows.cpp  gallows.h)
target_link_libraries(with_tests gtest gtest_main)
