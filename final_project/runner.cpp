#include "runner.h"

Runner::Runner()
{
    m_runner.load(":/parkour_resource/runner1.png");
    m_runner = m_runner.scaled(QSize(RUNNER_SIZE,RUNNER_SIZE),Qt::KeepAspectRatio);
    m_Rect.setWidth(m_runner.width()-40);
    m_Rect.setHeight(m_runner.height());
    setposition(RUNNER_START_POS_X,RUNNER_START_POS_Y);
    health = PLAYER_HEALTH;

}

void Runner::setposition(int x, int y)
{
    m_X = x;
    m_Y = y;
    m_Rect.moveTo(m_X,m_Y);
}

void Runner::stepForward()
{
    stat++;
    if(stat>=4)stat = 0;
    switch(stat){
        case 0:
            m_runner.load(":/parkour_resource/runner1.png");
            break;
        case 1:
            m_runner.load(":/parkour_resource/runner2.png");
            break;
        case 2:
            m_runner.load(":/parkour_resource/runner3.png");
            break;
        case 3:
            m_runner.load(":/parkour_resource/runner4.png");
            break;
        }
    m_runner = m_runner.scaled(QSize(RUNNER_SIZE,RUNNER_SIZE),Qt::KeepAspectRatio);
}

void Runner::loseHealth(){
    health--;
}
