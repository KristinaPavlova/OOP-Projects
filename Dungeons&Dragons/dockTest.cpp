#include<iostream>
#include"string.h"
#include"Position.h"
#include"Character.h"
#include"Hero.h"
#include"Monster.h"
#include"Maze.h"
#include <stdlib.h>  //srand rand
#include <time.h> //time
#include<fstream>
#include<iomanip>
#include<stdlib.h>
#include"linkedList.h"
#include"Game.h"
#include"Game.cpp"


#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"


//string
TEST_CASE("lenght")
{
    String myStr("ko");
    CHECK(myStr.lenght()==2);
}
TEST_CASE("push_back & pop_back")
{
    String myStr("ko");
    myStr.push_back('k');
    CHECK(myStr.lenght()==3);
    myStr.pop_back();
    CHECK(myStr.lenght()==2);
}
//position
TEST_CASE("operator == & operator !=")
{
    Position pos1 , pos2;
    pos1.x = 1;
    pos1.y = 1;
    pos2.x = 1;
    pos2.y = 1;
    CHECK(pos1 == pos2);
    pos2.x = 1;
    pos2.y = 2;
    CHECK(pos1 != pos2);
}
//Llist
TEST_CASE("list")
{
    LinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    CHECK(list.size() == 6);
    list.pop_back();
    CHECK(list.size() == 5);
    Box<int> lastElem = list.last();
    CHECK(lastElem.data == 5);
    Box<int> firstElem = list.first();
    CHECK(firstElem.data == 1);
}
//hero
TEST_CASE("hero construction")
{
    unsigned int rase = 0;
    Hero myHero;
    myHero.setRase(rase);
    myHero.constructOnChosenRace();
    //human features
    CHECK(myHero.getHealth() == 50.0f);
    CHECK(myHero.getMana() == 20.0f);
    CHECK(myHero.getStrenght() == 30.0f);
    // magician features
    rase = 1;
    myHero.setRase(rase);
    myHero.constructOnChosenRace();
    CHECK(myHero.getHealth() == 50.0f);
    CHECK(myHero.getMana() == 40.0f);
    CHECK(myHero.getStrenght() == 10.0f);
    // warrior features
    rase = 2;
    myHero.setRase(rase);
    myHero.constructOnChosenRace();
    CHECK(myHero.getHealth() == 50.0f);
    CHECK(myHero.getMana() == 10.0f);
    CHECK(myHero.getStrenght() == 40.0f);
    
}

int main()
{

    doctest::Context().run();

   

    return 0;
}