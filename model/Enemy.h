#ifndef ENEMY_H
#define ENEMY_H

#include "NPC.h"
#include "Spell.h"

#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::pair;

class Enemy: public NPC{
    private:
        int attackPoints;
        int magicPoints;
        vector<Spell> spells;
        string sprite;
    public:
        Enemy();
        ~Enemy();
        Enemy(string name, int maxHealthPoint, int healthPoints, int level, pair<int, int> position, int attackPoints, int magicPoints, vector<Spell> spells, string sprite);
        void getDamage();
        pair<int, Effect> useSpell();
        void receiveDamage(int dmg);
        bool checkAlive();
};

#endif