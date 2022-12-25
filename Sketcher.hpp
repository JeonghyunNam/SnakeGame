#pragma once
#include <iostream>

class Sketcher {
private:
    std::pair<char, char> *infoSnake = NULL;
    int snakelen;
    void gotoxy(int, int);

public:
    Sketcher();
    ~Sketcher();

    void drawMenu(void);

    void drawLoad(void);

    void drawInGame(void);
    void drawWall(void);
    void drawSnake(int&);

    void drawGameFinish(void);
    void drawProperInput(void);
    
    void getSnake(std::pair<char, char>*, int&);
};