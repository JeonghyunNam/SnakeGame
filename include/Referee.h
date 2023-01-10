#ifndef REFEREE_HPP
#define REFEREE_HPP

#include <iostream>

class Referee
{
private:
    std::pair<char, char> *p_snake = NULL, p_food;
    int snake_len;

public:
    Referee();
    ~Referee();

    void getSnake(std::pair<char, char> *, int &);
    void getFood(std::pair<char, char>);
    int adjustSpeed(int);

    bool checkMeetWall(std::pair<char, char> &);
    bool checkFoodContact(std::pair<char, char> &);
    bool checkSelfIntersect(std::pair<char, char> &);
    bool checkTerminate();
};
#endif