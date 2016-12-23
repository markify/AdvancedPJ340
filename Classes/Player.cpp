#include "Player.h"
#include "definitions.h"
#

Player::Player(void){}
Player::~Player(void){}

Player* Player::createPlayer( cocos2d::Layer* layer){
    
    Player* plyr = new Player();
    if(plyr && plyr->initPlayer(layer))
    {
        plyr->autorelease();
        return plyr;
    }
    
    CC_SAFE_DELETE(plyr);
    return NULL;
}

bool Player::initPlayer(cocos2d::Layer* layer){
    
    Size visibleSize = Director::getInstance()->getVisibleSize();   
    Point origin = Director::getInstance( )->getVisibleOrigin( );
    this->initWithFile("Player_ANIM/run_1.png"); //
    this->setPosition( Point(visibleSize.width * 0.25, visibleSize.height/2 * 0.25));
    this->setScale( 0.75 );
    this->runPlayerAnim();
    this->jumpAnim();
    
    return true;
}

void Player::runPlayerAnim(){
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    Vector<SpriteFrame*> animFrames(15);
    char str[100] = {0};
    for(int i = 1; i < 15; i++)
    {
        sprintf(str, "Player_ANIM/run_%d.png", i);
        auto frame = SpriteFrame::create(str, Rect(0,0,375,300));
        animFrames.pushBack(frame);
    }
    
    Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.05f);
    Animate* animate = Animate::create(animation);
    Action* action = RepeatForever::create(animate);
    this->runAction(action);
    
}


void Player::jumpAnim(){
    auto jump = JumpBy::create(1, Vec2(0, 0), 100, 1);
    auto sequence = Sequence::create(jump, nullptr);
    this->runAction(sequence);
    
}

void Player::deathAnim(){
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    Vector<SpriteFrame*> animFrames(10);
    char str[100] = {0};
    for(int i = 1; i <= 9; i++)
    {
        sprintf(str, "Player_Death/hurt_00%d.png", i);
        auto frame = SpriteFrame::create(str, Rect(0,0,375,300));
        animFrames.pushBack(frame);
    }
    
    Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.05f);
    Animate* animate = Animate::create(animation);
    Action* action = RepeatForever::create(animate);
    this->runAction(action);
}
