#include <iostream>
#include <memory>
#include "Controller.cpp"

int main()
{
    auto snakeGame = std::make_shared<Controller>();
    auto isTerminate = false;

    snakeGame->menu();
    while (!isTerminate)
    {
        if (snakeGame->load())
        {
            snakeGame->start();
            isTerminate = snakeGame->end();
        }
    }

    return 0;
}