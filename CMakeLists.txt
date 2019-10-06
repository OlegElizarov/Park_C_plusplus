cmake_minimum_required(VERSION 3.14)
project(C_plusplus)

add_subdirectory(Gtest/googletest-master)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})



set(CMAKE_C_STANDARD 11)

set(CMAKE_C_CPPCHECK "ccheck")

add_executable(C_plusplus IZN1.c)
add_subdirectory(Gtest)