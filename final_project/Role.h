#ifndef ROLE_H
#define ROLE_H

#include <QObject>
#include<QPoint>
#include<QImage>

class Role : public QObject
{
    Q_OBJECT
public:
    explicit Role(QObject *parent = 0);


    //对应在地图的行列映射
    int mRow;
    int mCol;//地图行列和实际绘制的位置是翻转的
    //绘图位置
    QPoint mPaintPos;
    //人物图片
    QImage mImg;

    void Move(int _dRow,int _dCol);//移动函数
    void Paint(QPainter* _p,QPoint _pos);//自己的绘制函数

signals:

public slots:
};

#endif // ROLE_H
