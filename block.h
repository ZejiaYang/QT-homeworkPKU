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
    Block(QWidget *parent = nullptr);
    virtual bool isBlack() = 0;
};

//具体产品 蓝块
class BlueBlock : public Block
{
    public:
    bool isBlack(){ return true;}
    BlueBlock(QWidget *parent = nullptr);
};
//具体产品 白块
class WhiteBlock : public Block
{
    public:
      bool isBlack(){ return false;}
    WhiteBlock(QWidget *parent = nullptr);
};

//抽象工厂
class Factory
{
public :
    virtual Block* CreateBlock(QWidget *parent = nullptr) = 0;
};

//具体产品工厂 蓝块工厂
class BlueBlockFactory : public Factory
{
public :
    Block* CreateBlock(QWidget *parent = nullptr)
    {
        Block* blueBlock = new BlueBlock(parent);
        return blueBlock;
    }
};

//具体产品工厂 白块工厂
class WhiteBlockFactory : public Factory
{
public :
    Block* CreateBlock(QWidget *parent = nullptr)
    {
        Block* whiteBlock = new WhiteBlock(parent);
        return whiteBlock;
    }
};

#endif // BLOCK_H

