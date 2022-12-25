#include <iostream>
#include "Snake.hpp"

Snake::Snake(){

}

Snake::~Snake() {
    if(this->_head != NULL){
        delete _head;
        this->_head = NULL;
    }
}