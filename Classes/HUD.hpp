#ifndef HUD_hpp
#define HUD_hpp

#include "cocos2d.h"
using namespace cocos2d;

class HelloWorldScene;

class HUD : public Layer
{
private:
    Menu* pauseMenu;
    Menu* resumeMenu;
    
    int score;
    Size visibleSize;
    Label* scoreLabel;
    
public:
    HUD(void);
    ~HUD(void);
    
    void updateScore(int score);
    void pauseGame(Ref* pSender);
    void resumeGame(Ref* pSender);
    
};












#endif /* HUD_hpp */
