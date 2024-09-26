cmake_minimum_required(VERSION 3.25)
project(LibInput)

set(CMAKE_CXX_STANDARD 23)

add_library(LibInput STATIC source/input.cpp)

target_include_directories(LibInput PUBLIC include)

target_link_libraries(LibInput Part)