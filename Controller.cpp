#include <iostream>
#include <conio.h>
#include "Controller.hpp"

#define RESTART  114
#define QUIT     113

Controller::Controller() {
    this->ptr_sketcher = NULL;
    this->ptr_snake    = NULL;
}

Controller::~Controller() {
    if(this->ptr_sketcher != NULL)  delete ptr_sketcher;
    if(this->ptr_snake != NULL) delete  ptr_snake;
}

void Controller::menu() {
    this->ptr_sketcher = new Sketcher;
    this->ptr_sketcher->drawMenu();
}

bool Controller::load() {
    this->ptr_sketcher->drawLoad();
    return true;
}

void Controller::start() {

}

bool Controller::end() {
    char input;
    if(this->ptr_snake != NULL){
        delete this->ptr_snake;
        this->ptr_snake = NULL;
    }
    while(1){
        this->ptr_sketcher->drawGameFinish();
        input = _getch();
        if (input == QUIT)  return true;
        else if (input == RESTART)  return false;
        this->ptr_sketcher->drawProperInput();
    }
}