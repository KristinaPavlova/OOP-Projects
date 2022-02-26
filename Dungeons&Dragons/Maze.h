#ifndef MAZE_H
#define MAZE_H
#include<iostream>
#include <stdlib.h>  //srand rand
#include <time.h> //time
#include<fstream>
#include"Position.h"
#include"linkedList.h"
#include<iomanip>
#include<stdlib.h>

class Maze
{
    private:
    int rows;
    int colums;
    int** matrix;

    void destroy();

    public:

    Maze();
    Maze(const Maze&) = delete;
    Maze& operator=(const Maze&) = delete;
    ~Maze();
    bool notNeighboar(int  , int , LinkedList<Position>& );
    void fillCorrectPath();
    bool isPath( int , int );
    void fillMaze(int& , int&);
    void createMaze();
    void updateMaze(int&);
    void drawMaze(int&);
    void changeValueOfMaze( Position& , int);
    bool correctMove(int& , int&);
    int getPositionValue(const Position&);
    Position& getExit() const; // for testing
    
};
#endif