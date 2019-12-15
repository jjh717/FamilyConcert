

#include "LoadScene.h"

LoadScene::LoadScene()
{
    
}

LoadScene::~LoadScene()
{
   
}
bool LoadScene::init()
{
   if( CCScene::init() )
	{
        _load_bg_layer = LoadBgLayer::create();
        /*
        _load_bg_layer->setScaleY(0.5);
        _load_bg_layer->setPosition(ccp(_load_bg_layer->getPositionX(),CCDirector::sharedDirector()->getVisibleSize().height/2));
        
        _load_bg_layer->setScaleY(0.5);
        _load_bg_layer->setPosition(ccp(_load_bg_layer->getPositionX(),0));
        */
        this->addChild(_load_bg_layer, -4);
        
        this->schedule( schedule_selector(LoadScene::update));
        
		return true;
	}
	else
	{
		return false;
	}
}

void LoadScene::update(float dt)
{
    _load_bg_layer->update(dt);
}

 
