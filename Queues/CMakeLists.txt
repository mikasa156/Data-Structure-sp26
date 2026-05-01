cmake_minimum_required(VERSION 4.2)
project(Queues)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Queues
        TLinkedQueue.h
        CirQueue.h
        CirQueue.tpp
        CirQueue.tpp)
