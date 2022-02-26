#ifndef CHARACTER_CPP
#define CHARACTER_CPP
#include"Character.h"

Character::Character()
{
    this->strenght = 0;
    this->mana = 0;
    this->health = 0;
    this->parPosition.x = 0;
    this->parPosition.y = 0;
}
Character::Character(float strenght_, float mana_, float health_, int x_, int y_):strenght(strenght_) , mana(mana_) , health(health_) 
{
    this->parPosition.x = x_;
    this->parPosition.y = y_;
}
void Character::setStrenght(float strenght_)
{
    this->strenght = strenght_;
}
void Character::setMana(float mana_)
{
    this->mana = mana_;
}
void Character::setHealth(float health_)
{
    this->health = health_;
}
void Character::setPosition(uint x_ , uint y_)
{
    this->parPosition.x = x_;
    this->parPosition.y = y_;
}
void Character::changePosition(int x_ , int y_)
{
    this->parPosition.x += x_;
    this->parPosition.y += y_;
}
float Character::getStrenght() const
{
    return this->strenght;
}
float Character::getMana() const
{
    return this->mana;
}
float Character::getHealth() const
{
    return this->health;
}
Position& Character::getPosition() 
{
    return this->parPosition;
}

void Character::increaseHealth(float add)
{
    this->health += add;
}
void Character::increaseMana(float add)
{
    this->mana += add; 
}
void Character::increaseStrength(float add)
{
    this->strenght += add; 
}
void Character::decreaseHealth(float& hit)
{
    if(hit > this->health)
    {
        //for testing
        //std::cout<<"yes"<<std::endl;
        this->health = 0;
    }
    else
    {
        this->health -= hit;
    }

}

bool Character::isDead() 
{
    if(this->health == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
#endif