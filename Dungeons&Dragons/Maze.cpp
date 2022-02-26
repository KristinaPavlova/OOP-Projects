#ifndef MAZE_CPP
#define MAZE_CPP

#include"Maze.h"
#include"linkedList.h"

void Maze::destroy()
{
    if(this->matrix == nullptr)
    {
        for (int i = 0; i < this->rows; ++i)
        {
            delete[] this->matrix[i];
        }
        delete[] this->matrix;
    }
    this->rows = 0 ;
    this->colums = 0;

}

Maze::Maze()
{
    this->rows = 0 ;
    this->colums = 0;
    this->matrix = nullptr;
}

Maze::~Maze()
{
    this->destroy();
}

bool Maze::isPath( int x_, int y_)
{
    if( x_ >= 0 && x_ < this->rows && y_ >= 0 && y_ < this->colums )
    {
        return true;
    }

    return false;
}

bool Maze::notNeighboar(int x_ , int y_ , LinkedList<Position>& passedPos)
{
    int z , t;
    int size = passedPos.size();
    for(int  i = 0 ; i < size ; ++i)
    {
        z = passedPos[i].data.x;
        t = passedPos[i].data.y;
        if( ( x_ == z-1 && y_== t ) || (x_ == z && y_ == t+1) || ( x_ == z+1 && y_ == t) || (x_ == z && y_ == t-1) )
        {
            return false;
        }
    }
    return true;
}
void Maze::fillCorrectPath()
{

    int x_ , y_;
    srand(time(0));
    int move;
    LinkedList<Position> passedPath;
    Position currentPosition ;
    bool** passed = new bool*[this->rows];
    for(int i = 0 ; i < this->rows ; ++i)
    {
        passed[i] = new bool[this->colums];
    }

    do
    {
        for (int i = 0; i < this->rows; ++i)
        {
            for (int j = 0; j < this->colums; ++j)
            {
                this->matrix[i][j] = 1;
            }
        }

        for (int i = 0; i < this->rows; ++i)
        {
            for (int j = 0; j < this->colums; ++j)
            {
                passed[i][j] = true;
            }
        }
        x_ = 0, y_ = 0;
        passedPath.clear();

        while (x_ != this->rows - 1 || y_ != this->colums - 1)
        {
            
            move = rand() % 4;

            if (move == 0 && isPath(x_, y_ + 1) && passed[x_][y_ + 1] == true && notNeighboar(x_, y_ + 1,passedPath)) //right
            {

                passed[x_][y_] = false;
                currentPosition.x = x_;
                currentPosition.y = y_;
                passedPath.push(currentPosition);
                
                y_++;
                this->matrix[x_][y_] = 0;
                continue;
            }
            else if (move == 1 && isPath(x_ + 1, y_) && passed[x_ + 1][y_] == true && notNeighboar(x_ + 1, y_, passedPath)) //down
            {

                passed[x_][y_] = false;
                currentPosition.x = x_;
                currentPosition.y = y_;
                passedPath.push(currentPosition);
              
                x_++;
                this->matrix[x_][y_] = 0;
                continue;
            }
            else if (move == 2 && isPath(x_, y_ - 1) && passed[x_][y_ - 1] == true && notNeighboar(x_, y_ - 1, passedPath)) // left
            {

                passed[x_][y_] = false;
                currentPosition.x = x_;
                currentPosition.y = y_;
                passedPath.push(currentPosition);
                
                y_--;
                this->matrix[x_][y_] = 0;
                continue;
            }
            else if (move == 3 && isPath(x_ - 1, y_) && passed[x_ - 1][y_] == true && notNeighboar(x_ - 1, y_, passedPath)) // up
            {

                passed[x_][y_] = false;
                currentPosition.x = x_;
                currentPosition.y = y_;
                passedPath.push(currentPosition);
                
                x_--;
                this->matrix[x_][y_] = 0;
                continue;
            }
            else if ((!isPath(x_, y_ + 1) || passed[x_][y_ + 1] == false || !notNeighboar(x_, y_ + 1, passedPath)) && (!isPath(x_ + 1, y_) || passed[x_ + 1][y_] == false || !notNeighboar(x_ + 1, y_, passedPath)) && (!isPath(x_, y_ - 1) || passed[x_][y_ - 1] == false || !notNeighboar(x_, y_ - 1, passedPath)) && (!isPath(x_ - 1, y_) || passed[x_ - 1][y_] == false || !notNeighboar(x_ - 1, y_, passedPath))) //death end
            {

                if(x_ == 0 && y_ == 0)
                {
                    break;
                }
                passed[x_][y_] = false;
                this->matrix[x_][y_] = 0;
                //save current position
                currentPosition.x = x_;
                currentPosition.y = y_;
                
                passedPath.push_back(currentPosition);
                
                x_ = passedPath.first().data.x;
                y_ = passedPath.first().data.y;
                passedPath.pop();
            }
        }
    } while (x_ != this->rows - 1 || y_ != this->colums - 1);


    // drawing  da rest of the maze's area
    while (!(x_ == 0 && y_ == 0))
    {
        move = rand() % 4;

        if (move == 0 && isPath(x_, y_ + 1) && passed[x_][y_ + 1] == true && notNeighboar(x_, y_ + 1, passedPath)) //right
        {

            passed[x_][y_] = false;
            currentPosition.x = x_;
            currentPosition.y = y_;
            passedPath.push(currentPosition);

            y_++;
            this->matrix[x_][y_] = 0;
            continue;
        }
        else if (move == 1 && isPath(x_ + 1, y_) && passed[x_ + 1][y_] == true && notNeighboar(x_ + 1, y_, passedPath)) //down
        {

            passed[x_][y_] = false;
            currentPosition.x = x_;
            currentPosition.y = y_;
            passedPath.push(currentPosition);

            x_++;
            this->matrix[x_][y_] = 0;
            continue;
        }
        else if (move == 2 && isPath(x_, y_ - 1) && passed[x_][y_ - 1] == true && notNeighboar(x_, y_ - 1, passedPath)) // left
        {

            passed[x_][y_] = false;
            currentPosition.x = x_;
            currentPosition.y = y_;
            passedPath.push(currentPosition);

            y_--;
            this->matrix[x_][y_] = 0;
            continue;
        }
        else if (move == 3 && isPath(x_ - 1, y_) && passed[x_ - 1][y_] == true && notNeighboar(x_ - 1, y_, passedPath)) // up
        {

            passed[x_][y_] = false;
            currentPosition.x = x_;
            currentPosition.y = y_;
            passedPath.push(currentPosition);

            x_--;
            this->matrix[x_][y_] = 0;
            continue;
        }
        else if ((!isPath(x_, y_ + 1) || passed[x_][y_ + 1] == false || !notNeighboar(x_, y_ + 1, passedPath)) && (!isPath(x_ + 1, y_) || passed[x_ + 1][y_] == false || !notNeighboar(x_ + 1, y_, passedPath)) && (!isPath(x_, y_ - 1) || passed[x_][y_ - 1] == false || !notNeighboar(x_, y_ - 1, passedPath)) && (!isPath(x_ - 1, y_) || passed[x_ - 1][y_] == false || !notNeighboar(x_ - 1, y_, passedPath))) //death end
        {

            if (x_ == 0 && y_ == 0)
            {
                break;
            }
            passed[x_][y_] = false;
            this->matrix[x_][y_] = 0;
            //save current position
            currentPosition.x = x_;
            currentPosition.y = y_;

            passedPath.push_back(currentPosition);

            x_ = passedPath.first().data.x;
            y_ = passedPath.first().data.y;
            passedPath.pop();
        }
    }
    

    for(int  i = 0 ; i < this->rows ; ++i)
    {
        delete[] passed[i];
    }
    delete[] passed;
}


void Maze::fillMaze(int& numberOfMonsters , int& numberOfTreasures)
{
    // 0 - free , 1  - wall , 2 - monster , 3 - treasure , 4 - hero
    this->fillCorrectPath();
    this->matrix[0][0] = 0;
    this->matrix[this->rows-1][this->colums-1]=0;
    
    srand(time(0));
    
    int x_;
    int y_;
    while(numberOfMonsters)
    {
        x_ = rand()%this->rows;
        y_ = rand()%this->colums;
        if( matrix[x_][y_] == 0 && ( x_!= this->rows-1 || y_ != this->colums-1 ))
        {
            matrix[x_][y_] = 2;
            numberOfMonsters--;
        }
    }
    while(numberOfTreasures)
    {
        x_ = rand()%this->rows;
        y_ = rand()%this->colums;
        if( matrix[x_][y_] == 0 && (  x_!= this->rows-1 || y_ != this->colums-1  ))
        {
            matrix[x_][y_] = 3;
            numberOfTreasures--;
        }
    }
    this->matrix[0][0] = 4;
}

void Maze::createMaze()
{
    this->matrix = new int*[this->rows];
    for(int i =0 ; i< this->rows ; ++i)
    {
        this->matrix[i] = new int[this->colums];
    }
    
}

void Maze::updateMaze(int& level)
{
    this->destroy();
    std::ifstream in("levels.txt");
    
    char row[30];
    int index = 0 ;
    int level_ = level - 1 ;
    while(level_)
    {
        in.getline(row , 29 , '\n');
        level_--;
    }
    in.getline(row , 29 , '\n');
    in.close();
    
    while(row[index] != ' ')
    {
        this->rows*=10;
        this->rows += row[index] - '0';
        index++;
    }
    index++;
     while(row[index] != ' ')
    {
        this->colums*=10;
        this->colums += row[index] - '0';
        index++;
    }
    index++;
    this->createMaze();

    int numberOfMonsters= 0 ;
    while(row[index] != ' ')
    {
        numberOfMonsters*=10;
        numberOfMonsters += row[index]- '0';
        index++;
    }
    index++;
    int numberOfTreasures = 0;
    while(row[index] != '\n' && row[index] != ' ' )
    {
        numberOfTreasures*=10;
        numberOfTreasures += row[index]- '0';
        index++;
    }
    this->fillMaze(numberOfMonsters , numberOfTreasures);
}
void Maze::drawMaze(int& level)
{
    //system("clear");
    std::cout<<std::setw(45)<<"------------------------------"<<std::endl;
    std::cout<<std::setw(34)<<"Level "<<level<<std::endl;
    std::cout<<std::setw(45)<<"------------------------------"<<std::endl;
    for(int i=0 ; i< this->colums+2 ; ++i)
    {
        std::cout<<"\033[1;90m\u2588\033[0m";
    }
    std::cout<<std::endl;

    for( int i = 0 ; i<this->rows ; ++i)
    {
        std::cout<<"\033[1;90m\u2588\033[0m";
        for(int j = 0 ; j<this->colums ; ++j)
        {
            // 0 - free , 1  - wall , 2 - monster , 3 - treasure , 4 - hero 
            if(matrix[i][j] == 0)
            {
                std::cout<<" ";
            }
            else if(matrix[i][j] == 1)
            {
                std::cout<<"\033[1;90m\u2588\033[0m";
            }
            else if(matrix[i][j] == 2)
            {
                std::cout<<"\033[1;31mM\033[0m";
            }
            else if(matrix[i][j] == 3)
            {
                //hidden treasure
                std::cout<<" ";
            }
            else if(matrix[i][j] == 4)
            {
                std::cout<<"\033[1;36mH\033[0m";
            }
            
        }
        std::cout<<"\033[1;90m\u2588\033[0m"<<std::endl;
    }
    
    for(int i=0 ; i< this->colums+2 ; ++i)
    {
        std::cout<<"\033[1;90m\u2588\033[0m";
    }
    std::cout<<std::endl;
}

void Maze::changeValueOfMaze( Position& currentPosition, int value_)
{
    this->matrix[currentPosition.x][currentPosition.y] = value_;
}

bool Maze::correctMove(int& x_ , int& y_)
{
    if( x_>=0 && x_<this->rows && y_>=0 && y_<this->rows && this->matrix[x_][y_] != 1 )
    {
        return true;
    }
    return false;
}

int Maze::getPositionValue(const Position& heroPos)
{
    return this->matrix[heroPos.x][heroPos.y];
}

Position& Maze::getExit() const
{
    Position exit;
    exit.x = this->rows - 1 ;
    exit.y = this->colums - 1;
    Position* ptr = &exit;
    return *ptr;
}
#endif