cmake_minimum_required(VERSION 3.21)

project(GameOfLife23)

set(CMAKE_CXX_STANDARD 14)

include_directories(C:/Users/lavab/CLionProjects)

add_executable( GameOfLife23 GameOfLifeTest.cpp GameOfLife.cpp )

# Use this to run the main method
# add_executable(GameOfLife23 main.cpp)
