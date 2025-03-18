cmake_minimum_required(VERSION 3.26)
project(lab3)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab3 src/main.cpp
        src/loadfile.cpp
        src/def.h
        src/funcs.h
        src/prim.cpp
        src/Kruskal.cpp
        src/createedge.cpp)
