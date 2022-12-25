#pragma once
#include <iostream>

class Food {
private:
    std::pair<char, char> *p_snake;
    int snakelen;
    
public:
    Food();
    ~Food();
    void updateSnakeInfo(std::pair<char, char> *p, int& len);
    void genFood(void);
};