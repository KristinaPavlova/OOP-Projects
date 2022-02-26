#ifndef POSITION_H
#define POSITION_H
#include<iostream>

struct Position
{
    //row
    int x;
    //colum
    int y;
    
    friend std::ostream& operator<<(std::ostream& out, Position& );
    bool operator==(const Position&);
    bool operator!=(const Position&);
    Position& operator=(Position&);
};
#endif