project(CppRoundRobinTest)

add_subdirectory(lib/gtest)

set(TEST_SRCS RoundRobinTest.cpp)
add_executable(CppRoundRobinTests ${TEST_SRCS})
target_link_libraries(CppRoundRobinTests gtest gtest_main)
