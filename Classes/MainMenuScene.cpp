#include "MainMenuScene.h"
#include "GameScene.h"
#include "Definitions.h"

USING_NS_CC;

Scene* MainMenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = MainMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto backgroundSprite = Sprite::create( "dt_menu.png" );
    backgroundSprite->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y ) );

    backgroundSprite->setScaleX( 2.5 );
    backgroundSprite->setScaleY( 1.7 );
    this->addChild( backgroundSprite );

    auto playItem = MenuItemImage::create( "play_b.png", "play_b.png", CC_CALLBACK_1( MainMenuScene::GoToGameScene, this ) );
    playItem->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y ) );
    playItem->setScale(1.5);
    auto menu = Menu::create( playItem, NULL );
    menu->setPosition( Point::ZERO );

    this->addChild( menu );

    return true;
}

void MainMenuScene::GoToGameScene( cocos2d::Ref *sender )
{
    auto scene = GameScene::createScene();

    Director::getInstance( )->replaceScene( TransitionFade::create( TRANSITION_TIME, scene ) );
}



