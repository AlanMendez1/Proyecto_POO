#include "Spell.h"

Spell::Spell(){

};

Spell::~Spell(){

};

Spell::Spell(string name, string description, int baseDamage, int manaCost, Effect effect){
    this->name = name;
    this->description = description;
    this->baseDamage = baseDamage;
    this->manaCost = manaCost;
    this->effect = effect;
};

int Spell::getBaseDamage(){
    return this->baseDamage;
};

int Spell::getManaCost(){
    return this->manaCost;
};

Effect Spell::getEffect(){
    return this->effect;
};

string Spell::getName(){
    return this->name;
};