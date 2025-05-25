#include "Map.h"

Map::Map(){

}

Map::~Map(){

}

bool Map::collision(int index){
    return this->tileSet[index] == "#";
}

void Map::drawMap(Player* player, vector<Enemy*> enemies, vector<Pickup*> pickups){
    int playerIndexCalculated = player->getPosition().second * 20 + player->getPosition().first;
    int enemyIndex, pickupIndex;
    bool flag;
    for(int i = 0; i < 400; i++){
        if(i % 20 == 0){
            cout << endl;
        }
        if(i == playerIndexCalculated){
            player->showSprite();
        } else{
            flag = true;
            for(int j = 0; j < enemies.size(); j++){
                enemyIndex = enemies[j]->getPosition().second * 20 + enemies[j]->getPosition().first;
                if(i == enemyIndex){
                    flag = false;
                    enemies[j]->showSprite();
                }
            }
            for(int k = 0; k < pickups.size(); k++){
                pickupIndex = pickups[k]->getPosition().second * 20 + pickups[k]->getPosition().first;
                if(i == pickupIndex){
                    flag = false;
                    pickups[k]->showSprite();
                }
            }
            if(flag){
                cout << this->tileSet[i];
            }
        }
    }
}
