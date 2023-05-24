#include "Role.h"
#include<QPainter>
Role::Role(QObject *parent) : QObject(parent)
{
    mRow=1;
    mCol=1;
    mImg=QImage(":/Image/people.png");


    //显示位置
    mPaintPos=QPoint(mCol,mRow)*mImg.width();
}
void Role::Move(int _dRow,int _dCol)
{
    mRow+=_dRow;
    mCol+=_dCol;
    mPaintPos=QPoint(mCol,mRow)*mImg.width();
    //只管移动， 不用判断是否碰到路
}
void Role::Paint(QPainter* _p,QPoint _pos)
{
    _p->drawImage(mPaintPos+_pos,mImg);

}
