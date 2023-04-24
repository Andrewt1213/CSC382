//
// Created by Lenovo on 4/20/2023.
//
#include "myModel.cpp"
class myController {
public:
    myController(){
        MyModel model;
        cout << "Play a game of Tic Tac Toe" << endl;
        while (!model.gameOver()) {
            do {
                model.printBoard();
                cout << "Enter row and column: ";
                int x, y;
                cin >> x >> y;
                if (model.validMove(x, y)) {
                    model.setBoard(x, y, 1);
                    break;
                }
                cout << "Invalid move" << endl;
            } while (true);
            if (!model.gameOver())
                model.computerRandomMove();
        }
        cout << "Game over" << endl;
        model.printBoard();
    }
};