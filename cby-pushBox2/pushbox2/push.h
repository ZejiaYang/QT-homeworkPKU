#ifndef PUSH_H
#define PUSH_H

#include"push_config.h"
#include <QWidget>
#include"GameMap.h"
#include<QPushButton>
#include"Role.h"
namespace Ui {
class push;
}

class push : public QWidget
{
    Q_OBJECT

public:
    explicit push(QWidget *parent = 0);
    ~push();

    virtual void paintEvent(QPaintEvent*event);//虚函数渲染一下
    //画图事件函数

    virtual void keyPressEvent(QKeyEvent*event);//键盘按下事件
    void Collision(int _dRow,int _dCol);
    bool GameOver();
    void show_exit();
    void show_intro();
    void show_NPC();
    void show_introWords();
     void close_all_intro();
     void endWords();


private:
    Ui::push *ui;
    QPushButton *endBtn;
    QPushButton*changeBtn;
     int totalRadius;
     int changeflag;
     int close_flag;
     bool intro_already_closed = 0;

private slots:
    void on_label_linkActivated(const QString &link);
    void quitClick();
    void changeClick();
    void on_pushButton_clicked();

private:

    GameMap*mPMap;
    //画家
    QPainter*mMapPainter;


    //角色
    Role *mRole;
    //游戏更新定时器
    QTimer * mTimer;
};

#endif // PUSH_H
