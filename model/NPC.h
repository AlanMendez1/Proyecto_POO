#ifndef NPC_H
#define NPC_H

#include <string>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::pair;

class NPC {
    protected:
        string name;
        int maxHealthPoints;
        int healthPoints;
        int level;
        pair<int, int> position;
    public:
        NPC();
        ~NPC();
        void updateHealthPoints();
        pair<int, int> getPosition();
        void setPosition(pair<int, int> pos);
};

#endif