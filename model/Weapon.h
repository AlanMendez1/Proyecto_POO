#ifndef WEAPON_H
#define WEAPON_H

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

class Weapon {
    protected:
        string name;
        string description;
        int attackPoints;
        int durability;
        string sprite;
    public:
        Weapon();
        ~Weapon();
        Weapon(string name, string description, int attackPoints, int durability, string sprite);
        int getAttackP();
        int getDurability();
        void showSprite();
        void showDescription();
};

#endif