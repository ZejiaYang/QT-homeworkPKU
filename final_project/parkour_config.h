#ifndef PARKOUR_CONFIG_H
#define PARKOUR_CONFIG_H

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define WINDOW_TITLE "54 Parkour"

#define GAME_WIDTH 1280
#define GAME_HEIGHT 720
#define GAME_POS_X 0
#define GAME_POS_Y 0
//游戏窗口位置大小参数，设置为填充整个画面

#define INTROWIDTH 1280
#define INTROHEIGHT 720
#define INTRO_POS_X 0
#define INTRO_POS_Y 0
//介绍界面参数

#define MAP_SCROLL_SPEED 5
//2像素一滚动
#define REFRESH_RATE 10
//10毫秒一刷新

#define RUNWAY_TOP 145
#define RUNWAY_BOTTOM 600
//跑道区域

//玩家参数
#define RUNNER_START_POS_X 50
#define RUNNER_START_POS_Y 300
#define RUNNER_SIZE 130
#define RUNNER_STEP_TIME 90//50ms迈一步
#define PLAYER_HEALTH 5
#define PLAYER_FOREWARD_SPEED 1
#define PLAYER_SIDEWARD_SPEED 3
#define PLAYER_BACKWARD_SPEED 5

//血量显示与碰撞参数
#define HEART_SIZE 100//血量显示图表大小
#define HEALTHBAR_POS_X 0
#define HEALTHBAR_POS_Y 0

#define COLLISION_LABEL_WIDTH 75
#define COLLISION_LABEL_HEIGHT 65
#define COLLISION_TIME 700

//障碍物参数
#define BARRIER_SPEED 3
#define BARRIER_SPEED_FLOAT 2
#define BARRIER_SIZE 130
#define BARRIER_NUM 20
#define BARRIER_INTERVAL 100

#define PHONE_POS_X 900
#define PHONE_POS_Y 20
#define PHONE_WIDTH 200
#define PHONE_HEIGHT 300

//游戏设定
#define WINTIME 8500//85s

//失败界面参数
#define LOSE_POS_X 285
#define LOSE_POS_Y 10
#define LOSE_WIDTH 710
#define LOSE_HEIGHT 700

//胜利界面参数
#define WIN_POS_X -30
#define WIN_POS_Y 93
#define WIN_WIDTH 1094
#define WIN_HEIGHT 550

#endif // PARKOUR_CONFIG_H
