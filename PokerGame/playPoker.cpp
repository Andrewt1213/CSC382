//
//
// This class is a poker game.
// It will create a new deck every time it is called.
// It will then shuffle the deck and deal the cards to the players.
// It will then determine the best hand for each player and then determine the winner.
// It will then pay out the winner.
// Programmer ANDREW TAPIA
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <iomanip>
#include "Card.cpp"
#include "Deck.cpp"
#include "Player.cpp"
using namespace std;
class playPoker {
private:
    Deck deck;
    vector<Player> players;
public:
    // TODO: ask about getting ptrs to player vector so I don't have to search player vector every time.
    playPoker(vector<Player> players) {
        this->players = players;
        this->deck = Deck(); // this creates a deck of cards
        continueGame(); // this shuffly// es the deck, deals the cards and determines the winner
    }

    void dealCards() {
        // adds 5 community cards
        vector<Card> communityCards;
        for (int i = 0; i < 5; i++){
            communityCards.push_back(deck.getCard());
        }
        cout << "Community Cards: " << PokerHand(communityCards.at(0), communityCards.at(1), communityCards.at(2), communityCards.at(3), communityCards.at(4)).toString() << endl;
        cout << "+++++++++++++++++++++++++++++++" << endl;
        // creates players with their two cards and then adds the community cards and then sets the best hand for the player.
        // TODO: go by playerNum instead of just looping. This will allow for output to look like:
        //  Player 1: ...
        //  Player 2: ...
        //  create function to get indexes of players by playerNum
        //  then loop through those indexes
        int playerNum = 1;
        while (playerNum <= players.size()) {
            for (auto& player : players) {
                if (player.getPlayerNum() == playerNum){
                    for (int j = 0; j < 2; j++) {
                        player.addCard(deck.getCard());
                    }
                    player.setBestHand(communityCards);
                    player.doBet();
                    cout << "Player " << player.getPlayerNum() << ": " << setprecision(2) << fixed << player.getMoney() << " - " << player.toString() << endl;
                    cout << "         Best hand: " << setw(30) << left << player.getHand().toString() << "     " << player.getWinningHandName() << endl;
                    cout << endl;
                    playerNum++;
                }
            }
        }
    }

    /*
     * This function will determine the winner of the game.
     * It will sort the players by their best hand and then search for ties.
     * Winners, as well as ties, will be added to a vector of winners.
     * The winnings ($2 * number of players) will be added to each winner's money.
     */
    /*
     * massive weird thing with ptrs not working so I'm going to store vectro of INDEXES of winners
     * instead and directly manipulately the players vecotr of this object.
     *
     */
    void determineWinner() {
        // Sorts the players by their best hand
        sort(players.begin(), players.end());
        // Adds winners to winner vector
        vector<int> winnersIndex;
        int winningIndex = players.size() - 1; // we know the winner is at the end.
        for (int i = players.size() - 1; i >= 0; i--) {
            if (players.at(i).getHand() < players.at(winningIndex).getHand()) {
                // no tie
                break;
            }
            else {
                // tie
                winnersIndex.push_back(i);
            }
        }
        // Pays out the winner(s)
        double moneyPot = players[0].getBet() * players.size();
        double moneyPerWinner = moneyPot / winnersIndex.size();
        for (int i : winnersIndex){
            players.at(i).addMoney(moneyPerWinner);
        }
        // Prints out the winner
        // if tie
        if (winnersIndex.size() > 1){
            cout << "Winning hands (tie) " << endl;
            for (int i = 0; i < winnersIndex.size(); i++){
                int index = winnersIndex.at(i);
                cout << players.at(index).getHand().toString() << " Player " << players.at(index).getPlayerNum() << " $" << setprecision(2) << fixed << players.at(index).getMoney() << " " <<endl;
            }
            cout << endl;
        }
        // if no tie
        else {
            cout << "Winner: Player " << players.at(winningIndex).getPlayerNum() << " $" << setprecision (2) << fixed << players.at(winningIndex).getMoney() << endl;
            cout << "+++++++++++++++++++++++++++++++" << endl;
            cout << players.at(winningIndex).getHand().toString() << "          " << players.at(winningIndex).getWinningHandName() <<  endl;
        }
        cout << endl;
    }

    void continueGame(){
        deck.resetDeck();
        for(auto & player : players){
            player.resetPlayer();
        }
        deck.shuffle();
        //deck.testDeck();
        dealCards();
        determineWinner();
    };

};
