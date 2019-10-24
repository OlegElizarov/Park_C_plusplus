cmake_minimum_required(VERSION 3.11)

set(CMAKE_C_STANDARD 11)

set(LIB_SOURCE_FILES
        func.c
        IZN2.c IZN2.h text.txt)

add_library(study_std_lib STATIC ${LIB_SOURCE_FILES})

project(Gtest_run)

add_executable(Gtest_run IZN2.c)
target_link_libraries(Gtest_run study_std_lib)