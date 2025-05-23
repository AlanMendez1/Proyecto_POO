#include "Player.h"

Player::Player(){

};

Player::~Player(){
    
};

Player::Player(string name, vector<Spell*> spells, string sprite){
    this->name = name;
    this->maxHealthPoints = 50;
    this->healthPoints = 50;
    this->level = 1;
    this->position = {0, 0};
    this->attackPoints = 10;
    this->maxMagicPoints = 10;
    this->magicPoints = 10;
    this->spells = spells;
    this->sprite = sprite;
}

void Player::showSprite(){
    cout << "\033[1;31m" << this->sprite << "\033[0m";
}

void Player::receiveDamage(int dmg){
    this->healthPoints = this->healthPoints - dmg;
}

bool Player::checkAlive(){
    return this->healthPoints > 0;
}

int Player::attack(){
    return this->attackPoints + this->weapon.getAttackP();
}

int Player::useSpell(){
    int opc;
    cout << "Selecciona un hechizo:\n";
    for(int i = 0; i < spells.size(); i++){
        cout << i + 1;
        spells[i]->showSpell();
    }
    cin >> opc;
    spells[opc - 1]->showEffect();
    int manaCost = spells[opc - 1]->getManaCost();
    int damage = spells[opc - 1]->getBaseDamage();
    if(manaCost >= this->magicPoints){
        this->magicPoints = this->magicPoints - manaCost;
        damage = damage + this->attackPoints;
        spells[opc - 1]->showEffect();
    } else{
        cout << "You don't have enough mana to use this spell.";
        damage = 0;
    }
    return damage;
}

void Player::move(){
// Black magic to prevent Linux from buffering keystrokes.
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);

// Once the buffering is turned off, the rest is simple.
    cout << "Enter a character: ";
    char c,d,e;
    cin >> c;
    cin >> d;
    cin >> e;
    cout << "\nYour character was ";
// Using 3 char type, Cause up down right left consist with 3 character
    if ((c==27)&&(d==91)) {
        if (e==65) { cout << "UP";}
        if (e==66) { cout << "DOWN";}
        if (e==67) { cout << "RIGHT";}
        if (e==68) { cout << "LEFT";}
        cout << endl;
    }
}
