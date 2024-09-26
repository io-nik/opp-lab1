cmake_minimum_required(VERSION 3.25)
project(Tests)

set(CMAKE_CXX_STANDARD 23)

add_executable(Tests   source/Test.cpp)

target_link_libraries(Tests Part
        Process)