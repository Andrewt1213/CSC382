// myModel.cpp
// Created by Andrew Tapia on 4/20/2023.
// This class represents the model of a tik tak toe game.
// It is responsible for keeping track of the state of the game.
// It is also responsible for determining if a move is valid.
// It is also responsible for printing a board to the console.
//
#include <iostream>
#include <tuple>
using namespace std;
class MyModel {
private:
    int board[3][3]{};
    int winner = -1;
    // int move = 0; Enable for testing forced tie
    int movesSoFar = 0;
    /*winning combinations
    int win[8][3] = {
            {0, 1, 2},
            {3, 4, 5},
            {6, 7, 8},
            {0, 3, 6},
            {1, 4, 7},
            {2, 5, 8},
            {0, 4, 8},
            {2, 4, 6}
    };
    */
public:
    MyModel() {
        newGame();
        srand(time(0));
    }

    // -1 means still playing
    // 0 means tie
    // 1 means player 1 wins
    // 2 means player 2 (computer) wins
    bool gameOver(){
        return winner > -1;
    }

    std::tuple<int, int> computerRandomMove(){
        int i = 0;
        do {
            int x = rand() % 3;
            int y = rand() % 3;
            if (validMove(x, y)) {
                setBoard(x, y, 2);
                return {x, y};
            }
            i++;
        } while (i < 10000);
        // error since more than 1000 loops to make a valid move
        if (i == 10000) {
            cout << "Error: computerRandomMove() failed" << endl;
        }
        return {-1,-1};
        /* Force tie
         switch(move){
            case 0:
                setBoard(0,1,2);
                checkGameOver();
                move++;
                return {0,1};
            case 1:
                setBoard(1,0,2);
                checkGameOver();
                move++;
                return {1,0};
            case 2:
                setBoard(2,0,2);
                checkGameOver();
                move++;
                return {2,0};
            case 3:
                setBoard(2,2,2);
                checkGameOver();
                move++;
                return {2,2};
        }
         return {-1,-1};
        */
    }

    void newGame() {
        winner = -1;
        movesSoFar = 0;
        //move = 0; Enable for testing forced tie
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = 0;
            }
        }
    }

    void checkGameOver() {
        // vertical and horizontal
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != 0)
                winner = board[i][0];
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != 0)
                winner = board[0][i];
        }

        // diagonals
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0)
            winner = board[0][0];
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != 0)
            winner = board[0][2];

        // tie
        if (movesSoFar == 9 && winner == -1)
            winner = 0;
    }

    bool validMove(int x, int y) {
        if (x < 0 || x > 2 || y < 0 || y > 2) {
            return false;
        }
        if (board[x][y] == 0) {
            return true;
        }
        return false;
    }

    void setBoard(int x, int y, int value) {
        movesSoFar++;
        board[x][y] = value;
        checkGameOver();
    }

    void printBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }

    int getWinner(){
        return winner;
    }
};