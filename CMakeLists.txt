cmake_minimum_required(VERSION 3.17)
project(Algorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(Algorithm
        main.cpp
        tree/tree.h
        tree/tree.cpp
        tree/binary_tree.h
        tree/binary_tree.cpp)
