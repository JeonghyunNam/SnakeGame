#include <iostream>
#include "Referee.hpp"

Referee::Referee() {

}

Referee::~Referee() {

}

void Referee::getSnake(std::pair<char, char> *p_snake, int& len) {
        this->infoSnake = p_snake;
        this->snakelen  = len;
}

bool Referee::meetWall(std::pair<char, char>& snakehead){
    if (snakehead.first == 0  || snakehead.first == 99)  return true;
    if (snakehead.second == 0 || snakehead.second == 49) return true;
    return false;   
}

bool Referee::selfIntersect(std::pair<char, char>& future_head){
    std::pair<char, char>* cur_snake = this->infoSnake; 
    for(int i=0; i<snakelen; i++){
        if(future_head.first == (cur_snake+i)->first && future_head.second == (cur_snake+i)->second){
            return true;
        }
    }
    return false;
}

bool Referee::isTerminate(std::pair<char, char>& snakehead){
    if (this->meetWall(snakehead))  return true;
    if (this->selfIntersect(snakehead)) return true;
    //food condition
    
    return false;
}