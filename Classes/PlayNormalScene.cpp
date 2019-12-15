#include "PlayNormalScene.h"

PlayNormalScene::PlayNormalScene()
{
    
}

PlayNormalScene::~PlayNormalScene()
{
  
}
bool PlayNormalScene::init()
{
   if( CCScene::init() )
   {
        totalttt = 0;
        Singleton<GameManager>::GetInst()->tutorialMode = true;

        _BgLayer = PlayNormalBgLayer::create();
       _BgLayer->retain();
        this->addChild(_BgLayer, -5);
       
        _ui_layer = PlayNormalUiLayer::create();
       _ui_layer->retain();
        this->addChild(_ui_layer, -4);
       
        _block_layer = PlayNormalBlockLayer::create();
       _block_layer->retain();
        this->addChild(_block_layer, -3);
       
        _control_layer = PlayNormalControlLayer::create();
       _control_layer->retain();
        this->addChild(_control_layer, -2);
       
       
        
        this->schedule( schedule_selector(PlayNormalScene::update));
		return true;
   }
   else
   {
       return false;
   }
}



void PlayNormalScene::endDelay()
{
    CC_SAFE_RELEASE_NULL(_BgLayer);
    CC_SAFE_RELEASE_NULL(_ui_layer);
    CC_SAFE_RELEASE_NULL(_block_layer);
    CC_SAFE_RELEASE_NULL(_control_layer);
    
    Singleton<GameManager>::GetInst()->game_end();
}
void PlayNormalScene::update(float dt)
{
    if(Singleton<GameManager>::GetInst()->gameEnding == END_DELAY)
    {
        Singleton<GameManager>::GetInst()->gameEnding = true;
        
        CCDelayTime *delay = CCDelayTime::create(0.5);
        CCCallFuncN *callSelectorAction = CCCallFuncN::create(this, callfuncN_selector(PlayNormalScene::endDelay));
        cocos2d::CCSequence * seq = CCSequence::createWithTwoActions(delay, callSelectorAction);
        this->runAction(seq);
        //
    }
    
    if(!Singleton<GameManager>::GetInst()->tutorialMode &&
       Singleton<GameManager>::GetInst()->gameEnding == END_FALSE)
    {
        totalttt = totalttt+dt;
  
        Singleton<GameManager>::GetInst()->timeBar->setPercentage(Singleton<GameManager>::GetInst()->timeBar->getPercentage() - ( 100 / (Singleton<GameManager>::GetInst()->maxTime+25))*dt*Singleton<GameManager>::GetInst()->gameSpeed);
        
        if(Singleton<GameManager>::GetInst()->timeBar->getPercentage() <= 0)
        {
            Singleton<GameManager>::GetInst()->game_wait_end();
        }
        _block_layer->update(dt);
        _ui_layer->update(dt);
    }
}


