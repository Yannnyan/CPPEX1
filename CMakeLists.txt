cmake_minimum_required(VERSION 3.21)
project(Ex1CPP)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Ex1CPP
        Demo.cpp
        doctest.h
        mat.cpp
        mat.hpp
        matTest.cpp
        mattest.cpp
        TestCounter.cpp
        TestExample.cpp)
