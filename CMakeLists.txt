cmake_minimum_required(VERSION 3.11)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

set(LIB_SOURCE_FILES
        func2.c
        )

add_library(study_std_lib SHARED ${LIB_SOURCE_FILES})

project(Gtest_run)


add_subdirectory(Gtest/googletest-master)
include_directories(Gtest/googletest-master/googletest/include Gtest/googletest-master/googletest/src )

add_executable(Gtest_run Gtest/test.cpp )
add_executable(Gtest_runn  IZN2.c)

target_link_libraries(Gtest_run study_std_lib)
target_link_libraries(Gtest_runn study_std_lib pthread)
target_link_libraries(Gtest_run gtest gtest_main pthread)
