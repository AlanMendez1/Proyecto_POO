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