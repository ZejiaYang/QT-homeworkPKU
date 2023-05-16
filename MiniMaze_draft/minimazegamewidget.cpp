#include "minimazegamewidget.h"
#include "ui_minimazegamewidget.h"



//game类定义

//迷宫左上角坐标
const int maze_corner_x = 40;
const int maze_corner_y = 260;


MazeGame::MazeGame(){
    maze_corner_pixel_x = maze_corner_x;
    maze_corner_pixel_y = maze_corner_y;
    init_maze();
}

void MazeGame::init_maze(){
    int map[10][15] = {
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,
        1,2,1,0,1,0,1,1,1,0,0,0,1,0,1,
        1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,
        1,1,1,0,1,1,1,0,0,0,1,0,1,0,3,
        1,0,0,0,0,0,0,0,1,1,1,0,1,0,1,
        1,0,1,0,1,1,1,0,1,0,0,0,1,0,1,
        1,1,1,0,0,0,0,0,1,1,1,1,1,0,1,
        1,0,0,0,1,0,1,0,0,0,0,0,0,0,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    };
    memcpy(maze,map,height*width*sizeof(int));
}


int MazeGame::keyDone(QKeyEvent* keyevent){
        switch (keyevent->key()){
            case Qt::Key_W:
            case Qt::Key_Up:{
                return 1;
            }
            case Qt::Key_A:
            case Qt::Key_Left:{
                return 2;
            }
            case Qt::Key_S:
            case Qt::Key_Down:{
                return 3;
            }
            case Qt::Key_D:
            case Qt::Key_Right:{
                return 4;
            }
            case Qt::Key_Space://游戏结束按键
                return -1;
            default:
                return 0;
        }
}

void MazeGame::playerMove(int direction){
    std::pair<int,int> pos = get_player_pos();
    int r = pos.first,c = pos.second;
    assert(0<r && r<(height-1) && 0<c && c<(width-1));
    switch (direction){
        case 1:
            if(maze[r-1][c]!=1){
                maze[r-1][c] += 2;
                maze[r][c] = 0;
            }
            break;
        case 2:
            if(maze[r][c-1]!=1){
                maze[r][c-1] += 2;
                maze[r][c] = 0;
            }
            break;
        case 3:
            if(maze[r+1][c]!=1){
                maze[r+1][c] += 2;
                maze[r][c] = 0;
            }
            break;
        case 4:
            if(maze[r][c+1]!=1){
                maze[r][c+1] += 2;
                maze[r][c] = 0;
            }
            break;
        default:break;
    }
}
std::pair<int,int> MazeGame::get_player_pos(){
    for(int i = 0;i < height;++i){
        for(int j = 0;j < width;++j){
            if(maze[i][j]==2)
                return std::make_pair(i,j);
        }
    }
    return std::make_pair(0,0);
}
void MazeGame::show_maze(QPainter* painter){
    QString imgURL = "://maze_resource/mazeBackground2.jpg";
    QImage backgrd(imgURL);
    painter->drawImage(QRect(0,0,backgrd.width(),backgrd.height()),backgrd);
    for(int i = 0;i<height;++i){
        for(int j = 0;j<width;++j){

            switch (maze[i][j]) {
            case 0:
                imgURL = "://maze_resource/road.png";
                break;
            case 1:
                imgURL = "://maze_resource/wall.png";
                break;
            case 2:
                imgURL = "://maze_resource/charatcer.png";
                break;
            case 3:
                imgURL = "://maze_resource/exit.png";
                break;
            default:
                break;
            }
            QImage img(imgURL);
            painter->drawImage(QRect(maze_corner_pixel_y + j*img.width(),
                                     maze_corner_pixel_x + i*img.height(),
                                     img.width(),img.height()),img);

        }
    }
}

bool MazeGame::gameOver(){
    for(int i = 0;i<height;++i){
        for(int j = 0;j<width;++j){
            if(maze[i][j]==5)//人物和出口重叠
                return true;
        }
    }
    return false;
}

void MazeGame::show_exit_page(QPainter* painter) {
    if(!gameOver())return;
    QString imgURL = "://maze_resource/exitGame.png";
    QImage exitG(imgURL);
    painter->drawImage(QRect( (1280- exitG.width())/2,
                              (720-exitG.height())/2,
                              exitG.width(),exitG.height()),exitG);

}

//以下widget类定义
MiniMazeGameWidget::MiniMazeGameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MiniMazeGameWidget)
{
    ui->setupUi(this);
    setFixedSize(1280,720);
    mazePainter = new QPainter(this);
    ptrMaze = new MazeGame();
}

void MiniMazeGameWidget::keyPressEvent(QKeyEvent *keyevent)
{
    int player_action = ptrMaze->keyDone(keyevent);
    if(!ptrMaze->gameOver() && player_action >0)ptrMaze->playerMove(player_action);
    else if(ptrMaze->gameOver()&&player_action == -1)
        this->close();
}

void MiniMazeGameWidget::paintEvent(QPaintEvent* paintevent){
    Q_UNUSED(paintevent);
    mazePainter->begin((this));
    ptrMaze->show_maze(mazePainter);
    ptrMaze->show_exit_page(mazePainter);
    mazePainter->end();
    update();
}

MiniMazeGameWidget::~MiniMazeGameWidget()
{
    delete ui;
}
