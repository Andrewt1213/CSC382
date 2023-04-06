//
// Created by Andrew on 3/16/2023.
//

#include "Stacks.hpp"
// This #define tells Catch to provide a main(). Only do this once
#define CATCH_CONFIG_MAIN

#include <catch.hpp>
#include <iostream>

/**
 *  Unit test for Game Of Life.
 */
TEST_CASE("vector") {
    VectorStack<int> *pAbs = new VectorStack<int>;
    REQUIRE(pAbs->isEmpty());
    pAbs->push(1);
    REQUIRE(not pAbs->isEmpty());
    pAbs->push(2);
    REQUIRE(pAbs->top() == 2);
    REQUIRE(pAbs->pop() == 2);
    REQUIRE(pAbs->top() == 1);
}
TEST_CASE("array list") {
    ArrayStack<int> *pAbs = new ArrayStack<int>;
    REQUIRE(pAbs->isEmpty());
    pAbs->push(1);
    REQUIRE(not pAbs->isEmpty());
    pAbs->push(2);
    REQUIRE(pAbs->top() == 2);
    REQUIRE(pAbs->pop() == 2);
    REQUIRE(pAbs->top() == 1);
}

TEST_CASE("linked list") {
    LinkedStack<int> *pAbs = new LinkedStack<int>;
    REQUIRE(pAbs->isEmpty());
    pAbs->push(1);
    REQUIRE(not pAbs->isEmpty());
    pAbs->push(2);
    REQUIRE(pAbs->top() == 2);
    REQUIRE(pAbs->pop() == 2);
    REQUIRE(pAbs->top() == 1);
}