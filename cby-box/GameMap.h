#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <QObject>
#include<QPainter>

enum MapElement{
    Road,//0
    Wall,//1
    Box,//2
    Point,//3
    InPoint,//4
    Wall1//5
};

class GameMap : public QObject
{
    Q_OBJECT
public:
    explicit GameMap(QObject *parent = 0);
    ~GameMap();

    bool InitByFile(QString fileName);
    void Clear();
    void Paint(QPainter* _p,QPoint _Pos);
    int mRow;
    int mCol;
    int **mPArr;//用于开辟二维数组，2D地图元素


signals:

public slots:
};

#endif // GAMEMAP_H
