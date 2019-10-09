#cmake_minimum_required(VERSION 3.12)
#project(C_plusplus)

#set(CMAKE_C_STANDARD 11)
#add_executable(C_plusplus IZN1.c)

project(Gtest_run)


add_subdirectory(Gtest/googletest-master)
include_directories(Gtest/googletest-master/googletest/include googletest-master/googletest/src )
include_directories(C_plusplus)

set(CMAKE_CXX_STANDARD 17)
add_executable(Gtest_run /Users/elenaelizarova/CLionProjects/Park_C_plusplus/Gtest/test.cpp)
target_link_libraries(Gtest_run gtest gtest_main)