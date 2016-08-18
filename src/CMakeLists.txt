project(RoundRobin)

set(SOURCE_FILES RoundRobin.cpp)
set(HEADER_FILES RoundRobin.h)

add_library(RoundRobin STATIC ${SOURCE_FILES} ${HEADER_FILES})