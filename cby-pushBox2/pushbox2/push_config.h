#ifndef PUSH_CONFIG_H
#define PUSH_CONFIG_H



#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
//窗口大小

#define GAME_WIDTH 1000
#define GAME_HEIGHT 600
#define GAME_POS_X 260
#define GAME_POS_Y 40

#define INTRO_WIDTH 1000
#define INTRO_HEIGHT 620
//intro_pos does not need to be defined, since it is settled in the middle of the window
#define INTRO_APPEAR_TIME 1000
//卷轴滚出的速度

#define NPC_HEIGHT 580
#define NPC_WIDTH 225
#define NPC_POS_X 915
#define NPC_POS_Y 100
//jygg的身高和体宽
#define NPC_APPEAR_TIME 400
//jygg冒出的速度

#define WORDS_POS_X 330
#define WORDS_POS_Y 70
//文字框的起始位置
#define WORDS_APPEAR_TIME 1000
//介绍词显示的速度

#define MAZE_WIDTH 25
#define MAZE_HEIGHT 15
//迷宫格数
#define PLAYER_MOVE_SPEED 300

#define MAZE_CORNER_X 220
#define MAZE_CORNER_Y 60
//地图左上角在窗口中的像素位置

#define BLOCKSIZE 40
//地图格子所占像素大小

#define UPDATETIME 100
//屏幕刷新速率

#define EXITBUTTON_X 20
#define EXITBUTTON_Y 640
#define EXITBUTTON_HEIGHT 60
#define EXITBUTTON_WIDTH 150
//退出按钮的参数

#define EXITNPC_HEIGHT 600
#define EXITNPC_WIDTH 300
#define EXITNPC_POS_X 100
#define EXITNPC_POS_Y 120
//jygg2的身高和体宽
#define EXITNPC_APPEAR_TIME 600
//jygg2冒出的速度

#define EXITWORDS_POS_X 415
#define EXITWORDS_POS_Y 93
#define EXITWORDS_WIDTH 450
#define EXITWORDS_HEIGHT 627

#endif // PUSH_CONFIG_H
