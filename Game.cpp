#include "Game.h"

Game::Game(){

}; 

Game::~Game(){

};

Game::Game(string name){
    this->name = name;
};

void Game::startGame(){
    cout << "This is " << this->name << ", the adventure begins..." << endl;
    Spell* sp1 = new Spell("Light ray", "Rayitos", 15, 5, NOEFFECT, "fff");
    vector<Spell*> j1Spells = {sp1}; 
    Player* j1 = new Player("Ray", j1Spells, "§");
    j1->move();
    j1->showSprite();
};

void Game::gameLoop(){ 

};