#include "Pickup.h"

Pickup::Pickup(){

}

Pickup::~Pickup(){

}

Pickup::Pickup(string sprite, int value, pair<int, int> position){
    this->sprite = sprite;
    this->value = value;
    this->position = position;
}

pair<int, int> Pickup::getPosition(){
    return this->position;
}

void Pickup::showSprite(){
    cout << this->sprite;
}

int Pickup::getExperience(){
    return this->value;
}