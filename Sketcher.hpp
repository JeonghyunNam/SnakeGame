#pragma once
#include <iostream>

class Sketcher
{
private:
    std::pair<char, char> *infoSnake = NULL;
    std::pair<char, char> infoFood;
    int snakelen;
    void gotoxy(int, int);

public:
    Sketcher();
    ~Sketcher();

    void drawMenu(void);

    void drawLoad(void);

    void drawInGame(void);
    void drawWall(void);
    void drawSnake(void);
    void drawFood(void);

    void drawGameFinish(void);
    void drawProperInput(void);

    void getSnake(std::pair<char, char> *, int &);
    void getFood(std::pair<char, char>);
};