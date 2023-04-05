//
// This class will be used to create a player.
// It will have money, a bet, a hand, and a vector of all cards.
// Programmer ANDREW TAPIA
//
#include "Card.cpp"
#include "PokerHand.cpp"
#include <vector>
#include <iomanip>

class Player {
private:
    double money;
    int bet;
    PokerHand hand;
    vector<Card> allCards;
    int playerNum;
public:
    Player(int playerNum) {
        this->money = 100.0;
        this->bet = 2.0;
        this->playerNum = playerNum;
    }

    void doBet(){
        money -= bet;
    }

    void addCard(Card card) {
        allCards.push_back(card);
    }

    int getPlayerNum() {
        return this->playerNum;
    }

    // This function will create the best hand possible for the player
    // given the community cards and the player's two cards
    // There are 21 possible hands which is known as 7 choose 5.
    void setBestHand(vector<Card> communityCards) {
        // Add all cards to one vector
        for (auto communityCard : communityCards) {
            allCards.push_back(communityCard);
        }
        vector<PokerHand> allHands;
        // Create all possible hands from 7 cards where each hand only has 5 cards
        // There are 21 possible hands which is known as 7 choose 5.
        int index = 0;
        for (int i = 0; i < 7; i++) {
            for (int j = i + 1; j < 7; j++) {
                for (int k = j + 1; k < 7; k++) {
                    for (int l = k + 1; l < 7; l++) {
                        for (int m = l + 1; m < 7; m++) {
                            allHands.push_back(PokerHand(allCards[i], allCards[j], allCards[k], allCards[l], allCards[m]));
                            //cout << allHands[index].toString() << endl;
                            index++;
                        }
                    }
                }
            }
        }

        // Sort allHands with sort function
        sort(allHands.begin(), allHands.end());
        this-> hand = allHands.at(20);
       // TODO: Test this gives all 21 combinations
    }

    double getBet() {
        return this->bet;
    }

    void addMoney(double amt) {
        money = money + amt;
    }

    PokerHand getHand() {
        return this->hand;
    }

    string getWinningHandName() {
        return this->hand.getWinningHandName();
    }

    bool operator<( Player &other) {
        if (this->getHand() < other.getHand())
            return true;
        return false;
    }

    void resetPlayer() {
        this->allCards.clear();

    }

    double getMoney() {
        return this->money;
    }

    string toString() {
        return allCards.at(0).toString() + " " + allCards.at(1).toString();
    }

};
