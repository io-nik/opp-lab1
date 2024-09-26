cmake_minimum_required(VERSION 3.25)
project(Part)

set(CMAKE_CXX_STANDARD 23)

add_library(Part STATIC source/Part.cpp)

target_include_directories(Part PUBLIC include)