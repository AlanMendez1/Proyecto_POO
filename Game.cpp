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

    Ally* ally1 = new Ally({12, 12});
    Ally* ally2 = new Ally({10, 15});
    Ally* ally3 = new Ally({3, 15});

    vector<Ally*> allies = {ally1, ally2, ally3};

    // 15 pickups amarillas (valor 10)
    Pickup* pickup1  = new Pickup("\033[1;33m☻\033[0m", 10, {1,  1});
    Pickup* pickup2  = new Pickup("\033[1;33m☻\033[0m", 10, {1,  3});
    Pickup* pickup3  = new Pickup("\033[1;33m☻\033[0m", 10, {1,  5});
    Pickup* pickup4  = new Pickup("\033[1;33m☻\033[0m", 10, {1,  7});
    Pickup* pickup5  = new Pickup("\033[1;33m☻\033[0m", 10, {1,  9});
    Pickup* pickup6  = new Pickup("\033[1;33m☻\033[0m", 10, {2,  2});
    Pickup* pickup7  = new Pickup("\033[1;33m☻\033[0m", 10, {2,  4});
    Pickup* pickup8  = new Pickup("\033[1;33m☻\033[0m", 10, {2,  6});
    Pickup* pickup9  = new Pickup("\033[1;33m☻\033[0m", 10, {2,  8});
    Pickup* pickup10 = new Pickup("\033[1;33m☻\033[0m", 10, {2, 10});
    Pickup* pickup11 = new Pickup("\033[1;33m☻\033[0m", 10, {3,  1});
    Pickup* pickup12 = new Pickup("\033[1;33m☻\033[0m", 10, {3,  3});
    Pickup* pickup13 = new Pickup("\033[1;33m☻\033[0m", 10, {3,  5});
    Pickup* pickup14 = new Pickup("\033[1;33m☻\033[0m", 10, {3,  7});
    Pickup* pickup15 = new Pickup("\033[1;33m☻\033[0m", 10, {3,  9});

    // 10 pickups azules (valor 20)
    Pickup* pickup16 = new Pickup("\033[1;34m☻\033[0m", 20, {5,  2});
    Pickup* pickup17 = new Pickup("\033[1;34m☻\033[0m", 20, {5,  5});
    Pickup* pickup18 = new Pickup("\033[1;34m☻\033[0m", 20, {5,  8});
    Pickup* pickup19 = new Pickup("\033[1;34m☻\033[0m", 20, {6,  3});
    Pickup* pickup20 = new Pickup("\033[1;34m☻\033[0m", 20, {6,  6});
    Pickup* pickup21 = new Pickup("\033[1;34m☻\033[0m", 20, {6,  9});
    Pickup* pickup22 = new Pickup("\033[1;34m☻\033[0m", 20, {7,  2});
    Pickup* pickup23 = new Pickup("\033[1;34m☻\033[0m", 20, {7,  5});
    Pickup* pickup24 = new Pickup("\033[1;34m☻\033[0m", 20, {7,  8});
    Pickup* pickup25 = new Pickup("\033[1;34m☻\033[0m", 20, {8,  4});

    // 5 pickups verdes (valor 30)
    Pickup* pickup26 = new Pickup("\033[1;32m☻\033[0m", 30, {10, 2});
    Pickup* pickup27 = new Pickup("\033[1;32m☻\033[0m", 30, {10, 6});
    Pickup* pickup28 = new Pickup("\033[1;32m☻\033[0m", 30, {11, 4});
    Pickup* pickup29 = new Pickup("\033[1;32m☻\033[0m", 30, {11, 8});
    Pickup* pickup30 = new Pickup("\033[1;32m☻\033[0m", 30, {12, 5});
    vector<Pickup*> pickups = {
        pickup1,  pickup2,  pickup3,  pickup4,  pickup5,
        pickup6,  pickup7,  pickup8,  pickup9,  pickup10,
        pickup11, pickup12, pickup13, pickup14, pickup15,
        pickup16, pickup17, pickup18, pickup19, pickup20,
        pickup21, pickup22, pickup23, pickup24, pickup25,
        pickup26, pickup27, pickup28, pickup29, pickup30
    };

    
    Spell* sp = new Spell("Light ray", "Rayitos", 15, 5, NOEFFECT);
    Spell* sp1  = new Spell("Sword Slash",    "Corte rápido de espada",        12,  3,  NOEFFECT);
    Spell* sp2  = new Spell("Arrow Shot",     "Disparo certero de flecha",     10,  2,  NOEFFECT);
    Spell* sp3  = new Spell("Flame Burst",    "Explosión ígnea concentrada",   20,  6,  NOEFFECT);

    Spell* sp4  = new Spell("Venom Dart",     "Dardo imbebido en veneno",       8,  4,  POISONED);
    Spell* sp5  = new Spell("Poison Cloud",   "Nube tóxica envenenante",        6,  5,  POISONED);
    Spell* sp6  = new Spell("Toxic Strike",   "Golpe con toxinas potentes",    15,  7,  POISONED);

    Spell* sp7  = new Spell("Shock Wave",     "Ola de choque paralizante",      5,  8,  PARALYZED);
    Spell* sp8  = new Spell("Thunder Clap",   "Aplastante trueno que aturde",  18, 10,  PARALYZED);

    Spell* sp9  = new Spell("Arcane Seal",    "Sello arcano que bloquea magia",  0, 12,  MAGICLESS);
    Spell* sp10 = new Spell("Nullify",        "Anulación de encantamientos",     0,  4,  MAGICLESS);

    vector<Spell*> j1Spells = {sp, sp1, sp3}; 
    vector<Spell*> goblinSpells    = { sp1,       sp2       }; // NOEFFECT
    vector<Spell*> skeletonSpells  = { sp2,       sp1       }; // NOEFFECT
    vector<Spell*> fireElemSpells  = { sp3,       sp2       }; // NOEFFECT
    vector<Spell*> slimeSpells     = { sp4,       sp5       }; // POSIONED
    vector<Spell*> snakeSpells     = { sp4,       sp6       }; // POSIONED
    vector<Spell*> warlockSpells   = { sp5,       sp6       }; // POSIONED
    vector<Spell*> thunderSpells   = { sp7,       sp8       }; // PARALYZED
    vector<Spell*> golemSpells     = { sp9,       sp8       }; // MAGICLESS
    vector<Spell*> wraithSpells    = { sp9,       sp10      }; // MAGICLESS
    vector<Spell*> antSpells       = { sp1,       sp7       }; // NOEFFECT, PARALYZED

    // 10 enemigos distintos
    Enemy* enemy1  = new Enemy("Normal Ant",           30, 30, 2, { 1, 1},  8,  5, goblinSpells,   "°");
    Enemy* enemy2  = new Enemy("Archer Ant",  25, 25, 3, { 3, 5}, 10,  4, skeletonSpells, "°");
    Enemy* enemy3  = new Enemy("Fire Ant",   40, 40, 5, { 5,10}, 12, 20, fireElemSpells, "°");
    Enemy* enemy4  = new Enemy("Poisonous Ant",  20, 20, 4, { 2, 8},  5, 10, slimeSpells,    "°");
    Enemy* enemy5  = new Enemy("Venomous Ant",   18, 18, 3, { 4, 2},  6,  6, snakeSpells,    "°");
    Enemy* enemy6  = new Enemy("Toxic Ant",    22, 22, 6, { 7, 7},  7, 18, warlockSpells,  "°");
    Enemy* enemy7  = new Enemy("Thunder Ant Spirit",   28, 28, 7, { 6, 3},  9, 15, thunderSpells,  "°");
    Enemy* enemy8  = new Enemy("Stone Ant",      60, 60, 8, { 8, 4}, 15,  0, golemSpells,    "°");
    Enemy* enemy9  = new Enemy("Arcane Ant",    35, 35, 7, { 9, 9},  5, 25, wraithSpells,   "°");
    Enemy* enemy10 = new Enemy("Elite Ant",        20, 20, 5, { 2, 3}, 10, 10, antSpells,      "°");
    Enemy* king = new Enemy("Fungus King", 100, 100, 10, {18, 18}, 30, 30, snakeSpells, "■");
        vector<Enemy*> enemies = {
        enemy1, enemy2, enemy3, enemy4, enemy5,
        enemy6, enemy7, enemy8, enemy9, enemy10, king
    };

    Player* j1 = new Player("Ray", j1Spells, "§");
    j1->showSprite();

    Map* board = new Map();
    // GAME LOOP
    while(!win && !lose){
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
            if(battle->checkWin()){
                cout << "HAS GANADO!" << endl;
                j1->levelUp(enemies[enemyToFight]->getLevel() * 10);
                cout << "Has obtenido " << enemies[enemyToFight]->getLevel() * 10 << " de experiencia!" << endl;
                enemies.erase(enemies.begin() + enemyToFight);
            } else if(!j1->checkAlive()){
                cout << "HAS PERDIDOOOOOOO! :(" << endl;
                lose = true;
            } else{
                cout << "Escapaste con exito" << endl;
            }
        }

        
        board->drawMap(j1, enemies, pickups, allies);
    }
    cout << "\nSE ACABO" << endl;
};

void Game::gameLoop(){ 

};