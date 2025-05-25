#ifndef GAME_H
#define GAME_H

#include "model/Player.h"
#include "model/Enemy.h"
#include "model/Spell.h"
#include "model/Map.h"

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

class Game {
    protected:
        string name;
    public:
        Game();
        ~Game();
        Game(string name);
        void startGame();
        void gameLoop();
};

#endif