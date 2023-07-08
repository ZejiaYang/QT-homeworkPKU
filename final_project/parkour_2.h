#ifndef PARKOUR_2_H
#define PARKOUR_2_H

#include"parkour_config.h"
#include <QWidget>
#include<QPainter.h>
#include <QTimer>
#include<QKeyEvent>
#include<ctime>
#include<QList>
#include<QPropertyAnimation>
#include<QGraphicsOpacityEffect>
#include<sstream>
#include<windows.h>
#include"map.h"
#include"runner.h"
#include"barrier.h"

namespace Ui {
class parkour_2;
}

class parkour_2 : public QWidget
{
    Q_OBJECT

public:
    explicit parkour_2(QWidget *parent = 0);
    ~parkour_2();

    void initWindow();
    //窗口初始化
    void playGame();
    //启动游戏
    void updatePos();
    //维护元素坐标
    void paintEvent(QPaintEvent *event);
    //绘制
    void keyPressEvent(QKeyEvent *keyevent);
    void keyReleaseEvent(QKeyEvent* keyevent);
    void playerMove();    //移动
    void collisionDectection();//检测玩家与障碍碰撞
    void winDectection();//检测胜利
    void loseDectection();//检测失败
    void showBackground();//显示介绍界面
    void closeBackground();//关闭介绍界面并同时开始游戏
    void updateDis();


    //障碍物相关函数
    void barrierAppear();
    void resetGame();

public slots:
    bool parkour_success_broadcast();
public:

    //多个障碍物，需要有障碍物数组记录
    Barrier barriers[BARRIER_NUM];
    //记录障碍物出场的时间间隔
    int b_recorder = 0;
    //记录该第几个障碍物出场
    int b_role = 0;
    int tpass = 0;
    int pass = 0;
    QLabel* introLabel;//介绍界面
    Map m_map;//背景地图对象
    Runner m_run;//玩家对象
    QTimer m_timer;//刷新计时器
    QTimer r_timer;//玩家运动计时器
    QTimer c_timer;//碰撞效果计时器
    int distanceCount = 0;
    bool gameLose = 0;//游戏结束且失败
    bool gameWin = 0;//游戏结束且获胜
    QList<int> keylist;//用于存储玩家按下的按键
    QLabel* collisionLabel;//碰撞Label
    QLabel* phoneLabel;//距离计数Label
    QLabel* loseLabel;
    QLabel* winLabel;

    bool intro_closed = 0;

private:
    Ui::parkour_2 *ui;

    QGraphicsOpacityEffect* GraphicsOpacityEffect;
    QPropertyAnimation* Animation;
};

#endif // PARKOUR_2_H
