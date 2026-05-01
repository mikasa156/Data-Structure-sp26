cmake_minimum_required(VERSION 4.2)
project(Lists)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lists
        SeqList.tpp
        SeqList.h
        SLList.tpp
        SLList.h
        TLinkedList.tpp
        TLinkedList.h
        SeqList.tpp)
