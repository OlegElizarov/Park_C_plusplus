cmake_minimum_required(VERSION 3.11)

project(Gtest_runn)

set(LIB_SOURCE_FILES
        ..//func.c
        )

add_library(study_std_lib STATIC ${LIB_SOURCE_FILES})

add_subdirectory(googletest-master)
include_directories(googletest-master/googletest/include googletest-master/googletest/src )

set(CMAKE_CXX_STANDARD 17)
add_executable(Gtest_runn test.cpp)

target_link_libraries(Gtest_runn gtest gtest_main)
target_link_libraries(Gtest_runn study_std_lib)
