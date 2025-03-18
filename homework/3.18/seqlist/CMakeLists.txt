cmake_minimum_required(VERSION 3.26)
project(datastructure)

set(CMAKE_CXX_STANDARD 17)

add_executable(datastructure main.cpp
        seqlistoper.h
        delete.cpp
        End.cpp
        def.h
        deleterepeat.cpp
        inverselist.cpp
        movecycle.cpp
        mergelist.cpp
        printlist.cpp)
