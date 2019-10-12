cmake_minimum_required(VERSION 3.11)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

set(LIB_SOURCE_FILES
        func.c
        Gtest/googletest-master/googletest/include/gtest/gtest.h
        )


find_package(GTest REQUIRED)
find_package(Threads)
INCLUDE_DIRECTORIES(${GTEST_INCLUDE_DIRS})

add_library(study_std_lib STATIC ${LIB_SOURCE_FILES})

project(Gtest_run)

add_executable(Gtest_run Gtest/test.cpp )
target_link_libraries(Gtest_run  ${GTEST_BOTH_LIBRARIES} study_std_lib)
