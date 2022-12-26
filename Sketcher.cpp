#include <iostream>
#include <Windows.h>
#include <string>

#include "Sketcher.hpp"

Sketcher::Sketcher()
{
}

Sketcher::~Sketcher()
{
}

void Sketcher::drawMenu(void)
{
    system("mode con:cols=100 lines=50");
    system("title SnakeGame. By Jeonghyun Nam");

    this->drawWall();
    gotoxy(40, 24);
    std::cout << "*******************";
    gotoxy(40, 25);
    std::cout << "*   Snake Game!   *";
    gotoxy(40, 26);
    std::cout << "*******************";
    gotoxy(43, 30);
    std::cout << "Press any key";
    system("pause>null");
}

void Sketcher::drawLoad(void)
{
    system("cls");
    this->drawWall();
    gotoxy(50, 25);
    for (int i = 3; i > 0; i--)
    {
        std::cout << i;
        Sleep(1000);
        gotoxy(50, 25);
    }
}

void Sketcher::drawInGame(void)
{
    this->drawWall();
    this->drawSnake();
    this->drawFood();
}

void Sketcher::drawWall(void)
{
    // width : 100, height : 50
    system("cls");
    gotoxy(0, 0);
    std::string widthwall = "==================================================";
    std::cout << widthwall + widthwall;
    for (int i = 1; i <= 48; i++)
    {
        gotoxy(0, i);
        std::cout << "|";
        gotoxy(99, i);
        std::cout << "|";
    }
    gotoxy(0, 49);
    std::cout << widthwall + widthwall;
}

void Sketcher::drawSnake()
{
    for (int i = 0; i < this->snakelen; i++)
    {
        gotoxy((int)(this->infoSnake + i)->first, (int)(this->infoSnake + i)->second);
        std::cout << "*";
    }
}

void Sketcher::drawFood()
{
    gotoxy((this->infoFood).first, (this->infoFood).second);
    std::cout << "O";
}

void Sketcher::drawGameFinish(void)
{
    system("cls");
    this->drawWall();
    gotoxy(40, 24);
    std::cout << "*******************";
    gotoxy(40, 25);
    std::cout << "*  ! Game Over !  *";
    gotoxy(40, 26);
    std::cout << "*******************";
    gotoxy(39, 30);
    std::cout << "Press r for restart  ";
    gotoxy(39, 31);
    std::cout << "      q for quit game";
}

void Sketcher::drawProperInput(void)
{
    system("cls");
    this->drawWall();
    gotoxy(38, 24);
    std::cout << "***********************";
    gotoxy(38, 25);
    std::cout << "*  Input Properly :<  *";
    gotoxy(38, 26);
    std::cout << "***********************";
    system("pause>null");
}

void Sketcher::getSnake(std::pair<char, char> *p_snake, int &len)
{
    this->infoSnake = p_snake;
    this->snakelen = len;
}

void Sketcher::getFood(std::pair<char, char> food)
{
    this->infoFood = food;
}

void Sketcher::gotoxy(int x, int y)
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}