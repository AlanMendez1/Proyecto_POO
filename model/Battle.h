#ifndef BATTLE_H
#define BATTLE_H

#include "Enemy.h"
#include "Player.h"

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <random>
#include <bits/stdc++.h>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::pair;
using std::map;

class Battle{
    protected:
        Player* player;
        Enemy* enemy;
        bool win = false;
    public:
        Battle();
        ~Battle();
        Battle(Player* player, Enemy* enemy);
        void startBattle();
        bool checkWin();
};

#endif