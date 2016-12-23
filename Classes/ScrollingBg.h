#ifndef ScrollingBg_h
#define ScrollingBg_h

#include <iostream>
#include "cocos2d.h"
#include <string>
using namespace std;
using namespace cocos2d;

class ScrollingBg: public Node{

private:
    Sprite* gameBg1, *gameBg2;
    float speed;
    string name;
    Size visibleSize;
public:
    static ScrollingBg* create(string name, float _speed, float _yPos);
    bool initScrollingBg(string _name, float _speed, float _yPos);
    void update();
    
};

#endif /* ScrollingBg_h */
