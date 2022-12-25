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
    void Init(std::pair<char, char>&);
    std::pair<char, char> * InformHead(void);
    int InformLen(void);
};