//
// Created by Lenovo on 4/20/2023.
//
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <iostream>
#include "myModel.cpp"
using namespace std;

TEST_CASE("Test validMove") {
    MyModel model;
    REQUIRE(model.validMove(0, 0) == true);
    REQUIRE(model.validMove(0, 1) == true);
    REQUIRE(model.validMove(0, 2) == true);

    REQUIRE(model.validMove(1, 0) == true);
    REQUIRE(model.validMove(1, 1) == true);
    REQUIRE(model.validMove(1, 2) == true);

    REQUIRE(model.validMove(2, 0) == true);
    REQUIRE(model.validMove(2, 1) == true);
    REQUIRE(model.validMove(2, 2) == true);

    REQUIRE(model.validMove(-1, -1) == false);
    REQUIRE(model.validMove(3, 3) == false);
}

TEST_CASE("Test gameOver") {
    MyModel model;
    model.setBoard(0, 0, 1);
    model.setBoard(0, 1, 1);
    model.setBoard(0, 2, 1);
    REQUIRE(model.gameOver() == true);
}


