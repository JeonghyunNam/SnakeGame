#include <iostream>
#include "../include/Referee.h"

Referee::Referee()
{
}

Referee::~Referee()
{
}

void Referee::getSnake(std::pair<char, char> *p_snake, int &len)
{
    this->p_snake = p_snake;
    this->snake_len = len;
}

void Referee::getFood(std::pair<char, char> food)
{
    this->p_food = food;
}

int Referee::adjustSpeed(int score)
{
    return (int)(score / 30);
}

bool Referee::checkFoodContact(std::pair<char, char> &future_snake_head)
{
    if (future_snake_head.first == (this->p_food).first && future_snake_head.second == (this->p_food).second)
    {
        return true;
    }
    return false;
}

bool Referee::checkMeetWall(std::pair<char, char> &snakehead)
{
    if (snakehead.first == 0 || snakehead.first == 58)
        return true;
    if (snakehead.second == 0 || snakehead.second == 29)
        return true;
    return false;
}

bool Referee::checkSelfIntersect(std::pair<char, char> &future_head)
{
    std::pair<char, char> *cur_snake = this->p_snake;
    for (int i = 1; i < snake_len; i++)
    {
        if (future_head.first == (cur_snake + i)->first && future_head.second == (cur_snake + i)->second)
        {
            return true;
        }
    }
    return false;
}

bool Referee::checkTerminate()
{

    if (this->checkMeetWall(*(this->p_snake)))
        return true;
    if (this->checkSelfIntersect(*(this->p_snake)))
        return true;

    return false;
}