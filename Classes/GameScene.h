#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include <iostream>
#include <stdio.h>
#include <string>
#include "cocos2d.h"
#include "Definitions.h"

#include "Player.h"
#include "Enemy.h"
#include "HUD.hpp"
#include "ScrollingBg.h"
#include "ScrollingBgLayer.h"
#include "GamePlayLayer.h"

using namespace std;
using namespace cocos2d;
class GameScene : public cocos2d::Layer
{
private:
    
    /**_LAYER_OBJECTS_*/
    GamePlayLayer* gpLayer;
    ScrollingBgLayer* scrollingBgLayer;
    HUD* hud;
    
    /**_CHARACTER_OBJECTS_*/
    Player* player;
    Enemy* enemy;
    
    /**_DISPLAY_&_SCREEN_*/
    Size visibleSize;
    Vec2 origin;
    
    /**_SCORE_**/
    int score;
    
public:
    static cocos2d::Scene* createScene();
    virtual bool init() override;
    bool isGameOver;
    
    /**_UTILITY_*/
    bool onTouchBegan(Touch *touch, Event *event);
    void setTouchEnabled(bool enabled);
    void update(float delta);
    void spawnEnemies(float dt);
    void checkCollisions();
    void gameOver();
    void gameResumed();
    void gamePaused();
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);

};

#endif // __SPLASH_SCENE_H__
