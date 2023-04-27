//
// Created by Andrew Tapia on 4/27/2023.
//
#include <QWidget>
#include <QIcon>
#include <QPushButton>
#include <QMessageBox>
#include <QGridLayout>
#include <iostream>
class ButtonWindow : public QWidget {
public:
    ButtonWindow(){
        layoutGUI();
        addEventHandlers();
    }

private:
    QPushButton *button1, *button2;
    QMessageBox messageBox;

    void layoutGUI(){
        button1 = new QPushButton();
        QIcon *letterO = new QIcon("C:\\Users\\Lenovo\\CLionProjects\\CSC382\\TicTacToe\\cmake-build-debug-coverage\\O.png");
        button1->setIcon(*letterO);
        button1->setFixedWidth(50);
        button1->setFixedHeight(50);

        button2 = new QPushButton();
        QIcon *letterX = new QIcon("C:\\Users\\Lenovo\\CLionProjects\\CSC382\\TicTacToe\\cmake-build-debug-coverage\\X.png");
        button2->setIcon(*letterX);
        button2->setFixedWidth(50);
        button2->setFixedHeight(50);

        auto *layout = new QGridLayout();
        layout->addWidget(button1, 0, 0);
        layout->addWidget(button2, 0, 1);

        this->setLayout(layout);

    }

    void addEventHandlers(){
        QObject::connect(button1, &QPushButton::clicked,
                         this, &ButtonWindow::button1Clicked);
        QObject::connect(button2, &QPushButton::clicked,
                         this, &ButtonWindow::button2Clicked);
    }

    void button1Clicked(){
        messageBox.setText("Button 1 was clicked");
        messageBox.exec();
    }

    void button2Clicked(){
        messageBox.setText("Button 2 was clicked");
        messageBox.exec();
    }
};