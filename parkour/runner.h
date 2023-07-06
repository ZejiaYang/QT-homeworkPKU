#include"parkour_config.h"
#include<QPixmap>
#include<QRect>
#include <QApplication>
#include <QMovie>
#include <QLabel>
#include<QTimer>
#include"parkour_config.h"
#ifndef RUNNER_H
#define RUNNER_H


class Runner{
public:
    Runner();
    //设置位置
    void setposition(int x, int y);
    void loseHealth();
public slots:
    void stepForward();//向前迈一步
public:
    QPixmap m_runner;//资源 对象
    int m_X;int m_Y;//坐标
    QRect m_Rect;//碰撞箱

    int stat = 0;//步伐状态
    int health = 0;

//    QTimer runner_timer;
//    QLabel* runnerLabel;
//    QMovie* runnerMovie;
};
#endif // RUNNER_H


