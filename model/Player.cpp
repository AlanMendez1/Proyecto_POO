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
    this->position = {1, 1};
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
        cout << i + 1 << ". " << spells[i]->getName() << endl;;
    }
    cin >> opc;
    int manaCost = spells[opc - 1]->getManaCost();
    int damage = spells[opc - 1]->getBaseDamage();
    if(manaCost >= this->magicPoints){
        this->magicPoints = this->magicPoints - manaCost;
        damage = damage + this->attackPoints;
        cout << "Acabas de utilizar " << spells[opc - 1]->getName() << endl;
    } else{
        cout << "No tienes mana para utilizar este hechizo." << endl;
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
    int playerIndex = this->position.second * 20 + this->position.first;
    if ((c==27)&&(d==91)) {
        if (e==65) { 
            cout << "UP";
            this->position = {this->position.first, this->position.second - 1};
        }
        if (e==66) { 
            cout << "DOWN"; 
            this->position = {this->position.first, this->position.second + 1};
        }
        if (e==67) { 
            cout << "RIGHT"; 
            this->position = {this->position.first + 1, this->position.second};
        }
        if (e==68) { 
            cout << "LEFT"; 
            this->position = {this->position.first - 1, this->position.second};
        }
        cout << endl;
    }
}

void Player::levelUp(int exp){
    this->experience = this->experience + exp;
    if(this->experience >= this->experienceToLvlUp){
        this->experience = this->experience - this->experienceToLvlUp;
        this->experienceToLvlUp = this->experienceToLvlUp + 15;
        this->level = this->level + 1;
    }
}

void Player::setMana(int newMana){
    this->magicPoints = newMana;
}

int Player::getMana(){
    return this->magicPoints;
}
