#ifndef BARRIER_H
#define BARRIER_H
#include<QPixmap>
#include<QRect>
#include<parkour_config.h>

class Barrier
{
public:
    Barrier();
    void updatePos();
    QPixmap m_bar;
    QRect m_Rect;
    int m_X;
    int m_Y;
    int m_speed;
    int m_kind;//贴图种类
    bool onMap = 0;
    bool bumped = 0;
};

#endif // BARRIER_H
