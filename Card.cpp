/*
 * Card.hpp
 *
 * Author: Rick Mercer
 *
 * Description: class Card with a Suit and Rank
 */

#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include <vector>
#include <iostream>
#include <windows.h>

// These integer values are used to determine of oneCard < anotherCard
enum class Rank {
    DEUCE = 2,
    THREE = 3,
    FOUR = 4,
    FIVE = 5,
    SIX = 6,
    SEVEN = 7,
    EIGHT = 8,
    NINE = 9,
    TEN = 10,
    JACK = 11,
    QUEEN = 12,
    KING = 13,
    ACE = 14
};

enum class Suit {
    SPADES = 0, HEARTS = 1, DIAMONDS = 2, CLUBS = 3
};

class Card {

private:
    Rank rank;
    Suit suit;

public:
    Card(Rank r, Suit s) {
        this->rank = r;
        this->suit = s;
    }

    int getValue() const {
        // Need to static_cast the enum to get the int value
        return static_cast<int>(this->rank);
    }

    // Need to static_cast the enum to get the int value
    int getSuit() const {
        return static_cast<int>(this->suit);
    }

    // Need to static_cast the enum to get the int value
    int getRank() const {
        return static_cast<int>(this->rank);
    }

    std::string toString() const {
        SetConsoleOutputCP(CP_UTF8);
        std::vector<std::string> suits{"\xe2\x99\xa0", "\xe2\x99\xa5", "\xe2\x99\xa6", "\xe2\x99\xa3"};
        std::vector<std::string> face{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

        return face.at(static_cast<int>(this->rank) - 2)
               + suits.at(static_cast<int>(this->suit));
    }

    bool operator<(const Card &other) const {
        return rank < other.rank;
    }
};

#endif //CARD_HPP_
