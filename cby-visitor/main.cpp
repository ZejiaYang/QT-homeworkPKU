#include "visitor.h"
#include <QApplication>
#include <QApplication>
#include <QFile>
#include <QTextStream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile file(":/res/qss/style-1.qss");/*QSS文件所在的路径*/

    file.open(QFile::ReadOnly);
    QTextStream filetext(&file);
    QString stylesheet = filetext.readAll();
    a.setStyleSheet(stylesheet);
    file.close();

    Visitor w;
    w.show();

    return a.exec();
}
