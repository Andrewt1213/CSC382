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
class GUIview : public QWidget {
public:
    GUIview(){
        layoutGUI();
        addEventHandlers();
    }

private:
    int playerType = 0;
    QPushButton   *button00, *button01, *button02
                , *button10, *button11, *button12
                , *button20, *button21, *button22;
    QMessageBox messageBox;

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

/*
        button1 = new QPushButton();
        QIcon *letterO = new QIcon("C:\\Users\\Lenovo\\CLionProjects\\CSC382\\TicTacToe\\cmake-build-debug-coverage\\O.png");
        button1->setIcon(*letterO);
        button1->setFixedWidth(50);
        button1->setFixedHeight(50);*/

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

    void button00Clicked(){
        QIcon *letterO = new QIcon("C:\\Users\\Lenovo\\CLionProjects\\CSC382\\TicTacToe\\cmake-build-debug-coverage\\O.png");
        QIcon *letterX = new QIcon("C:\\Users\\Lenovo\\CLionProjects\\CSC382\\TicTacToe\\cmake-build-debug-coverage\\X.png");
        // check icon of button is null before applying icon
        if(button00->icon().isNull()){
            if(playerType == 0){
                button00->setIcon(*letterO);
                playerType = 1;
            } else {
                button00->setIcon(*letterX);
                playerType = 0;
            }
        }
    }

    void button01Clicked(){
        QIcon *letterO = new QIcon("C:\\Users\\Lenovo\\CLionProjects\\CSC382\\TicTacToe\\cmake-build-debug-coverage\\O.png");
        QIcon *letterX = new QIcon("C:\\Users\\Lenovo\\CLionProjects\\CSC382\\TicTacToe\\cmake-build-debug-coverage\\X.png");
        // check icon of button is null before applying icon
        if(button01->icon().isNull()){
            if(playerType == 0){
                button01->setIcon(*letterO);
                playerType = 1;
            } else {
                button01->setIcon(*letterX);
                playerType = 0;
            }
        }
    }

    void button02Clicked(){
        QIcon *letterO = new QIcon("C:\\Users\\Lenovo\\CLionProjects\\CSC382\\TicTacToe\\cmake-build-debug-coverage\\O.png");
        QIcon *letterX = new QIcon("C:\\Users\\Lenovo\\CLionProjects\\CSC382\\TicTacToe\\cmake-build-debug-coverage\\X.png");
        // check icon of button is null before applying icon
        if(button02->icon().isNull()){
            if(playerType == 0){
                button02->setIcon(*letterO);
                playerType = 1;
            } else {
                button02->setIcon(*letterX);
                playerType = 0;
            }
        }
    }

    void button10Clicked(){
        QIcon *letterO = new QIcon("C:\\Users\\Lenovo\\CLionProjects\\CSC382\\TicTacToe\\cmake-build-debug-coverage\\O.png");
        QIcon *letterX = new QIcon("C:\\Users\\Lenovo\\CLionProjects\\CSC382\\TicTacToe\\cmake-build-debug-coverage\\X.png");
        // check icon of button is null before applying icon
        if(button10->icon().isNull()){
            if(playerType == 0){
                button10->setIcon(*letterO);
                playerType = 1;
            } else {
                button10->setIcon(*letterX);
                playerType = 0;
            }
        }
    }

    void button11Clicked(){
        QIcon *letterO = new QIcon("C:\\Users\\Lenovo\\CLionProjects\\CSC382\\TicTacToe\\cmake-build-debug-coverage\\O.png");
        QIcon *letterX = new QIcon("C:\\Users\\Lenovo\\CLionProjects\\CSC382\\TicTacToe\\cmake-build-debug-coverage\\X.png");
        // check icon of button is null before applying icon
        if(button11->icon().isNull()){
            if(playerType == 0){
                button11->setIcon(*letterO);
                playerType = 1;
            } else {
                button11->setIcon(*letterX);
                playerType = 0;
            }
        }
    }

    void button12Clicked(){
        QIcon *letterO = new QIcon("C:\\Users\\Lenovo\\CLionProjects\\CSC382\\TicTacToe\\cmake-build-debug-coverage\\O.png");
        QIcon *letterX = new QIcon("C:\\Users\\Lenovo\\CLionProjects\\CSC382\\TicTacToe\\cmake-build-debug-coverage\\X.png");
        // check icon of button is null before applying icon
        if(button12->icon().isNull()){
            if(playerType == 0){
                button12->setIcon(*letterO);
                playerType = 1;
            } else {
                button12->setIcon(*letterX);
                playerType = 0;
            }
        }
    }

    void button20Clicked(){
        QIcon *letterO = new QIcon("C:\\Users\\Lenovo\\CLionProjects\\CSC382\\TicTacToe\\cmake-build-debug-coverage\\O.png");
        QIcon *letterX = new QIcon("C:\\Users\\Lenovo\\CLionProjects\\CSC382\\TicTacToe\\cmake-build-debug-coverage\\X.png");
        // check icon of button is null before applying icon
        if(button20->icon().isNull()){
            if(playerType == 0){
                button20->setIcon(*letterO);
                playerType = 1;
            } else {
                button20->setIcon(*letterX);
                playerType = 0;
            }
        }
    }

    void button21Clicked(){
        QIcon *letterO = new QIcon("C:\\Users\\Lenovo\\CLionProjects\\CSC382\\TicTacToe\\cmake-build-debug-coverage\\O.png");
        QIcon *letterX = new QIcon("C:\\Users\\Lenovo\\CLionProjects\\CSC382\\TicTacToe\\cmake-build-debug-coverage\\X.png");
        // check icon of button is null before applying icon
        if(button21->icon().isNull()){
            if(playerType == 0){
                button21->setIcon(*letterO);
                playerType = 1;
            } else {
                button21->setIcon(*letterX);
                playerType = 0;
            }
        }
    }

    void button22Clicked(){
        QIcon *letterO = new QIcon("C:\\Users\\Lenovo\\CLionProjects\\CSC382\\TicTacToe\\cmake-build-debug-coverage\\O.png");
        QIcon *letterX = new QIcon("C:\\Users\\Lenovo\\CLionProjects\\CSC382\\TicTacToe\\cmake-build-debug-coverage\\X.png");

        // check icon of button is null before applying icon
        if(button22->icon().isNull()){
            if(playerType == 0){
                button22->setIcon(*letterO);
                playerType = 1;
            } else {
                button22->setIcon(*letterX);
                playerType = 0;
            }
        }
    }

};