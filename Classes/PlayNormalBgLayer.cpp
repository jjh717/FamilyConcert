#include "PlayNormalBgLayer.h"

 


PlayNormalBgLayer::PlayNormalBgLayer()
{
    
}

PlayNormalBgLayer::~PlayNormalBgLayer()
{
    
}


bool PlayNormalBgLayer::init()
{
    setIosKeyEnabled(true);
  
    Singleton<GameManager>::GetInst()->normal_bg->setAnchorPoint(ccp(0.0f, 0.0f));
    Singleton<GameManager>::GetInst()->normal_bg->setPosition(ccp(0.0f,0.0f));
    
    this->addChild(Singleton<GameManager>::GetInst()->normal_bg, 0);

    
  
    
    
    
    
  //  this->tutorial_display();
    return true;
}


void PlayNormalBgLayer::tutorial_display_end()
{
    Singleton<GameManager>::GetInst()->tutorial_bg->setVisible(false);
    
    Singleton<GameManager>::GetInst()->tutorial_piano[0]->setVisible(false);
    Singleton<GameManager>::GetInst()->tutorial_piano[1]->setVisible(false);
    Singleton<GameManager>::GetInst()->tutorial_piano[2]->setVisible(false);
    Singleton<GameManager>::GetInst()->tutorial_piano[3]->setVisible(false);
    Singleton<GameManager>::GetInst()->tutorial_piano[4]->setVisible(false);
    Singleton<GameManager>::GetInst()->tutorial_piano[5]->setVisible(false);
    Singleton<GameManager>::GetInst()->tutorial_piano[6]->setVisible(false);
    
    Singleton<GameManager>::GetInst()->tutorialMode = false;
    Singleton<GameManager>::GetInst()->gameStart = true;
    
    tutorialMent->setVisible(false);
}

void PlayNormalBgLayer::update(float dt)
{
    
    
}

/*
void PlayNormalBgLayer::keypadDown(int keyCode, int deviceID)
{
    if(Singleton<GameManager>::GetInst()->tutorialMode)
    {
        CCString keyStringCode = Singleton<GameManager>::GetInst()->keyCheck(keyCode); //c0 ??
        if(keyStringCode.compare("C3")) //도
        {
            Singleton<GameManager>::GetInst()->tutorial_piano[0]->setVisible(true);
            Singleton<GameManager>::GetInst()->keyMatching[0] = true;
        }
        else if(keyStringCode.compare("D3")) //레
        {
            if(Singleton<GameManager>::GetInst()->keyMatching[0])
            {
                Singleton<GameManager>::GetInst()->tutorial_piano[1]->setVisible(true);
                Singleton<GameManager>::GetInst()->keyMatching[1] = true;
            }
        }
        else if(keyStringCode.compare("E3")) //미
        {
            if(Singleton<GameManager>::GetInst()->keyMatching[1])
            {
                Singleton<GameManager>::GetInst()->tutorial_piano[2]->setVisible(true);
                Singleton<GameManager>::GetInst()->keyMatching[2] = true;
            }
        }
        else if(keyStringCode.compare("F3")) //파
        {
            if(Singleton<GameManager>::GetInst()->keyMatching[2])
            {
                Singleton<GameManager>::GetInst()->tutorial_piano[3]->setVisible(true);
                Singleton<GameManager>::GetInst()->keyMatching[3] = true;
            }
        }
        else if(keyStringCode.compare("G3")) //솔
        {
            if(Singleton<GameManager>::GetInst()->keyMatching[3])
            {
                Singleton<GameManager>::GetInst()->tutorial_piano[4]->setVisible(true);
                Singleton<GameManager>::GetInst()->keyMatching[4] = true;
            }
        }
        else if(keyStringCode.compare("A3")) //라
        {
            if(Singleton<GameManager>::GetInst()->keyMatching[4])
            {
                Singleton<GameManager>::GetInst()->tutorial_piano[5]->setVisible(true);
                Singleton<GameManager>::GetInst()->keyMatching[5] = true;
            }
        }
        else if(keyStringCode.compare("B3")) //시
        {
            if(Singleton<GameManager>::GetInst()->keyMatching[5])
            {
                if(!Singleton<GameManager>::GetInst()->keyMatching[6])
                {
                    CCDelayTime *delayAction = CCDelayTime::create(2);
                    CCCallFuncN *callSelectorAction = CCCallFuncN::create(this, callfuncN_selector(PlayNormalBgLayer::tutorial_display_end));
                    
                    this->runAction(CCSequence::create(delayAction, callSelectorAction, NULL));
                }
                Singleton<GameManager>::GetInst()->tutorial_piano[6]->setVisible(true);
                Singleton<GameManager>::GetInst()->keyMatching[6] = true;
            }
        }
    }
    
    
    
    
    
    if(Singleton<GameManager>::GetInst()->firstDeviceID < deviceID)
    {
        //나중에 들어온거
        CCLOG("plz/....");
        if(Singleton<GameManager>::GetInst()->gameMode == ANG_GAME || Singleton<GameManager>::GetInst()->gameMode == ANG_FREE)
        {
            //  _ui_layer_copy->keypadDown(keyCode, deviceID);
        }
        
    }
    else
    {
        //_ui_layer->keypadDown(keyCode, deviceID);
        
    }
}

void PlayNormalBgLayer::keypadUp(int keyCode, int deviceID)
{
    
    if(Singleton<GameManager>::GetInst()->firstDeviceID < deviceID)
    {
        //나중에 들어온거
        if(Singleton<GameManager>::GetInst()->gameMode == ANG_GAME || Singleton<GameManager>::GetInst()->gameMode == ANG_FREE)
        {
            //_ui_layer_copy->keypadDown(keyCode, deviceID);
        }
        
    }
    else
    {
        // _ui_layer->keypadDown(keyCode, deviceID);
        
    }
}




void PlayNormalBgLayer::iosKeypadDown(const char *keyCode)
{
    if(Singleton<GameManager>::GetInst()->tutorialMode)
    {
        std::string keyStringCode;
        if(strcmp(keyCode,"q") == 0)
        {
            keyStringCode = Singleton<GameManager>::GetInst()->keyCheck(39);
        }
        if(strcmp(keyCode,"w") == 0)
        {
            keyStringCode = Singleton<GameManager>::GetInst()->keyCheck(41);
        }
        if(strcmp(keyCode,"e") == 0)
        {
            keyStringCode = Singleton<GameManager>::GetInst()->keyCheck(43);
        }
        if(strcmp(keyCode,"r") == 0)
        {
            keyStringCode = Singleton<GameManager>::GetInst()->keyCheck(44);
        }
        if(strcmp(keyCode,"t") == 0)
        {
            keyStringCode = Singleton<GameManager>::GetInst()->keyCheck(46);
        }
        if(strcmp(keyCode,"y") == 0)
        {
            keyStringCode = Singleton<GameManager>::GetInst()->keyCheck(48);
        }
        if(strcmp(keyCode,"u") == 0)
        {
            keyStringCode = Singleton<GameManager>::GetInst()->keyCheck(50);
        }
        
        
        if(keyStringCode.find("C3") == 0) //도
        {
            if(!Singleton<GameManager>::GetInst()->keyMatching[0])
            {
                Singleton<GameManager>::GetInst()->tutorial_piano[0]->setVisible(true);
                Singleton<GameManager>::GetInst()->keyMatching[0] = true;
                tutorialMent->setString("press D3");
            }
        }
        else if(keyStringCode.find("D3") == 0) //레
        {
            if(Singleton<GameManager>::GetInst()->keyMatching[0] && !Singleton<GameManager>::GetInst()->keyMatching[1])
            {
                Singleton<GameManager>::GetInst()->tutorial_piano[1]->setVisible(true);
                Singleton<GameManager>::GetInst()->keyMatching[1] = true;
                tutorialMent->setString("press E3");
            }
        }
        else if(keyStringCode.find("E3") == 0) //미
        {
            if(Singleton<GameManager>::GetInst()->keyMatching[1] && !Singleton<GameManager>::GetInst()->keyMatching[2])
            {
                Singleton<GameManager>::GetInst()->tutorial_piano[2]->setVisible(true);
                Singleton<GameManager>::GetInst()->keyMatching[2] = true;
                tutorialMent->setString("press F3");
            }
        }
        else if(keyStringCode.find("F3") == 0) //파
        {
            if(Singleton<GameManager>::GetInst()->keyMatching[2] && !Singleton<GameManager>::GetInst()->keyMatching[3])
            {
                Singleton<GameManager>::GetInst()->tutorial_piano[3]->setVisible(true);
                Singleton<GameManager>::GetInst()->keyMatching[3] = true;
                tutorialMent->setString("press G3");
            }
        }
        else if(keyStringCode.find("G3") == 0) //솔
        {
            if(Singleton<GameManager>::GetInst()->keyMatching[3] && !Singleton<GameManager>::GetInst()->keyMatching[4])
            {
                Singleton<GameManager>::GetInst()->tutorial_piano[4]->setVisible(true);
                Singleton<GameManager>::GetInst()->keyMatching[4] = true;
                tutorialMent->setString("press A3");
            }
        }
        else if(keyStringCode.find("A3") == 0) //라
        {
            if(Singleton<GameManager>::GetInst()->keyMatching[4] && !Singleton<GameManager>::GetInst()->keyMatching[5])
            {
                Singleton<GameManager>::GetInst()->tutorial_piano[5]->setVisible(true);
                Singleton<GameManager>::GetInst()->keyMatching[5] = true;
                tutorialMent->setString("press B3");
            }
        }
        else if(keyStringCode.find("B3") == 0) //시
        {
            if(Singleton<GameManager>::GetInst()->keyMatching[5] && !Singleton<GameManager>::GetInst()->keyMatching[6])
            {
                CCDelayTime *delayAction = CCDelayTime::create(2);
                CCCallFuncN *callSelectorAction = CCCallFuncN::create(this, callfuncN_selector(PlayNormalBgLayer::tutorial_display_end));
                
                this->runAction(CCSequence::create(delayAction, callSelectorAction, NULL));

                Singleton<GameManager>::GetInst()->tutorial_piano[6]->setVisible(true);
                Singleton<GameManager>::GetInst()->keyMatching[6] = true;
                tutorialMent->setString("Complete");
            }
        }
    }
    
   
}
*/
void PlayNormalBgLayer::tutorial_display()
{
    Singleton<GameManager>::GetInst()->tutorial_bg->setAnchorPoint(ccp(0, 0));
    Singleton<GameManager>::GetInst()->tutorial_bg->setPosition(ccp(0,0));
    this->addChild(Singleton<GameManager>::GetInst()->tutorial_bg,1);
    
    
    
    
    Singleton<GameManager>::GetInst()->tutorial_piano[0]->setAnchorPoint(ccp(0, 0));
    Singleton<GameManager>::GetInst()->tutorial_piano[0]->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2-120,CCDirector::sharedDirector()->getVisibleSize().height/2-Singleton<GameManager>::GetInst()->tutorial_piano[0]->getContentSize().height/2-120));
    Singleton<GameManager>::GetInst()->tutorial_piano[0]->setVisible(false);
    this->addChild(Singleton<GameManager>::GetInst()->tutorial_piano[0],2);
    
    Singleton<GameManager>::GetInst()->tutorial_piano[1]->setAnchorPoint(ccp(0, 0));
    Singleton<GameManager>::GetInst()->tutorial_piano[1]->setPosition(ccp(Singleton<GameManager>::GetInst()->tutorial_piano[0]->getPositionX()+Singleton<GameManager>::GetInst()->tutorial_piano[0]->getContentSize().width,Singleton<GameManager>::GetInst()->tutorial_piano[0]->getPositionY()));
    Singleton<GameManager>::GetInst()->tutorial_piano[1]->setVisible(false);
    this->addChild(Singleton<GameManager>::GetInst()->tutorial_piano[1],2);
    
    
    Singleton<GameManager>::GetInst()->tutorial_piano[2]->setAnchorPoint(ccp(0, 0));
    Singleton<GameManager>::GetInst()->tutorial_piano[2]->setPosition(ccp(Singleton<GameManager>::GetInst()->tutorial_piano[1]->getPositionX()+Singleton<GameManager>::GetInst()->tutorial_piano[1]->getContentSize().width,Singleton<GameManager>::GetInst()->tutorial_piano[1]->getPositionY()));
    Singleton<GameManager>::GetInst()->tutorial_piano[2]->setVisible(false);
    this->addChild(Singleton<GameManager>::GetInst()->tutorial_piano[2],2);
    
    
    Singleton<GameManager>::GetInst()->tutorial_piano[3]->setAnchorPoint(ccp(0, 0));
    Singleton<GameManager>::GetInst()->tutorial_piano[3]->setPosition(ccp(Singleton<GameManager>::GetInst()->tutorial_piano[2]->getPositionX()+Singleton<GameManager>::GetInst()->tutorial_piano[2]->getContentSize().width,Singleton<GameManager>::GetInst()->tutorial_piano[2]->getPositionY()));
    Singleton<GameManager>::GetInst()->tutorial_piano[3]->setVisible(false);
    this->addChild(Singleton<GameManager>::GetInst()->tutorial_piano[3],2);
    
    
    Singleton<GameManager>::GetInst()->tutorial_piano[4]->setAnchorPoint(ccp(0, 0));
    Singleton<GameManager>::GetInst()->tutorial_piano[4]->setPosition(ccp(Singleton<GameManager>::GetInst()->tutorial_piano[3]->getPositionX()+Singleton<GameManager>::GetInst()->tutorial_piano[3]->getContentSize().width,Singleton<GameManager>::GetInst()->tutorial_piano[3]->getPositionY()));
    Singleton<GameManager>::GetInst()->tutorial_piano[4]->setVisible(false);
    this->addChild(Singleton<GameManager>::GetInst()->tutorial_piano[4],2);
    
    
    Singleton<GameManager>::GetInst()->tutorial_piano[5]->setAnchorPoint(ccp(0, 0));
    Singleton<GameManager>::GetInst()->tutorial_piano[5]->setPosition(ccp(Singleton<GameManager>::GetInst()->tutorial_piano[4]->getPositionX()+Singleton<GameManager>::GetInst()->tutorial_piano[4]->getContentSize().width,Singleton<GameManager>::GetInst()->tutorial_piano[4]->getPositionY()));
    Singleton<GameManager>::GetInst()->tutorial_piano[5]->setVisible(false);
    this->addChild(Singleton<GameManager>::GetInst()->tutorial_piano[5],2);
    
    
    Singleton<GameManager>::GetInst()->tutorial_piano[6]->setAnchorPoint(ccp(0, 0));
    Singleton<GameManager>::GetInst()->tutorial_piano[6]->setPosition(ccp(Singleton<GameManager>::GetInst()->tutorial_piano[5]->getPositionX()+Singleton<GameManager>::GetInst()->tutorial_piano[5]->getContentSize().width,Singleton<GameManager>::GetInst()->tutorial_piano[5]->getPositionY()));
    Singleton<GameManager>::GetInst()->tutorial_piano[6]->setVisible(false);
    this->addChild(Singleton<GameManager>::GetInst()->tutorial_piano[6],2);
    
    
    /*
    tutorialMent = CCLabelTTF::create("press C3", "fonts/Cartoon_Regular.ttf", 68);
	tutorialMent->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2,CCDirector::sharedDirector()->getVisibleSize().height/2));
	tutorialMent->setColor(ccc3(0,255,255));
    CCLog("tutorialMent->getFontName(); %s",tutorialMent->getFontName());
    this->addChild(tutorialMent,3);
*/
}


