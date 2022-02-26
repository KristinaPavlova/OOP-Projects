#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>
#include"card.h"
#include<iostream>
#include"player.h"
#include<fstream>
#include<cstdio>
#include<iomanip>
#include<cstring>
struct fractionalNumber
{
    //if you win
    int numerator;
    //game
    int denominator;

};

class Player
{
    private:

    char* name;
    int age;
    size_t wins;
    fractionalNumber winsOfGames;
    size_t points;

    
    void destroy();
    void copy( Player& );

    public:
    //constructors
    Player();
    Player(Player&)  ;
    Player& operator=(Player&) ;
    ~Player();
    int& lenghtOfName();
    size_t& getPoints();
    void calculatePoints(Card&);
    void increaseWins();
    void increaseGames();

    friend std::istream& operator>>(std::istream& in, Player&);

};
#endif