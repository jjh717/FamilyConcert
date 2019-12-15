#include "PlayEffectLayer.h"

 


PlayEffectLayer::PlayEffectLayer()
{
    
}

PlayEffectLayer::~PlayEffectLayer()
{
    
}


bool PlayEffectLayer::init()
{
    Singleton<GameManager>::GetInst()->SetEffectLayer(this);
    //this->addChild(Singleton<GameManager>::GetInst()->m_emitter,-3);
    
    return true;
}


void PlayEffectLayer::update(float dt)
{
   
}

 
