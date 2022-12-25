#pragma once
#include <iostream>
#include "Sketcher.cpp"
#include "Snake.cpp"

class Controller {
private:
    Sketcher *ptr_sketcher;
    Snake    *ptr_snake;

public:
    Controller();
    ~Controller();
    void menu(void);    //initial main window
    bool load(void);    //loading game window
    void start(void);   //main game
    bool end(void);     //end game window
};