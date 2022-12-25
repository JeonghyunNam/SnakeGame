#pragma once
#include <iostream>

class Sketcher {
private:
    void gotoxy(int, int);

public:
    Sketcher();
    ~Sketcher();
    void drawMenu(void);
    void drawLoad(void);
    void drawInGame(void);
    void drawGameFinish(void);
    void drawProperInput(void);
};