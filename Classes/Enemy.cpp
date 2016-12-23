#include "Enemy.h"
#include "definitions.h"

Enemy::Enemy(void){}
Enemy::~Enemy(void){}

Enemy* Enemy::createEnemy(std::string objName)
{
    Enemy* ene = new Enemy();
    if(ene && ene->initEnemy(objName))
    {
        ene->autorelease();
        return ene;
    }
    
    CC_SAFE_DELETE(ene);
    return NULL;
    
}

bool Enemy::initEnemy(std::string objName)
{
    visibleSize = Director::getInstance()->getVisibleSize();
	
    if (objName == "frog")
    {
        this->initWithFile("frog.png");
        this->setPosition( Point(visibleSize.width + this->getContentSize().width/2 , 0.5));
        this->runFrogAnim();
    }
    if(objName == "alien")
    {
        this->initWithFile("alien_1.png");
        this->setPosition( Point(visibleSize.width + this->getContentSize().width/2 , 0.5));
        this->runAlienAnim();
    }
    
    return true;
}


void Enemy::update()
{
    Point _mp = this->getPosition();
    Point _d = _mp + Point(-3,0);
    this->setPosition(_d);
    
    //create random jump
    int randJump = rand() % 16 + 1; //random number b/w 1 and 16
    if(randJump == 8)
        this->jumpEnemy();
}

void Enemy::jumpEnemy()
{
    auto jump = JumpBy::create(1, Vec2(0, 0), 100, 1);
    auto sequence = Sequence::create(jump, nullptr);
    this->runAction(sequence);
}

void Enemy::runFrogAnim()
{
    
    Vector<SpriteFrame*> animFrames(2);
    auto frame = SpriteFrame::create("frog.png", Rect(0, 0,  58, 39));
    auto frame2 = SpriteFrame::create("frog_leap.png", Rect(0, 0, 61, 54));
    animFrames.pushBack(frame);
    animFrames.pushBack(frame2);
    
    Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.90f);
    Animate *animate = Animate::create(animation);
    Action *action = RepeatForever::create(animate);
    runAction(action);
    
}

void Enemy::runAlienAnim()
{
    
    Vector<SpriteFrame*> animFrames(2);
    auto frame = SpriteFrame::create("alien_1.png", Rect(0, 0,  66, 92));
    auto frame2 = SpriteFrame::create("alien_2.png", Rect(0, 0, 66, 92));
    animFrames.pushBack(frame);
    animFrames.pushBack(frame2);
    
    Animation* animation = Animation::createWithSpriteFrames(animFrames, 2.0f);
    Animate *animate = Animate::create(animation);
    Action *action = RepeatForever::create(animate);
    runAction(action);
    
}





