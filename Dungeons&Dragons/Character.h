#ifndef CHARACTER_H
#define CHARACTER_H
#include<iostream>
#include"Position.h"

using uint = unsigned int;
// heros and monsters are Characters in the game
class Character
{
    protected:

    float strenght;
    float mana;
    float health;
    Position parPosition;
    
    public:
    Character();
    Character(float , float , float , int , int);
    //setters
    void setStrenght(float);
    void setMana(float);
    void setHealth(float);
    void setPosition(uint , uint);
    //when Character move
    void changePosition(int , int);

    //getters
    float getStrenght() const;
    float getMana() const;
    float getHealth() const;
    Position& getPosition() ;
    virtual void increaseArmor(int&) = 0;

    void increaseHealth(float);
    void increaseMana(float);
    void increaseStrength(float);

    void decreaseHealth(float&);
    bool isDead();
    
};
#endif