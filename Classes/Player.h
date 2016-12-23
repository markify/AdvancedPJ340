#ifndef Player_h
#define Player_h

#include "cocos2d.h"
using namespace cocos2d;

class Player : public Sprite {
    
public:
    Player(void);
    ~Player(void);
    bool isFalling;
    
    static Player* createPlayer(cocos2d::Layer *layer);
    
    bool initPlayer( cocos2d::Layer *layer);
    void runPlayerAnim();
    void playerUpdate();
    void jumpAnim();
    void deathAnim();    
};

#endif /* Player_h */
