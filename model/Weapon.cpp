#include "Weapon.h"

Weapon::Weapon(){

}

Weapon::~Weapon(){

} 

Weapon::Weapon(string name, string description, int attackPoints, int durability, string sprite){
    this->name = name;
    this->description = description;
    this->attackPoints = attackPoints;
    this->durability = durability;
    this->sprite = sprite;
}

int Weapon::getAttackP(){
    return this->attackPoints;
}

int Weapon::getDurability(){
    return this->durability;
}

void Weapon::showSprite(){
    cout << sprite << endl;
}

void Weapon::showDescription(){
    cout << description << endl;
}