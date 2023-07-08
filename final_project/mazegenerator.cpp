#include"mazegenerator.h"


void MazeGenerator::create_maze_path(int x, int y) //随机生成迷
{
    int c[4][2] = { 0,1,1,0,0,-1,-1,0 }; //四个方向
    int i, j, t;
    //将方向打乱
    for (i = 0; i < 4; i++)
    {
        j = rand() % 4;
        t = c[i][0]; c[i][0] = c[j][0]; c[j][0] = t;
        t = c[i][1]; c[i][1] = c[j][1]; c[j][1] = t;
    }
    map[x][y] = Road;
    for (i = 0; i < 4; i++)
        if (map[x + 2 * c[i][0]][y + 2 * c[i][1]] == Wall)
        {
            map[x + c[i][0]][y + c[i][1]] = Road;
            create_maze_path(x + 2 * c[i][0], y + 2 * c[i][1]);
        }
}

void MazeGenerator:: generate_maze(unsigned int randnum)
{
    int i, j;
    srand(randnum); //初始化随即种子
    for (i = 0; i <= Height + 1; i++)
        for (j = 0; j <= Width + 1; j++)
            if (i == 0 || i == Height + 1 || j == 0 || j == Width + 1) //初始化迷宫
                map[i][j] = Road;
            else map[i][j] = Wall;
    create_maze_path(2 * (rand() % (Height / 2) + 1), 2 * (rand() % (Width / 2) + 1)); //从随机一个点开始生成迷宫，该点行列都为偶数
    for (i = 0; i <= Height + 1; i++) //边界处理
    {
        map[i][0] = Wall;
        map[i][Width + 1] = Wall;
    }
    for (j = 0; j <= Width + 1; j++) //边界处理
    {
        map[0][j] = Wall;
        map[Height + 1][j] = Wall;
    }
    map[2][1] = Start; //给定入口
    map[Height - 1][Width] = End; //给定出口
}

int MazeGenerator::readMaze(int x,int y){
    return map[x][y];
}
