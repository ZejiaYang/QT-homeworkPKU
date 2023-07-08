#ifndef BLOCK_H
#define BLOCK_H

#include <QWidget>

//抽象产品
class Block : public QWidget
{
public:
    void down(int step){
        move(pos().x(),pos().y() + step);
    }
    Block(QWidget *parent = nullptr,int x = 0,int y = 0);
    virtual bool isBlack() = 0;
    int width;
    int height;
};

//具体产品 蓝块
class BlueBlock : public Block
{
    public:
    bool isBlack(){ return true;}
    BlueBlock(QWidget *parent = nullptr,int x = 0, int y = 0);
};
//具体产品 白块
class WhiteBlock : public Block
{
    public:
      bool isBlack(){ return false;}
    WhiteBlock(QWidget *parent = nullptr,int x = 0, int y = 0,int s=0);
};

//抽象工厂
class Factory
{
public :
    virtual Block* CreateBlock(QWidget *parent = nullptr,int x = 0, int y = 0,int s= 0) = 0;
};

//具体产品工厂 蓝块工厂
class BlueBlockFactory : public Factory
{
public :
    Block* CreateBlock(QWidget *parent = nullptr,int x = 0, int y = 0, int s = 0)
    {
        Block* blueBlock = new BlueBlock(parent,x,y);
        return blueBlock;
    }
};

//具体产品工厂 白块工厂
class WhiteBlockFactory : public Factory
{
public :
    Block* CreateBlock(QWidget *parent = nullptr,int x = 0, int y = 0,int s = 0)
    {
        Block* whiteBlock = new WhiteBlock(parent,x,y,s);
        return whiteBlock;
    }
};

#endif // BLOCK_H

