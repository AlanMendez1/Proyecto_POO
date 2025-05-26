#include "Battle.h"

Battle::Battle(){

}

Battle::~Battle(){

}

Battle::Battle(Player* player, Enemy* enemy){
    this->player = player;
    this->enemy = enemy;
}

void Battle::startBattle(){
    bool battleEnd = false;
    int select, dmgToEnemy, dmgToPlayer, random, cont = 0, oldMana;
    pair<int, Effect> usedEnemySpell = {0, NOEFFECT};
    while(!battleEnd){
        if(cont == 0){
            usedEnemySpell = {0, NOEFFECT};
        }
        if(usedEnemySpell.second == POISONED){
            player->receiveDamage(10);
            if(!player->checkAlive()){
                battleEnd = true;
            }
        } else if(usedEnemySpell.second == MAGICLESS && cont == 2){
            oldMana = player->getMana();
            player->setMana(0);
        }
        cout << "====================================================" << endl;
        cout << player->getName() << endl;
        if(player->getHealthPoints() == player->getMaxHealthPoints()){
            string life(player->getHealthPoints()/10, '#');
            cout << '[' << life << ']' << player->getMaxHealthPoints() << "/" << player->getMaxHealthPoints() << endl;
        } else{
            string life(player->getHealthPoints()/10, '#');
            string lifeRemaining((player->getMaxHealthPoints() - player->getHealthPoints())/10, ' ');
            cout << '[' << life << lifeRemaining << ']' << player->getHealthPoints() << "/" << player->getMaxHealthPoints() << endl;
        }

        cout << "====================================================" << endl;
        cout << enemy->getName() << endl;
        if(enemy->getHealthPoints() == enemy->getMaxHealthPoints()){
            string life(enemy->getHealthPoints()/10, '#');
            cout << '[' << life << ']' << enemy->getMaxHealthPoints() << "/" << enemy->getMaxHealthPoints() << endl;
        } else{
            string life(enemy->getHealthPoints()/10, '#');
            string lifeRemaining((enemy->getMaxHealthPoints() - enemy->getHealthPoints())/10, ' ');
            cout << '[' << life << lifeRemaining << ']' << enemy->getHealthPoints() << "/" << enemy->getMaxHealthPoints() << endl;
        }

        if(usedEnemySpell.second != PARALYZED){
            cout << "====================================================" << endl;
            cout << "Seleccione una opcion:\n1. Atacar\n2. Usar habilidad\n3. Escapar" << endl;
            cin >> select;
            switch(select){
                case 1: dmgToEnemy = player->attack();
                        enemy->receiveDamage(dmgToEnemy);
                        cout << "LE HICISTE " << dmgToEnemy << " DE DANIO A " << enemy->getName() << endl;
                        if(!enemy->checkAlive()){
                            battleEnd = true;
                            this->win = true;
                            cout << "ganeeeee" << endl;
                        }
                        break;
                case 2: dmgToEnemy = player->useSpell();
                        enemy->receiveDamage(dmgToEnemy);
                        cout << "LE HICISTE " << dmgToEnemy << " DE DANIO A " << enemy->getName() << endl;
                        if(!enemy->checkAlive()){
                            battleEnd = true;
                            this->win = true;
                        }
                        break;
                case 3: battleEnd = true;
                        break;
                default: break;
            }
        } else{
            cont = cont - 1;
        }
        if(usedEnemySpell.second == MAGICLESS){
            player->setMana(oldMana);
        }
        if(!battleEnd){
            random = rand() % 2;
            switch(random){
                case 0: dmgToPlayer = enemy->getDamage();
                        player->receiveDamage(dmgToPlayer);
                        cout << "Recibiste " << dmgToPlayer << " de danio" << endl;
                        if(!player->checkAlive()){
                            battleEnd = true;
                        }
                        break;
                case 1: cout << "es por aca owo" << endl;
                        usedEnemySpell = enemy->useSpell();
                        cout << "salgo del hechizou" << endl;
                        player->receiveDamage(usedEnemySpell.first);
                        cout << "Recibiste " << usedEnemySpell.first << " de danio" << endl;
                        cont = 2;
                        if(!player->checkAlive()){
                            battleEnd = true;
                        }
                        break;
                default: break;
            }
        }
    }
}

bool Battle::checkWin(){
    return this->win;
}