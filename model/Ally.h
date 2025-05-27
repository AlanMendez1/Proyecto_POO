#ifndef ALLY_H
#define ALLY_H

#include "NPC.h"

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

class Ally: public NPC{
    protected:
        string sprite;
    public:
        Ally();
        ~Ally();
        Ally(pair<int, int> position);
        void showSprite();
};

#endif