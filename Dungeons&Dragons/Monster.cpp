#ifndef MONSTER_CPP
#define MONSTER_CPP

#include"Monster.h"

Monster::Monster():Character()
{
    this->setStrenght(25);
    this->setMana(25);
    this->setHealth(50);
    this->armor = 15;
}

Monster::Monster(const Monster& other)
{
    this->setStrenght(other.getStrenght());
    this->setMana(other.getMana());
    this->setHealth(other.getHealth());
    this->armor = other.getArmor();
}
void Monster::constructOnLevel(int level)
{
    int mArmor = 5;
    level-=1;
    while(level)
    {
        this->increaseStrength(10);
        this->increaseMana(10);
        this->increaseHealth(10);
        this->increaseArmor(mArmor);
        level--;
    }
}
Monster& Monster::operator=(const Monster& other)
{
    if(this != &other)
    {
        this->setStrenght(other.getStrenght());
        this->setMana(other.getMana());
        this->setHealth(other.getHealth());
        this->armor = other.getArmor();
    }
    return *this;
}

double Monster::getArmor() const
{
    return this->armor;
}

void Monster::increaseArmor(int& level)
{
    this->armor +=  level;
}
#endif