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

    void drawObject(int &);
    void removeObject(void);

    void drawWall(void);
    void removeWall(void);
    
    void drawSnake(void);
    void removeSnake(void);

    void drawFood(void);
    void removeFood(void);

    void drawScore(int &);

    void drawGameFinish(void);
    void drawProperInput(void);

    void getSnake(std::pair<char, char> *, int &);
    void getFood(std::pair<char, char>);
};