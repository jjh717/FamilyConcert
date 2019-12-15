#include "PlayBgLayer_Copy.h"

 


PlayBgLayer_Copy::PlayBgLayer_Copy()
{
    
}

PlayBgLayer_Copy::~PlayBgLayer_Copy()
{
    
}


bool PlayBgLayer_Copy::init()
{
    if(Singleton<GameManager>::GetInst()->gameMode == ANG_FREE)
    {
        Singleton<GameManager>::GetInst()->LoadBG_Free_copy->setAnchorPoint(ccp(0.0f, 0.0f));
        Singleton<GameManager>::GetInst()->LoadBG_Free_copy->setPosition(ccp(0.0f,0.0f));
        
        this->addChild(Singleton<GameManager>::GetInst()->LoadBG_Free_copy, 0);
    }
    else
    {
        Singleton<GameManager>::GetInst()->GameBG_copy->setAnchorPoint(ccp(0.0f, 0.0f));
        Singleton<GameManager>::GetInst()->GameBG_copy->setPosition(ccp(0.0f,0.0f));
        
        this->addChild(Singleton<GameManager>::GetInst()->GameBG_copy, 0);
        
        Singleton<GameManager>::GetInst()->pianoBG_copy->setAnchorPoint(ccp(0.0f, 0.0f));
        Singleton<GameManager>::GetInst()->pianoBG_copy->setPosition(ccp(20,122));
        
        this->addChild(Singleton<GameManager>::GetInst()->pianoBG_copy, 1);
    }
    return true;
}


void PlayBgLayer_Copy::update(float dt)
{
    /*
    if(Singleton<GameManager>::GetInst()->GameBG->getPosition().y < CCDirector::sharedDirector()->getWinSize().height)
    {
        Singleton<GameManager>::GetInst()->GameBG->setPosition(ccp(0.0f,Singleton<GameManager>::getInstance().bgtile1_move));
    }
     */
}


/*
// on "init" you need to initialize your instance
bool PlayBgLayer::init()
{
    char str[100] = {0};
    _interval = 960.0;
    _interval_inverse = 1/_interval;
    move = 0;
    for (int i = 0; i < 3; i++)
    {
        sprintf(str, "HelloWorld%i.png", i);
        _scroll_bg[i] = CCSprite::create(str);
    }
    
    for (int i = 3; i < 5; i++)
    {
        sprintf(str, "HelloWorld%i.png", i-3);
        _scroll_bg[i] = CCSprite::create(str);
    }
    
    for (int i = 0; i < 5; i++)
    {
        _scroll_bg[i]->setAnchorPoint(ccp(0.0f, 0.0f));
        _scroll_bg[i]->setPosition(ccp(0.0f,320.0f*i));
        _scroll_bg[i]->getTexture()->setAliasTexParameters();
        this->addChild(_scroll_bg[i], 0);
    }

    

    return true;
}
*/





/*
 CGPoint position = _player.position;
 double  move = position.x * 0.1;
 int     value = move * _interval_inverse;
 double  offset = -(move - _interval*value);
 
 self.position = ccp(offset, 0.0f);
 */
