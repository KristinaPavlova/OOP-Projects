#ifndef HERO_CPP
#define HERO_CPP

#include "Hero.h"


using uint = unsigned int;

Hero :: Hero():Character() , armor(0) , weapon(0) , spell(0)
{
    this->heroRace = human;
}

void Hero::constructOnChosenRace()
{
    switch (this->heroRace)
    {
        case human :

            this->setStrenght(30);
            this->setMana(20);
            this->setHealth(50);
            break;
        case magician :
  
            this->setStrenght(10);
            this->setMana(40);
            this->setHealth(50);
            break;
        case warrior :
            this->setStrenght(40);
            this->setMana(10);
            this->setHealth(50);
            break;
    }
    this->weapon = 20;
    this->spell = 20;
   
}
//not shure if I need it
void Hero::printRase()
{
    switch (this->heroRace)
    {
        case human: 
            std::cout<<"human"<<std::endl;
            break;
        case magician:
            std::cout<<"magician"<<std::endl;
            break;
        case warrior:
            std::cout<<"warrior"<<std::endl;
            break;
        default : std::cout<<"still doesn't have any rase"<<std::endl;
    
    }
}
void Hero::setRase(uint& rase)
{
    switch (rase)
    {
        case 0: this->heroRace = human;
            break;
        case 1: this->heroRace = magician;
            break;
        case 2: this->heroRace = warrior;
            break;
    }

}

void Hero::setArmor(double& value)
{
    this->armor = value;
}

void Hero::seWeapon(double& value)
{
    this->weapon = value;
}

void Hero::setSpell(double& value)
{
    this->spell = value;
}

int Hero::getRace()
{
    return this->heroRace;
}
double Hero::getArmor()
{
    return this->armor;
}
double Hero::getWeapon() const
{
    return this->weapon;
}
double Hero::getSpell() const
{
    return this->spell;
}
void Hero::increaseArmor(int& level)
{
    this->armor += 5*level;
}
void Hero::increaseWeapon(int& level)
{
    this->weapon += 5*level;
}
void Hero::increaseSpell(int& level)
{
    this->spell += 5*level;
}
int Hero::Move( Maze& maze )
{
    char symbol[10];
    // 0 - free , 1  - wall , 2 - monster , 3 - treasure , 4 - hero

    int x_ = this->parPosition.x;
    int y_ = this->parPosition.y;
    int PositionValue;
    int wrongPos = 9;
  
        //std::cin.ignore();
        std::cout << "enter move: " << std::endl;
        std::cin.get(symbol, 9);
        // up
        if (symbol[2] == 'A')
        {
            x_ -= 1;
            if (maze.correctMove(x_, y_))
            {
                maze.changeValueOfMaze(this->parPosition, 0);
                this->changePosition(-1, 0);
                PositionValue = maze.getPositionValue(this->parPosition);
                maze.changeValueOfMaze(this->parPosition, 4);
                

                return PositionValue;
            }
            else
            {
                std::cout << "incorrect move" << std::endl;
                return wrongPos;
            }
        }
        // down
        else if (symbol[2] == 'B')
        {
            x_ += 1;
            if (maze.correctMove(x_, y_))
            {
                maze.changeValueOfMaze(this->parPosition, 0);
                this->changePosition(1, 0);
                PositionValue = maze.getPositionValue(this->parPosition);
                maze.changeValueOfMaze(this->parPosition, 4);
                

                return PositionValue;
            }
            else
            {
                std::cout << "incorrect move" << std::endl;
                return wrongPos;
            }
        }
        // right
        else if (symbol[2] == 'C')
        {
            y_ += 1;
            if (maze.correctMove(x_, y_))
            {
                maze.changeValueOfMaze(this->parPosition, 0);
                this->changePosition(0, 1);
                PositionValue = maze.getPositionValue(this->parPosition);
                maze.changeValueOfMaze(this->parPosition, 4);
                

                return PositionValue;
            }
            else
            {
                std::cout << "incorrect move" << std::endl;
                return wrongPos;
            }
        }
        // left
        else if (symbol[2] == 'D')
        {
            y_ -= 1;
            if (maze.correctMove(x_, y_))
            {
                maze.changeValueOfMaze(this->parPosition, 0);
                this->changePosition(0, -1);
                PositionValue = maze.getPositionValue(this->parPosition);
                maze.changeValueOfMaze(this->parPosition, 4);
                

                return PositionValue;
            }
            else
            {
                std::cout << "incorrect move" << std::endl;
                return wrongPos;
            }
        }
        else
        {
            std::cout << "incorrect move" << std::endl;
            return wrongPos;
        }
   

    
    
}
void Hero::restartPosition()
{
    this->setPosition(0 , 0);
}
std::istream& operator>> (std::istream& in, Hero& myHero )
{
    std::cout<<"Enter your hero's race : ( human , magician , warrior)"<<std::endl;
    String human_("human");
    String magician_("magician");
    String warrior_("warrior");
    String chosenRase;
   bool correctRase = false;
    do
    {
        std::cout << "enter race:" << std::endl;
        std::cin >> chosenRase;
        std::cout<<chosenRase;
        if (chosenRase == human_)
        {
            myHero.heroRace = Race::human;
            myHero.constructOnChosenRace();
            std::cout<<std::endl;
            correctRase = true;
            break;
            
        }
        else if (chosenRase == magician_)
        {
            myHero.heroRace = Race::magician;
            myHero.constructOnChosenRace();
            std::cout<<std::endl;
            correctRase = true;
            break;
        }
        else if (chosenRase == warrior_)
        {
            myHero.heroRace = Race::warrior;
            myHero.constructOnChosenRace();
            std::cout<<std::endl;
            correctRase = true;
            break;
            
        }
        else
        {
            std::cout << "unvalid rase" << std::endl;
        }
        chosenRase.clear();
    } while (correctRase == false);
    return in;

    
}
std::ostream& operator<< (std::ostream& out, Hero& myHero)
{

    out<<"your hero is - ";
    myHero.printRase();
    out<<"health- "<<myHero.getHealth()<<std::endl;
    out<<"strength- "<<myHero.getStrenght()<<std::endl;
    out<<"mana- "<<myHero.getMana()<<std::endl;
    out<<"weapon- "<<myHero.weapon<<"%"<<std::endl;
    out<<"armor- "<<myHero.armor<<"%"<<std::endl;
    out<<"spell- "<<myHero.spell<<"%"<<std::endl;

    out<<"your hero position: ";
    out<<myHero.getPosition()<<std::endl;
    return out;
}
#endif
