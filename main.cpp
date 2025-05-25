#include <string>
#include <iostream>
#include "Game.h"

using std::cout;
using std::cin;
using std::string;

int main(){
    Game* game = new Game("PARADIS ISLAND!");
    game->startGame();
    return 0;
}