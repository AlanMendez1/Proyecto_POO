#include "Ally.h"

Ally::Ally(){

}

Ally::~Ally(){

}

Ally::Ally(pair<int, int> position){
    this->name = "Pacific Ant";
    this->sprite = "\033[1;34m♥\033[0m";
    this->position = position;
}  

void Ally::showSprite(){
    cout << sprite;
}