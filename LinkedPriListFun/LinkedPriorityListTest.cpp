
//
// Unit test for LinkedPriorityList
// Make sure you test that all exceptions are thrown
//
// Programmers Rick Mercer and Andrew Tapia
//

#define CATCH_CONFIG_MAIN

#include <catch.hpp>
#include "LinkedPriorityList.hpp"
#include <string>

using namespace std;

TEST_CASE ("testGenericityInsertElementAtSizeIsEmpty") {
    LinkedPriorityList<string> list3;
    REQUIRE(list3.isEmpty());
    list3.insertElementAt(0, "1st");
    REQUIRE(!list3.isEmpty());
    list3.insertElementAt(0, "2nd");
    REQUIRE(2 == list3.size());
}

TEST_CASE ("testGet") {
    LinkedPriorityList<string> list3;
    REQUIRE(list3.isEmpty());
    list3.insertElementAt(0, "1");
    list3.insertElementAt(1, "2");
    list3.insertElementAt(2, "3");

    REQUIRE(list3.getElementAt(0) == "1");
    REQUIRE(list3.getElementAt(1) == "2");
    REQUIRE(list3.getElementAt(2) == "3");
    CHECK_THROWS(list3.insertElementAt(-1, "In getElementAt, index was -1"));
    CHECK_THROWS(list3.getElementAt(-1));

}

TEST_CASE ("testRemove") {
    LinkedPriorityList<string> list3;
    REQUIRE(list3.isEmpty());
    list3.insertElementAt(0, "1");
    list3.insertElementAt(1, "2");
    list3.insertElementAt(2, "3");

    list3.removeElementAt(0);
    REQUIRE(list3.getElementAt(0) == "2");

    list3.insertElementAt(0, "1");
    list3.removeElementAt(1);
    REQUIRE(list3.getElementAt(0) == "1");
    REQUIRE(list3.getElementAt(1) == "3");

    list3.insertElementAt(1, "2");
    list3.removeElementAt(2);
    REQUIRE(list3.getElementAt(0) == "1");
    REQUIRE(list3.getElementAt(1) == "2");

    CHECK_THROWS(list3.removeElementAt(2));

}

TEST_CASE ("testInsert") {
    LinkedPriorityList<string> list3;
    REQUIRE(list3.isEmpty());
    list3.insertElementAt(0, "1");
    REQUIRE(list3.getElementAt(0) == "1");
    list3.insertElementAt(0, "2");
    REQUIRE(list3.getElementAt(0) == "2");
    list3.insertElementAt(0, "3");
    REQUIRE(list3.getElementAt(0) == "3");
    // 3, 2, 1

    list3.insertElementAt(1, "4");
    // 3 4 2 1
    REQUIRE(list3.getElementAt(1) == "4");

    REQUIRE(list3.getElementAt(0) == "3");
    REQUIRE(list3.getElementAt(1) == "4");
    REQUIRE(list3.getElementAt(2) == "2");
    REQUIRE(list3.getElementAt(3) == "1");

    list3.insertElementAt(4, "5");
    // 3 4 2 1 5
    REQUIRE(list3.getElementAt(4) == "5");
}

TEST_CASE ("test lower priority") {
    LinkedPriorityList<string> list3;
    REQUIRE(list3.isEmpty());
    list3.insertElementAt(0, "1");
    list3.insertElementAt(1, "2");
    list3.insertElementAt(2, "3");

    // 123 -> 213
    list3.lowerPriorityOf(0);
    REQUIRE(list3.getElementAt(0) == "2");

    // 213 -> 231
    list3.lowerPriorityOf(1);
    REQUIRE(list3.getElementAt(1) == "3");

    // 231 -> 231
    list3.lowerPriorityOf(2); // 2 3 1
    REQUIRE(list3.getElementAt(0) == "2");
    REQUIRE(list3.getElementAt(1) == "3");
    REQUIRE(list3.getElementAt(2) == "1");

    CHECK_THROWS(list3.lowerPriorityOf(3));
}

TEST_CASE ("test move to top") {
    LinkedPriorityList<string> list3;
    REQUIRE(list3.isEmpty());
    list3.insertElementAt(0, "1");
    list3.insertElementAt(1, "2");
    list3.insertElementAt(2, "3");

    list3.moveToTop(0); //  123
    REQUIRE(list3.getElementAt(0) == "1");

    list3.moveToTop(1); // 2 1 3
    REQUIRE(list3.getElementAt(0) == "2");

    list3.moveToTop(2); // 3 2 1
    REQUIRE(list3.getElementAt(0) == "3");

    CHECK_THROWS(list3.moveToTop(3));


}

TEST_CASE ("test raisePriority and moveToLast") {// raise with no change
    LinkedPriorityList<string> list;
    list.insertElementAt(0, "1st");
    list.insertElementAt(1, "2nd");
    list.insertElementAt(2, "3rd");
    list.raisePriorityOf(2);
    REQUIRE("1st" == list.getElementAt(0));
    REQUIRE("3rd" == list.getElementAt(1));
    REQUIRE("2nd" == list.getElementAt(2));
    list.moveToLast(0);
    REQUIRE("3rd" == list.getElementAt(0));
    REQUIRE("2nd" == list.getElementAt(1));
    REQUIRE("1st" == list.getElementAt(2));

    list.moveToLast(1);
    REQUIRE("3rd" == list.getElementAt(0));
    REQUIRE("1st" == list.getElementAt(1));
    REQUIRE("2nd" == list.getElementAt(2));

    list.moveToLast(2);
    REQUIRE("3rd" == list.getElementAt(0));
    REQUIRE("1st" == list.getElementAt(1));
    REQUIRE("2nd" == list.getElementAt(2));
    CHECK_THROWS(list.raisePriorityOf(3));
    CHECK_THROWS(list.moveToLast(3));
}

TEST_CASE ("testInsertExceptLower") {
    LinkedPriorityList<string> list;
    CHECK_THROWS(list.insertElementAt(-1, "negative"));
}

///// Make sure all functions throw exceptions when they are supposed to !!!!!
TEST_CASE ("testInsertException") {
    LinkedPriorityList<string> list;
    list.insertElementAt(0, "1st");
    list.insertElementAt(1, "2nd");
    CHECK_THROWS(list.insertElementAt(3, "One too many"));
}
