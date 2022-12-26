#include <iostream>
#include "Referee.hpp"

Referee::Referee()
{
}

Referee::~Referee()
{
}

void Referee::getSnake(std::pair<char, char> *p_snake, int &len)
{
    this->infoSnake = p_snake;
    this->snakelen = len;
}

void Referee::getFood(std::pair<char, char> food)
{
    this->infoFood = food;
}

float Referee::adjustSpeed(int &score)
{
    return ((int)(score / 30) + 1);
}

bool Referee::contactFood(std::pair<char, char> &future_snake_head)
{
    if (future_snake_head.first == (this->infoFood).first && future_snake_head.second == (this->infoFood).second)
    {
        return true;
    }
    return false;
}

bool Referee::meetWall(std::pair<char, char> &snakehead)
{
    if (snakehead.first == 0 || snakehead.first == 58)
        return true;
    if (snakehead.second == 0 || snakehead.second == 29)
        return true;
    return false;
}

bool Referee::selfIntersect(std::pair<char, char> &future_head)
{
    std::pair<char, char> *cur_snake = this->infoSnake;
    for (int i = 1; i < snakelen; i++)
    {
        if (future_head.first == (cur_snake + i)->first && future_head.second == (cur_snake + i)->second)
        {
            return true;
        }
    }
    return false;
}

bool Referee::isTerminate()
{

    if (this->meetWall(*(this->infoSnake)))
        return true;
    if (this->selfIntersect(*(this->infoSnake)))
        return true;

    return false;
}