#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "GUIview.cpp"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QGraphicsScene scene;
    GUIview window;
    window.show();

    return a.exec();
}
