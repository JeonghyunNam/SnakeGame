#include <iostream>
#include <memory>
#include "Controller.cpp"

int main() {
    std::unique_ptr<Controller> snakegame(new Controller);
    bool isTerminate = false;
    
    snakegame->menu();
    while(!isTerminate){
        if(snakegame->load()){
            snakegame->start();
            isTerminate = snakegame->end();
        }
    }
    
    return 0;
}