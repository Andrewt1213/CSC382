
/**
 * This class has a test method for each of the nine functions in VectorFun.hpp
 *
 * Author  Rick Mercer and Andrew Tapia
 */
#define CATCH_CONFIG_MAIN

#include <catch.hpp>
#include <vector>
#include <string>
#include "VectorFun.hpp"

using namespace std;

TEST_CASE("test NumberOfPairs") {
    vector<string> s1{};
    // The next line will not compile until you add the correct function heading in VectorFun.hpp
    REQUIRE(0 == numberOfPairs(s1));

    vector<int> i1{1, 2, 3};
    REQUIRE(0 == numberOfPairs(i1));

    vector<string> s2{"a", "b", "b", "b"};
    REQUIRE(2 == numberOfPairs(s2));
}


TEST_CASE("test sumIsGreater") {
    vector<double> x = {1.1, 2.2, 3.3};
    REQUIRE(sumGreaterThan(x, 4.0));
}


TEST_CASE("test frequency") {
    vector<int> nums{1, 1, 1, 3, 3, 5, 6, 6, 10, 10, 10};
    vector<int> result = frequency(nums);
    REQUIRE(0 == result[0]);
    REQUIRE(3 == result[1]);
    REQUIRE(0 == result[2]);
    REQUIRE(2 == result[3]);
    REQUIRE(0 == result[4]);
    REQUIRE(1 == result[5]);
    REQUIRE(2 == result[6]);
    REQUIRE(0 == result[7]);
    REQUIRE(0 == result[8]);
    REQUIRE(0 == result[9]);
    REQUIRE(3 == result[10]);
}


TEST_CASE("test howMany") {
    vector<string> strs{"a", "C", "X", "x", "b", "a", "b", "b", "a", "b", "a"};
    REQUIRE(4 == howMany(strs, "b"));
    REQUIRE(0 == howMany(strs, "c"));
    REQUIRE(1 == howMany(strs, "x"));
    REQUIRE(1 == howMany(strs, "x"));
    REQUIRE(0 == howMany(strs, "t"));
}


TEST_CASE("test evensLeft") {
    vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    evensLeft(a);

// left side of the array at indexes 0..2 are even
    for (int i = 0; i <= 2; i++)
        REQUIRE(0 == a[i] % 2);

// right side of the array at indexes 3..6 are odd
    for (int i = 3; i <= 6; i++)
        REQUIRE(1 == a[i] % 2);
}


TEST_CASE("test shiftOnce") {
    vector<int> v = {1, 2, 3};
    shiftOnce(v);
    REQUIRE(2 == v[0]);
    REQUIRE(3 == v[1]);
    REQUIRE(1 == v[2]);
}


TEST_CASE("test shiftNTimes with argument 2") {
    vector<int> a = {1, 2, 3};
    shiftNTimes(a, 2);
    REQUIRE(3 == a[0]);
    REQUIRE(1 == a[1]);
    REQUIRE(2 == a[2]);
}


TEST_CASE("test range") {
    vector<int> x = {1, 2, -1, 4, 3};
    REQUIRE(5 == range(x));
}


TEST_CASE("test fizzBuzz for 1..6") {
    vector<string> strs = fizzBuzz(1, 16);
    REQUIRE("1" == strs[0]);
    REQUIRE("2" == strs[1]);
    REQUIRE("Fizz" == strs[2]);
    REQUIRE("4" == strs[3]);
    REQUIRE("Buzz" == strs[4]);
    REQUIRE("FizzBuzz" == strs[14]);
}