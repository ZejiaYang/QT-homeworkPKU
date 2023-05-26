#include "widget.h"
#include "gameview.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gameview w;
    w.initgameview();
    w.show();
    return a.exec();
}
