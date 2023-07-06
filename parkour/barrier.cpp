#include "barrier.h"

Barrier::Barrier()
{
    m_X = GAME_WIDTH;
    m_Y = 0;
    onMap = false;
    bumped = false;
    m_kind = rand()%4;
    switch(m_kind){
    case 0:
        m_bar.load(":/parkour_resource/b1.png");
        break;
    case 1:
        m_bar.load(":/parkour_resource/b2.png");
        break;
    case 2:
        m_bar.load(":/parkour_resource/b3.png");
        break;
    case 3:
        m_bar.load(":/parkour_resource/b4.png");
        break;
    }
    m_bar = m_bar.scaled(80,130,Qt::KeepAspectRatio);


    int tmp = rand()%(BARRIER_SPEED_FLOAT);
    m_speed = BARRIER_SPEED+tmp;
    m_Rect.setWidth(m_bar.width());
    m_Rect.setHeight(m_bar.height());
    m_Rect.moveTo(m_X,m_Y);
}

void Barrier::updatePos(){
    if(!onMap)return;
    m_X -= m_speed;
    m_Rect.moveTo(m_X,m_Y);
    if(m_X+m_Rect.width()<=0){
        onMap = false;
    }
}
