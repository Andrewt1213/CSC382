//
// Created by Lenovo on 4/1/2023.
//

#include <random>
#include <vector>
#include <algorithm>
#include "Card.cpp"
#include "52Cards.hpp"

using namespace std;

class Deck {
private:
    vector<Card> cards;

public:
    void shuffle() {
        //::shuffle(cards.begin(), cards.end(), default_random_engine(10));
        ::shuffle(cards.begin(), cards.end(), mt19937{random_device{}()});
    }

    Card getCard(){
        Card card = cards.back();
        cards.pop_back();
        return card;
    };

    void resetDeck() {
        cards.clear();
        for (int i = 0; i < 4; i++) {
            for (int j = 2; j < 15; j++) {
                cards.push_back(Card(static_cast<Rank>(j), static_cast<Suit>(i)));
            }
        }
    }

    void testDeck(){
        cards.push_back(Card(static_cast<Rank>(11), static_cast<Suit>(1)));
        cards.push_back(Card(static_cast<Rank>(10), static_cast<Suit>(3)));

        cards.push_back(Card(static_cast<Rank>(11), static_cast<Suit>(1)));
        cards.push_back(Card(static_cast<Rank>(10), static_cast<Suit>(1)));

        cards.push_back(Card(static_cast<Rank>(11), static_cast<Suit>(2)));
        cards.push_back(Card(static_cast<Rank>(10), static_cast<Suit>(2)));

        cards.push_back(Card(static_cast<Rank>(11), static_cast<Suit>(0)));
        cards.push_back(Card(static_cast<Rank>(10), static_cast<Suit>(0)));

        cards.push_back(Card(static_cast<Rank>(11), static_cast<Suit>(2)));
        cards.push_back(Card(static_cast<Rank>(10), static_cast<Suit>(2)));

        cards.push_back(Card(static_cast<Rank>(14), static_cast<Suit>(0)));
        cards.push_back(Card(static_cast<Rank>(13), static_cast<Suit>(0)));
        cards.push_back(Card(static_cast<Rank>(12), static_cast<Suit>(0)));
        cards.push_back(Card(static_cast<Rank>(11), static_cast<Suit>(0)));
        cards.push_back(Card(static_cast<Rank>(10), static_cast<Suit>(0)));

    }
};