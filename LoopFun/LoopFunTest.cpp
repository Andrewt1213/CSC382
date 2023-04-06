//
// Created by Richard H. Mercer on 6-Sep-2022.
// Author: Andrew Tapia
// This tells Catch to provide a main() - only do this in one cpp file

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "LoopFun.hpp"

TEST_CASE ("fibonnacci") {
    REQUIRE(21 == fibonacci(8));
    REQUIRE(3524578 == fibonacci(33));
}

TEST_CASE ("factorial") {
    REQUIRE(1 == factorial(0));
    REQUIRE(120 == factorial(5));
}

TEST_CASE ("vowelCount") {
    REQUIRE(10 == vowelCount("a e i o u A E I O U"));
}

TEST_CASE("isPrime") {
    REQUIRE_FALSE(isPrime(4));
    REQUIRE_FALSE(isPrime(8));
    REQUIRE(isPrime(5));
    REQUIRE(isPrime(7));
}

TEST_CASE ("numberOfPairs") {
    REQUIRE(2 == numberOfPairs("abbba"));
    REQUIRE(0 == numberOfPairs("abBba"));
}

TEST_CASE("isSorted") {
    // Cast str.length() to an int with this
    // static_cast<int>(str.length())
    REQUIRE(isSorted("abbcddef"));
    REQUIRE_FALSE(isSorted("BA"));
}

TEST_CASE ("howSwedish") {
    REQUIRE(0 == howSwedish("aBBbba"));
    REQUIRE(1 == howSwedish("aBBaAbbXa"));
}


TEST_CASE ("allAsLeft") {
    REQUIRE("AAAaaa" == allAsLeft("aaaAAA"));
}


TEST_CASE ("mirrorEnds") {
    REQUIRE("ab" == mirrorEnds("abXYZba"));
    REQUIRE("aasdsaa" == mirrorEnds("aasdsaa"));
}


TEST_CASE ("starOut") {
    REQUIRE(starOut("ab*cd") == "ad");
    REQUIRE(starOut("*stringy") == "tringy");
    REQUIRE(starOut("sm*eil*ly") == "siy");
}


TEST_CASE ("GCD") {
    REQUIRE(123 == GCD(123, 0));
    REQUIRE(2 == GCD(22, 32));
}

TEST_CASE ("Square root") {
    // 4.000000000000 != 4.000000000022 so use Catch2's wrapper class Approx
    REQUIRE(Approx(4.0) == square_root(16.0, 1e-10));
    REQUIRE(Approx(2.0) == square_root(4.0, 1e-10));
    REQUIRE(Approx(111.108) == square_root(12345.0, 1e-10));
    REQUIRE(Approx(3.0) == square_root(9.0, 1e-10));
    REQUIRE(Approx(1.4142135624) == square_root(2.0, 1e-10));
    REQUIRE(Approx(3.45) == square_root(11.9025, 1e-10));
    REQUIRE(Approx(3.450001) == square_root(11.9025, 1e-10));
}