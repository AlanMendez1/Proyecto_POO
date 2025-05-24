#include "Enemy.h"

Enemy::Enemy(){

};

Enemy::~Enemy(){

};

Enemy::Enemy(string name, int maxHealthPoint, int healthPoints, int level, pair<int, int> position, int attackPoints, int magicPoints, vector<Spell> spells, string sprite){
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
    Spell usedSpell = this->spells[random];
    if(magicPoints >= usedSpell.getManaCost()){
        magicPoints = magicPoints - usedSpell.getManaCost();
        attack = {usedSpell.getBaseDamage() * this->attackPoints, usedSpell.getEffect()};
    } else {
        attack = {0, NOEFFECT};
        cout << this->name << " can't use this spell, NOT ENOUGH MANA!" << endl;
    }
    return attack;
};

void Enemy::receiveDamage(int dmg){
    this->healthPoints = this->healthPoints - dmg;
};

bool Enemy::checkAlive(){
    return this->healthPoints > 0;
};

void Enemy::movement(int x, int y){
    this->position.first = this->position.first + x;
    this->position.second = this->position.second + y;
}