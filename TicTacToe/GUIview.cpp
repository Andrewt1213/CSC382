// GUIview.cpp
// Created by Andrew Tapia on 4/27/2023.
// This class represents the view of a tik tak toe game.
// It is responsible for displaying the state of the game.
// It uses QT in order to dipslay the game.
//
#include <QWidget>
#include <QIcon>
#include <QPushButton>
#include <QMessageBox>
#include <QGridLayout>
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

    bool isWinner(){
        if (model.gameOver()) {
            if (model.getWinner() == 2) {
                messageBox.setText("You Lose!");
                messageBox.exec();
            }
            else if (model.getWinner() == 1) {
                messageBox.setText("You Win!");
                messageBox.exec();
            }
            else if (model.getWinner() == 0) {
                messageBox.setText("Tie!");
                messageBox.exec();
            }
            return true;
        }
        return false;
    }

    void checkComputerMove(){
        tuple<int, int> move = model.computerRandomMove();
        computerMove(get<0>(move), get<1>(move));
    }

    void button00Clicked(){
        // check icon of button is null before applying icon
        if(button00->icon().isNull() && !model.gameOver()) {
            button00->setIcon(*letterO);
            model.setBoard(0, 0, 1);
            if (!isWinner()){
                checkComputerMove();
                isWinner();
            }
        }
    }

    void button01Clicked(){
        if(button01->icon().isNull() && !model.gameOver()) {
            button01->setIcon(*letterO);
            model.setBoard(0, 1, 1);
            if (!isWinner()){
                checkComputerMove();
                isWinner();
            }
        }
    }

    void button02Clicked(){
        if(button02->icon().isNull() && !model.gameOver()) {
            button02->setIcon(*letterO);
            model.setBoard(0, 2, 1);
            if (!isWinner()){
                checkComputerMove();
                isWinner();
            }
        }
    }

    void button10Clicked(){
        if(button10->icon().isNull() && !model.gameOver()) {
            button10->setIcon(*letterO);
            model.setBoard(1, 0, 1);
            if (!isWinner()){
                checkComputerMove();
                isWinner();
            }
        }
    }

    void button11Clicked(){
        if(button11->icon().isNull() && !model.gameOver()) {
            button11->setIcon(*letterO);
            model.setBoard(1, 1, 1);
            if (!isWinner()){
                checkComputerMove();
                isWinner();
            }
        }
    }

    void button12Clicked(){
        if(button12->icon().isNull() && !model.gameOver()) {
            button12->setIcon(*letterO);
            model.setBoard(1, 2, 1);
            if (!isWinner()){
                checkComputerMove();
                isWinner();
            }
        }
    }

    void button20Clicked(){
        if(button20->icon().isNull() && !model.gameOver()) {
            button20->setIcon(*letterO);
            model.setBoard(2, 0, 1);
            if (!isWinner()){
                checkComputerMove();
                isWinner();
            }
        }
    }

    void button21Clicked(){
        if(button21->icon().isNull() && !model.gameOver()) {
            button21->setIcon(*letterO);
            model.setBoard(2, 1, 1);
            if (!isWinner()){
                checkComputerMove();
                isWinner();
            }
        }
    }

    void button22Clicked(){
        if(button22->icon().isNull() && !model.gameOver()) {
            button22->setIcon(*letterO);
            model.setBoard(2, 2, 1);
            if (!isWinner()){
                checkComputerMove();
                isWinner();
            }
        }
    }



};