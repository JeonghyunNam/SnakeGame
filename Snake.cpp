#include <iostream>
#include "Snake.hpp"

Snake::Snake(){
    this->_len = 1;
    this->_head = NULL;
}

Snake::~Snake() {
    if(this->_head != NULL){
        delete _head;
        this->_head = NULL;
    }
}

void Snake::Init(std::pair<char, char>& headpos) {
    this->_head = new std::pair<char, char>;
    *(this->_head) = headpos;
}

std::pair<char, char> * Snake::InformHead(void) {
    return (this->_head);
}

int Snake::InformLen(void) {
    return (this->_len);
}