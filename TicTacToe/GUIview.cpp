//
// Created by Andrew Tapia on 4/27/2023.
//
#include <QWidget>
#include <QIcon>
#include <QPushButton>
#include <QMessageBox>
#include <QGridLayout>
#include <iostream>
#include <QGraphicsLineItem>
#include <tuple>
#include "myModel.cpp"
class GUIview : public QWidget {
public:
    GUIview(){
        layoutGUI();
        addEventHandlers();
    }

private:
    MyModel model;
    int playerType = 0;
    QPushButton   *button00, *button01, *button02
                , *button10, *button11, *button12
                , *button20, *button21, *button22;
    QMessageBox messageBox;
    QIcon *letterX = new QIcon("C:\\Users\\Lenovo\\CLionProjects\\CSC382\\TicTacToe\\cmake-build-debug-coverage\\X.png");
    QIcon *letterO = new QIcon("C:\\Users\\Lenovo\\CLionProjects\\CSC382\\TicTacToe\\cmake-build-debug-coverage\\O.png");


    void layoutGUI(){
        // Create 9 buttons named according to their coordinates on the board
        button00 = new QPushButton();
        button01 = new QPushButton();
        button02 = new QPushButton();
        button10 = new QPushButton();
        button11 = new QPushButton();
        button12 = new QPushButton();
        button20 = new QPushButton();
        button21 = new QPushButton();
        button22 = new QPushButton();

        auto *layout = new QGridLayout();
        layout->addWidget(button00, 0, 0);
        layout->addWidget(button01, 0, 1);
        layout->addWidget(button02, 0, 2);
        layout->addWidget(button10, 1, 0);
        layout->addWidget(button11, 1, 1);
        layout->addWidget(button12, 1, 2);
        layout->addWidget(button20, 2, 0);
        layout->addWidget(button21, 2, 1);
        layout->addWidget(button22, 2, 2);

        this->setLayout(layout);

    }

    void addEventHandlers(){
        QObject::connect(button00, &QPushButton::clicked,
                         this, &GUIview::button00Clicked);

        QObject::connect(button01, &QPushButton::clicked,
                            this, &GUIview::button01Clicked);

        QObject::connect(button02, &QPushButton::clicked,
                            this, &GUIview::button02Clicked);

        QObject::connect(button10, &QPushButton::clicked,
                            this, &GUIview::button10Clicked);

        QObject::connect(button11, &QPushButton::clicked,
                            this, &GUIview::button11Clicked);

        QObject::connect(button12, &QPushButton::clicked,
                            this, &GUIview::button12Clicked);

        QObject::connect(button20, &QPushButton::clicked,
                            this, &GUIview::button20Clicked);

        QObject::connect(button21, &QPushButton::clicked,
                            this, &GUIview::button21Clicked);

        QObject::connect(button22, &QPushButton::clicked,
                            this, &GUIview::button22Clicked);
    }

    void computerMove(int x, int y){
        if (x == 0 && y == 0){
            button00->setIcon(*letterX);
        }
        if (x == 0 && y == 1){
            button01->setIcon(*letterX);
        }
        if (x == 0 && y == 2){
            button02->setIcon(*letterX);
        }
        if (x == 1 && y == 0){
            button10->setIcon(*letterX);
        }
        if (x == 1 && y == 1){
            button11->setIcon(*letterX);
        }
        if (x == 1 && y == 2){
            button12->setIcon(*letterX);
        }
        if (x == 2 && y == 0){
            button20->setIcon(*letterX);
        }
        if (x == 2 && y == 1){
            button21->setIcon(*letterX);
        }
        if (x == 2 && y == 2) {
            button22->setIcon(*letterX);
        }
    }

    void checkWinner(){
        if (model.gameOver()) {
            if (model.getWinner() == 2) {
                messageBox.setText("You Lose!");
                messageBox.exec();
            }
            else if (model.getWinner() == 1) {
                messageBox.setText("You Win!");
                messageBox.exec();
            }
            else {
                messageBox.setText("Tie!");
                messageBox.exec();
            }
        }

    }

    void checkComputerMove(){
        if (!model.gameOver()) {
            tuple<int, int> move = model.computerRandomMove();
            computerMove(get<0>(move), get<1>(move));
            checkWinner();
        }
    }

    void button00Clicked(){
        // check icon of button is null before applying icon
        if(button00->icon().isNull()) {
            button00->setIcon(*letterO);
            model.setBoard(0, 0, 1);
            checkWinner();
            checkComputerMove();
        }
    }

    void button01Clicked(){
        if(button01->icon().isNull()) {
            button01->setIcon(*letterO);
            model.setBoard(0, 1, 1);
            checkWinner();
            checkComputerMove();
        }
    }

    void button02Clicked(){
        if(button02->icon().isNull()) {
            button02->setIcon(*letterO);
            model.setBoard(0, 2, 1);
            checkWinner();
            checkComputerMove();
        }
    }

    void button10Clicked(){
        if(button10->icon().isNull()) {
            button10->setIcon(*letterO);
            model.setBoard(1, 0, 1);
            checkWinner();
            checkComputerMove();
        }
    }

    void button11Clicked(){
        if(button11->icon().isNull()) {
            button11->setIcon(*letterO);
            model.setBoard(1, 1, 1);
            checkWinner();
            checkComputerMove();
        }
    }

    void button12Clicked(){
        if(button12->icon().isNull()) {
            button12->setIcon(*letterO);
            model.setBoard(1, 2, 1);
            checkWinner();
            checkComputerMove();
        }
    }

    void button20Clicked(){
        if(button20->icon().isNull()) {
            button20->setIcon(*letterO);
            model.setBoard(2, 0, 1);
            checkWinner();
            checkComputerMove();
        }
    }

    void button21Clicked(){
        if(button21->icon().isNull()) {
            button21->setIcon(*letterO);
            model.setBoard(2, 1, 1);
            checkWinner();
            checkComputerMove();
        }
    }

    void button22Clicked(){
        if(button22->icon().isNull()) {
            button22->setIcon(*letterO);
            model.setBoard(2, 2, 1);
            checkWinner();
            checkComputerMove();
        }
    }



};