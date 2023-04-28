//
// Created by Andrew Tapia on 4/20/2023.
//
#include <iostream>
#include <tuple>
using namespace std;
class MyModel {
private:
    int board[3][3]{};
    int winner = 0;
    int move = 0;
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

    std::tuple<int, int> computerRandomMove(){
        /*int i = 0;
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
        return {-1,-1};*/
        switch(move){
            case 0:
                setBoard(0,1,2);
                move++;
                return {0,1};
            case 1:
                setBoard(1,0,2);
                move++;
                return {1,0};
            case 2:
                setBoard(2,0,2);
                move++;
                return {2,0};
            case 3:
                setBoard(2,2,2);
                move++;
                return {2,2};
        }
    }

    void newGame() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = 0;
            }
        }
    }

    bool gameOver() {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != 0) {
                winner = board[i][0];
                return true;
            }
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != 0) {
                winner = board[0][i];
                return true;
            }
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0) {
            winner = board[0][0];
            return true;
        }
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != 0) {
            winner = board[0][2];
            return true;
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; i < 3; i++) {
                if (board[i][j] == 0) {
                    return false;
                }
            }
        }
        return true;
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
        board[x][y] = value;
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