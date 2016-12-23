#ifndef Enemy_h
#define Enemy_h

#include "cocos2d.h"
using namespace cocos2d;

class Enemy : public Sprite {
    
    public:
    Enemy(void);
    ~Enemy(void);
    
    Size visibleSize;
    Point origin;
    
    static Enemy* createEnemy(std::string objName);
    
    bool initEnemy(std::string objName);
    void runFrogAnim();
    void runAlienAnim();
    void update();
    void jumpEnemy();

};

#endif /* Enemy_h */
