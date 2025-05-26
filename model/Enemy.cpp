#include "Enemy.h"

Enemy::Enemy(){

};

Enemy::~Enemy(){

};

Enemy::Enemy(string name, int maxHealthPoint, int healthPoints, int level, pair<int, int> position, int attackPoints, int magicPoints, vector<Spell*> spells, string sprite){
    this->name = name;
    this->maxHealthPoints = maxHealthPoint;
    this->healthPoints = healthPoints;
    this->level = level;
    this->position = position;
    this->attackPoints = attackPoints;
    this->magicPoints = magicPoints;
    this->spells = spells;
    this->sprite = sprite;
};

int Enemy::getDamage(){
    return this->attackPoints;
};

pair<int, Effect> Enemy::useSpell(){
    int random = rand() % 2; 
    pair<int, Effect> attack;
    Spell* usedSpell = this->spells[random];
    if(magicPoints >= usedSpell->getManaCost()){
        magicPoints = magicPoints - usedSpell->getManaCost();
        attack = {usedSpell->getBaseDamage() * this->attackPoints, usedSpell->getEffect()};
        cout << this->name << " acaba de utilizar " << usedSpell->getName() << endl;
    } else {
        attack = {0, NOEFFECT};
        cout << this->name << " no puede utilizar este hechizo, FALTA MANAAA!" << endl;
    }
    return attack;
};

void Enemy::receiveDamage(int dmg){
    this->healthPoints = this->healthPoints - dmg;
};

bool Enemy::checkAlive(){
    return this->healthPoints > 0;
};

void Enemy::movement(){
    int random = rand() % 4; 
    switch(random){
        case 0: this->position.second = this->position.second - 1;
                break;
        case 1: this->position.first = this->position.first + 1;
                break;
        case 2: this->position.second = this->position.second + 1;
                break;
        case 3: this->position.first = this->position.first - 1;
                break;
        default: break;
    }
}

void Enemy::showSprite(){
    cout << "\033[1;31m" << this->sprite << "\033[0m";
}

int Enemy::getMana(){
    return this->magicPoints;
}