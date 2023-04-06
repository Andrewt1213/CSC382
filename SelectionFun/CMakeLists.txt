cmake_minimum_required(VERSION 3.13)
project(SelectionStart)

set(CMAKE_CXX_STANDARD 14)

add_executable(SelectionFun catch.hpp SelectionFun.hpp SelectionFunTest.cpp)

