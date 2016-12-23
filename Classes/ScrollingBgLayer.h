#ifndef ScrollingBgLayer_h
#define ScrollingBgLayer_h

#include "ScrollingBg.h"
using namespace cocos2d;

class ScrollingBgLayer : public Layer {
    
private:
    ScrollingBg* bg;
public:
    ScrollingBgLayer(float speed);
    ~ScrollingBgLayer();
    void update();
};


#endif /* ScrollingBgLayer_h */
