#ifndef PLAYER_H
#define PLAYER_H

#include "NPC.h"
#include "Spell.h"
#include "Weapon.h"
#include <termios.h>
#define STDIN_FILENO 0

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <random>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::pair;

class Player: public NPC {
    protected:
        int attackPoints;
        int maxMagicPoints;
        int magicPoints;
        int experience;
        int experienceToLvlUp;
        float armor;
        string sprite;
        vector<Spell*> spells;
        Weapon weapon;
    public:
        Player();
        ~Player();
        Player(string name, vector<Spell*> spells, string sprite);
        void showSprite();
        void receiveDamage(int dmg);
        bool checkAlive();
        int attack();
        int useSpell();
        void move();
        void levelUp(int exp);
        void setMana(int newMana);
        int getMana();
};

#endif