#include "Game.h"

Game::Game(){

}; 

Game::~Game(){

};

Game::Game(string name){
    this->name = name;
};


void Game::startGame(){
    pair<int, int> oldPos, newPos, oldEnemyPos, newEnemyPos;
    int newIndex, oldEnemyIndex, enemyIndex, oldIndex, newEnemyIndex;
    bool battleFlag, win = false, lose = false;
    cout << "This is " << this->name << ", the adventure begins..." << endl;
    Spell* sp1 = new Spell("Light ray", "Rayitos", 15, 5, NOEFFECT, "fff");
    vector<Spell*> j1Spells = {sp1}; 
    Player* j1 = new Player("Ray", j1Spells, "§");
    j1->showSprite();
    Enemy* enemy1 = new Enemy("Elite Ant", 20, 20, 5, {2, 3}, 10, 10, j1Spells, "°");
    vector<Enemy*> enemies = {enemy1}; 
    Map* board = new Map();
    // GAME LOOP
    while(!win || !lose){
        oldPos = j1->getPosition();
        oldIndex = oldPos.second * 20 + oldPos.first;
        j1->move();
        newPos = j1->getPosition();
        newIndex = newPos.second * 20 + newPos.first;
        if(board->collision(newIndex)){
            cout << "You cannot do this move!" << endl;
            j1->setPosition(oldPos);
        }
        battleFlag = false;
        for(int i = 0; i < enemies.size(); i++){
            oldEnemyPos = enemies[i]->getPosition();
            oldEnemyIndex = oldEnemyPos.second * 20 + oldEnemyPos.first;
            enemies[i]->movement();
            newEnemyPos = enemies[i]->getPosition();
            newEnemyIndex = newEnemyPos.second * 20 + newEnemyPos.first;
            if(newIndex == oldEnemyIndex){
                j1->setPosition(oldPos);
                enemies[i]->setPosition(oldEnemyPos);
                battleFlag = true;
            } else if (oldIndex == newEnemyIndex){
                j1->setPosition(oldPos);
                enemies[i]->setPosition(oldEnemyPos);
                battleFlag = true;
            } else if (newIndex = newEnemyIndex){
                battleFlag = true;
            } else if(board->collision(newEnemyIndex)){
                enemies[i]->setPosition(oldEnemyPos);
            }
        }
        if(battleFlag){
            // TO DO BATTLE
            cout << "BATTLE STARTED!" << endl;
        }

        
        board->drawMap(j1, enemies);
    }
};

void Game::gameLoop(){ 

};