cmake_minimum_required(VERSION 3.26)
project(lab2)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab2 main.cpp
        def.h
        CreateHT.cpp
        InitHT.cpp
        loadfile.cpp
        funcs.h
        InputW.cpp
        SelectMin.cpp
        huff2code.cpp
        file2code.cpp
        decode.cpp
        comprerate.cpp)
