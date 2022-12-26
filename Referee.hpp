#pragma once
#include <iostream>

class Referee {
private:
    std::pair<char, char> *infoSnake = NULL, infoFood;
    int snakelen;
public:
    Referee();
    ~Referee();

    void getSnake(std::pair<char, char>*, int&);
    void getFood(std::pair<char, char>);

    bool meetWall(std::pair<char, char>&);
    bool contactFood(std::pair<char, char>&);
    bool selfIntersect(std::pair<char, char>&);
    bool isTerminate(std::pair<char, char>&);
};