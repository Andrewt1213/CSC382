/*
 * RunGameMain.cpp
 *
 *  Created on: Sep 20, 2018
 *      Author: mercer
 */
#include <iostream>
#include "GameOfLife.cpp"

using namespace std;

//
// Andrew Tapia
//
// int mainRUN () { need this when running a unit test
int main() {
    GameOfLife society(5, 7);

    society.growCellAt(1, 3);
    society.growCellAt(2, 3);
    society.growCellAt(3, 3);


    string ch;
    for (int count = 1; count <= 10; count++) {
        cout << society.toString() << endl;
        society.update();
    }
    return 0;
}
