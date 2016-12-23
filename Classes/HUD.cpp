#include "HUD.hpp"
#include "GameScene.h"

HUD::HUD()
{
    visibleSize = Director::getInstance()->getVisibleSize();
    
    __String *tempScore = __String::createWithFormat( "%i", score );
    scoreLabel = Label::createWithTTF( tempScore->getCString( ), "fonts/Marker Felt.ttf", visibleSize.height * 0.05);
    scoreLabel->setColor( Color3B::BLACK );
    scoreLabel->setPosition(Vec2(visibleSize.width * 0.50, visibleSize.height * 0.90));
    scoreLabel->setScale(0.75);
    this->addChild(scoreLabel, 10);
    
    
    MenuItemImage* pauseItem = MenuItemImage::create("pause.png", "pause.png", this, menu_selector(HUD::pauseGame));
    
    pauseItem->setPosition(Vec2(visibleSize.width - pauseItem->getContentSize().width/2,
                                visibleSize.height- pauseItem->getContentSize().height/2));
    
    
    pauseMenu = Menu::create(pauseItem, NULL);
    pauseMenu->setPosition(Vec2::ZERO);
    this->addChild(pauseMenu);
    
}

HUD::~HUD(void)
{
    
}

void HUD::pauseGame(Object* pSender)
{
    
    GameScene* gs = (GameScene*)this->getParent();
    
    if(!gs->isGameOver)
    {
        pauseMenu->setTouchEnabled(false);
        
        MenuItemImage* resumeItem = MenuItemImage::create("resume.png", "resume.png", this, menu_selector(HUD::resumeGame));
        resumeItem->setPosition(Vec2(visibleSize.width * 0.5, visibleSize.height* 0.5));
        
        resumeMenu = Menu::create(resumeItem, NULL);
        resumeMenu->setPosition(Vec2::ZERO);
        this->addChild(resumeMenu);
        
        gs->gamePaused();
    }
}

void HUD::resumeGame(Ref* pSender)
{
    pauseMenu->setTouchEnabled(true);
    this->removeChild(resumeMenu);
    
    GameScene* gs = (GameScene*)this->getParent();
    gs->gameResumed();
    
}

void HUD::updateScore(int score)
{
    char scoreTxt[100];
    sprintf(scoreTxt, "Score: %d", score);
    scoreLabel->setString(scoreTxt);
}
