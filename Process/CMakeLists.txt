cmake_minimum_required(VERSION 3.25)
project(Process)

set(CMAKE_CXX_STANDARD 23)

add_library(Process STATIC source/process.cpp)

target_include_directories(Process PUBLIC include)

target_link_libraries(Process Part)