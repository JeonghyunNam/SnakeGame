#pragma once
#include <iostream>
#include <utility>

class Snake {
private:
    int _len;
    std::pair<char, char> *_head; 

public:
    Snake();
    ~Snake();
    
};