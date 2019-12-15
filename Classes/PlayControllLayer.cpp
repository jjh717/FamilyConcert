 
#include "PlayControllLayer.h"



PlayControllLayer::PlayControllLayer()
{
    
}


PlayControllLayer::~PlayControllLayer()
{
    for(int a=0;a<88;a++)
    {
        CC_SAFE_RELEASE_NULL(p_shake[a]);
    }

}


bool PlayControllLayer::init()
{
    setIosKeyEnabled(true);
    key_type = 0;
    
    for(int a=0;a<88;a++)
    {
        p_shake[a] = CCShake::createWithStrength(0.1,3,3); //진동
        p_shake[a]->retain();
    }
    
    
   
    Singleton<GameManager>::GetInst()->SetControllLayer(this);
    
    return true;
}
void PlayControllLayer::shakeUpdate(CCNode* sender, int keyCode)
{
    if(keyPressVale[keyCode])
    {
        CCDelayTime *delayAction = CCDelayTime::create(0.1);
        CCCallFuncND *func = CCCallFuncND::create(this, callfuncND_selector(PlayControllLayer::shakeUpdate), (void*)keyCode);
        this->runAction(CCSequence::create(delayAction, func, NULL));
    
    
        Singleton<GameManager>::GetInst()->draw_line[keyCode]->setPosition(ccp(Singleton<GameManager>::GetInst()->DownBlockEndPosX[keyCode], Singleton<GameManager>::GetInst()->startBlockPoint));
        Singleton<GameManager>::GetInst()->draw_line[keyCode]->setOpacity(255);
        Singleton<GameManager>::GetInst()->draw_line[keyCode]->stopAllActions();
        Singleton<GameManager>::GetInst()->draw_line[keyCode]->runAction(p_shake[keyCode]);
    }
    else
    {
        Singleton<GameManager>::GetInst()->draw_line[keyCode]->setPosition(ccp(Singleton<GameManager>::GetInst()->DownBlockEndPosX[keyCode], Singleton<GameManager>::GetInst()->startBlockPoint));
        Singleton<GameManager>::GetInst()->draw_line[keyCode]->stopAllActions();
        Singleton<GameManager>::GetInst()->draw_line[keyCode]->setOpacity(LINE_OPACITY);
    //    Singleton<GameManager>::GetInst()->hit_yellow_effect_rotate[keyCode] = 0;
        Singleton<GameManager>::GetInst()->piano_press_sprite[keyCode]->setVisible(false);
    }
}




void PlayControllLayer::keypadDown(int keyCode, int deviceID)
{
   
    if(Singleton<GameManager>::GetInst()->tutorialMode)
    {
        std::string keyStringCode = Singleton<GameManager>::GetInst()->keyCheck(keyCode);

        if(keyStringCode.find("C3") == 0) //도
        {
            if(!Singleton<GameManager>::GetInst()->keyMatching[0])
            {
                Singleton<GameManager>::GetInst()->tutorial_piano[0]->setVisible(true);
                Singleton<GameManager>::GetInst()->keyMatching[0] = true;

                Singleton<GameManager>::GetInst()->tutorialMent1->setVisible(false);
                Singleton<GameManager>::GetInst()->tutorialMent2->setVisible(true);
            }
        }
        else if(keyStringCode.find("D3") == 0) //레
        {
            if(Singleton<GameManager>::GetInst()->keyMatching[0] && !Singleton<GameManager>::GetInst()->keyMatching[1])
            {
                Singleton<GameManager>::GetInst()->tutorial_piano[1]->setVisible(true);
                Singleton<GameManager>::GetInst()->keyMatching[1] = true;
                Singleton<GameManager>::GetInst()->tutorialMent1->setVisible(false);
                Singleton<GameManager>::GetInst()->tutorialMent2->setVisible(false);
                Singleton<GameManager>::GetInst()->tutorialMent3->setVisible(true);
            }
        }
        else if(keyStringCode.find("E3") == 0) //미
        {
            if(Singleton<GameManager>::GetInst()->keyMatching[1] && !Singleton<GameManager>::GetInst()->keyMatching[2])
            {
                Singleton<GameManager>::GetInst()->tutorial_piano[2]->setVisible(true);
                Singleton<GameManager>::GetInst()->keyMatching[2] = true;
                Singleton<GameManager>::GetInst()->tutorialMent1->setVisible(false);
                Singleton<GameManager>::GetInst()->tutorialMent2->setVisible(false);
                Singleton<GameManager>::GetInst()->tutorialMent3->setVisible(false);
                Singleton<GameManager>::GetInst()->tutorialMent4->setVisible(true);
            }
        }
        else if(keyStringCode.find("F3") == 0) //파
        {
            if(Singleton<GameManager>::GetInst()->keyMatching[2] && !Singleton<GameManager>::GetInst()->keyMatching[3])
            {
                Singleton<GameManager>::GetInst()->tutorial_piano[3]->setVisible(true);
                Singleton<GameManager>::GetInst()->keyMatching[3] = true;
                Singleton<GameManager>::GetInst()->tutorialMent1->setVisible(false);
                Singleton<GameManager>::GetInst()->tutorialMent2->setVisible(false);
                Singleton<GameManager>::GetInst()->tutorialMent3->setVisible(false);
                Singleton<GameManager>::GetInst()->tutorialMent4->setVisible(false);
                Singleton<GameManager>::GetInst()->tutorialMent5->setVisible(true);
            }
        }
        else if(keyStringCode.find("G3") == 0) //솔
        {
            if(Singleton<GameManager>::GetInst()->keyMatching[3] && !Singleton<GameManager>::GetInst()->keyMatching[4])
            {
                Singleton<GameManager>::GetInst()->tutorial_piano[4]->setVisible(true);
                Singleton<GameManager>::GetInst()->keyMatching[4] = true;
                Singleton<GameManager>::GetInst()->tutorialMent1->setVisible(false);
                Singleton<GameManager>::GetInst()->tutorialMent2->setVisible(false);
                Singleton<GameManager>::GetInst()->tutorialMent3->setVisible(false);
                Singleton<GameManager>::GetInst()->tutorialMent4->setVisible(false);
                Singleton<GameManager>::GetInst()->tutorialMent5->setVisible(false);
                Singleton<GameManager>::GetInst()->tutorialMent6->setVisible(true);
               // Singleton<GameManager>::GetInst()->tutorialMent = CCLabelTTF::create("Press C3 key..", "fonts/Cartoon_Regular.ttf", 50);
            }
        }
        else if(keyStringCode.find("A3") == 0) //라
        {
            if(Singleton<GameManager>::GetInst()->keyMatching[4] && !Singleton<GameManager>::GetInst()->keyMatching[5])
            {
                Singleton<GameManager>::GetInst()->tutorial_piano[5]->setVisible(true);
                Singleton<GameManager>::GetInst()->keyMatching[5] = true;
                Singleton<GameManager>::GetInst()->tutorialMent1->setVisible(false);
                Singleton<GameManager>::GetInst()->tutorialMent2->setVisible(false);
                Singleton<GameManager>::GetInst()->tutorialMent3->setVisible(false);
                Singleton<GameManager>::GetInst()->tutorialMent4->setVisible(false);
                Singleton<GameManager>::GetInst()->tutorialMent5->setVisible(false);
                Singleton<GameManager>::GetInst()->tutorialMent6->setVisible(false);
                Singleton<GameManager>::GetInst()->tutorialMent7->setVisible(true);
            }
        }
        else if(keyStringCode.find("B3") == 0) //시
        {
            if(Singleton<GameManager>::GetInst()->keyMatching[5] && !Singleton<GameManager>::GetInst()->keyMatching[6])
            {
                CCDelayTime *delayAction = CCDelayTime::create(2);
                CCCallFuncN *callSelectorAction = CCCallFuncN::create(this, callfuncN_selector(PlayControllLayer::tutorial_display_end));

                this->runAction(CCSequence::create(delayAction, callSelectorAction, NULL));

                Singleton<GameManager>::GetInst()->tutorial_piano[6]->setVisible(true);
                Singleton<GameManager>::GetInst()->keyMatching[6] = true;
                Singleton<GameManager>::GetInst()->tutorialMent1->setVisible(false);
                Singleton<GameManager>::GetInst()->tutorialMent2->setVisible(false);
                Singleton<GameManager>::GetInst()->tutorialMent3->setVisible(false);
                Singleton<GameManager>::GetInst()->tutorialMent4->setVisible(false);
                Singleton<GameManager>::GetInst()->tutorialMent5->setVisible(false);
                Singleton<GameManager>::GetInst()->tutorialMent6->setVisible(false);
                Singleton<GameManager>::GetInst()->tutorialMent7->setVisible(false);
                Singleton<GameManager>::GetInst()->tutorialMent8->setVisible(true);
            }
        }
    }

    if(!Singleton<GameManager>::GetInst()->tutorialMode)
    {
        if(Singleton<GameManager>::GetInst()->gameMode == ANG_FREE || Singleton<GameManager>::GetInst()->gameMode == SINGE_FREE) // ang
        {
            Singleton<GameManager>::GetInst()->piano_press_sprite[keyCode]->setVisible(true);
        }
        else
        {
            
            CCDelayTime *delayAction = CCDelayTime::create(0.1);
            CCCallFuncND *func = CCCallFuncND::create(this, callfuncND_selector(PlayControllLayer::shakeUpdate), (void*)keyCode);
            this->runAction(CCSequence::create(delayAction, func, NULL));
            
            keyPressVale[keyCode] = true;
            
            Singleton<GameManager>::GetInst()->draw_line[keyCode]->setPosition(ccp(Singleton<GameManager>::GetInst()->DownBlockEndPosX[keyCode], Singleton<GameManager>::GetInst()->startBlockPoint));
            Singleton<GameManager>::GetInst()->draw_line[keyCode]->setOpacity(255);
            Singleton<GameManager>::GetInst()->draw_line[keyCode]->stopAllActions();
            Singleton<GameManager>::GetInst()->draw_line[keyCode]->runAction(p_shake[keyCode]);
            Singleton<GameManager>::GetInst()->piano_press_sprite[keyCode]->setVisible(true);
            Singleton<GameManager>::GetInst()->checkCollisionBox(keyCode);
        }
    }
}

void PlayControllLayer::keypadUp(int keyCode, int deviceID)
{
    if(!Singleton<GameManager>::GetInst()->tutorialMode)
    {
        if(Singleton<GameManager>::GetInst()->gameMode == ANG_FREE || Singleton<GameManager>::GetInst()->gameMode == SINGE_FREE) // ang
        {
            Singleton<GameManager>::GetInst()->piano_press_sprite[keyCode]->setVisible(false);
        }
        else
        {
            keyPressVale[keyCode] = false;
            
            Singleton<GameManager>::GetInst()->draw_line[keyCode]->setPosition(ccp(Singleton<GameManager>::GetInst()->DownBlockEndPosX[keyCode], Singleton<GameManager>::GetInst()->startBlockPoint));
            Singleton<GameManager>::GetInst()->draw_line[keyCode]->stopAllActions();
            Singleton<GameManager>::GetInst()->draw_line[keyCode]->setOpacity(LINE_OPACITY);
       //     Singleton<GameManager>::GetInst()->hit_yellow_effect_rotate[keyCode] = 0;
            Singleton<GameManager>::GetInst()->piano_press_sprite[keyCode]->setVisible(false);
        }
    }
}

void PlayControllLayer::iosKeypadUp(const char *keyCode)
{
    
    
    if(strcmp(keyCode,"q") == 0)
    {
        CCDelayTime *delayAction = CCDelayTime::create(2);
        CCCallFuncN *callSelectorAction = CCCallFuncN::create(this, callfuncN_selector(PlayControllLayer::tutorial_display_end));
        
        this->runAction(CCSequence::create(delayAction, callSelectorAction, NULL));
    
        
        /*
        keyPressVale[44] = false;
        
        Singleton<GameManager>::GetInst()->draw_line[44]->setPosition(ccp(Singleton<GameManager>::GetInst()->DownBlockEndPosX[44], Singleton<GameManager>::GetInst()->startBlockPoint));
        Singleton<GameManager>::GetInst()->draw_line[44]->stopAllActions();
        Singleton<GameManager>::GetInst()->draw_line[44]->setOpacity(LINE_OPACITY);
        Singleton<GameManager>::GetInst()->hit_yellow_effect_rotate[44] = 0;
        Singleton<GameManager>::GetInst()->piano_press_sprite[44]->setVisible(false);
*/
        /*
        CCLOG("iosKeypadUp : %s",keyCode);
        Singleton<GameManager>::GetInst()->draw_line[46]->setOpacity(LINE_OPACITY);
        Singleton<GameManager>::GetInst()->hit_yellow_effect_rotate[46] = 0;
        Singleton<GameManager>::GetInst()->piano_press_sprite[46]->setVisible(false);
         */
    }
    if(strcmp(keyCode,"w") == 0)
    {
        Singleton<GameManager>::GetInst()->checkCollisionBox(keyCode);
      //  keyPressVale[45] = false;
        /*
         CCLOG("iosKeypadUp : %s",keyCode);
         Singleton<GameManager>::GetInst()->draw_line[46]->setOpacity(LINE_OPACITY);
         Singleton<GameManager>::GetInst()->hit_yellow_effect_rotate[46] = 0;
         Singleton<GameManager>::GetInst()->piano_press_sprite[46]->setVisible(false);
         */
    }
}

void PlayControllLayer::tutorial_display_end()
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
    
    Singleton<GameManager>::GetInst()->tutorialMent8->setVisible(false);
}

void PlayControllLayer::iosKeypadDown(const char *keyCode)
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
        
        /*
        if(keyStringCode.find("C3") == 0) //도
        {
            if(!Singleton<GameManager>::GetInst()->keyMatching[0])
            {
                Singleton<GameManager>::GetInst()->tutorial_piano[0]->setVisible(true);
                Singleton<GameManager>::GetInst()->keyMatching[0] = true;
                Singleton<GameManager>::GetInst()->tutorialMent->setString("Press D3 key..");
            }
        }
        else if(keyStringCode.find("D3") == 0) //레
        {
            if(Singleton<GameManager>::GetInst()->keyMatching[0] && !Singleton<GameManager>::GetInst()->keyMatching[1])
            {
                Singleton<GameManager>::GetInst()->tutorial_piano[1]->setVisible(true);
                Singleton<GameManager>::GetInst()->keyMatching[1] = true;
                Singleton<GameManager>::GetInst()->tutorialMent->setString("Press E3 key..");
            }
        }
        else if(keyStringCode.find("E3") == 0) //미
        {
            if(Singleton<GameManager>::GetInst()->keyMatching[1] && !Singleton<GameManager>::GetInst()->keyMatching[2])
            {
                Singleton<GameManager>::GetInst()->tutorial_piano[2]->setVisible(true);
                Singleton<GameManager>::GetInst()->keyMatching[2] = true;
                Singleton<GameManager>::GetInst()->tutorialMent->setString("Press F3 key..");
            }
        }
        else if(keyStringCode.find("F3") == 0) //파
        {
            if(Singleton<GameManager>::GetInst()->keyMatching[2] && !Singleton<GameManager>::GetInst()->keyMatching[3])
            {
                Singleton<GameManager>::GetInst()->tutorial_piano[3]->setVisible(true);
                Singleton<GameManager>::GetInst()->keyMatching[3] = true;
                Singleton<GameManager>::GetInst()->tutorialMent->setString("Press G3 key..");
            }
        }
        else if(keyStringCode.find("G3") == 0) //솔
        {
            if(Singleton<GameManager>::GetInst()->keyMatching[3] && !Singleton<GameManager>::GetInst()->keyMatching[4])
            {
                Singleton<GameManager>::GetInst()->tutorial_piano[4]->setVisible(true);
                Singleton<GameManager>::GetInst()->keyMatching[4] = true;
                Singleton<GameManager>::GetInst()->tutorialMent->setString("Press A3 key..");
            }
        }
        else if(keyStringCode.find("A3") == 0) //라
        {
            if(Singleton<GameManager>::GetInst()->keyMatching[4] && !Singleton<GameManager>::GetInst()->keyMatching[5])
            {
                Singleton<GameManager>::GetInst()->tutorial_piano[5]->setVisible(true);
                Singleton<GameManager>::GetInst()->keyMatching[5] = true;
                Singleton<GameManager>::GetInst()->tutorialMent->setString("Press B3 key..");
            }
        }
        else if(keyStringCode.find("B3") == 0) //시
        {
            if(Singleton<GameManager>::GetInst()->keyMatching[5] && !Singleton<GameManager>::GetInst()->keyMatching[6])
            {
                CCDelayTime *delayAction = CCDelayTime::create(2);
                CCCallFuncN *callSelectorAction = CCCallFuncN::create(this, callfuncN_selector(PlayControllLayer::tutorial_display_end));
                
                this->runAction(CCSequence::create(delayAction, callSelectorAction, NULL));
                
                Singleton<GameManager>::GetInst()->tutorial_piano[6]->setVisible(true);
                Singleton<GameManager>::GetInst()->keyMatching[6] = true;
                Singleton<GameManager>::GetInst()->tutorialMent->setString("Tutorial Complete!!");
            }
        }
        */
    }

    
    //Singleton<GameManager>::GetInst()->checkCollisionBox(keyCode);
    
  //  sprintf(str, "piano/%d.wav", 1);
  //  CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(str);
   // CCLOG("iosKeypadDown : %s",keyCode);
  //   CCLOG("aa %s", keyCode);
/*
    switch (keyCode)
    {
        case "q":
            
            break;
            
        default:
            break;
    }
*/
//
//    Singleton<GameManager>::GetInst()->piano_press_sprite[0]->setVisible(true);
    if(strcmp(keyCode,"q") == 0) //switch 臾몄�濡�諛�씀��
    {
                
        
        /*
        CCDelayTime *delayAction = CCDelayTime::create(0.1);
        CCCallFuncND *func = CCCallFuncND::create(this, callfuncND_selector(PlayControllLayer::shakeUpdate), (void*)44);
        this->runAction(CCSequence::create(delayAction, func, NULL));
        
        keyPressVale[44] = true;
        
        Singleton<GameManager>::GetInst()->draw_line[44]->setPosition(ccp(Singleton<GameManager>::GetInst()->DownBlockEndPosX[44], Singleton<GameManager>::GetInst()->startBlockPoint));
        Singleton<GameManager>::GetInst()->draw_line[44]->setOpacity(255);
        Singleton<GameManager>::GetInst()->draw_line[44]->stopAllActions();
        Singleton<GameManager>::GetInst()->draw_line[44]->runAction(p_shake[44]);
        Singleton<GameManager>::GetInst()->piano_press_sprite[44]->setVisible(true);
        Singleton<GameManager>::GetInst()->checkCollisionBox(44);
*/
        
        /*
        if(Singleton<GameManager>::GetInst()->remoteUpDownPosition > 0 && Singleton<GameManager>::GetInst()->gameMode != SINGE_FREE && Singleton<GameManager>::GetInst()->gameMode != ANG_FREE)
        {
            --Singleton<GameManager>::GetInst()->remoteUpDownPosition;
            Singleton<GameManager>::GetInst()->remoteUpDownController(Singleton<GameManager>::GetInst()->remoteUpDownPosition);
            Singleton<GameManager>::GetInst()->remoteUpDownOverImage(Singleton<GameManager>::GetInst()->remoteUpDownPosition);
            Singleton<GameManager>::GetInst()->remoteController(-1);
            Singleton<GameManager>::GetInst()->remoteOverImage(-1);
            
        }
        
        if(Singleton<GameManager>::GetInst()->remoteUpDownPosition == 0 && Singleton<GameManager>::GetInst()->gameMode != SINGE_FREE && Singleton<GameManager>::GetInst()->gameMode != ANG_FREE)
        {
            Singleton<GameManager>::GetInst()->remoteController(Singleton<GameManager>::GetInst()->remotePosition);
            Singleton<GameManager>::GetInst()->remoteOverImage(Singleton<GameManager>::GetInst()->remotePosition);
        }
        if(Singleton<GameManager>::GetInst()->remoteUpDownPosition > 0 && Singleton<GameManager>::GetInst()->gameMode == SINGE_FREE)
        {
            --Singleton<GameManager>::GetInst()->remoteUpDownPosition;
            CCLog("remoteUpDownPosition : %d",Singleton<GameManager>::GetInst()->remoteUpDownPosition);
            Singleton<GameManager>::GetInst()->FreeremoteController(Singleton<GameManager>::GetInst()->remotePosition);
            Singleton<GameManager>::GetInst()->remoteOverImageFree(Singleton<GameManager>::GetInst()->remotePosition);
            //Singleton<GameManager>::GetInst()->remoteUpDownController(Singleton<GameManager>::GetInst()->remoteUpDownPosition);
            //Singleton<GameManager>::GetInst()->remoteUpDownOverImage(Singleton<GameManager>::GetInst()->remoteUpDownPosition);
        }
         */
    }
    else if(strcmp(keyCode,"w") == 0)
    {
        
        
                /*
        CCDelayTime *delayAction = CCDelayTime::create(0.1);
        CCCallFuncND *func = CCCallFuncND::create(this, callfuncND_selector(PlayControllLayer::shakeUpdate), (void*)45);
        this->runAction(CCSequence::create(delayAction, func, NULL));
        
        keyPressVale[45] = true;
        
        
        Singleton<GameManager>::GetInst()->draw_line[45]->setPosition(ccp(Singleton<GameManager>::GetInst()->DownBlockEndPosX[45], Singleton<GameManager>::GetInst()->startBlockPoint));
        Singleton<GameManager>::GetInst()->draw_line[45]->setOpacity(255);
   //     Singleton<GameManager>::GetInst()->draw_line[45]->stopAction(Singleton<GameManager>::GetInst()->p_shake);
   //     Singleton<GameManager>::GetInst()->draw_line[45]->runAction(Singleton<GameManager>::GetInst()->p_shake);
        Singleton<GameManager>::GetInst()->piano_press_sprite[45]->setVisible(true);
*/
        
        /*
        if(Singleton<GameManager>::GetInst()->remoteUpDownPosition < 3 && Singleton<GameManager>::GetInst()->gameMode != SINGE_FREE && Singleton<GameManager>::GetInst()->gameMode != ANG_FREE)
        {
            ++Singleton<GameManager>::GetInst()->remoteUpDownPosition;
            Singleton<GameManager>::GetInst()->remoteUpDownController(Singleton<GameManager>::GetInst()->remoteUpDownPosition);
            Singleton<GameManager>::GetInst()->remoteUpDownOverImage(Singleton<GameManager>::GetInst()->remoteUpDownPosition);
            Singleton<GameManager>::GetInst()->remoteController(-1);
            Singleton<GameManager>::GetInst()->remoteOverImage(-1);
        }
        if(Singleton<GameManager>::GetInst()->remoteUpDownPosition < 1 && Singleton<GameManager>::GetInst()->gameMode == SINGE_FREE)
        {
            ++Singleton<GameManager>::GetInst()->remoteUpDownPosition;
            CCLog("remoteUpDownPosition : %d",Singleton<GameManager>::GetInst()->remoteUpDownPosition);
            Singleton<GameManager>::GetInst()->FreeremoteController(-1);
            Singleton<GameManager>::GetInst()->remoteOverImageFree(-1);
            //Singleton<GameManager>::GetInst()->remoteUpDownController(Singleton<GameManager>::GetInst()->remoteUpDownPosition);
            //Singleton<GameManager>::GetInst()->remoteUpDownOverImage(Singleton<GameManager>::GetInst()->remoteUpDownPosition);
        }
         */
    }
    else if(strcmp(keyCode,"e") == 0)
    {
        
    }
    else if(strcmp(keyCode,"r") == 0)
    {
        

    }
    else if(strcmp(keyCode,"t") == 0)
    {
        if(Singleton<GameManager>::GetInst()->remoteUpDownPosition == 0)
        {
            int position = Singleton<GameManager>::GetInst()->remotePosition;

            if(Singleton<GameManager>::GetInst()->gameMode == SINGE_FREE || Singleton<GameManager>::GetInst()->gameMode == ANG_FREE) //free
            {
                if(position == 0)
                {
                    Singleton<GameManager>::GetInst()->remoteOverPosition[0] = Singleton<GameManager>::GetInst()->remotePosition;
                    Singleton<GameManager>::GetInst()->acousticButtonPress();
                }
                if(position == 1)
                {
                    Singleton<GameManager>::GetInst()->remoteOverPosition[0] = Singleton<GameManager>::GetInst()->remotePosition;
                    Singleton<GameManager>::GetInst()->brightButtonPress();
                }
                if(position == 2)
                {
                    Singleton<GameManager>::GetInst()->remoteOverPosition[0] = Singleton<GameManager>::GetInst()->remotePosition;
                    Singleton<GameManager>::GetInst()->chorusButtonPress();
                }
                if(position == 3)
                {
                    Singleton<GameManager>::GetInst()->remoteOverPosition[0] = Singleton<GameManager>::GetInst()->remotePosition;
                    Singleton<GameManager>::GetInst()->electricButtonPress();
                }
                if(position == 4)
                {
                    Singleton<GameManager>::GetInst()->remoteOverPosition[0] = Singleton<GameManager>::GetInst()->remotePosition;
                    Singleton<GameManager>::GetInst()->hongkyButtonPress();
                }
                if(position == 5)
                {
                    Singleton<GameManager>::GetInst()->remoteOverPosition[0] = Singleton<GameManager>::GetInst()->remotePosition;
                    Singleton<GameManager>::GetInst()->rhodesButtonPress();
                }
                
                
                if(position == 6)
                {
                    Singleton<GameManager>::GetInst()->remoteOverPosition[1] = Singleton<GameManager>::GetInst()->remotePosition;
                    Singleton<GameManager>::GetInst()->pianoRainbowButtonPress();
                }
                if(position == 7)
                {
                    Singleton<GameManager>::GetInst()->remoteOverPosition[1] = Singleton<GameManager>::GetInst()->remotePosition;
                    Singleton<GameManager>::GetInst()->pianoMarkButtonPress();
                }
                if(position == 8)
                {
                    Singleton<GameManager>::GetInst()->remoteOverPosition[1] = Singleton<GameManager>::GetInst()->remotePosition;
                    Singleton<GameManager>::GetInst()->pianoNormalButtonPress();
                }
                
            }
            else
            {
                if(Singleton<GameManager>::GetInst()->remotePosition == 0)
                {
                    Singleton<GameManager>::GetInst()->escButtonPress();
                }
                if(position == 1)
                {
                    Singleton<GameManager>::GetInst()->pauseButtonPress();
                }
                if(position == 2)
                {
                    Singleton<GameManager>::GetInst()->remoteOverPosition[0] = position;
                    Singleton<GameManager>::GetInst()->x1SpeedButtonPress();
                }
                if(position == 3)
                {
                    Singleton<GameManager>::GetInst()->remoteOverPosition[0] = position;
                    Singleton<GameManager>::GetInst()->x2SpeedButtonPress();
                }
                if(position == 4)
                {
                    Singleton<GameManager>::GetInst()->remoteOverPosition[0] = position;
                    Singleton<GameManager>::GetInst()->x12SpeedButtonPress();
                }
                if(position == 5)
                {
                    Singleton<GameManager>::GetInst()->remoteOverPosition[0] = position;
                    Singleton<GameManager>::GetInst()->x14SpeedButtonPress();
                }
                
                
                
                
                if(position == 6)
                {
                    Singleton<GameManager>::GetInst()->remoteOverPosition[1] = Singleton<GameManager>::GetInst()->remotePosition;
                    Singleton<GameManager>::GetInst()->acousticButtonPress();
                }
                if(position == 7)
                {
                    Singleton<GameManager>::GetInst()->remoteOverPosition[1] = Singleton<GameManager>::GetInst()->remotePosition;
                    Singleton<GameManager>::GetInst()->brightButtonPress();
                }
                if(position == 8)
                {
                    Singleton<GameManager>::GetInst()->remoteOverPosition[1] = Singleton<GameManager>::GetInst()->remotePosition;
                    Singleton<GameManager>::GetInst()->chorusButtonPress();
                }
                if(position == 9)
                {
                    Singleton<GameManager>::GetInst()->remoteOverPosition[1] = Singleton<GameManager>::GetInst()->remotePosition;
                    Singleton<GameManager>::GetInst()->electricButtonPress();
                }
                if(position == 10)
                {
                    Singleton<GameManager>::GetInst()->remoteOverPosition[1] = Singleton<GameManager>::GetInst()->remotePosition;
                    Singleton<GameManager>::GetInst()->hongkyButtonPress();
                }
                if(position == 11)
                {
                    Singleton<GameManager>::GetInst()->remoteOverPosition[1] = Singleton<GameManager>::GetInst()->remotePosition;
                    Singleton<GameManager>::GetInst()->rhodesButtonPress();
                }
            }
        }
        else
        {
            if(Singleton<GameManager>::GetInst()->gameMode == SINGE_FREE)
            {
                Singleton<GameManager>::GetInst()->escButtonPress();
            }
            else
            {
                if(Singleton<GameManager>::GetInst()->remoteUpDownPosition == 1)
                {
                    Singleton<GameManager>::GetInst()->remoteUpDownOverPosition = Singleton<GameManager>::GetInst()->remoteUpDownPosition;
                    Singleton<GameManager>::GetInst()->pianoNormalButtonPress();
                }
                else if(Singleton<GameManager>::GetInst()->remoteUpDownPosition == 2)
                {
                    Singleton<GameManager>::GetInst()->remoteUpDownOverPosition = Singleton<GameManager>::GetInst()->remoteUpDownPosition;
                    Singleton<GameManager>::GetInst()->pianoMarkButtonPress();
                }
                else if(Singleton<GameManager>::GetInst()->remoteUpDownPosition == 3)
                {
                    Singleton<GameManager>::GetInst()->remoteUpDownOverPosition = Singleton<GameManager>::GetInst()->remoteUpDownPosition;
                    Singleton<GameManager>::GetInst()->pianoRainbowButtonPress();
                }
            }
            
        }
    }
    else if(strcmp(keyCode,"y") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[5]->setVisible(true);
    }
    else if(strcmp(keyCode,"u") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[6]->setVisible(true);
    }
    else if(strcmp(keyCode,"i") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[7]->setVisible(true);
    }
    else if(strcmp(keyCode,"o") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[8]->setVisible(true);
    }
    else if(strcmp(keyCode,"p") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[9]->setVisible(true);
    }
    else if(strcmp(keyCode,"[") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[10]->setVisible(true);
    }
    else if(strcmp(keyCode,"]") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[11]->setVisible(true);
    }
    else if(strcmp(keyCode,"a") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[12]->setVisible(true);
    }
    else if(strcmp(keyCode,"s") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[13]->setVisible(true);
    }
    else if(strcmp(keyCode,"d") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[14]->setVisible(true);
    }
    else if(strcmp(keyCode,"f") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[15]->setVisible(true);
    }
    else if(strcmp(keyCode,"g") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[16]->setVisible(true);
    }
    else if(strcmp(keyCode,"h") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[17]->setVisible(true);
    }
    else if(strcmp(keyCode,"j") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[18]->setVisible(true);
    }
    else if(strcmp(keyCode,"k") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[19]->setVisible(true);
    }
    else if(strcmp(keyCode,"l") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[20]->setVisible(true);
    }
    else if(strcmp(keyCode,";") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[21]->setVisible(true);
    }
    else if(strcmp(keyCode,"'") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[22]->setVisible(true);
    }
    else if(strcmp(keyCode,"z") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[23]->setVisible(true);
    }
    else if(strcmp(keyCode,"x") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[24]->setVisible(true);
    }
    else if(strcmp(keyCode,"c") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[25]->setVisible(true);
    }
    else if(strcmp(keyCode,"v") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[26]->setVisible(true);
    }
    else if(strcmp(keyCode,"b") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[27]->setVisible(true);
    }
    else if(strcmp(keyCode,"n") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[28]->setVisible(true);
    }
    else if(strcmp(keyCode,"m") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[29]->setVisible(true);
    }
    else if(strcmp(keyCode,",") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[30]->setVisible(true);
    }
    else if(strcmp(keyCode,".") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[31]->setVisible(true);
    }
    else if(strcmp(keyCode,"/") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[32]->setVisible(true);
    }
    else if(strcmp(keyCode,"`") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[33]->setVisible(true);
    }
    else if(strcmp(keyCode,"1") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[34]->setVisible(true);
    }
    else if(strcmp(keyCode,"2") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[35]->setVisible(true);
    }
    else if(strcmp(keyCode,"3") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[36]->setVisible(true);
    }
    else if(strcmp(keyCode,"4") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[37]->setVisible(true);
    }
    else if(strcmp(keyCode,"5") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[38]->setVisible(true);
    }
    else if(strcmp(keyCode,"6") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[39]->setVisible(true);
    }
    else if(strcmp(keyCode,"7") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[40]->setVisible(true);
    }
    else if(strcmp(keyCode,"8") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[41]->setVisible(true);
    }
    else if(strcmp(keyCode,"9") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[42]->setVisible(true);
    }
    else if(strcmp(keyCode,"0") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[43]->setVisible(true);
    }
    else if(strcmp(keyCode,"-") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[44]->setVisible(true);
    }
    else if(strcmp(keyCode,"=") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[45]->setVisible(true);
    }
    
//
//
//
    
    
    /*
    if(strcmp(keyCode,"q") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[46]->setVisible(true);
    }
    else if(strcmp(keyCode,"w") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[47]->setVisible(true);
    }
    else if(strcmp(keyCode,"e") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[48]->setVisible(true);
    }
    else if(strcmp(keyCode,"r") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[49]->setVisible(true);
    }
    else if(strcmp(keyCode,"t") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[50]->setVisible(true);
    }
    else if(strcmp(keyCode,"y") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[51]->setVisible(true);
    }
    else if(strcmp(keyCode,"u") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[52]->setVisible(true);
    }
    else if(strcmp(keyCode,"i") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[53]->setVisible(true);
    }
    else if(strcmp(keyCode,"o") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[54]->setVisible(true);
    }
    else if(strcmp(keyCode,"p") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[55]->setVisible(true);
    }
    else if(strcmp(keyCode,"[") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[56]->setVisible(true);
    }
    else if(strcmp(keyCode,"]") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[57]->setVisible(true);
    }
    else if(strcmp(keyCode,"a") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[58]->setVisible(true);
    }
    else if(strcmp(keyCode,"s") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[59]->setVisible(true);
    }
    else if(strcmp(keyCode,"d") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[60]->setVisible(true);
    }
    else if(strcmp(keyCode,"f") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[61]->setVisible(true);
    }
    else if(strcmp(keyCode,"g") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[62]->setVisible(true);
    }
    else if(strcmp(keyCode,"h") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[63]->setVisible(true);
    }
    else if(strcmp(keyCode,"j") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[64]->setVisible(true);
    }
    else if(strcmp(keyCode,"k") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[65]->setVisible(true);
    }
    else if(strcmp(keyCode,"l") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[66]->setVisible(true);
    }
    else if(strcmp(keyCode,";") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[67]->setVisible(true);
    }
    else if(strcmp(keyCode,"'") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[68]->setVisible(true);
    }
    else if(strcmp(keyCode,"z") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[69]->setVisible(true);
    }
    else if(strcmp(keyCode,"x") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[70]->setVisible(true);
    }
    else if(strcmp(keyCode,"c") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[71]->setVisible(true);
    }
    else if(strcmp(keyCode,"v") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[72]->setVisible(true);
    }
    else if(strcmp(keyCode,"b") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[73]->setVisible(true);
    }
    else if(strcmp(keyCode,"n") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[74]->setVisible(true);
    }
    else if(strcmp(keyCode,"m") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[75]->setVisible(true);
    }
    else if(strcmp(keyCode,",") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[76]->setVisible(true);
    }
    else if(strcmp(keyCode,".") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[77]->setVisible(true);
    }
    else if(strcmp(keyCode,"/") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[78]->setVisible(true);
    }
    else if(strcmp(keyCode,"`") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[79]->setVisible(true);
    }
    else if(strcmp(keyCode,"1") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[80]->setVisible(true);
    }
    else if(strcmp(keyCode,"2") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[81]->setVisible(true);
    }
    else if(strcmp(keyCode,"3") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[82]->setVisible(true);
    }
    else if(strcmp(keyCode,"4") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[83]->setVisible(true);
    }
    else if(strcmp(keyCode,"5") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[84]->setVisible(true);
    }
    else if(strcmp(keyCode,"6") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[85]->setVisible(true);
    }
    else if(strcmp(keyCode,"7") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[86]->setVisible(true);
    }
    else if(strcmp(keyCode,"8") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[87]->setVisible(true);
    }
    */
 
}

 /*
void PlayControllLayer::processWin32KeyPress(UINT message, WPARAM wParam, LPARAM lParam)
{
	CCLog("%d",wParam);
   
	if( WM_KEYDOWN == message )
	{
		if(wParam == 77){//m
			PlayMusic::sharedMusic()->playmainlayer_music(40);
		}
		if(wParam == 81){//q
			PlayMusic::sharedMusic()->playmainlayer_music(42);
		}
		if(wParam == 87){//w
			PlayMusic::sharedMusic()->playmainlayer_music(44);
		}
		if(wParam == 69){//e
			PlayMusic::sharedMusic()->playmainlayer_music(45);
		}
		if(wParam == 82){//r
			PlayMusic::sharedMusic()->playmainlayer_music(47);
		}
		if(wParam == 84){//t
			PlayMusic::sharedMusic()->playmainlayer_music(49);
		}
		if(wParam == 89){//y
			PlayMusic::sharedMusic()->playmainlayer_music(51);
		}
		if(wParam == 85){//u
			PlayMusic::sharedMusic()->playmainlayer_music(52);
		}
		if(wParam == 73){//i
			PlayMusic::sharedMusic()->playmainlayer_music(54);
		}
		if(wParam == 79){//o
			PlayMusic::sharedMusic()->playmainlayer_music(56);
		}
		if(wParam == 80){//p
			PlayMusic::sharedMusic()->playmainlayer_music(57);
		}
		if(wParam == 65){//a
			PlayMusic::sharedMusic()->playmainlayer_music(59);
		}
		if(wParam == 83){//s
			PlayMusic::sharedMusic()->playmainlayer_music(61);
		}
		if(wParam == 68){//d
			PlayMusic::sharedMusic()->playmainlayer_music(63);
		}
		if(wParam == 70){//f
			PlayMusic::sharedMusic()->playmainlayer_music(64);
		}
		if(wParam == 71){//g
			PlayMusic::sharedMusic()->playmainlayer_music(66);
		}
		if(wParam == 72){//h
			PlayMusic::sharedMusic()->playmainlayer_music(68);
		}
		if(wParam == 74){//j
			PlayMusic::sharedMusic()->playmainlayer_music(69);
		}
		if(wParam == 75){//k
			PlayMusic::sharedMusic()->playmainlayer_music(71);
		}
		if(wParam == 76){//l
			PlayMusic::sharedMusic()->playmainlayer_music(73);
		}
		if(wParam == 90){//z
			PlayMusic::sharedMusic()->playmainlayer_music(76);
		}
		if(wParam == 88){//x
			PlayMusic::sharedMusic()->playmainlayer_music(78);
		}
		if(wParam == 67){//c
			PlayMusic::sharedMusic()->playmainlayer_music(37);
		}
		if(wParam == 86){//v
			PlayMusic::sharedMusic()->playmainlayer_music(38);
		}
		if(wParam == 66){//b
			PlayMusic::sharedMusic()->playmainlayer_music(81);
		}
		if(wParam == 78){//n
			PlayMusic::sharedMusic()->playmainlayer_music(83);
		}
		if(wParam == 49){//1
			PlayMusic::sharedMusic()->playmainlayer_music(201);
		}
		if(wParam == 50){//2
			PlayMusic::sharedMusic()->playmainlayer_music(202);
		}
		if(wParam == 51){//3
			PlayMusic::sharedMusic()->playmainlayer_music(203);
		}
		if(wParam == 52){//4
			PlayMusic::sharedMusic()->playmainlayer_music(204);
		}
		if(wParam == 53){//5
			PlayMusic::sharedMusic()->playmainlayer_music(205);
		}
		if(wParam == 54){//6
			PlayMusic::sharedMusic()->playmainlayer_music(206);
		}
		if(wParam == 55){//7
			PlayMusic::sharedMusic()->playmainlayer_music(207);
		}
	}
	if( WM_KEYUP == message )
	{
		if(wParam == VK_LEFT )
		{
			//PlayMusic::sharedMusic()->pausemainlayer_music();
		}
	}
    
}
 */



/*
void PlayControllLayer::update(float dt)
{
    
}

*/
/*

bool PlayControllLayer::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
    start_point = touch->getLocation();
    return true;
}


void PlayControllLayer::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
   // CCLog("ccTouchMoved");
}

void PlayControllLayer::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
    float x_dir = start_point.x - touch->getLocation().x;
    float y_dir = start_point.y - touch->getLocation().y;
    float x_dist = abs(x_dir);
    float y_dist = abs(y_dir);
    
    if(x_dist > y_dist)
    {
        if(x_dir > 0)
        {
            CCLog("�쇱そ");
            if(Singleton<Piano>::getPointer()->state == PLAYER_STATE_IDLE)
            {
                Singleton<GameManager>::GetInst()->arrowMatching(TOUCH_LEFT);
            }
        }
        else
        {
            CCLog("�ㅻⅨ履�);
            if(Singleton<Piano>::getPointer()->state == PLAYER_STATE_IDLE)
            {
                Singleton<GameManager>::GetInst()->arrowMatching(TOUCH_RIGHT);
            }
        }
      //  CCLog("dist : %f   %f   %f",x_dist,y_dist,x_dir);
    }
    else
    {
        if(y_dir > 0)
        {
            CCLog("���");
            if(Singleton<Piano>::getPointer()->state == PLAYER_STATE_IDLE)
            {
                Singleton<GameManager>::GetInst()->arrowMatching(TOUCH_DOWN);
            }
        }
        else
        {
            CCLog("��);
            if(Singleton<Piano>::getPointer()->state == PLAYER_STATE_IDLE)
            {
                Singleton<GameManager>::GetInst()->arrowMatching(TOUCH_UP);
            }
        }
    }
 
}
*/
