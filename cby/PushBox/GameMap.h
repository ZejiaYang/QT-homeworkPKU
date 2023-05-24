#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <QObject>
#include<QPainter>

enum MapElement{
    Road,
    Wall,
    Box,
    Point,
    InPoint
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
