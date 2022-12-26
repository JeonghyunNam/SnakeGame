#pragma once
#include <iostream>
#include "Sketcher.cpp"
#include "Snake.cpp"
#include "Food.cpp"
#include "Referee.cpp"

class Controller
{
private:
    Sketcher *ptr_sketcher;
    Referee *ptr_referee;
    Snake *ptr_snake;
    Food *ptr_food;

public:
    Controller();
    ~Controller();

    void menu(void);  // initial main window
    bool load(void);  // loading game window
    void start(void); // main game
    bool end(void);   // end game window

    void setObject(void);                        // set snake, food
    void updateObserver(void);                   // synchronize snake, food to sketcher, referee
    std::pair<char, char> MoveSnakeHead(char &); // move snakehead
    bool validInput(char &, char &);
};