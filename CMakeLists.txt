cmake_minimum_required(VERSION 3.15)
project(datastruct)

set(CMAKE_CXX_STANDARD 14)

add_executable(datastruct tests/main.cpp src/DataStruct.cpp src/DataStruct.hxx
        src/common.h src/Heap.hxx src/SegmentTree.hxx)