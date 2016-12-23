#include "GameplayLayer.h"
GamePlayLayer::GamePlayLayer(){}

GamePlayLayer::~GamePlayLayer(){}

Vector<Enemy*>& GamePlayLayer::getEnemiesVec(){
    return enemies;
}

void GamePlayLayer::update(){
        for(int i = 0; i < enemies.size(); i++)
        {
            Enemy* newEn = (Enemy*)enemies.at(i);
            newEn->update();
            if(newEn->getPositionX() + (newEn->getContentSize().width/2) < 0)
            { enemies.erase(enemies.begin() + i); }
        }
}

