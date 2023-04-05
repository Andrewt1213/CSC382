cmake_minimum_required(VERSION 3.25)
project(PokerGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(PokerGame main.cpp playPoker.cpp Deck.cpp Player.cpp PokerHand.cpp 52Cards.hpp)
