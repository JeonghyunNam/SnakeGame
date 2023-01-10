#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <iostream>
#include <utility>

class Snake
{
private:
    int len_snake;
    std::pair<char, char> *p_headpos_snake;

public:
    Snake();
    ~Snake();

    void genSnake(std::pair<char, char> &);

    void moveAndGrow(bool, std::pair<char, char>);

    std::pair<char, char> *informSnakeHeadPos(void);
    int informSnakeLen(void);
};
#endif