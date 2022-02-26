#ifndef GAME_CPP
#define GAME_CPP
#include"Game.h"


using uint = unsigned int;

void Game::battle(Hero& myHero, Monster monster) 
{
    
    float originalHealthOfHero = myHero.getHealth();
    float originalHealthOfMonster = monster.getHealth();
    this->printHealth(myHero , originalHealthOfHero , monster , originalHealthOfMonster);
    srand(time(0));
    int order;
    order = rand()%2;

    float MonsterAttack;
    float HeroAttack;
    String heroChoice;

    String brute_force("brute force");
;
    String magic("magic");
    bool correctHeroChoice = false;

    float monsterStrenght = monster.getStrenght();
    float monsterMana = monster.getMana();

    float heroStrenght = myHero.getStrenght();
    float heroMana = myHero.getMana();

    if(order == 0 ) // Monster is first
    {
        std::cout<<"monster attacks first"<<std::endl;
        MonsterAttack = rand()%2;
        if( MonsterAttack == 0) // strenght
        {
           MonsterAttack = monsterStrenght;
           MonsterAttack -= ( (myHero.getArmor()*0.01) * monsterStrenght );
           myHero.decreaseHealth(MonsterAttack);
           this->printHealth(myHero , originalHealthOfHero , monster , originalHealthOfMonster);
            std::cout<<"\n";
           std::cout<<"monster attack with brute force "<<std::endl;
           usleep(2000000);
           if(myHero.isDead())
           {
               return;
           }
        }
        else // mana
        {
            MonsterAttack =monsterMana;
            MonsterAttack -= ( (myHero.getArmor()*0.01) * monsterMana );
            myHero.decreaseHealth(MonsterAttack);
            this->printHealth(myHero , originalHealthOfHero , monster , originalHealthOfMonster);
            std::cout<<"\n";
            std::cout<<"monster attack with magic "<<std::endl;
            usleep(2000000);
            if(myHero.isDead())
           {
               return;
           }
        }
        
    }
    
    while ( myHero.getHealth()!= 0 && monster.getHealth()!=0 )
    {
        do
        {
            //hero attack
            this->printHealth(myHero , originalHealthOfHero , monster , originalHealthOfMonster);
            std::cout<<"\n";
            std::cout << "Attack with ( brute force / magic): ";
            std::cin >> heroChoice;

            if (heroChoice == brute_force) // attack with brute force
            {
                correctHeroChoice = true;
                HeroAttack = heroStrenght;
                HeroAttack += (myHero.getWeapon() * 0.01) * heroStrenght;
                HeroAttack -= (monster.getArmor() * 0.01) * heroStrenght;
                monster.decreaseHealth(HeroAttack);
                std::cout << "\n";
                    this->printHealth(myHero , originalHealthOfHero , monster , originalHealthOfMonster);

                usleep(2000000);
                if (monster.isDead())
                {
                    break;
                }
            }
            else if (heroChoice == magic) // attack with magic
            {
                correctHeroChoice = true;
                HeroAttack = heroMana;
                HeroAttack += (myHero.getSpell() * 0.01) * heroMana;
                HeroAttack -= (monster.getArmor() * 0.01) * heroMana;
                monster.decreaseHealth(HeroAttack);
                    this->printHealth(myHero , originalHealthOfHero , monster , originalHealthOfMonster);

                usleep(2000000);
                if (monster.isDead())
                {
                    break;
                }
            }
            else
            {
                std::cout << "incorrect choice for attack" << std::endl;
                std::cout << std::endl;
                usleep(2000000);
                heroChoice.clear();
                std::cin.ignore();
            }
        } while (correctHeroChoice == false);

        heroChoice.clear();
        correctHeroChoice = false;
        if (monster.isDead())
        {
            break;
        }

        //attack of monster
        MonsterAttack = rand()%2;
        //this->printHealth(myHero, originalHealthOfHero, monster, originalHealthOfMonster);

        if( MonsterAttack == 0) // strenght
        {
            
           MonsterAttack = monsterStrenght;
           MonsterAttack -= ( (myHero.getArmor()*0.01) * monsterStrenght );
           myHero.decreaseHealth(MonsterAttack);
               this->printHealth(myHero , originalHealthOfHero , monster , originalHealthOfMonster);
             std::cout<<"\n";
           std::cout<<"monster attack with brute force "<<std::endl;
           usleep(2000000);
        }
        else // mana
        {
            
            MonsterAttack =monsterMana;
            MonsterAttack -= ( (myHero.getArmor()*0.01) * monsterMana );
            myHero.decreaseHealth(MonsterAttack);
                this->printHealth(myHero , originalHealthOfHero , monster , originalHealthOfMonster);
            std::cout<<"\n";
            std::cout<<"monster attack with magic "<<std::endl;
            usleep(2000000);
        }
    }
    this->printHealth(myHero, originalHealthOfHero, monster, originalHealthOfMonster);


    if(myHero.isDead() == false)
    {
        if( myHero.getHealth() < (originalHealthOfHero/2))
        {
           
            myHero.setHealth(originalHealthOfHero/2); 
            std::cout<<"your strenght now is : "<<myHero.getHealth()<<std::endl;
            usleep(2000000);
            return;
        }
    }
    usleep(2000000);
    return ;
    
}
void Game::printHealth(Hero& myHero , float startedHealthH , Monster& monster , float startedHealthM)
{
    system("clear");
    std::cout<<std::setw(45)<<"------------------------------"<<std::endl;
    std::cout<<std::setw(34)<<"    Battle "<<std::endl;
    std::cout<<std::setw(45)<<"------------------------------"<<std::endl;
    std::cout<<"\n"<<"Your health ("<<myHero.getHealth()<<"): ";
    float value = 0.0;
    float currentHealthH = myHero.getHealth();
    std::cout<<"|";
    while (value < currentHealthH)
    {
        std::cout<<"\033[1;31m\u2588\033[0m";
        value += startedHealthH*0.05;
    }
    
    if( value >= startedHealthH )
    {
        std::cout<<"|"<<std::endl;
        //return;
    }
    else
    {
        while (value < startedHealthH)
        {
            std::cout << " ";
            value += startedHealthH * 0.05;

        }
        std::cout<<"|"<<std::endl;
        //return;
    }

    std::cout<<"\n"<<"Monster health ("<<monster.getHealth()<<"): ";
    value = 0.0;
    float currentHealthM = monster.getHealth();
    std::cout<<"|";
    while (value < currentHealthM)
    {
        std::cout<<"\033[1;31m\u2588\033[0m";
        value += startedHealthM*0.05;
    }
    
    if( value >= startedHealthM )
    {
        std::cout<<"|"<<std::endl;
        
    }
    else
    {
        while (value < startedHealthM)
        {
            std::cout << " ";
            value += startedHealthM * 0.05;

        }
        std::cout<<"|"<<std::endl;
        
    }
    
    
}
void Game::wonBattle(Hero& myHero , int& level)
{
    srand(time(0));
    float features;
    features = level*10;
    std::cout<<"You won "<<features<<" points"<<std::endl;
    std::cout<<"set them to (health , strenght , mana): ";
    String choice;
    std::cin>>choice;
    if(choice == "health")
    {
        myHero.increaseHealth(features);
    }
    else if(choice == "strenght")
    {
        myHero.increaseStrength(features);
    }
    else if(choice == "mana")
    {
        myHero.increaseMana(features);
        
    }
    else
    {
        std::cout<<"unvalid choice"<<std::endl;

    }    

}
void Game::foundTreasure(Hero& myHero , int& level)
{
    std::cout<<"\033[103m\033[3m\033[30mYOU FOUND TREASURE\033[0m"<<std::endl;
    srand(time(0));
    int treasure;
    treasure = rand()%3;
    bool correctChoice = false;
    String choice;
    String take_("take");
    String leave_("leave");
   
    if( treasure == 0) //weapon
    {
        std::cout<<"weapon! (take / leave)"<<std::endl;
        //std::cin.ignore();
        do
        {
            std::cin >> choice;
            if (choice == "take")
            {
                correctChoice = true;
                std::cout << "your brute force attack increased with 5%" << std::endl;
                myHero.increaseWeapon(level);
                usleep(1500000);
            }
            else if (choice == "leave")
            {
                return;
            }
            else
            {
                choice.clear();
                std::cout << "\n";
                std::cout << "incorrect choice" << std::endl;
                std::cin.ignore();
                std::cout << "\n"
                          << "enter choice : ";
            }
        } while (!correctChoice);
        
    }
    else if( treasure == 1 ) // spell
    {
        std::cout << "spell! (take / leave)" << std::endl;
        //std::cin.ignore();
        do
        {
            std::cin >> choice;
            if (choice == "take")
            {
                correctChoice = true;
                std::cout << "your magicattack increased with 5%" << std::endl;
                myHero.increaseSpell(level);
                usleep(1500000);
            }
            else if (choice == "leave")
            {
                return;
            }
            else
            {
                choice.clear();
                std::cout << "\n";
                std::cout << "incorrect choice" << std::endl;
                std::cin.ignore();
                std::cout << "\n"
                          << "enter choice : ";
            }
        } while (!correctChoice);
    }
    else // armor
    {
        std::cout<<"armor! (take / leave)"<<std::endl;
        //std::cin.ignore();
        do
        {
            std::cin >> choice;
            if (choice == "take")
            {
                correctChoice = true;
                std::cout << "your armor  increased with 5%" << std::endl;
                myHero.increaseArmor(level);
                usleep(1500000);
            }
            else if (choice == "leave")
            {
                return;
            }
            else
            {
                choice.clear();
                std::cout << "\n";
                std::cout << "incorrect choice" << std::endl;
                std::cin.ignore();
                std::cout << "\n"
                          << "enter choice : ";
            }
        } while (!correctChoice);
    }
    
}

void Game::start(Hero& myHero , Monster monster , int& lev )
{
    system("clear");
    Maze lab;
    lab.updateMaze(lev);
    lab.drawMaze(lev);
    
    Position exit_ = lab.getExit();

    int PositionValue;
    do
    {
        PositionValue = myHero.Move(lab);
        std::cin.ignore();
    } while (PositionValue == 9); // 9 is for incorrect move

    do
    {
        if(PositionValue == 2)
        {
            this->battle(myHero , monster);
            if(myHero.isDead())
            {
                usleep(1000000);
                system("clear");
                std::cout << " GAME OVER " << std::endl;
                usleep(1000000);
                return ;
            }
            else
            {
                std::cout<<std::setw(25)<<"YOU WON THE BATTLE"<<std::endl;
                this->wonBattle(myHero , lev);
                usleep(2000000);
            }
            //std::cin.ignore();
        }
        else if(PositionValue == 3)
        {
            this->foundTreasure(myHero , lev);
            //std::cin.ignore();
        }
        system("clear");
        lab.drawMaze(lev);
        
        do
        {
            PositionValue = myHero.Move(lab);
            std::cin.ignore();
        } while (PositionValue == 9);

    } while ( myHero.getPosition() != exit_);

}
bool Game::enterUser(String& userName , String& password ,Hero& myHero , Monster& monster , int& level)
{
    int choice;
    std::cout << std::setw(45) << "------------------------------" << std::endl;
    std::cout << std::setw(24) <<"⚒️"<< "\033[1;31m Dungeons & Dragons \033[0m"<<"⚒️"<< std::endl;
    std::cout << std::setw(45) << "------------------------------" << std::endl;
    std::cout << std::setw(25) << "1. Sign up" << std::endl;
    std::cout << std::setw(24) << "2. Log in" << std::endl;
    std::cout << std::setw(27) << "enter choice: ";
    std::cin>>choice;
    String playerName;
    String playerPassword;
    bool correctPass = false;
    bool correctUserName = false;
    uint rase_;
    float value;
    double d_value;
    int level_;
    
    std::cin.ignore();
    if(choice == 1)
    {
        std::cout<<"Enter name: ";
        std::cin>>playerName;
        std::ifstream input("users.txt");
        char row[30];
        while (!input.eof())
        {
            input.getline(row, 20, '\n');
            if (playerName == row)
            {
                correctUserName = true;
                input.getline(row, 20, '\n');
                std::cout<<"Enter password: ";
                std::cin>>playerPassword;
                do
                {
                    if (playerPassword == row)
                    {
                        std::cout << "YES" << std::endl;
                        correctPass = true;
                        input>>rase_;
                        myHero.setRase(rase_);
                        input>>value;
                        myHero.setHealth(value);
                        input>>value;
                        myHero.setStrenght(value);
                        input>>value;
                        myHero.setMana(value);
                        input>>d_value;
                        myHero.setArmor(d_value);
                        input>>d_value;
                        myHero.setSpell(d_value);
                        input>>d_value;
                        myHero.seWeapon(d_value);
                        input>>level_;
                        level = level_;
                        monster.constructOnLevel(level);
                        break;
                    }
                    else
                    {
                        std::cout << "incorrect Password" << std::endl;
                        playerPassword.clear();
                        std::cout << "Enter password: ";
                        std::cin >> playerPassword;
                    }
                } while (correctPass == false);

            }
            
            
        }
        input.close();
        if(correctUserName)
        {
            userName = playerName;
            password = playerPassword;
            usleep(100000);
            system("clear");
            return true;
        }

        std::cout << "\033[1;31m    NO SUCH USERNAME!\033[0m" << std::endl;
        usleep(2000000);
        system("clear");
        return false;
    }
    
    else if(choice == 2)
    {
        // system("clear");
        std::cout<<"Enter username : ";
        std::cin>>userName;
        std::cout<<"Enter password : ";
        std::cin>>password;
        std::cin >> myHero;
        usleep(100000);
        system("clear");
        return true;
    }
    else
    {
        std::cout<<"\033[1;31m    INCORRECT CHOICE!\033[0m"<<std::endl;
        usleep(2000000);
        system("clear");
        return false;
    }
    

}
void Game::saveUser(Hero& myHero  , int& level , String& username , String& password)
{
    bool existUser = false;
    std::ifstream input("users.txt");
    std::ofstream output("newUsers.txt");
    char row[30];
    while (!input.eof())
    {
        input.getline(row, 20, '\n');
        if (username == row)
        {
            existUser = true;
            output << row << "\n"
                   << password
                   << myHero.getRace() << "\n"
                   << myHero.getHealth() << "\n"
                   << myHero.getStrenght() << "\n"
                   << myHero.getMana() << "\n"
                   << myHero.getArmor() << "\n"
                   << myHero.getSpell() << "\n"
                   << myHero.getWeapon() << "\n"
                   << level << "\n";
            for (int i = 0; i < 9; ++i)
            {
                input.getline(row, 20, '\n');
            }
        }
        else
        {
            output<<row;
            output<<"\n";
        }
        
    }
    if(!existUser)
    {
        output << username
                   << password << "\n"
                   << myHero.getRace() << "\n"
                   << myHero.getHealth() << "\n"
                   << myHero.getStrenght() << "\n"
                   << myHero.getMana() << "\n"
                   << myHero.getArmor() << "\n"
                   << myHero.getSpell() << "\n"
                   << myHero.getWeapon() << "\n"
                   << level << "\n";
    }
    std::remove("users.txt");
    input.close();
    output.close();
    int result = std::rename("newUsers.txt", "users.txt") ;
    if(result == 0)
    {
        std::cout<<"all files are successfully saved"<<std::endl;
    }
    else
    {
        std::cout<<"something went wrong"<<std::endl;
    }
}
void Game::deleteUser(String& username , String& password)
{
    std::ifstream input("users.txt");
    std::ofstream output("newUsers.txt");
    char row[30];
    while (!input.eof())
    {
        input.getline(row, 20, '\n');
        if (username == row)
        {
            for (int i = 0; i < 9; ++i)
            {
                input.getline(row, 20, '\n');
            }
        }
        else
        {
            output<<row;
            output<<"\n";
        }
        
    }
    std::remove("users.txt");
    input.close();
    output.close();
    int result = std::rename("newUsers.txt", "users.txt") ;
    if(result == 0)
    {
        std::cout<<"all files are successfully saved"<<std::endl;
    }
    else
    {
        std::cout<<"something went wrong"<<std::endl;
    }
}
void Game::menu()
{
    Hero myHero;
    Monster monster;
    int level = 1;
    int mArmor = 5;
    int points , sumOfPoints = 0;
    String username;
    String password;
    
    bool insertUser;
    do
    {
        insertUser = this->enterUser(username , password , myHero , monster, level);
        
    } while (insertUser == false);

    std::cout<<myHero<<std::endl;
    usleep(2000000);
    system("clear");
    std::cout << std::setw(45) << "------------------------------" << std::endl;
    std::cout << std::setw(24) <<"⚔️"<< "\033[1;31m  Dungeons & Dragons \033[0m" <<"⚔️"<< std::endl;
    std::cout << std::setw(45) << "------------------------------" << std::endl;
    std::cout << std::setw(25) << "1. Start game" << std::endl;
    std::cout << std::setw(19) << "2. Exit" << std::endl;
    std::cout << std::setw(20) << "enter choice: ";

    int choice ;
    std::cin >> choice;
    std::cin.ignore();
    if (choice == 2)
    {
        system("clear");
        std::cout << "EXIT THE GAME" << std::endl;
        return;
    }

    String saveToFile;

    do
    {
        if (choice == 1)
        {
            this->start(myHero, monster, level);
            if (myHero.isDead())
            {
                std::cout<<"do you want to save your youres(Yes/No):"<<std::endl;
                std::cin>>saveToFile;
                break;
            }
        }
        else
        {
            system("clear");
            std::cout << "EXIT THE GAME" << std::endl;
            break;
        }
        usleep(1000000);
        system("clear");
        std::cout<<"COMPLETE LEVEL!"<<std::endl;
        usleep(1000000);
        std::cout<<monster.getArmor()<<std::endl;
        std::cout<<monster.getHealth()<<std::endl;
        std::cout<<monster.getStrenght()<<std::endl;
        std::cout<<monster.getMana()<<std::endl;
        std::cout<<monster.getPosition()<<std::endl;
        system("clear");
        myHero.restartPosition();
        level++;
        points = 0;
        sumOfPoints = 0;

        std::cout << "you receive 30 points" << std::endl;
        std::cout << "how much you will set to you health: ";
        std::cin >> points;
        myHero.increaseHealth(points);
        sumOfPoints += points;
        if (sumOfPoints < 30)
        {
            std::cout << "how much you will set to you strenght: ";
            std::cin >> points;
            myHero.increaseStrength(points);
            sumOfPoints += points;
        }
        if (sumOfPoints < 30)
        {
            std::cout << "how much you will set to you mana: ";
            std::cin >> points;
            myHero.increaseMana(points);
            sumOfPoints += points;
        }
        system("clear");
        std::cout<<std::endl;
        std::cout << std::setw(25) << "1. Go to next level" << std::endl;
        std::cout << std::setw(13) << "2. Exit" << std::endl;
        std::cout << std::setw(20) << "enter choice: ";
        std::cin >> choice;
        
        if (choice == 1)
        {
            std::cout << myHero;
            std::cin.ignore();
            monster.increaseStrength(10);
            monster.increaseMana(10);
            monster.increaseHealth(10);
            monster.increaseArmor(mArmor);
            std::cout << std::endl;
        }
        else
        {
            this->saveUser(myHero, level, username, password);
            system("clear");
            std::cout << "EXIT THE GAME" << std::endl;
            return;
        }

    } while (level<7);

    if(saveToFile == "Yes")
    {
        myHero.constructOnChosenRace();
        level = 1;
        this->saveUser(myHero , level , username , password);
    }
    else
    {
        this->deleteUser(username , password);
        std::cout<<"DELETED USER"<<std::endl;
    }
    

}

#endif