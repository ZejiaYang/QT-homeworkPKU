#ifndef MAP_H
#define MAP_H
#include"parkour_config.h"
#include <QPixmap>

class Map
{
public:
    Map();
    void mapPosition();
    //用于计算背景滚动时的坐标

    QPixmap m_map1;//第一张背景图片
    QPixmap m_map2;//第二章背景图片

    int m_map1_posX;
    int m_map2_posX;

    int m_scroll_speed;//滚动速度
};

#endif // MAP_H
