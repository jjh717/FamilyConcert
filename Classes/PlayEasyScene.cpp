

#include "PlayEasyScene.h"

PlayEasyScene::PlayEasyScene()
{
    
}

PlayEasyScene::~PlayEasyScene()
{
  
}
bool PlayEasyScene::init()
{
   if( CCScene::init() )
   {
         
       
        _BgLayer = PlayEasyBgLayer::create();
       _BgLayer->retain();
        this->addChild(_BgLayer, -5);
       
       _control_layer = PlayEasyControlLayer::create();
       _control_layer->retain();
       this->addChild(_control_layer, -4);
/*
       std::string keyStingCode= Singleton<GameManager>::GetInst()->keyCheck(3);
       int index = keyStingCode.find("C");
       CCLog("index : %d",index);
       
       std::string keyStingCode1= Singleton<GameManager>::GetInst()->keyCheck(2);
       int index1 = keyStingCode1.find("C");
       CCLog("index1 : %d",index1);
*/
       
		return true;
   }
   else
   {
       return false;
   }
}



void PlayEasyScene::endDelay()
{
    CC_SAFE_RELEASE_NULL(_BgLayer);
    CC_SAFE_RELEASE_NULL(_control_layer);
  
    Singleton<GameManager>::GetInst()->game_end();
}
void PlayEasyScene::update(float dt)
{
    if(Singleton<GameManager>::GetInst()->gameEnding == END_DELAY)
    {
        Singleton<GameManager>::GetInst()->gameEnding = true;
        
        CCDelayTime *delay = CCDelayTime::create(0.5);
        CCCallFuncN *callSelectorAction = CCCallFuncN::create(this, callfuncN_selector(PlayEasyScene::endDelay));
        cocos2d::CCSequence * seq = CCSequence::createWithTwoActions(delay, callSelectorAction);
        this->runAction(seq);
        //
    }

}

