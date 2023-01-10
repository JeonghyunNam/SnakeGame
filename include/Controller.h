#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <iostream>
#include "../include/Sketcher.h"
#include "../include/Snake.h"
#include "../include/Food.h"
#include "../include/Referee.h"

class Controller
{
private:
    Sketcher *p_sketcher;
    Referee *p_referee;
    Snake *p_snake;
    Food *p_food;

public:
    Controller();
    ~Controller();

    void loadMenu(void); // initial main window
    bool loadGame(void); // loading game window
    void doGame(void);   // main game
    bool endGame(void);  // end game window

    void setObject(void);      // set snake, food
    void updateObserver(void); // synchronize snake, food to sketcher, referee
    bool checkValidInput(char &, char &);

    std::pair<char, char> predictSnakeHead(char &); // move snakehead
};
#endif
