cmake_minimum_required(VERSION 4.1)
project(Data_structure_sp26)

set(CMAKE_CXX_STANDARD 14)

include_directories(implements)

add_executable(Data_structure_sp26
        hw1/第一章_杨其霄_信科/Integer.cpp
        hw1/第一章_杨其霄_信科/q4.cpp
        hw1/Integer.cpp
        hw1/q4.cpp
        implements/SeqList.cpp
        implements/SeqList.h
        implements/SLList.cpp
        implements/SLList.h
        hw2/test.cpp
        hw2/q3-2.cpp
        hw2/q3-3.cpp
        hw2/q3-5.cpp
        hw2/q3-6.cpp)
