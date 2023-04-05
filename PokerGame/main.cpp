#include <iostream>
#include "playPoker.cpp"

using namespace std;

int main() {
    // Get the number of players
    int numPlayers = 5;
    cout << "How many players? ";
    cin >> numPlayers;
    vector<Player> players;
    for ( int i = 1; i <= numPlayers; i++) {
        players.push_back(Player(i));
    }
    playPoker game = playPoker(players);
    // Ask the user if they want to play another game
    bool continue_game = true;
    while (continue_game) {
        cout << "Play another game? (y/n): ";
        char answer;
        cin >> answer;
        if (answer == 'n') {
            continue_game = false;
        } else if (answer == 'y') {
            continue_game = true;
            game.continueGame(); // this shuffles the deck, deals the cards and determines the winner
        } else {
            cout << "Invalid input. Please enter y or n." << endl;
        }
    }

    return 0;
}


