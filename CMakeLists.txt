cmake_minimum_required(VERSION 3.6)

project(CppRoundRobin)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/RoundRobin.cpp src/RoundRobin.h)
add_library(CppRoundRobin ${SOURCE_FILES})