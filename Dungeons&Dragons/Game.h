#ifndef GAME_H
#define GAME_H
#include"Position.h"
#include"Character.h"
#include"Maze.h"
#include"Race.h"
#include"Hero.h"
#include"Monster.h"
#include"string.h"
#include<iomanip>
#include<iostream>
#include <stdlib.h>  //srand rand
#include <time.h> //time

#include <unistd.h> // for usleep
#include <stdlib.h>
#include <stdio.h>

class Game
{
    public:
    void start(Hero&  , Monster  , int&  );
    void wonBattle(Hero& , int&);
    void printHealth(Hero& , float , Monster& , float );
    void battle(Hero& , Monster) ; // take a copy of a monster to save the original one after the battle
    void foundTreasure(Hero& , int&);
    bool enterUser(String& , String& ,Hero& , Monster& , int&);
    void saveUser(Hero& , int& , String& , String&);
    void deleteUser(String& , String&);
    void menu();
};

#endif