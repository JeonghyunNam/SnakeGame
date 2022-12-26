#include <iostream>
#include "Snake.hpp"

Snake::Snake()
{
    this->_head = NULL;
}

Snake::~Snake()
{
    if (this->_head != NULL)
    {
        delete _head;
        this->_head = NULL;
    }
}

void Snake::Init(std::pair<char, char> &headpos)
{
    this->_head = new std::pair<char, char>;
    this->_len = 1;
    *(this->_head) = headpos;
}

std::pair<char, char> *Snake::InformHead(void)
{
    return (this->_head);
}

int Snake::InformLen(void)
{
    return (this->_len);
}

void Snake::Move(bool isTaller, std::pair<char, char> futurehead)
{
    std::pair<char, char> *p_future_head;
    if (isTaller)
        ++(this->_len);
    p_future_head = new std::pair<char, char>[this->_len];
    int prev_len = this->_len - 1;
    *p_future_head = futurehead;
    if (this->_len > 1)
    {
        memcpy(p_future_head + 1, _head, sizeof(std::pair<char, char>) * prev_len);
    }
    delete[] this->_head;
    this->_head = p_future_head;
}