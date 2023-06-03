#include "minimazegamewidgetiii.h"
#include "ui_minimazegamewidgetiii.h"
#include "mazegenerator.h"

//game类定义

//迷宫左上角坐标
const int maze_corner_x = 40;
const int maze_corner_y = 260;


MazeGame::MazeGame(){
    maze_corner_pixel_x = MAZE_CORNER_X;
    maze_corner_pixel_y = MAZE_CORNER_Y;
    init_maze();
}

void MazeGame::init_maze(){
    int map[MAZE_HEIGHT][MAZE_WIDTH];
    MazeGenerator mzGenerator;
    srand((unsigned int)time(nullptr));
    mzGenerator.generate_maze(rand());
    for(int i = 1;i<=MAZE_HEIGHT;++i){
        for(int j = 1;j<=MAZE_WIDTH;++j)
            maze[i-1][j-1]=mzGenerator.readMaze(i,j);
    }
    //memcpy(maze,map,height*width*sizeof(int));
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
            case Qt::Key_O://开发者一键通关按钮
                return 10;
            default:
                return 0;
        }
}

void MazeGame::playerMove(int direction){
    std::pair<int,int> pos = get_player_pos();
    int r = pos.first,c = pos.second;
    assert(0<=r && r<=(height-1) && 0<=c && c<=(width-1));
    switch (direction){
        case 1:
            if(r-1<0)return;
            if(maze[r-1][c]!=1){
                maze[r-1][c] += 2;
                maze[r][c] = 0;
            }
            break;
        case 2:
            if(c-1<0)return;
            if(maze[r][c-1]!=1){
                maze[r][c-1] += 2;
                maze[r][c] = 0;
            }
            break;
        case 3:
            if(r+1>=height)return;
            if(maze[r+1][c]!=1){
                maze[r+1][c] += 2;
                maze[r][c] = 0;
            }
            break;
        case 4:
            if(c+1>=width)return;
            if(maze[r][c+1]!=1){
                maze[r][c+1] += 2;
                maze[r][c] = 0;
            }
            break;
        case 10://开发者一键通关
            maze[r][c] = 0;
            maze[MAZE_HEIGHT-2][MAZE_WIDTH-2]+=2;
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
    return std::make_pair(MAZE_HEIGHT-2,MAZE_WIDTH-1);//没有找到玩家就是通关了
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
    QPixmap endp(imgURL);


}


//以下为Widget类定义————————————————————————————————————

MiniMazeGameWidgetIII::MiniMazeGameWidgetIII(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MiniMazeGameWidgetIII)
{
    ui->setupUi(this);
    setFixedSize(WINDOW_WIDTH,WINDOW_HEIGHT);
    mazePainter = new QPainter(this);
    ptrMaze = new MazeGame();
    show_player();
    show_intro();
    show_NPC();
    show_introWords();
    ui->end_page_label->hide();
    ui->PlayerLabel->hide();
    set_exit_button();
    mazeTimer = new QTimer(this);
    mazeTimer->setInterval(UPDATETIME);//每UPDATETIME毫秒刷新一次界面
    connect(mazeTimer,SIGNAL(timeout()),this,SLOT(update()));
    ui->ExitButton->setFocusPolicy(Qt::NoFocus);//避免空格和Exit绑定
    connect(ui->ExitButton,SIGNAL(clicked(bool)),this,SLOT(close()));

}


void MiniMazeGameWidgetIII::keyPressEvent(QKeyEvent *keyevent)
{
    close_all_intro();
    ui->PlayerLabel->show();
    int player_action = ptrMaze->keyDone(keyevent);
    if(!ptrMaze->gameOver() && player_action >0)
       move_character(player_action);

    else if(ptrMaze->gameOver()&&player_action == -1){
        this->mazegame_success_broadcast();
        this->close();
    }
}


void MiniMazeGameWidgetIII::paintEvent(QPaintEvent* paintevent){
    Q_UNUSED(paintevent);
    print_backGround();
    show_end_page();
 }

void MiniMazeGameWidgetIII::show_intro(){
    int i = (WINDOW_WIDTH-INTRO_WIDTH)/2;
    int j = (WINDOW_HEIGHT-INTRO_HEIGHT)/2;
    ui->scrollLabel->setGeometry(i,j,INTRO_WIDTH,INTRO_HEIGHT);
    QPixmap scr("://maze_resource/scroll.png");
    scr = scr.scaled(ui->scrollLabel->size(), Qt::KeepAspectRatio);
    ui->scrollLabel->setPixmap(scr);
    //以下为卷轴的动画
    QPropertyAnimation *intro_animation = new QPropertyAnimation(ui->scrollLabel, "geometry");
    intro_animation->setDuration(INTRO_APPEAR_TIME);  // Animation duration in milliseconds
    intro_animation->setStartValue(QRect(1280,j,
                             INTRO_WIDTH,INTRO_HEIGHT));
    intro_animation->setEndValue(QRect(i,j,INTRO_WIDTH,INTRO_HEIGHT));
    intro_animation->start();
}

void MiniMazeGameWidgetIII::show_NPC(){
    ui->NPCLabel->raise();
    ui->NPCLabel->setGeometry(NPC_POS_X,NPC_POS_Y,NPC_WIDTH,NPC_HEIGHT);
    QPixmap npc("://maze_resource/jygg1.png");
    npc = npc.scaled(ui->NPCLabel->size(), Qt::KeepAspectRatio);
    ui->NPCLabel->setPixmap(npc);

    QPropertyAnimation *NPC_animation = new QPropertyAnimation(ui->NPCLabel, "geometry");
    NPC_animation->setDuration(NPC_APPEAR_TIME);  // Animation duration in milliseconds
    NPC_animation->setStartValue(QRect(NPC_POS_X,720,
                             NPC_WIDTH,NPC_HEIGHT));
    NPC_animation->setEndValue(QRect(NPC_POS_X,NPC_POS_Y,NPC_WIDTH,NPC_HEIGHT));
    NPC_animation->start();

}

void MiniMazeGameWidgetIII::show_introWords(){
    ui->IntroLabel->setGeometry(WORDS_POS_X,WORDS_POS_Y,800,600);
    ui->IntroLabel->setText("            理科一号楼，\n"
                            "是广大数院信科学子的圣地，\n"
                            "    也是享有\"理一迷宫\"之称的\n"
                            "          大一萌新噩梦。\n"
                            "          顺利走出迷宫,\n"
                            "这将会是你学到的第一个技能。\n\n\n"
                            "      按 任意键 开始游戏。\n");
    ui->IntroLabel->setFont(QFont("华文新魏", 28));
    QPropertyAnimation *words_animation = new QPropertyAnimation(ui->IntroLabel, "geometry");
    words_animation->setDuration(WORDS_APPEAR_TIME);  // Animation duration in milliseconds
    words_animation->setStartValue(QRect(1280,WORDS_POS_Y,800,600));
    words_animation->setEndValue(QRect(WORDS_POS_X,WORDS_POS_Y,800,600));
    words_animation->start();
}

void MiniMazeGameWidgetIII::set_exit_button(){
    ui->ExitButton->setGeometry(QRect(EXITBUTTON_X-10,EXITBUTTON_Y,
                                      EXITBUTTON_WIDTH,EXITBUTTON_HEIGHT));
    QIcon icon;
    icon.addFile(":/maze_resource/exitButton.png");
    ui->ExitButton->setIcon(icon);
    ui->ExitButton->setIconSize(QSize(ui->ExitButton->width()+20, ui->ExitButton->height()+10));
    ui->ExitButton->show();
}

void MiniMazeGameWidgetIII::print_backGround(){

    QPainter* painter = new QPainter(this);
    painter->begin(this);
    QString imgURL = "://maze_resource/mazeBackground5.png";
    QImage backgrd(imgURL);
    painter->drawImage(QRect(0,0,backgrd.width(),backgrd.height()),backgrd);
    for(int i = 0;i<MAZE_HEIGHT;++i){
        for(int j = 0;j<MAZE_WIDTH;++j){

            switch (ptrMaze->maze[i][j]) {
            case 0:
                imgURL = "://maze_resource/roadNONENONE.png";
                break;
            case 1:
                imgURL = "://maze_resource/wall2.png";
                break;
            case 2:
                imgURL = "://maze_resource/charatcerNONE.png";
                break;
            case 3:
                imgURL = "://maze_resource/exit.png";
                break;
            default:
                break;
            }
            QImage img(imgURL);
            painter->drawImage(QRect(MAZE_CORNER_X + j*img.width(),
                                     MAZE_CORNER_Y + i*img.height(),
                                     img.width(),img.height()),img);

        }
    }
    painter->end();
    delete painter;
}

void MiniMazeGameWidgetIII::show_player(){
    std::pair<int,int> cur_plr_pos = ptrMaze->get_player_pos();
    ui->PlayerLabel->setGeometry(MAZE_CORNER_X+cur_plr_pos.second*BLOCKSIZE,
                                 MAZE_CORNER_Y+cur_plr_pos.first*BLOCKSIZE,
                                 BLOCKSIZE,BLOCKSIZE);
    QPixmap plr("://maze_resource/character3.png");
    plr = plr.scaled(ui->PlayerLabel->size(), Qt::KeepAspectRatio);
    ui->PlayerLabel->setPixmap(plr);
    ui->PlayerLabel->show();
}

void MiniMazeGameWidgetIII::move_character(int action){

    std::pair<int,int> last_plr_pos = ptrMaze->get_player_pos();
    ptrMaze->playerMove(action);
    std::pair<int,int> cur_plr_pos = ptrMaze->get_player_pos();
    QPixmap action_player;
    switch(action){
    case 1:
        action_player = QPixmap("://maze_resource/up1.png");
        break;
    case 2:
        action_player = QPixmap("://maze_resource/left1.png");
        break;
    case 3:
        action_player = QPixmap("://maze_resource/down1.png");
        break;
    case 4:
        action_player = QPixmap("://maze_resource/right1.png");
        break;
    default:
        action_player = QPixmap("");
        break;
    }
    action_player = action_player.scaled(ui->PlayerLabel->size(), Qt::KeepAspectRatio);
    ui->PlayerLabel->setPixmap(action_player);
    QPropertyAnimation *animation = new QPropertyAnimation(ui->PlayerLabel, "geometry");
    animation->setDuration(PLAYER_MOVE_SPEED);  // Animation duration in milliseconds
    animation->setStartValue(QRect(MAZE_CORNER_X+last_plr_pos.second*BLOCKSIZE,
                             MAZE_CORNER_Y+last_plr_pos.first*BLOCKSIZE,
                             BLOCKSIZE,BLOCKSIZE));
    animation->setEndValue(QRect(MAZE_CORNER_X+cur_plr_pos.second*BLOCKSIZE,
                             MAZE_CORNER_Y+cur_plr_pos.first*BLOCKSIZE,
                             BLOCKSIZE,BLOCKSIZE));
    animation->start();
}

void MiniMazeGameWidgetIII::close_all_intro(){
    if(intro_already_closed)return;
    intro_already_closed = 1;

    QPropertyAnimation *words_close_animation = new QPropertyAnimation(ui->IntroLabel, "geometry");
    words_close_animation->setDuration(WORDS_APPEAR_TIME);  // Animation duration in milliseconds
    words_close_animation->setEndValue(QRect(1280,WORDS_POS_Y,800,600));
    words_close_animation->setStartValue(QRect(WORDS_POS_X,WORDS_POS_Y,800,600));
    words_close_animation->start();

    QPropertyAnimation *NPC_close_animation = new QPropertyAnimation(ui->NPCLabel, "geometry");
    NPC_close_animation->setDuration(NPC_APPEAR_TIME);  // Animation duration in milliseconds
    NPC_close_animation->setEndValue(QRect(NPC_POS_X,720,
                             NPC_WIDTH,NPC_HEIGHT));
    NPC_close_animation->setStartValue(QRect(NPC_POS_X,NPC_POS_Y,NPC_WIDTH,NPC_HEIGHT));
    NPC_close_animation->start();

    int i = (WINDOW_WIDTH-INTRO_WIDTH)/2;
    int j = (WINDOW_HEIGHT-INTRO_HEIGHT)/2;
    QPropertyAnimation *intro_close_animation = new QPropertyAnimation(ui->scrollLabel, "geometry");
    intro_close_animation->setDuration(INTRO_APPEAR_TIME);  // Animation duration in milliseconds
    intro_close_animation->setEndValue(QRect(1280,j,
                             INTRO_WIDTH,INTRO_HEIGHT));
    intro_close_animation->setStartValue(QRect(i,j,INTRO_WIDTH,INTRO_HEIGHT));
    intro_close_animation->start();


}

void MiniMazeGameWidgetIII::show_end_page(){
    if(!ptrMaze->gameOver())
        return;
    if(end_page_shown)
        return;
    end_page_shown = 1;
    ui->end_page_label->setGeometry(EXITNPC_POS_X,EXITNPC_POS_Y,EXITNPC_WIDTH,EXITNPC_HEIGHT);
    QPixmap endp("://maze_resource/jygg2.png");
    endp = endp.scaled(ui->end_page_label->size(), Qt::KeepAspectRatio);
    ui->end_page_label->setPixmap(endp);
    ui->end_page_label->show();

    //结束ui界面的动画目前有bug，无法显示，尚未修复
//    QPropertyAnimation *Exit_NPC_animation = new QPropertyAnimation(ui->end_page_label, "geometry");
//    Exit_NPC_animation->setDuration(EXITNPC_APPEAR_TIME);  // Animation duration in milliseconds
//    Exit_NPC_animation->setStartValue(QRect(EXITNPC_POS_X,720,
//                             EXITNPC_WIDTH,EXITNPC_HEIGHT));
//    Exit_NPC_animation->setEndValue(QRect(EXITNPC_POS_X,EXITNPC_POS_Y,
//                                          EXITNPC_WIDTH,EXITNPC_HEIGHT));
//    Exit_NPC_animation->start();
    ui->end_words_label->setGeometry(EXITWORDS_POS_X,EXITWORDS_POS_Y,
                                     EXITWORDS_WIDTH,EXITWORDS_HEIGHT);
    QPixmap endw("://maze_resource/exit_words.png");
    endw = endw.scaled(ui->end_words_label->size(), Qt::KeepAspectRatio);
    ui->end_words_label->setPixmap(endw);
    ui->end_words_label->show();

}


bool MiniMazeGameWidgetIII::mazegame_success_broadcast(){
    return 1;
}

MiniMazeGameWidgetIII::~MiniMazeGameWidgetIII()
{
    delete ui;
}



