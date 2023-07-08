#include"minimaze_config.h"
#include<memory.h>
#include<assert.h>
#include<stdlib.h>
#include<QString>
#include<QImage>
#include<QPainter>
#include<QEvent>
#include<QKeyEvent>
#include<QRect>
#include<QLabel>
#include <QPropertyAnimation>
#include<ctime>
#include<windows.h>
#include<QTimer>

//以下为game类声明，主要实现游戏逻辑
#ifndef MAZEGAME_H
#define MAZEGAME_H

class MazeGame{
private:
    int wall_size;
    int maze_corner_pixel_x;
    int maze_corner_pixel_y;
public:
    int height = MAZE_HEIGHT;
    int width = MAZE_WIDTH;
    int maze[MAZE_HEIGHT][MAZE_WIDTH];//1墙，2人，3出口
    std::pair<int,int> player_pos = {1,1};//起点位于(1,1)
    std::pair<int,int> exit_pos = {MAZE_HEIGHT-2,MAZE_WIDTH-2};

    MazeGame();
    void init_maze();
    void show_maze(QPainter* painter);
    int keyDone(QKeyEvent* keyevent);//检测玩家按键，1234对应前左后右
    void playerMove(int direction);
    std::pair<int,int> get_player_pos();//找到玩家当下的(i,j)坐标
    bool gameOver();
    void show_exit_page(QPainter* painter);
};

#endif


//以下为widget类声明，主要实现ui控制

#ifndef MINIMAZEGAMEWIDGETIII_H
#define MINIMAZEGAMEWIDGETIII_H

#include <QWidget>

namespace Ui {
class MiniMazeGameWidgetIII;
}

class MiniMazeGameWidgetIII : public QWidget
{
    Q_OBJECT

public:
    int tpass;
    int pass;
    explicit MiniMazeGameWidgetIII(QWidget *parent = 0);
    ~MiniMazeGameWidgetIII();
    void keyPressEvent(QKeyEvent *event);
    void paintEvent(QPaintEvent* paintevent);

    void show_intro();
    void show_NPC();
    void show_introWords();
    void print_backGround();
    void show_player();
    void move_character(int action);
    void show_end_page();
    void set_exit_button();
    void close_all_intro();
    bool mazegame_success_broadcast();

private:
    Ui::MiniMazeGameWidgetIII *ui;
    QPainter* mazePainter;
    MazeGame* ptrMaze;
    bool backgrdShown = 0;
    bool end_page_shown = 0;
    bool intro_already_closed = 0;
    QTimer* mazeTimer;

};

#endif // MINIMAZEGAMEWIDGETIII_H
