#include "PlayEasyBgLayer.h"

 


PlayEasyBgLayer::PlayEasyBgLayer()
{
    
}

PlayEasyBgLayer::~PlayEasyBgLayer()
{
    
}


bool PlayEasyBgLayer::init()
{
    Singleton<GameManager>::GetInst()->practice_bg->setAnchorPoint(ccp(0, 0));
    Singleton<GameManager>::GetInst()->practice_bg->setPosition(ccp(0, 0));
    this->addChild(Singleton<GameManager>::GetInst()->practice_bg, -5);
    
    Singleton<GameManager>::GetInst()->practice_frame->setAnchorPoint(ccp(0, 0));
    Singleton<GameManager>::GetInst()->practice_frame->setPosition(ccp(0, 0));
    this->addChild(Singleton<GameManager>::GetInst()->practice_frame, -5);
    
    Singleton<GameManager>::GetInst()->practice_logo->setAnchorPoint(ccp(0.5, 0.5));
    Singleton<GameManager>::GetInst()->practice_logo->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2, CCDirector::sharedDirector()->getWinSize().height/2));
    this->addChild(Singleton<GameManager>::GetInst()->practice_logo, -4);

    
    Singleton<GameManager>::GetInst()->image_do->setVisible(false);
    Singleton<GameManager>::GetInst()->image_do->setAnchorPoint(ccp(0, 0));
    Singleton<GameManager>::GetInst()->image_do->setPosition(ccp(0, 0));
    this->addChild(Singleton<GameManager>::GetInst()->image_do, -3);
    
    Singleton<GameManager>::GetInst()->image_fa->setVisible(false);
    Singleton<GameManager>::GetInst()->image_fa->setAnchorPoint(ccp(0, 0));
    Singleton<GameManager>::GetInst()->image_fa->setPosition(ccp(0, 0));
    this->addChild(Singleton<GameManager>::GetInst()->image_fa, -3);
    
    Singleton<GameManager>::GetInst()->image_mi->setVisible(false);
    Singleton<GameManager>::GetInst()->image_mi->setAnchorPoint(ccp(0, 0));
    Singleton<GameManager>::GetInst()->image_mi->setPosition(ccp(0, 0));
    this->addChild(Singleton<GameManager>::GetInst()->image_mi, -3);
    
    Singleton<GameManager>::GetInst()->image_ra->setVisible(false);
    Singleton<GameManager>::GetInst()->image_ra->setAnchorPoint(ccp(0, 0));
    Singleton<GameManager>::GetInst()->image_ra->setPosition(ccp(0, 0));
    this->addChild(Singleton<GameManager>::GetInst()->image_ra, -3);
    
    Singleton<GameManager>::GetInst()->image_re->setVisible(false);
    Singleton<GameManager>::GetInst()->image_re->setAnchorPoint(ccp(0, 0));
    Singleton<GameManager>::GetInst()->image_re->setPosition(ccp(0, 0));
    this->addChild(Singleton<GameManager>::GetInst()->image_re, -3);
    
    Singleton<GameManager>::GetInst()->image_si->setVisible(false);
    Singleton<GameManager>::GetInst()->image_si->setAnchorPoint(ccp(0, 0));
    Singleton<GameManager>::GetInst()->image_si->setPosition(ccp(0, 0));
    this->addChild(Singleton<GameManager>::GetInst()->image_si, -3);
    
    Singleton<GameManager>::GetInst()->image_so->setVisible(false);
    Singleton<GameManager>::GetInst()->image_so->setAnchorPoint(ccp(0, 0));
    Singleton<GameManager>::GetInst()->image_so->setPosition(ccp(0, 0));
    this->addChild(Singleton<GameManager>::GetInst()->image_so, -3);
    
    
    
    
    
    Singleton<GameManager>::GetInst()->practice_btn_exit_over->setVisible(false);
    Singleton<GameManager>::GetInst()->practice_btn_exit_over->setAnchorPoint(ccp(0, 0));
    Singleton<GameManager>::GetInst()->practice_btn_exit_over->setPosition(ccp(0, 0));
    this->addChild(Singleton<GameManager>::GetInst()->practice_btn_exit_over, -3);
    
    
    Singleton<GameManager>::GetInst()->practice_btn_exit_press->setVisible(false);
    Singleton<GameManager>::GetInst()->practice_btn_exit_press->setAnchorPoint(ccp(0, 0));
    Singleton<GameManager>::GetInst()->practice_btn_exit_press->setPosition(ccp(0, 0));
    this->addChild(Singleton<GameManager>::GetInst()->practice_btn_exit_press, -3);

    
    Singleton<GameManager>::GetInst()->text_do->setVisible(false);
    Singleton<GameManager>::GetInst()->text_do->setAnchorPoint(ccp(0.5, 0.5));
    Singleton<GameManager>::GetInst()->text_do->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2, CCDirector::sharedDirector()->getWinSize().height/2));
    this->addChild(Singleton<GameManager>::GetInst()->text_do, -3);

    Singleton<GameManager>::GetInst()->text_fa->setVisible(false);
    Singleton<GameManager>::GetInst()->text_fa->setAnchorPoint(ccp(0.5, 0.5));
    Singleton<GameManager>::GetInst()->text_fa->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2, CCDirector::sharedDirector()->getWinSize().height/2));
    this->addChild(Singleton<GameManager>::GetInst()->text_fa, -3);
    
    Singleton<GameManager>::GetInst()->text_la->setVisible(false);
    Singleton<GameManager>::GetInst()->text_la->setAnchorPoint(ccp(0.5, 0.5));
    Singleton<GameManager>::GetInst()->text_la->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2, CCDirector::sharedDirector()->getWinSize().height/2));
    this->addChild(Singleton<GameManager>::GetInst()->text_la, -3);
    
    Singleton<GameManager>::GetInst()->text_mi->setVisible(false);
    Singleton<GameManager>::GetInst()->text_mi->setAnchorPoint(ccp(0.5, 0.5));
    Singleton<GameManager>::GetInst()->text_mi->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2, CCDirector::sharedDirector()->getWinSize().height/2));
    this->addChild(Singleton<GameManager>::GetInst()->text_mi, -3);
    
    Singleton<GameManager>::GetInst()->text_re->setVisible(false);
    Singleton<GameManager>::GetInst()->text_re->setAnchorPoint(ccp(0.5, 0.5));
    Singleton<GameManager>::GetInst()->text_re->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2, CCDirector::sharedDirector()->getWinSize().height/2));
    this->addChild(Singleton<GameManager>::GetInst()->text_re, -3);
    
    Singleton<GameManager>::GetInst()->text_so->setVisible(false);
    Singleton<GameManager>::GetInst()->text_so->setAnchorPoint(ccp(0.5, 0.5));
    Singleton<GameManager>::GetInst()->text_so->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2, CCDirector::sharedDirector()->getWinSize().height/2));
    this->addChild(Singleton<GameManager>::GetInst()->text_so, -3);
    
    Singleton<GameManager>::GetInst()->text_ti->setVisible(false);
    Singleton<GameManager>::GetInst()->text_ti->setAnchorPoint(ccp(0.5, 0.5));
    Singleton<GameManager>::GetInst()->text_ti->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2, CCDirector::sharedDirector()->getWinSize().height/2));
    this->addChild(Singleton<GameManager>::GetInst()->text_ti, -3);
    
    
    
    
    return true;
}


void PlayEasyBgLayer::update(float dt)
{
    
    
}

