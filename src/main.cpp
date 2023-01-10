#include <iostream>
#include <memory>
#include "../include/Controller.h"

int main()
{
    auto snakeGame = std::make_shared<Controller>();
    auto isTerminate = false;

    snakeGame->loadMenu();
    while (!isTerminate)
    {
        if (snakeGame->loadGame())
        {
            snakeGame->doGame();
            isTerminate = snakeGame->endGame();
        }
    }

    return 0;
}
