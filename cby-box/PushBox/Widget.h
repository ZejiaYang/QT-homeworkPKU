#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"GameMap.h"
#include<QPushButton>
#include"Role.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    virtual void paintEvent(QPaintEvent*event);//虚函数渲染一下
    //画图事件函数
    ~Widget();
    virtual void keyPressEvent(QKeyEvent*event);//键盘按下事件
    void Collision(int _dRow,int _dCol);
    bool GameOver();
    void show_exit();




private slots:
    void on_label_linkActivated(const QString &link);
    void quitClick();

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;

    GameMap*mPMap;
    //画家
    QPainter*mMapPainter;

    QPushButton*quit;
    //角色
    Role *mRole;
    //游戏更新定时器
    QTimer * mTimer;

};

#endif // WIDGET_H
