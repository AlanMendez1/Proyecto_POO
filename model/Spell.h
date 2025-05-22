#ifndef SPELL_H
#define SPELL_H

#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::pair;

enum Effect {
    NOEFFECT,
    POISONED,
    PARALYZED,
    MAGICLESS
};

class Spell {
    private:
        string name;
        string description;
        int baseDamage;
        int manaCost;
        Effect effect;
        string visualEffect;
    public:
        Spell();
        ~Spell();
        Spell(string name, string description, int baseDamage, int manaCost, Effect effect, string visualEffect);
        void showSpell();
        void showEffect();
        int getBaseDamage();
        int getManaCost();
        Effect getEffect();
};

#endif