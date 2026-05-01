cmake_minimum_required(VERSION 4.2)
project(Stacks)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Stacks
        ArrayStack.tpp
        ArrayStack.h
        LinkStack.tpp
        LinkStack.h
        TLinkedQueue.cpp
        TLinkedQueue.h
)
