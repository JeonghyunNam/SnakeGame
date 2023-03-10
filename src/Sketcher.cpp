#include <iostream>
#include <Windows.h>
#include <string>
#include "../include/Sketcher.h"

Sketcher::Sketcher()
{
    this->score = 0;
}

Sketcher::~Sketcher()
{
}

void Sketcher::drawMenu(void)
{
    system("mode con:cols=60 lines=33");
    system("title SnakeGame. By Jeonghyun Nam");
    system("chcp 65001");

    this->drawWall();
    gotoxy(20, 14);
    std::cout << "□□□□□□□□□□";
    gotoxy(20, 15);
    std::cout << "□   Snake Game   □";
    gotoxy(20, 16);
    std::cout << "□□□□□□□□□□";
    gotoxy(23, 20);
    std::cout << "Press any key!";

    this->showConsoleCursor(false);
    system("pause>nul");
}

void Sketcher::drawLoad(void)
{
    system("cls");
    this->drawWall();
    gotoxy(30, 15);
    for (int i = 3; i > 0; i--)
    {
        std::cout << i;
        Sleep(1000);
        gotoxy(30, 15);
    }

    this->showConsoleCursor(false);
}

void Sketcher::drawObject(int &score)
{
    this->drawSnake();
    this->drawFood();
    this->drawScore(score);
    this->showConsoleCursor(false);
}

void Sketcher::removeObject(void) {
    this->removeSnake();
    this->removeFood();
}

void Sketcher::drawWall(void)
{
    // width : 60, height : 30
    system("cls");
    gotoxy(0, 0);
    std::string widthwall = "□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□";
    std::cout << widthwall;
    for (int i = 1; i <= 28; i++)
    {
        gotoxy(0, i);
        std::cout << "□";
        gotoxy(58, i);
        std::cout << "□";
    }
    gotoxy(0, 29);
    std::cout << widthwall;
}

void Sketcher::removeWall(void) {
        // width : 60, height : 30
    system("cls");
    gotoxy(0, 0);
    std::string widthwall = "                                                                                          ";
    std::cout << widthwall;
    for (int i = 1; i <= 28; i++)
    {
        gotoxy(0, i);
        std::cout << "   ";
        gotoxy(58, i);
        std::cout << "   ";
    }
    gotoxy(0, 29);
    std::cout << widthwall;
}

void Sketcher::drawSnake()
{
    for (int i = 0; i < this->snake_len; i++)
    {
        gotoxy((int)(this->p_snake + i)->first, (int)(this->p_snake + i)->second);
        std::cout << "■";
    }
}

void Sketcher::removeSnake() {
    for (int i = 0; i < this->snake_len; i++)
    {
        gotoxy((int)(this->p_snake + i)->first, (int)(this->p_snake + i)->second);
        std::cout << "  ";
    }
}

void Sketcher::drawFood()
{
    gotoxy((this->food_pos).first, (this->food_pos).second);
    std::cout << "◯";
}

void Sketcher::removeFood() {
    gotoxy((this->food_pos).first, (this->food_pos).second);
    std::cout << "  ";
}

void Sketcher::drawScore(int &scores)
{
    this->score = scores;
    gotoxy(25, 31);
    std::cout << "Score :\t" << scores << std::endl;
}

void Sketcher::drawGameFinish(void)
{
    system("cls");
    this->drawWall();
    this->drawScore(this->score);
    gotoxy(20, 14);
    std::cout << "□□□□□□□□□□";
    gotoxy(20, 15);
    std::cout << "□   Game Over!   □";
    gotoxy(20, 16);
    std::cout << "□□□□□□□□□□";
    gotoxy(30, 25);
    std::cout << "Press R for restart ";
    gotoxy(30, 26);
    std::cout << "      Q for quit";
    this->showConsoleCursor(false);
}

void Sketcher::drawProperInput(void)
{
    system("cls");
    this->drawWall();
    gotoxy(18, 14);
    std::cout << "□□□□□□□□□□□□";
    gotoxy(18, 15);
    std::cout << "□  Input Properly :< □";
    gotoxy(18, 16);
    std::cout << "□□□□□□□□□□□□";
    this->showConsoleCursor(false);
    system("pause>nul");
}

void Sketcher::getSnake(std::pair<char, char> *p_snake_info, int &len)
{
    this->p_snake = p_snake_info;
    this->snake_len = len;
}

void Sketcher::getFood(std::pair<char, char> food)
{
    this->food_pos = food;
}

void Sketcher::gotoxy(int x, int y)
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Sketcher::showConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}