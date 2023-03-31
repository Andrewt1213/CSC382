//
// Created by Richard H. Mercer on 3/23/23.
//
// Unit test for class Card
#define CATCH_CONFIG_MAIN

#include <catch.hpp>
#include "52Cards.hpp"
#include "Card.cpp"
#include "PokerHand.cpp"

TEST_CASE("test getValue()") {
    REQUIRE(C2.getValue() == 2);
    REQUIRE(D4.getValue() == 4);
    REQUIRE(H10.getValue() == 10);
    REQUIRE(SA.getValue() == 14);
}

TEST_CASE("test toString()") {
    REQUIRE(C3.toString() == "3♣");
    REQUIRE(D6.toString() == "6♦");
    REQUIRE(HJ.toString() == "J♥");
    REQUIRE(SA.toString() == "A♠");
}

TEST_CASE("test getSuit()") {
    // getSuit could return any integer value. I chose 3, 2, 1, and 0
    REQUIRE(C3.getSuit() == 3);
    REQUIRE(D6.getSuit() == 2);
    REQUIRE(HJ.getSuit() == 1);
    REQUIRE(SA.getSuit() == 0);
}

TEST_CASE("test getRank()") {
    // getSuit could return any integer value. I chose 3, 2, 1, and 0
    REQUIRE(static_cast<int>(C3.getRank()) == 3);
    REQUIRE(static_cast<int>(D6.getRank()) == 6);
    REQUIRE(static_cast<int>(HJ.getRank()) == 11);
    REQUIRE(static_cast<int>(SA.getRank()) == 14);
}

TEST_CASE("test <") {
    REQUIRE(C3 < C4);
    REQUIRE(not(C3 < C3));
    REQUIRE(SK < SA); // King of Spades < Ace of Spades
    REQUIRE(SJ < CQ); // different suits don't matter
    REQUIRE(not(CQ < SJ));
}

TEST_CASE("Test High Card 1") {
    PokerHand a(C3, C4, D6, D7, DA);
    PokerHand b(C2, C5, C7, DQ, DK);
    REQUIRE(b < a);
}

TEST_CASE("Test High Card 2") {
    PokerHand nothing72(C2, C3, C4, C5, D7);
    PokerHand nothing73(D2, D4, D5, D6, C7);
    REQUIRE(nothing72 < nothing73);
    REQUIRE(not(nothing73 < nothing72));
}

// TEST PAIRS PokerHand pair(D2, H2, D3, S7, H6);
TEST_CASE("Test Pairs 1") {
    PokerHand a(C3, C4, C7, CJ, DJ);
    PokerHand b(D2, D5, D7, D10, S10);
    REQUIRE(b < a);
}

TEST_CASE("testPair of fives") {
    PokerHand a(C5, D5, D6, S8, H9);
    PokerHand b(H5, S5, C7, D8, D9);
    REQUIRE(a < b); // 9 == 9, 8 == 8, 6 < 7
}

TEST_CASE("Test two pairs - tie") {
    PokerHand a(C5, D5, C4, D4, D8); //c and d
    PokerHand b(H5, S5, H4, S4, S8); // h and s
    REQUIRE(not(a < b)); // should be a tie
    REQUIRE(not(b < a)); // should be a tie
}

TEST_CASE("Test two pairs 2") {
    PokerHand a(C5, D5, C4, D4, D8); //c and d
    PokerHand b(H5, S5, H4, S4, S9); // h and s
    REQUIRE(a < b);
}

TEST_CASE("Test two pairs 3") {
    PokerHand a(C5, D5, C8, D4, D4); //c and d
    PokerHand b(H5, S5, H9, S4, S4); // h and s
    REQUIRE(a < b);
}

TEST_CASE("Test two pairs 4") {
    PokerHand a(C4, D5, C5, D4, D4); //c and d
    PokerHand b(H5, S5, H5, S4, S4); // h and s
    REQUIRE(a < b);
}

TEST_CASE("Test two pairs 5") {
    PokerHand a(C5, D5, C4, D4, D8); //c and d
    PokerHand b(H6, S6, H4, S4, S8); // h and s
    REQUIRE(a < b);
}

TEST_CASE("Test two pairs 6") {
    PokerHand a(C5, D5, C4, D4, D8); //c and d
    PokerHand b(H5, S5, H3, S3, S8); // h and s
    REQUIRE(b < a);
}

TEST_CASE("Test three of a kind - on left") {
    PokerHand a(C5, D5, H5, D4, D8); //c and d
    PokerHand b(C6, D6, H6, S4, S8);
    REQUIRE(a < b);
}

TEST_CASE("Test three of a kind - middle") {
    PokerHand a(C4, D5, H5, D5, D8); //c and d
    PokerHand b(D4, C6, H6, S6, S8);
    REQUIRE(a < b);
}

TEST_CASE("Test three of a kind - right") {
    PokerHand a(C4, D8, H5, D5, D5); //c and d
    PokerHand b(D4, S8, H6, S6, C6);
    REQUIRE(a < b);
}

TEST_CASE("Test three of a kind - tie") {
    PokerHand a(C4, D8, H5, D5, S5);
    PokerHand b(D4, S8, C5, S5, H5);
    REQUIRE(not(a < b));
    REQUIRE(not(b < a));
}

TEST_CASE("Test three of a kind - second highest") {
    PokerHand a(C4, D8, H5, D5, S5); //c and d
    PokerHand b(D4, S9, C5, S5, H5);
    REQUIRE(a < b);
}

TEST_CASE("Test three of a kind - third highest") {
    PokerHand a(C4, D8, H5, D5, S5); //c and d
    PokerHand b(D5, S8, C5, S5, H5);
    REQUIRE(a < b);
}

TEST_CASE("Test straight - tie") {
    PokerHand a(C4, H5, H6, D7, S8); //c and d
    PokerHand b(C4, H5, H6, D7, S8);
    REQUIRE(not(a < b));
    REQUIRE(not(b < a));
}

TEST_CASE("Test straight - first highest") {
    PokerHand a(C4, H5, H6, D7, S8); //c and d
    PokerHand b(C5, H6, H7, D8, S9);
    REQUIRE(a < b);
}

TEST_CASE("Test flush - tie") {
    PokerHand a(C4, C3, C6, C7, C8);
    PokerHand b(C4, C3, C6, C7, C8);
    REQUIRE(not(a < b));
    REQUIRE(not(b < a));
}

TEST_CASE("Test flush - first highest") {
    PokerHand a(C4, C3, C6, C7, C8);
    PokerHand b(C5, C3, C6, C7, C8);
    REQUIRE(a < b);
}

TEST_CASE("Test flush - second highest") {
    PokerHand a(C4, C3, C6, C7, C8);
    PokerHand b(C4, C4, C6, C7, C8);
    REQUIRE(a < b);
}

TEST_CASE("Test flush - third highest") {
    PokerHand a(C4, C3, C6, C7, C8);
    PokerHand b(C4, C3, C7, C7, C8);
    REQUIRE(a < b);
}

TEST_CASE("Test flush - fourth highest") {
    PokerHand a(C4, C3, C6, C7, C8);
    PokerHand b(C4, C3, C6, C8, C8);
    REQUIRE(a < b);
}

TEST_CASE("Test flush - fifth highest") {
    PokerHand a(C4, C3, C6, C7, C8);
    PokerHand b(C4, C3, C6, C7, C9);
    REQUIRE(a < b);
}

TEST_CASE("Test full house - tie") {
    PokerHand a(C4, D4, H4, C7, D7);
    PokerHand b(C4, D4, H4, C7, D7);
    REQUIRE(not(a < b));
    REQUIRE(not(b < a));
}

TEST_CASE("Test full house - first highest") {
    PokerHand a(C4, D4, H4, C7, D7);
    PokerHand b(C5, D5, H5, C7, D7);
    REQUIRE(a < b);
}

TEST_CASE("Test full house - second highest") {
    PokerHand a(C4, D4, H4, C7, D7);
    PokerHand b(C4, D4, H4, C8, D8);
    REQUIRE(a < b);
}

TEST_CASE("Test full house - tie - on right") {
    PokerHand a(C4, D4, H7, C7, D7);
    PokerHand b(C4, D4, H7, C7, D7);
    REQUIRE(not(a < b));
    REQUIRE(not(b < a));
}

TEST_CASE("Test full house - first highest - on right") {
    PokerHand a(C4, D4, H7, C7, D7);
    PokerHand b(C5, D5, H7, C7, D7);
    REQUIRE(a < b);
}

TEST_CASE("Test full house - second highest - on right") {
    PokerHand a(C4, D4, H7, C7, D7);
    PokerHand b(C4, D4, H8, C8, D8);
    REQUIRE(a < b);
}

TEST_CASE("Test four of a kind - tie") {
    PokerHand a(C4, D4, H4, S4, D7);
    PokerHand b(C4, D4, H4, S4, D7);
    REQUIRE(not(a < b));
    REQUIRE(not(b < a));
}

TEST_CASE("Test four of a kind - first highest") {
    PokerHand a(C4, D4, H4, S4, D7);
    PokerHand b(C5, D5, H5, S5, D7);
    REQUIRE(a < b);
}

TEST_CASE("Test four of a kind - second highest") {
    PokerHand a(C4, D4, H4, S4, D7);
    PokerHand b(C4, D4, H4, S4, D8);
    REQUIRE(a < b);
}

TEST_CASE("Test four of a kind - tie - on right") {
    PokerHand a(C8, D4, H4, S4, D4);
    PokerHand b(C8, D4, H4, S4, D4);
    REQUIRE(not(a < b));
    REQUIRE(not(b < a));
}

TEST_CASE("Test four of a kind - first highest - on right") {
    PokerHand a(C8, D4, H4, S4, D4);
    PokerHand b(C9, D4, H4, S4, D4);
    REQUIRE(a < b);
}

TEST_CASE("Test four of a kind - second highest - on right") {
    PokerHand a(C8, D4, H4, S4, D4);
    PokerHand b(C8, D5, H5, S5, D5);
    REQUIRE(a < b);
}

TEST_CASE("Test straight flush - tie") {
    PokerHand a(C4, C5, C6, C7, C8);
    PokerHand b(C4, C5, C6, C7, C8);
    REQUIRE(not(a < b));
    REQUIRE(not(b < a));
}

TEST_CASE("Test straight flush - first highest") {
    PokerHand a(C4, C5, C6, C7, C8);
    PokerHand b(C5, C6, C7, C8, C9);
    REQUIRE(a < b);
}

TEST_CASE("Test royal flush - tie") {
    PokerHand a(C10, CJ, CQ, CK, CA);
    PokerHand b(C10, CJ, CQ, CK, CA);
    REQUIRE(not(a < b));
    REQUIRE(not(b < a));
}

