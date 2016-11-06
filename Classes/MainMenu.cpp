#include "MainMenu.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* MainMenu::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = MainMenu::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // create sprite  background
    auto backgroundSprite = Sprite::create("dreamtalebackgroundmenu.jpeg");
    backgroundSprite->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y ) );
    this->addChild(backgroundSprite);

    // UI play button, exit button sprites

    // transition to game when click on play , exit app when clicked on exit

    return true;
}


void MainMenu::LoadGame(Ref* pSender)
{
    auto scene = GameScene::createScene();
    Director::getInstance( )->replaceScene( TransitionFade::create( loading_time, scene ) );
    //Director::getInstance()->end();
}
