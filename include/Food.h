#ifndef FOOD_HPP
#define FOOD_HPP

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
#endif