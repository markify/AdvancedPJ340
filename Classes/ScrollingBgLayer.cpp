#include "ScrollingBgLayer.h" 

ScrollingBgLayer::ScrollingBgLayer(float speed){
    bg = ScrollingBg::create("landscape.png", speed * 0.25, 0);
    this->addChild(bg, -1);
}

ScrollingBgLayer::~ScrollingBgLayer(){}

void ScrollingBgLayer::update(){
    bg->update();
}
