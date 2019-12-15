#include "PlayLineLayer.h"

PlayLineLayer::PlayLineLayer()
{
    
}

PlayLineLayer::~PlayLineLayer()
{

}



bool PlayLineLayer::init()
{
 
    Singleton<GameManager>::GetInst()->SetLineLayer(this);
  //  this->addChild(Singleton<GameManager>::GetInst()->m_debugDraw);
    
    
    
    float x=0, y=0, z=0;
    this->getCamera()->getCenterXYZ(&x, &y, &z);
    CCLOG("PlayLineLayer y = %f",y);
    this->getCamera()->setCenterXYZ(x, y+0.0000001, z);

    
    
    
    
    
    
    return true;
}



void PlayLineLayer::update(float dt)
{
   
}

