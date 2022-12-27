#pragma once
#include <iostream>

class Food
{
private:
    std::pair<char, char> *p_snake, food;
    int len_snake;

public:
    Food();
    ~Food();
    void genFood(void);
    std::pair<char, char> informFood();
    void updateSnakeInfo(std::pair<char, char> *p, int &len);
};