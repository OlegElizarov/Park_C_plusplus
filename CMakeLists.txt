cmake_minimum_required(VERSION 3.11)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

set(LIB_SOURCE_FILES
        func.c
        Gtest/googletest-master/googletest/include/gtest/gtest.h
        )

add_library(study_std_lib STATIC ${LIB_SOURCE_FILES})

project(Gtest_run)

add_executable(Gtest_run Gtest/test.cpp)
target_link_libraries(Gtest_run study_std_lib)
