#include <iostream>
#include "Snake.hpp"

Snake::Snake()
{
    this->p_headpos_snake = NULL;
}

Snake::~Snake()
{
    if (this->p_headpos_snake != NULL)
    {
        delete p_headpos_snake;
        this->p_headpos_snake = NULL;
    }
}

void Snake::genSnake(std::pair<char, char> &target_headpos)
{
    this->p_headpos_snake = new std::pair<char, char>;
    this->len_snake = 1;
    *(this->p_headpos_snake) = target_headpos;
}

std::pair<char, char> *Snake::informSnakeHeadPos(void)
{
    return (this->p_headpos_snake);
}

int Snake::informSnakeLen(void)
{
    return (this->len_snake);
}

void Snake::moveAndGrow(bool b_have2tall, std::pair<char, char> info_futurehead)
{
    std::pair<char, char> *p_future_head;
    if (b_have2tall)
        ++(this->len_snake);
    p_future_head = new std::pair<char, char>[this->len_snake];
    int prev_len = this->len_snake - 1;
    *p_future_head = info_futurehead;
    if (this->len_snake > 1)
    {
        memcpy(p_future_head + 1, p_headpos_snake, sizeof(std::pair<char, char>) * prev_len);
    }
    delete[] this->p_headpos_snake;
    this->p_headpos_snake = p_future_head;
}