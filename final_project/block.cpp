#include "block.h"

Block::Block(QWidget *parent,int x, int y) : QWidget(parent)
{
    width = x;
    height = y;
    resize(80,120);
}
WhiteBlock::WhiteBlock(QWidget *parent,int x,int y,int s) : Block(parent,x,y)
{
    if(s == 0)
        this->setStyleSheet("background-color:white;");
    else if(s == 1)
        this->setStyleSheet(QString("background-image:url(:/WhiteBlockImage/gw2.png);"));
    else if(s == 2)
        this->setStyleSheet(QString("background-image:url(:/WhiteBlockImage/ljy2.png);"));
    else
        this->setStyleSheet(QString("background-image:url(:/WhiteBlockImage/zqj.png);"));
    //或者使用重绘事件  画背景图
}
BlueBlock::BlueBlock(QWidget *parent,int x,int y) : Block(parent,x,y)
{
     this->setStyleSheet(QString("background-image:url(:/WhiteBlockImage/AC.png);"));
}

