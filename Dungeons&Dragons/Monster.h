#ifndef MONSTER_H
#define MONSTER_H
#include<iostream>
#include"Character.h"

using uint = unsigned int;
class Monster: public Character
{
    private:
    double armor;

    public:
    Monster();
    Monster(const Monster&);
    void constructOnLevel(int);
    Monster& operator=(const Monster&);
    double getArmor() const;
    void increaseArmor(int&);
    
};
#endif