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

Controller::Controller()
{
    this->p_sketcher = NULL;
    this->p_referee = NULL;
    this->p_snake = NULL;
    this->p_food = NULL;
}

Controller::~Controller()
{
    if (this->p_sketcher != NULL)
        delete p_sketcher;
    if (this->p_referee != NULL)
        delete p_referee;
    if (this->p_snake != NULL)
        delete p_snake;
    if (this->p_food != NULL)
        delete p_food;
}

void Controller::loadMenu()
{
    // Create Observer
    this->p_sketcher = new Sketcher;
    this->p_referee = new Referee;

    this->p_sketcher->drawMenu();
}

bool Controller::loadGame()
{
    this->p_snake = new Snake;
    this->p_food = new Food;
    this->setObject();      // Snake, Food
    this->updateObserver(); // Sketcher, Referee

    this->p_sketcher->drawLoad();

    return true;
}

void Controller::doGame()
{
    int score = 0, init_speed = 200, speed;
    bool b_is_terminate, b_is_contact;
    char input = UP, inputs;
    std::pair<char, char> future_snakepos;

    this->p_sketcher->drawWall();
    this->p_sketcher->drawObject(score);
    while (1)
    {
        // Draw all Scene
        int count_frame = 0;
        char candidate_input = input;
        while(count_frame < 15){
            // Get next input
            if (kbhit())
            {
                if (getch() == MAGICKEY)
                {
                    inputs = getch();
                    if (inputs == UP || inputs == DOWN || inputs == LEFT || inputs == RIGHT)
                    {
                        if (this->checkValidInput(input, inputs))
                        {
                            candidate_input = inputs;
                        }
                    }
                }
            }
            count_frame++;
            // Sleep(2);
        }
        input = candidate_input;

        // move snake
        future_snakepos = this->predictSnakeHead(input);

        // Check food & snake intersect
        b_is_contact = this->p_referee->checkFoodContact(future_snakepos);
        if (b_is_contact)
        {
            this->p_food->genFood();
            score += 10;
        }

        this->p_sketcher->removeObject();

        this->p_snake->moveAndGrow(b_is_contact, future_snakepos);
        this->updateObserver();
        this->p_sketcher->drawObject(score);

        // Check meet wall, self-intersection
        b_is_terminate = this->p_referee->checkTerminate();
        if (b_is_terminate)
            break;

        speed = init_speed - 10*(this->p_referee->adjustSpeed(score));
        Sleep(speed);
    }
}

bool Controller::endGame()
{
    char input;
    if (this->p_snake != NULL)
    {
        delete this->p_snake;
        this->p_snake = NULL;
    }

    if (this->p_food != NULL)
    {
        delete this->p_food;
        this->p_food = NULL;
    }

    while (1)
    {
        this->p_sketcher->drawGameFinish();
        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
        input = getch();
        if (input == QUIT)
            return true;
        else if (input == RESTART)
            return false;
        this->p_sketcher->drawProperInput();
    }
}

void Controller::setObject()
{
    // Init snake with random pos(food also) and len 1
    std::pair<char, char> snake_headpos;
    // Snake
    srand(time(0));
    snake_headpos.first = 2 * (rand() % 28 + 1);
    snake_headpos.second = rand() % 28 + 1;
    this->p_snake->genSnake(snake_headpos);

    // Food
    auto p_snake_head = this->p_snake->informSnakeHeadPos();
    int snake_len = this->p_snake->informSnakeLen();
    this->p_food->updateSnakeInfo(p_snake_head, snake_len);
    this->p_food->genFood();
}

void Controller::updateObserver()
{
    // Give object information to observer
    auto p_snake_headpos = this->p_snake->informSnakeHeadPos();
    int snake_len = this->p_snake->informSnakeLen();
    auto food_pos = this->p_food->informFood();

    // snake
    this->p_sketcher->getSnake(p_snake_headpos, snake_len);
    this->p_referee->getSnake(p_snake_headpos, snake_len);

    // food
    this->p_sketcher->getFood(food_pos);
    this->p_referee->getFood(food_pos);
}

std::pair<char, char> Controller::predictSnakeHead(char &input)
{
    std::pair<char, char> cur_snakepos = *(this->p_snake->informSnakeHeadPos());
    std::pair<char, char> future_snakepospos = cur_snakepos;
    switch (input)
    {
    case UP:
        future_snakepospos.second -= 1;
        break;
    case DOWN:
        future_snakepospos.second += 1;
        break;
    case LEFT:
        future_snakepospos.first -= 2;
        break;
    case RIGHT:
        future_snakepospos.first += 2;
        break;
    }
    return future_snakepospos;
}

bool Controller::checkValidInput(char &input, char &cur_input)
{
    switch (input)
    {
    case UP:
        if (cur_input == DOWN)
            return false;
        break;
    case DOWN:
        if (cur_input == UP)
            return false;
        break;
    case LEFT:
        if (cur_input == RIGHT)
            return false;
        break;
    case RIGHT:
        if (cur_input == LEFT)
            return false;
        break;
    }
    return true;
}