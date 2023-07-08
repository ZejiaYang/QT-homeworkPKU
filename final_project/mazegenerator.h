#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include"minimaze_config.h"
using namespace std;

#define Wall 1
#define Road 0
#define Start 2
#define End 3

#ifndef MAZEGENERATOR_H
#define MAZEGENERATOR_H

class MazeGenerator{
private:
   const int Height = MAZE_HEIGHT;
   const int Width = MAZE_WIDTH;
   int map[MAZE_HEIGHT + 2][MAZE_WIDTH + 2];
public:
    MazeGenerator(){}
    int readMaze(int x,int y);
    void create_maze_path(int x, int y);
    void generate_maze(unsigned int seed);
};

#endif // MAZEGENERATOR_H
