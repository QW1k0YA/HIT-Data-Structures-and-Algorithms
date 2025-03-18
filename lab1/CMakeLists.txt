cmake_minimum_required(VERSION 3.26)
project(lab1)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab1 main.cpp
        Stack.h
        popstack.cpp
        pushstack.cpp
        loadfile.cpp
        printstack.cpp)
