cmake_minimum_required(VERSION 3.27)
project(cpp_ds)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp_ds main.cpp
        include/OVec.h
        include/OStArray.h
        include/OLinkedList.h)
