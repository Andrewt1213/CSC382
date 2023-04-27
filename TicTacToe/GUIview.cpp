//
// Created by Andrew Tapia on 4/27/2023.
//
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsLineItem>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QGraphicsScene scene;

    auto *horizontal = new QGraphicsLineItem(0, 100, 150, 100);
    scene.addItem(horizontal);
    QGraphicsLineItem *horizontal2 = new QGraphicsLineItem(0, 150, 150, 150);
    scene.addItem(horizontal2);

    auto *vertical = new QGraphicsLineItem(50, 50, 50, 200);
    scene.addItem(vertical);
    QGraphicsLineItem *vertical2 = new QGraphicsLineItem(100, 50, 100, 200);
    scene.addItem(vertical2);

    QGraphicsView view(&scene);
    view.show();
    return a.exec();
}