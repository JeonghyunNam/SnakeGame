#include <iostream>
#include <memory>
#include "Controller.cpp"

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