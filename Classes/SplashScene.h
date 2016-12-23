#ifndef __SPLASH_SCENE_H__
#define __SPLASH_SCENE_H__

#include "cocos2d.h"
#include "Definitions.h"

class SplashScene : public cocos2d::Layer
{
public:
    
    static cocos2d::Scene* createScene();

    virtual bool init();
    //void GoToMainMenuScene( float dt );
    // implement the "static create()" method manually
    CREATE_FUNC(SplashScene);


    private:

        void GoToMainMenuScene( float dt );
};

#endif // __SPLASH_SCENE_H__
