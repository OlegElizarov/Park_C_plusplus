project(Gtest_runn)


add_subdirectory(googletest-master)
include_directories(googletest-master/googletest/include googletest-master/googletest/src )
include_directories(C_plusplus)

set(CMAKE_CXX_STANDARD 17)
add_executable(Gtest_runn test.cpp)
target_link_libraries(Gtest_runn gtest gtest_main)