#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QWidget>
#include <QMessageBox>
#include <QPainter>
#include "gamesetting.h"
#include "gameview.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    void paintEvent(QPaintEvent*event);
    ~Widget();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();
    void gameoverslot();
private:
    gameview* gameVc;
    Ui::Widget *ui;
};

#endif // WIDGET_H

