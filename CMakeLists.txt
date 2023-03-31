cmake_minimum_required(VERSION 3.24)
project(Poker)

set(CMAKE_CXX_STANDARD 17)

include_directories(C:/Users/lavab/CLionProjects)

add_executable(Poker Card.cpp PokerHand.cpp CardTest.cpp)
