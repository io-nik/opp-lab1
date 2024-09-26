cmake_minimum_required(VERSION 3.25)
project(lab1)

set(CMAKE_CXX_STANDARD 23)


set(flag "FALSE")

if(flag)
    add_subdirectory(Dialoge)
    add_subdirectory(Input)
    add_subdirectory(Part)
    add_subdirectory(Process)
else()
    add_subdirectory(Tests)
    add_subdirectory(Part)
    add_subdirectory(Process)
endif()
