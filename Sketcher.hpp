#pragma once
#include <iostream>

class Sketcher
{
private:
    std::pair<char, char> *p_snake = NULL;
    std::pair<char, char> food_pos;
    int snake_len, score;
    void gotoxy(int, int);
    void showConsoleCursor(bool);

public:
    Sketcher();
    ~Sketcher();

    void drawMenu(void);

    void drawLoad(void);

    void drawInGame(int &);
    void drawWall(void);
    void drawSnake(void);
    void drawFood(void);
    void drawScore(int &);

    void drawGameFinish(void);
    void drawProperInput(void);

    void getSnake(std::pair<char, char> *, int &);
    void getFood(std::pair<char, char>);
};