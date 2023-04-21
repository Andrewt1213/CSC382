cmake_minimum_required(VERSION 3.25)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 17)

include_directories(C:/Users/Lenovo/CLionProjects/CSC382)

add_executable(TicTacToe myModel.cpp TicTacToeTests.cpp myController.cpp myController.cpp)
