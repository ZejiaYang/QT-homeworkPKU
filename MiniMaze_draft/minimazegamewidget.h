//以下为game类声明，主要实现游戏逻辑
#ifndef MAZEGAME_H
#define MAZEGAME_H
#include<memory.h>
#include<assert.h>
#include<stdlib.h>
#include<QString>
#include<QImage>
#include<QPainter>
#include<QEvent>
#include<QKeyEvent>
#include<QRect>
class MazeGame{
private:
    int wall_size;
    int maze_corner_pixel_x;
    int maze_corner_pixel_y;
protected:
    int height = 10;
    int width = 15;
    int maze[10][15];//1墙，2人，3出口
public:
    MazeGame();
    void init_maze();
    void show_maze(QPainter* painter);
    int keyDone(QKeyEvent* keyevent);//检测玩家按键，1234对应前左后右
    void playerMove(int direction);
    std::pair<int,int> get_player_pos();//找到玩家当下的(i,j)坐标
    bool gameOver();
    void show_exit_page(QPainter* painter);
};
#endif // MAZEGAME_H
//以下为widget类声明，主要实现ui在窗口中的呈现————————————————————————————————————————————————————
#ifndef MINIMAZEGAMEWIDGET_H
#define MINIMAZEGAMEWIDGET_H

#include <QWidget>

namespace Ui {
class MiniMazeGameWidget;
}

class MiniMazeGameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MiniMazeGameWidget(QWidget *parent = 0);
    ~MiniMazeGameWidget();
    void keyPressEvent(QKeyEvent* keyevent);
    void paintEvent(QPaintEvent* paintevent);

private:
    Ui::MiniMazeGameWidget *ui;
    QPainter* mazePainter;
    MazeGame* ptrMaze;
};

#endif // MINIMAZEGAMEWIDGET_H


