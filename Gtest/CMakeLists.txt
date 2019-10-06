project(Gtest_run)


add_subdirectory(googletest-master)
include_directories(googletest-master/googletest/include googletest-master/googletest/src )
include_directories(C_plusplus)

set(CMAKE_CXX_STANDARD 17)
add_executable(Gtest_run IZN1_test.cpp)
target_link_libraries(Gtest_run gtest gtest_main)