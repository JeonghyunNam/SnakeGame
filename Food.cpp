#include <iostream>
#include "Food.hpp"

Food::Food()
{
    this->p_snake = NULL;
    this->len_snake = 0;
}

Food::~Food()
{
}
void Food::updateSnakeInfo(std::pair<char, char> *p_snakehead, int &len)
{
    this->p_snake = p_snakehead;
    this->len_snake = len;
}

std::pair<char, char> Food::informFood()
{
    return this->food;
}

void Food::genFood(void)
{
    bool isRepeat = true;
    while (isRepeat)
    {
        (this->food).first = 2 * (rand() % 28 + 1);
        (this->food).second = rand() % 28 + 1;
        for (int i = 0; i < len_snake; i++)
        {
            if (this->food.first == (this->p_snake + i)->first && this->food.second == (this->p_snake + i)->second)
            {
                isRepeat = true;
                break;
            }
            isRepeat = false;
        }
    }
}