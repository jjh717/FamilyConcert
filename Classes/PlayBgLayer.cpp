#include "PlayBgLayer.h"

 


PlayBgLayer::PlayBgLayer()
{
    
}

PlayBgLayer::~PlayBgLayer()
{
    
}


bool PlayBgLayer::init()
{
    /*
    float x=0, y=0, z=0;
    this->getCamera()->getCenterXYZ(&x, &y, &z);
    CCLOG("PlayBlockLayer_Copy y = %f",y);
    this->getCamera()->setCenterXYZ(x, y+0.0000001, z);
*/
    if(Singleton<GameManager>::GetInst()->gameMode == SINGE_FREE)
    {
        Singleton<GameManager>::GetInst()->LoadBG_Free->setAnchorPoint(ccp(0.0f, 0.0f));
        Singleton<GameManager>::GetInst()->LoadBG_Free->setPosition(ccp(0.0f,0.0f));
        
        this->addChild(Singleton<GameManager>::GetInst()->LoadBG_Free, 0);
        
        
        Singleton<GameManager>::GetInst()->pianoBG->setAnchorPoint(ccp(0.0f, 0.0f));
        Singleton<GameManager>::GetInst()->pianoBG->setPosition(ccp(20,40));
        
        this->addChild(Singleton<GameManager>::GetInst()->pianoBG, 1);

    }
    else if(Singleton<GameManager>::GetInst()->gameMode == ANG_FREE)
    {
        Singleton<GameManager>::GetInst()->LoadBG_Free_copy->setAnchorPoint(ccp(0.0f, 0.0f));
        Singleton<GameManager>::GetInst()->LoadBG_Free_copy->setPosition(ccp(0.0f,0.0f));
        
        this->addChild(Singleton<GameManager>::GetInst()->LoadBG_Free_copy, 0);
    }
    else
    {
        
        Singleton<GameManager>::GetInst()->GameBG->setAnchorPoint(ccp(0.0f, 0.0f));
        Singleton<GameManager>::GetInst()->GameBG->setPosition(ccp(0.0f,136.0f));
        
        this->addChild(Singleton<GameManager>::GetInst()->GameBG, 0);
        
        
     
    }
    
    return true;
}


void PlayBgLayer::update(float dt)
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
