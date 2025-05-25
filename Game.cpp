#include "Game.h"

Game::Game(){

}; 

Game::~Game(){

};

Game::Game(string name){
    this->name = name;
};


void Game::startGame(){
    pair<int, int> oldPos, newPos;
    int index;
    cout << "This is " << this->name << ", the adventure begins..." << endl;
    Spell* sp1 = new Spell("Light ray", "Rayitos", 15, 5, NOEFFECT, "fff");
    vector<Spell*> j1Spells = {sp1}; 
    Player* j1 = new Player("Ray", j1Spells, "§");
    j1->showSprite();
    Enemy* enemy1 = new Enemy("Elite Ant", 20, 20, 5, {2, 3}, 10, 10, j1Spells, "°");
    vector<Enemy*> enemies = {enemy1}; 
    Map* board = new Map();
    while(true){
        oldPos = j1->getPosition();
        j1->move();
        newPos = j1->getPosition();
        index = newPos.second * 20 + newPos.first;
        if(board->collision(index)){
            cout << "You cannot do this move!" << endl;
            j1->setPosition(oldPos);
        }
        board->drawMap(j1, enemies);
    }
};

void Game::gameLoop(){ 

};