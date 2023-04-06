/*
 * A unit test for the 11 functions in SelectionFun.hpp
 */
// This #define tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include <string>
#include "SelectionFun.hpp"

/*
 * This unit test has at least one test method for each of the 12 methods
 * in catch.hpp. However, they are incomplete and do not represent
 * 100% code coverage. This is meant to encourage you to think of other
 * needed test cases and add your own REQUIREs.
 *
 * We will run a unit test that is much, much larger than this starter unit test.
 *
 * Think of as many test cases as you can.
 *
 * Programmers: Rick Mercer and Andrew Tapia
 */

TEST_CASE("test dayOfWeek") {
    REQUIRE(dayOfWeek(0) == "Unknown");
    REQUIRE(dayOfWeek(1) == "Monday");
    REQUIRE(dayOfWeek(2) == "Tuesday");
    REQUIRE(dayOfWeek(3) == "Wednesday");
    REQUIRE(dayOfWeek(4) == "Thursday");
    REQUIRE(dayOfWeek(5) == "Friday");
    REQUIRE(dayOfWeek(6) == "Saturday");
    REQUIRE(dayOfWeek(7) == "Sunday");
    REQUIRE(dayOfWeek(8) == "Unknown");

}

TEST_CASE("test Salary") {
    REQUIRE(salary(10000) == 1500);
    REQUIRE(salary(10001) == 1500.05);
    REQUIRE(salary(0.0) == 1500);
    REQUIRE(salary(10500) == 1525);
    REQUIRE(salary(30000) == 2800);
    REQUIRE(salary(20000) == 2000);
    REQUIRE(salary(20001) == 2000.08);
}

TEST_CASE("test firstOfThree") {
    REQUIRE("a" == firstOf3("a", "a", "b"));
    REQUIRE("Ma" == firstOf3("Ma", "ma", "ma"));
    REQUIRE(firstOf3("123", "123 0", "1232") == "123");
    REQUIRE(firstOf3("AAA", "aaa", "bbb") == "AAA");
    REQUIRE(firstOf3("1234", "AAA", "aaa") == "1234");
    REQUIRE(firstOf3("zxc", "zxcb", "zxcv") == "zxc");
    REQUIRE(firstOf3("", "", "") == "");
    REQUIRE(firstOf3("121", "123", " 122") == " 122");
    REQUIRE(firstOf3("", "", " 1") == "");
    REQUIRE(firstOf3("2", "1", "3") == "1");
    REQUIRE(firstOf3("2", "3", "1") == "1");

}


TEST_CASE("test isLeapYear") {
    REQUIRE(isLeapYear(2020));
    REQUIRE_FALSE(isLeapYear(2021));
    REQUIRE_FALSE(isLeapYear(2023));
    REQUIRE_FALSE(isLeapYear(1900));
    REQUIRE_FALSE(isLeapYear(2100));
    REQUIRE(isLeapYear(2000));
    REQUIRE_FALSE(isLeapYear(0));
    // Add more assertions
}


TEST_CASE ("test dayNumber") {
    REQUIRE(1 == dayNumber("01/01/2018"));
    REQUIRE(31 + 28 + 1 == dayNumber("03/01/2017"));
    REQUIRE(31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 +
            31 + 9
            == dayNumber("11/09/2017"));
    REQUIRE(31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 +
            31 + 30 + 10
            == dayNumber("12/10/2017"));
    REQUIRE(31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 +
            31 + 30 + 31
            == dayNumber("12/31/2000"));
}


TEST_CASE ("test validDate when all dates are valid") {
    REQUIRE(validDate("01/01/2018"));
    REQUIRE(validDate("02/29/2024"));
    REQUIRE(validDate("01/31/2016"));
    REQUIRE(validDate("06/15/2018"));
    REQUIRE(validDate("02/28/2019"));
    REQUIRE(validDate("01/01/0001"));
    REQUIRE_FALSE(validDate("01/32/2018"));
    REQUIRE_FALSE(validDate("11/31/9999"));

}

TEST_CASE ("test validDate when all dates are NOT valid") {
    REQUIRE_FALSE(validDate("00/32/2017"));
    REQUIRE_FALSE(validDate("02/30/2020"));
    REQUIRE_FALSE(validDate("12/00/2020"));
}


TEST_CASE("test fizzBuzz") {
    REQUIRE("Fizz" == fizzBuzz("f"));
    REQUIRE("Buzz" == fizzBuzz("b"));
    REQUIRE("FizzBuzz" == fizzBuzz("fb"));
    REQUIRE("Fizz" == fizzBuzz("fbakvbavhahva"));
    REQUIRE("FizzBuzz" == fizzBuzz("fnagabvaivavab"));
    REQUIRE("Buzz" == fizzBuzz("kabkavkvaab"));
    REQUIRE("" == fizzBuzz(""));
    REQUIRE("abc" == fizzBuzz("abc"));

}
