cmake_minimum_required(VERSION 3.26)
project(3)

set(CMAKE_CXX_STANDARD 17)

add_executable(3 main.cpp
        loadfile.cpp
        def.h
        createlist.cpp)
