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
    int newIndex, oldEnemyIndex, oldIndex, newEnemyIndex, itemIndex, itemToDelete, enemyToFight;
    bool battleFlag, win = false, lose = false, pickedFlag;
    cout << "This is " << this->name << ", the adventure begins..." << endl;
    Pickup* pickup1 = new Pickup("\033[1;33m☻\033[0m", 10, {3, 3});
    vector<Pickup*> pickups = {pickup1};
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
        pickedFlag = false;
        for(int i = 0; i < enemies.size(); i++){
            oldEnemyPos = enemies[i]->getPosition();
            oldEnemyIndex = oldEnemyPos.second * 20 + oldEnemyPos.first;
            enemies[i]->movement();
            newEnemyPos = enemies[i]->getPosition();
            newEnemyIndex = newEnemyPos.second * 20 + newEnemyPos.first;
            if(newIndex == oldEnemyIndex){
                // cout << "AQUI1" << endl;
                j1->setPosition(oldPos);
                enemies[i]->setPosition(oldEnemyPos);
                battleFlag = true;
                enemyToFight = i;
            } else if (oldIndex == newEnemyIndex){
                // cout << "AQUI2" << endl;
                j1->setPosition(oldPos);
                enemies[i]->setPosition(oldEnemyPos);
                battleFlag = true;
                enemyToFight = i;
            } else if (newIndex == newEnemyIndex){
                // cout << "AQUI3" << endl;
                battleFlag = true;
                enemyToFight = i;
            } else if(board->collision(newEnemyIndex)){
                enemies[i]->setPosition(oldEnemyPos);
            }
        }
        for(int j = 0; j < pickups.size(); j++){
            itemIndex = pickups[j]->getPosition().second * 20 + pickups[j]->getPosition().first;
            if(newIndex == itemIndex){
                itemToDelete = j;
                pickedFlag = true;
                j1->levelUp(pickups[j]->getExperience());
            }
        }
        if(pickedFlag){
            pickups.erase(pickups.begin() + itemToDelete);
        }
        if(battleFlag){
            // TO DO BATTLE
            cout << battleFlag << endl;
            Battle* battle = new Battle(j1, enemies[enemyToFight]);
            cout << "BATTLE STARTED!" << endl;
            battle->startBattle();
        }

        
        board->drawMap(j1, enemies, pickups);
    }
};

void Game::gameLoop(){ 

};