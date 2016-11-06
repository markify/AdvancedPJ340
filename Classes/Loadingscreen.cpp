#include "Loadingscreen.h"
#include "SimpleAudioEngine.h"
#include "Switchscreen.h"

USING_NS_CC;

Scene* Loadingscreen::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = Loadingscreen::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Loadingscreen::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    this->scheduleOnce( schedule_selector( Loadingscreen::LoadMainMenuScene ), display_time );
    // add "Loadingscreen" splash screen"
    auto backgroundSprite = Sprite::create("dreamtaleloadingscreen.jpeg");

    // position the sprite on the center of the screen
    backgroundSprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(backgroundSprite);

    return true;
}

// transition to main menu
void Loadingscreen::LoadMainMenu( float loadtime )
{
    auto scene = MainMenu::createScene();

    Director::getInstance( )->replaceScene( TransitionFade::create( loading_time , scene ) );
}
