#include <iostream>
#include "myModel.cpp"
using namespace std;
int main() {
    MyModel model;
    model.printBoard();
    model.setBoard(0, 0, 1);
    cout << model.validMove(0, 0) << endl;
    cout << model.validMove(1, 1) << endl;
    model.printBoard();
    model.setBoard(0, 1, 1);
    model.printBoard();
    model.setBoard(0, 2, 1);
    model.printBoard();
    cout << model.gameOver() << endl;
    return 0;
}
