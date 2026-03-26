#include <QApplication>
#include <QScreen>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow window;

    window.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    QScreen* screen = QGuiApplication::primaryScreen();
    QRect geometry = screen->geometry();

    window.setGeometry(geometry);
    window.show();

    return app.exec();
}
