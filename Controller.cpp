#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Controller.hpp"

// Key input
#define RESTART 114
#define QUIT 113
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define MAGICKEY 224

// Env Setting
#define WIDTH 100
#define HEIGHT 50

Controller::Controller()
{
    this->ptr_sketcher = NULL;
    this->ptr_referee = NULL;
    this->ptr_snake = NULL;
}

Controller::~Controller()
{
    if (this->ptr_sketcher != NULL)
        delete ptr_sketcher;
    if (this->ptr_referee != NULL)
        delete ptr_referee;
    if (this->ptr_snake != NULL)
        delete ptr_snake;
    if (this->ptr_food != NULL)
        delete ptr_food;
}

void Controller::menu()
{
    // Create Observer
    this->ptr_sketcher = new Sketcher;
    this->ptr_referee = new Referee;

    this->ptr_sketcher->drawMenu();
}

bool Controller::load()
{
    this->ptr_snake = new Snake;
    this->ptr_food = new Food;
    this->setObject();      // Snake, Food
    this->updateObserver(); // Sketcher, Referee

    this->ptr_sketcher->drawLoad();

    return true;
}

void Controller::start()
{
    int _step = 0;
    bool _isTerminate, _isContact;
    char input;
    std::pair<char, char> future_snake;
    while (1)
    {
        // Draw all Scene
        this->ptr_sketcher->drawInGame();

        // Get next input
        if (_getch() == MAGICKEY)
        {
            input = _getch();
            if (input != UP && input == DOWN && input == LEFT && input == RIGHT)
                continue;
        }
        else
            continue;

        // Move snake
        future_snake = this->MoveSnakeHead(input);

        // Check meet wall, self-intersection
        _isTerminate = this->ptr_referee->isTerminate(future_snake);
        if (_isTerminate)
            break;

        // Update Observer(get snakehead, len info)
        this->updateObserver();

        // Check food & snake intersect
        _isContact = this->ptr_referee->contactFood(future_snake);
        if (_isContact)
        {
            this->ptr_food->genFood();
        }
        this->ptr_snake->Move(_isContact, future_snake);

        this->updateObserver();
        ++_step;
    }
}

bool Controller::end()
{
    char input;
    if (this->ptr_snake != NULL)
    {
        delete this->ptr_snake;
        this->ptr_snake = NULL;
    }

    if (this->ptr_food != NULL)
    {
        delete this->ptr_food;
        this->ptr_food = NULL;
    }

    while (1)
    {
        this->ptr_sketcher->drawGameFinish();
        input = _getch();
        if (input == QUIT)
            return true;
        else if (input == RESTART)
            return false;
        this->ptr_sketcher->drawProperInput();
    }
}

void Controller::setObject()
{
    // Init snake with random pos(food also) and len 1
    std::pair<char, char> snake_head;
    // Snake
    srand(time(0));
    snake_head.first = rand() % 98 + 1;
    snake_head.second = rand() % 48 + 1;
    this->ptr_snake->Init(snake_head);

    // Food
    auto p_snake_head = this->ptr_snake->InformHead();
    int snake_len = this->ptr_snake->InformLen();
    this->ptr_food->updateSnakeInfo(p_snake_head, snake_len);
    this->ptr_food->genFood();
}

void Controller::updateObserver()
{
    // Give object information to observer
    auto snake_head = this->ptr_snake->InformHead();
    int snakelen = this->ptr_snake->InformLen();
    auto food_pos = this->ptr_food->InformFood();

    // snake
    this->ptr_sketcher->getSnake(snake_head, snakelen);
    this->ptr_referee->getSnake(snake_head, snakelen);

    // food
    this->ptr_sketcher->getFood(food_pos);
    this->ptr_referee->getFood(food_pos);
}

std::pair<char, char> Controller::MoveSnakeHead(char &input)
{
    std::pair<char, char> cur_snake = *(this->ptr_snake->InformHead());
    std::pair<char, char> future_snake = cur_snake;
    switch (input)
    {
    case UP:
        future_snake.second -= 1;
        break;
    case DOWN:
        future_snake.second += 1;
        break;
    case LEFT:
        future_snake.first -= 1;
        break;
    case RIGHT:
        future_snake.first += 1;
        break;
    }
    return future_snake;
}