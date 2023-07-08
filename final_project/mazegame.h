#ifndef mazegame_H
#define mazegame_H

#include <QWidget>
#include <QWidget>
#include <QMouseEvent>
#include <QVector>
#include <QTimer>
#include "puzzlepart.h"
#include <QWidget>
#include<QGraphicsPixmapItem>//图形元素
#include<QGraphicsView>//视图
#include<QGraphicsScene>//场景
#include<QList>
#include"minimaze_config.h"
#include<QStackedWidget>
#include<QMediaPlayer>
class QPushButton;
class QSpinBox;
class QLineEdit;
namespace Ui {
class mazegame;
}

class mazegame : public QWidget
{
    Q_OBJECT

public:
    int pass;
    int tpass;
    explicit mazegame(QWidget *parent = 0);
    ~mazegame();


    void show_intro();
    void show_NPC();
    void show_introWords();
     void close_all_intro();

    virtual void paintEvent(QPaintEvent *);//绘制界面
     void keyPressEvent(QKeyEvent* keyevent);
    //可以在此函数中调用背景
public slots://槽函数
    //void onBtnClicked();//当鼠标点击时
    void onSpinBoxValueChanged(int);//当spinbox里面的值改变时
    void onTimeOutSlot();//计时器，
    void onStartBtnClicked();//开始按钮的响应函数
    void onEndBtnClicked();
private:
    Ui::mazegame *ui;
    bool intro_already_closed = 0;
private:
    //开始场景设置



    int width;//宽
    int height;//高，格子数
    int radius;//正方形格子的边长
    int totalRadius;//固定大小为600*600，然后根据width算出radius
    int stepCount;//步数计数器
    int mm,ss;//时间的分和秒
    bool isStart;//判断是否是开始按钮，以在开始/暂停功能间转换
    //QImage *image;


    QImage *img;
    QPushButton *btn;
    QSpinBox *diffLevel;
    QLineEdit *curStepCount;
    QLineEdit *timeLineEdit;
    QTimer *timer;
    QPushButton *startBtn;
    QPushButton *endBtn;

    bool win;

    PuzzlePart **map;

    void orderBroken();//将格子打乱顺序

    virtual void click(QPoint pt);//处理鼠标点击

    virtual void mouseReleaseEvent(QMouseEvent *ev); // 鼠标点击象棋并释放鼠标时候触发

    bool checkRange(int,int);//检查是否越界

    bool checkGameOver();//检查游戏是否结束
};

#endif // MAZEGAME_H
