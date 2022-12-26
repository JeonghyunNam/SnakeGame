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
    void updateSnakeInfo(std::pair<char, char> *p, int &len);
    void genFood(void);
    std::pair<char, char> InformFood();
};