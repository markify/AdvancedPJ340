#ifndef GameplayLayer_hpp
#define GameplayLayer_hpp

#include "cocos2d.h"
#include <vector>

#include "Enemy.h"
#include "Player.h"

using namespace cocos2d;

class GamePlayLayer : public Layer {
    
private:
    Vector<Enemy*> enemies;
public:
    GamePlayLayer();
    ~GamePlayLayer();
    void update();
    Vector<Enemy*>& getEnemiesVec();

};

#endif /* GameplayLayer_hpp */
