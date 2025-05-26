#include "NPC.h"

NPC::NPC(){

}

NPC::~NPC(){
    
}

void NPC::updateHealthPoints(){

};

pair<int, int> NPC::getPosition(){
    return this->position;
}

void NPC::setPosition(pair<int, int> pos){
    this->position = pos;
}

string NPC::getName(){
    return this->name;
};

int NPC::getMaxHealthPoints(){
    return this->maxHealthPoints;
};


int NPC::getHealthPoints(){
    return this->healthPoints;
};

int NPC::getLevel(){
    return this->level;
};