#ifndef __Loadingscreen_H__
#define __Loadingscreen_H__

#include "cocos2d.h"

class Loadingscreen : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(Loadingscreen);
};
private:
    void LoadMainMenu(float loadtime);

};

#endif // __Loadingscreen_H__
