#pragma once
#include <iostream>

class Referee {
private:
    std::pair<char, char> *infoSnake = NULL;
    int snakelen;
public:
    Referee();
    ~Referee();

    void getSnake(std::pair<char, char>*, int&);

    bool meetWall(std::pair<char, char>&);
    bool selfIntersect(std::pair<char, char>&);
    bool isTerminate(std::pair<char, char>&);
};