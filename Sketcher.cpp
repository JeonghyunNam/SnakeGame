#include <iostream>
#include <Windows.h>
#include "Sketcher.hpp"

Sketcher::Sketcher() {

}

Sketcher::~Sketcher() {

}

void Sketcher::drawMenu(void){
    system("mode con:cols=100 lines=50");
    system("title SnakeGame. By Jeonghyun Nam");
    
    gotoxy(40, 24);
    std::cout<<"*******************";
    gotoxy(40, 25);
    std::cout<<"*   Snake Game!   *";
    gotoxy(40, 26);
    std::cout<<"*******************";
    gotoxy(43, 30);
    std::cout<<"Press any key";
    system("pause>null");
}

void Sketcher::drawLoad(void){
    system("cls");
    gotoxy(50, 25);
    for(int i=3; i>0; i--){
        std::cout<<i;
        Sleep(1000);
        gotoxy(50, 25);
    }
}

void Sketcher::drawInGame(void){

}

void Sketcher::drawGameFinish(void){
    gotoxy(40, 24);
    std::cout<<"*******************";
    gotoxy(40, 25);
    std::cout<<"*  ! Game Over !  *";
    gotoxy(40, 26);
    std::cout<<"*******************";
    gotoxy(39, 30);
    std::cout<<"Press r for restart  ";
    gotoxy(39, 31);
    std::cout<<"      q for quit game";
}

void Sketcher::drawProperInput(void){
    system("cls");
    gotoxy(38, 24);
    std::cout<<"***********************";
    gotoxy(38, 25);
    std::cout<<"*  Input Properly :<  *";
    gotoxy(38, 26);
    std::cout<<"***********************";
    system("pause>null");
}

void Sketcher::gotoxy(int x, int y)
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}