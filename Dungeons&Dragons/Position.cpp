#ifndef POSITION_CPP
#define POSITION_CPP

#include"Position.h"


std::ostream& operator<<(std::ostream& out, Position& position )
{
    out<<position.x <<" : "<<position.y;
    return out;
}
bool Position::operator==(const Position& other)
{
    if( this->x == other.x && this->y == other.y)
    {
        return true;
    }
    else
    {
        return false;
    } 
}
Position& Position::operator=( Position& other)
{
    this->x = other.x;
    this->y = other.y;
    return *this;
}
bool Position::operator!=(const Position& other)
{
    if( this->x != other.x || this->y != other.y)
    {
        return true;
    }
    else
    {
        return false;
    } 
}
#endif