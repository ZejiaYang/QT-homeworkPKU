#include "block.h"

Block::Block(QWidget *parent) : QWidget(parent)
{
    resize(80,120);
}
WhiteBlock::WhiteBlock(QWidget *parent) : Block(parent)
{
     this->setStyleSheet("background-color:white;");
    //或者使用重绘事件  画背景图
}
BlueBlock::BlueBlock(QWidget *parent) : Block(parent)
{
     this->setStyleSheet("background-color:black;");
}

