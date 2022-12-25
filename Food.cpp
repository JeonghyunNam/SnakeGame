#include <iostream>
#include "Food.hpp"

Food::Food(){
    this->p_snake = NULL;
}

Food::~Food() {

    
}
void Food::updateSnakeInfo(std::pair<char, char> *p_snakehead, int& len){
    this->p_snake = p_snakehead;
    this->snakelen = len;
}

void Food::genFood(void){

}