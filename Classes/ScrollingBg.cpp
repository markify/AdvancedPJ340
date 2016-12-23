#include "ScrollingBg.h"

ScrollingBg* ScrollingBg::create(string _name, float _speed, float _yPos)
{
    ScrollingBg* ob = new ScrollingBg();
    if(ob && ob->initScrollingBg(_name, _speed, _yPos))
    {
        ob->autorelease();
        return ob;
    }
    
    CC_SAFE_DELETE(ob);
    return NULL;
    
}

bool ScrollingBg::initScrollingBg(string _name, float _speed, float _yPos)
{
    visibleSize = Director::getInstance()->getVisibleSize();
    
    speed = _speed;
    
    gameBg1 = Sprite::create(_name.c_str());
    gameBg2 = Sprite::create(_name.c_str());
    
    
    gameBg1->setScale(visibleSize.width / gameBg1->getContentSize().width, visibleSize.height / gameBg1->getContentSize().height);
    
    gameBg1->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
    gameBg1->setAnchorPoint(Point(0.5,0.5));
    addChild(gameBg1);
    
    gameBg2->setScale(visibleSize.width / gameBg2->getContentSize().width, visibleSize.height / gameBg2->getContentSize().height);

    gameBg2->setPosition(Point(visibleSize.width + (visibleSize.width/2), visibleSize.height/2));
    gameBg2->setAnchorPoint(Point(0.5,0.5));
    addChild(gameBg2);
    
    return true;
}

void ScrollingBg::update()
{
    
    // scroll bg left or right
    Point bg1pos = gameBg1->getPosition();
    gameBg1->setPosition(Point( (bg1pos.x - speed), bg1pos.y) );
    
    
    if(gameBg1->getPosition().x < - visibleSize.width/2 )
        gameBg1->setPosition(Point(visibleSize.width + visibleSize.width/2, gameBg1->getPosition().y));
    
    
    
    Point bg2pos = gameBg2->getPosition();
    gameBg2->setPosition(Point((bg2pos.x - speed), bg2pos.y));
    
    
    if(gameBg2->getPosition().x < - visibleSize.width/2 )
        gameBg2->setPosition(Point(visibleSize.width + visibleSize.width/2,gameBg2->getPosition().y));
    
}
