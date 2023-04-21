#include <QApplication>
#include <QPushButton>
#include <iostream>

int main(int argc, char *argv[]) {
     QApplication app{argc, argv};
     QPushButton button("Hello world!", nullptr);
     button.resize(200, 100);
     button.show();
     return app.exec();
}