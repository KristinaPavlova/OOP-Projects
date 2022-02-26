#ifndef HERO_H
#define HERO_H
#include"Position.h"
#include"Character.h"
#include"Maze.h"
#include"Race.h"
#include<iostream>
#include "Hero.h"
#include<cstring>
#include<cmath>
#include"string.h"
#include <unistd.h>

using uint = unsigned int;

class Hero: public Character
{
   private:

    Race heroRace;

    double armor ; 
    double weapon ; 
    double spell ;
    
    public:

    Hero();
    void constructOnChosenRace();
    void printRase();
    void setRase(uint&);
    void setArmor(double&);
    void seWeapon(double&);
    void setSpell(double&);
    int getRace();
    double getArmor();
    double getWeapon()const;
    double getSpell()const;
    void increaseArmor(int&);
    void increaseWeapon(int&);
    void increaseSpell(int&);
    int Move(Maze&);
    void restartPosition();
    friend std::istream& operator>> (std::istream& in, Hero& );
    friend std::ostream& operator<< (std::ostream& out, Hero& );
    
};
#endif