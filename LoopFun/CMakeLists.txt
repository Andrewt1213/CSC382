cmake_minimum_required(VERSION 3.24)
project(LoopFun)

set(CMAKE_CXX_STANDARD 17)

# Change the path to the path that now has your new file catch.hpp, could be c:\users\name\ClionProjects
include_directories(C:/Users/lavab/CLionProjects)
include_directories(cmake-build-debug)
add_executable(LoopFun LoopFun.hpp LoopFunTest.cpp)
