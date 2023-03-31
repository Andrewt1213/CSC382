//
// Created by Andrew on 3/29/2023.
//
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include "Card.cpp"

using namespace std;

// A poker hand is a vector of 5 cards
class PokerHand {
private:
    vector<Card> hand;
    vector<string> suits{"\xe2\x99\xa0", "\xe2\x99\xa5", "\xe2\x99\xa6", "\xe2\x99\xa3"};
    int firstCardValue = 0;
    int secondCardValue = 0;
    int thirdCardValue = 0;
    int fourthCardValue = 0;
    int handValue = 0;
public:
    PokerHand(Card a, Card b, Card c, Card d, Card e) {
        hand.push_back(a);
        hand.push_back(b);
        hand.push_back(c);
        hand.push_back(d);
        hand.push_back(e);
        sort(hand.begin(), hand.end());
        firstCardValue = hand.at(4).getRank();
        secondCardValue = hand.at(3).getRank();
        thirdCardValue = hand.at(2).getRank();
        fourthCardValue = hand.at(1).getRank();
        if (isRoyalFlush())
            handValue += 10;
        else if (isStraightFlush())
            handValue += 9;
        else if (fourOfAKind())
            handValue += 8;
        else if (fullHouse())
            handValue += 7;
        else if (isFlush())
            handValue += 6;
        else if (isStraight())
            handValue += 5;
        else if (threeOfAKind())
            handValue += 4;
        else if (twoPair())
            handValue += 3;
        else if (onePair())
            handValue += 2;
    }

    bool operator<(const PokerHand &other) const {
        if (handValue < other.handValue)
            return true;
        else if (handValue > other.handValue)
            return false;
        else {
            // royal flush
            if (handValue == 10)
                return false;
                // straight flush
            else if (handValue == 9) {
                if (highCard() < other.highCard())
                    return true;
                else
                    return false;
            }
                // four of a kind
            else if (handValue == 8) {
                if (firstCardValue < other.firstCardValue)
                    return true;
                else if (firstCardValue > other.firstCardValue)
                    return false;
                else {
                    if (secondCardValue < other.secondCardValue)
                        return true;
                    else
                        return false;
                }
            }
                // full house
            else if (handValue == 7) {
                if (firstCardValue < other.firstCardValue)
                    return true;
                else if (firstCardValue > other.firstCardValue)
                    return false;
                else {
                    if (secondCardValue < other.secondCardValue)
                        return true;
                    else
                        return false;
                }
            }
                // flush
            else if (handValue == 6) {
                for (int i = 4; i >= 0; i--) {
                    if (hand.at(i).getRank() < other.hand.at(i).getRank())
                        return true;
                    else if (hand.at(i).getRank() > other.hand.at(i).getRank())
                        return false;
                }
            }
                // straight
            else if (handValue == 5) {
                if (highCard() < other.highCard())
                    return true;
                else
                    return false;
            }
                // three of a kind
            else if (handValue == 4) {
                if (firstCardValue < other.firstCardValue)
                    return true;
                else if (firstCardValue > other.firstCardValue)
                    return false;
                else {
                    if (secondCardValue < other.secondCardValue)
                        return true;
                    else if (secondCardValue > other.secondCardValue)
                        return false;
                    else {
                        if (thirdCardValue < other.thirdCardValue)
                            return true;
                        else
                            return false;
                    }
                }
            }
                // two pairs
            else if (handValue == 3) {
                if (firstCardValue < other.firstCardValue)
                    return true;
                else if (firstCardValue > other.firstCardValue)
                    return false;
                else {
                    if (secondCardValue < other.secondCardValue)
                        return true;
                    else if (secondCardValue > other.secondCardValue)
                        return false;
                    else {
                        if (thirdCardValue < other.thirdCardValue)
                            return true;
                        else
                            return false;
                    }
                }
            }
                // one pair
            else if (handValue == 2) {
                if (firstCardValue < other.firstCardValue)
                    return true;
                else if (firstCardValue > other.firstCardValue)
                    return false;
                else {
                    if (secondCardValue < other.secondCardValue)
                        return true;
                    else if (secondCardValue > other.secondCardValue)
                        return false;
                    else {
                        if (thirdCardValue < other.thirdCardValue)
                            return true;
                        else if (thirdCardValue > other.thirdCardValue)
                            return false;
                        else {
                            if (fourthCardValue < other.fourthCardValue)
                                return true;
                            else {
                                return false;
                            }
                        }
                    }
                }
            } else {
                for (int i = 4; i >= 0; i--) {
                    if (hand.at(i).getRank() < other.hand.at(i).getRank())
                        return true;
                    else if (hand.at(i).getRank() > other.hand.at(i).getRank())
                        return false;
                }
            }
        }
        return false;
    }

    string toString() const {
        string result = "";
        for (auto itr = hand.begin(); itr != hand.end(); itr++) {
            result += itr->toString() + " ";
        }
        return result;
    }

    int highCard() const {
        return hand.at(4).getRank();
    }

    bool onePair() {
        for (int i = 0; i < 4; i++) {
            if (hand.at(i).getRank() == hand.at(i + 1).getRank()) {
                firstCardValue = hand.at(i).getRank();
                // secondCardValue is equal to the highest card that is not part of the pair
                if (i == 0) {
                    secondCardValue = hand.at(4).getRank();
                    thirdCardValue = hand.at(3).getRank();
                    fourthCardValue = hand.at(2).getRank();
                } else if (i == 1) {
                    secondCardValue = hand.at(4).getRank();
                    thirdCardValue = hand.at(3).getRank();
                    fourthCardValue = hand.at(0).getRank();
                } else if (i == 2) {
                    secondCardValue = hand.at(4).getRank();
                    thirdCardValue = hand.at(1).getRank();
                    fourthCardValue = hand.at(0).getRank();
                } else {
                    secondCardValue = hand.at(2).getRank();
                    thirdCardValue = hand.at(1).getRank();
                    fourthCardValue = hand.at(0).getRank();
                }
                return true;
            }
        }
        return false;
    }

    bool twoPair() {
        // check for first pair
        if (hand.at(0).getRank() == hand.at(1).getRank()) {
            // check for second pair
            if (hand.at(2).getRank() == hand.at(3).getRank()) {
                firstCardValue = hand.at(0).getRank();
                secondCardValue = hand.at(2).getRank();
                thirdCardValue = hand.at(4).getRank();
                return true;
            } else if (hand.at(3).getRank() == hand.at(4).getRank()) {
                firstCardValue = hand.at(0).getRank();
                secondCardValue = hand.at(3).getRank();
                thirdCardValue = hand.at(2).getRank();
                return true;
            }
        } else if (hand.at(1).getRank() == hand.at(2).getRank()) {
            // check for second pair
            if (hand.at(3).getRank() == hand.at(4).getRank()) {
                firstCardValue = hand.at(1).getRank();
                secondCardValue = hand.at(3).getRank();
                thirdCardValue = hand.at(0).getRank();
                return true;
            }
        }
        return false;
    }

    bool threeOfAKind() {
        for (int i = 0; i < 3; i++) {
            int rank = hand.at(i).getRank();
            int count = 0;
            for (int j = i; j < 3 + i; j++) {
                if (hand.at(j).getRank() == rank) {
                    count++;
                    if (count == 3) {
                        firstCardValue = rank;
                        // secondCardValue is equal to the highest card that is not part of the three of a kind
                        if (i == 0) {
                            secondCardValue = hand.at(4).getRank();
                            thirdCardValue = hand.at(3).getRank();
                        } else if (i == 1) {
                            secondCardValue = hand.at(4).getRank();
                            thirdCardValue = hand.at(0).getRank();
                        } else {
                            secondCardValue = hand.at(1).getRank();
                            thirdCardValue = hand.at(0).getRank();
                        }
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool isStraight() {
        for (int i = 0; i < 5; i++) {
            if (hand.at(i).getRank() != hand.at(i).getRank() - 1) {
                return false;
            }
        }
        return true;
    }

    bool isFlush() {
        int suit = hand.at(0).getSuit();
        for (auto itr = hand.begin(); itr != hand.end(); itr++) {
            if (itr->getSuit() != suit) {
                return false;
            }
        }
        return true;
    }

    bool fullHouse() {
        // must call threeOfAKind last in order to set firstCardValue and secondCard Value correctly
        bool onePairResult = onePair();
        bool threeOfAKindResult = threeOfAKind();
        return onePairResult && threeOfAKindResult;
    }

    bool fourOfAKind() {
        for (int i = 0; i < 2; i++) {
            int rank = hand.at(i).getRank();
            int count = 0;
            for (int j = i; j < 4 + i; j++) {
                if (hand.at(j).getRank() == rank) {
                    count++;
                    if (count == 4) {
                        firstCardValue = rank;
                        // secondCardValue is equal to the highest card that is not part of the four of a kind
                        if (i == 0) {
                            secondCardValue = hand.at(4).getRank();
                        } else {
                            secondCardValue = hand.at(0).getRank();
                        }
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool isStraightFlush() {
        return isFlush() && isStraight();
    }

    bool isRoyalFlush() {
        return isFlush() && isStraight() && hand.at(0).getRank() == 10;
    }


};