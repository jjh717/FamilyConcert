 
#include "PlayUILayer.h"



PlayUILayer::PlayUILayer()
{
    
}


PlayUILayer::~PlayUILayer()
{
}


bool PlayUILayer::init()
{
    combo_printing = false;
    grade_printing = false;
    
    if(Singleton<GameManager>::GetInst()->gameMode == SINGE_FREE || Singleton<GameManager>::GetInst()->gameMode == ANG_FREE)
    {
        Singleton<GameManager>::GetInst()->exitButton->setPosition(ccp(-CCDirector::sharedDirector()->getWinSize().width/2 + Singleton<GameManager>::GetInst()->exitButton->getContentSize().width/2 + 10, CCDirector::sharedDirector()->getWinSize().height/2 - Singleton<GameManager>::GetInst()->acousticButton->getContentSize().height/2 - 22));
        
        
        Singleton<GameManager>::GetInst()->acousticButton->setPosition(ccp(-850, -194));
        
        Singleton<GameManager>::GetInst()->brightButton->setPosition(ccp(Singleton<GameManager>::GetInst()->acousticButton->getPositionX()+ Singleton<GameManager>::GetInst()->acousticButton->getContentSize().width+10, -194));
        
        Singleton<GameManager>::GetInst()->chorusButton->setPosition(ccp(Singleton<GameManager>::GetInst()->brightButton->getPositionX()+ Singleton<GameManager>::GetInst()->brightButton->getContentSize().width+10, -194));
        
        Singleton<GameManager>::GetInst()->electricButton->setPosition(ccp(Singleton<GameManager>::GetInst()->chorusButton->getPositionX()+ Singleton<GameManager>::GetInst()->chorusButton->getContentSize().width+10, -194));
        
        Singleton<GameManager>::GetInst()->hongkyButton->setPosition(ccp(Singleton<GameManager>::GetInst()->electricButton->getPositionX()+ Singleton<GameManager>::GetInst()->electricButton->getContentSize().width+10, -194));
        
        Singleton<GameManager>::GetInst()->rhodesButton->setPosition(ccp(Singleton<GameManager>::GetInst()->hongkyButton->getPositionX()+ Singleton<GameManager>::GetInst()->hongkyButton->getContentSize().width+10, -194));
        
        //��쇱����몄�대�몄��������
        
        Singleton<GameManager>::GetInst()->pianoRainbowButton->setPosition(ccp(617,-206));
        Singleton<GameManager>::GetInst()->pianoMarkButton->setPosition(ccp(Singleton<GameManager>::GetInst()->pianoRainbowButton->getPositionX()+ Singleton<GameManager>::GetInst()->pianoRainbowButton->getContentSize().width+5,-206));
        Singleton<GameManager>::GetInst()->pianoNormalButton->setPosition(Singleton<GameManager>::GetInst()->pianoMarkButton->getPositionX()+ Singleton<GameManager>::GetInst()->pianoMarkButton->getContentSize().width+5,-206);

        
        this->addChild(Singleton<GameManager>::GetInst()->menu,-4);
        
        
       // Singleton<GameManager>::GetInst()->papi->setAnchorPoint(ccp(0.5,0.5));
      //  Singleton<GameManager>::GetInst()->papi->setScaleX(0.8f);
      //  Singleton<GameManager>::GetInst()->papi->setScaleY(0.4f);
       // Singleton<GameManager>::GetInst()->papi->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2, CCDirector::sharedDirector()->getWinSize().height/2+0));
       // this->addChild(Singleton<GameManager>::GetInst()->papi,-3);
        
        
        
        Singleton<GameManager>::GetInst()->remoteOverImageFree(Singleton<GameManager>::GetInst()->remotePosition);
        Singleton<GameManager>::GetInst()->FreeremoteController(Singleton<GameManager>::GetInst()->remotePosition);
        
        //��쇱����� 誘몃━ ������
        if(Singleton<GameManager>::GetInst()->pianoSelectValue == ACOUSTIC_MODE)
        {
            Singleton<GameManager>::GetInst()->acousticButtonPress();
        }
        else if(Singleton<GameManager>::GetInst()->pianoSelectValue == BRIGHT_MODE)
        {
            Singleton<GameManager>::GetInst()->brightButtonPress();
        }
        else if(Singleton<GameManager>::GetInst()->pianoSelectValue == CHORUS_MODE)
        {
            Singleton<GameManager>::GetInst()->chorusButtonPress();
        }
        else if(Singleton<GameManager>::GetInst()->pianoSelectValue == ELECTRIC_MODE)
        {
            Singleton<GameManager>::GetInst()->electricButtonPress();
        }
        else if(Singleton<GameManager>::GetInst()->pianoSelectValue == HONGKY_MODE)
        {
            Singleton<GameManager>::GetInst()->hongkyButtonPress();
        }
        else if(Singleton<GameManager>::GetInst()->pianoSelectValue == RHODES_MODE)
        {
            Singleton<GameManager>::GetInst()->rhodesButtonPress();
        }
        else
        {
            Singleton<GameManager>::GetInst()->acousticButtonPress();
        }
    }
    else
    {
        Singleton<GameManager>::GetInst()->hitLine->setAnchorPoint(ccp(0.0f, 0.0f));
        Singleton<GameManager>::GetInst()->hitLine->setPosition(ccp(22,HIT_LINE));
        
        this->addChild(Singleton<GameManager>::GetInst()->hitLine,-5);
        
        
        Singleton<GameManager>::GetInst()->escButton->setPosition(ccp(-CCDirector::sharedDirector()->getWinSize().width/2 + Singleton<GameManager>::GetInst()->escButton->getContentSize().width/2 + 10, -CCDirector::sharedDirector()->getWinSize().height/2 + Singleton<GameManager>::GetInst()->escButton->getContentSize().height/2 + 10));
        
        Singleton<GameManager>::GetInst()->pauseButton->setPosition(ccp(Singleton<GameManager>::GetInst()->escButton->getPositionX()+ Singleton<GameManager>::GetInst()->escButton->getContentSize().width+10, -CCDirector::sharedDirector()->getWinSize().height/2 + Singleton<GameManager>::GetInst()->pauseButton->getContentSize().height/2 + 10));
  
        
        
        
        Singleton<GameManager>::GetInst()->x14SpeedButton->setPosition(ccp(Singleton<GameManager>::GetInst()->pauseButton->getPositionX()+ Singleton<GameManager>::GetInst()->pauseButton->getContentSize().width+10, -CCDirector::sharedDirector()->getWinSize().height/2 + Singleton<GameManager>::GetInst()->acousticButton->getContentSize().height/2 + 12));
        
        Singleton<GameManager>::GetInst()->x12SpeedButton->setPosition(ccp(Singleton<GameManager>::GetInst()->x14SpeedButton->getPositionX()+ Singleton<GameManager>::GetInst()->x14SpeedButton->getContentSize().width+10, -CCDirector::sharedDirector()->getWinSize().height/2 + Singleton<GameManager>::GetInst()->acousticButton->getContentSize().height/2 + 12));
        
        Singleton<GameManager>::GetInst()->x1SpeedButton->setPosition(ccp(Singleton<GameManager>::GetInst()->x12SpeedButton->getPositionX()+ Singleton<GameManager>::GetInst()->x12SpeedButton->getContentSize().width+10, -CCDirector::sharedDirector()->getWinSize().height/2 + Singleton<GameManager>::GetInst()->acousticButton->getContentSize().height/2 + 12));
        
        Singleton<GameManager>::GetInst()->x2SpeedButton->setPosition(ccp(Singleton<GameManager>::GetInst()->x1SpeedButton->getPositionX()+ Singleton<GameManager>::GetInst()->x1SpeedButton->getContentSize().width+10, -CCDirector::sharedDirector()->getWinSize().height/2 + Singleton<GameManager>::GetInst()->acousticButton->getContentSize().height/2 + 12));

        
        
        
        Singleton<GameManager>::GetInst()->acousticButton->setPosition(ccp(Singleton<GameManager>::GetInst()->x2SpeedButton->getPositionX()+ Singleton<GameManager>::GetInst()->x2SpeedButton->getContentSize().width+710, -CCDirector::sharedDirector()->getWinSize().height/2 + Singleton<GameManager>::GetInst()->acousticButton->getContentSize().height/2 + 12));
        
        
        
        
        Singleton<GameManager>::GetInst()->brightButton->setPosition(ccp(Singleton<GameManager>::GetInst()->acousticButton->getPositionX()+ Singleton<GameManager>::GetInst()->acousticButton->getContentSize().width+10, -CCDirector::sharedDirector()->getWinSize().height/2 + Singleton<GameManager>::GetInst()->acousticButton->getContentSize().height/2 + 12));
        
        Singleton<GameManager>::GetInst()->chorusButton->setPosition(ccp(Singleton<GameManager>::GetInst()->brightButton->getPositionX()+ Singleton<GameManager>::GetInst()->brightButton->getContentSize().width+10, -CCDirector::sharedDirector()->getWinSize().height/2 + Singleton<GameManager>::GetInst()->acousticButton->getContentSize().height/2 + 12));
        
        Singleton<GameManager>::GetInst()->electricButton->setPosition(ccp(Singleton<GameManager>::GetInst()->chorusButton->getPositionX()+ Singleton<GameManager>::GetInst()->chorusButton->getContentSize().width+10, -CCDirector::sharedDirector()->getWinSize().height/2 + Singleton<GameManager>::GetInst()->acousticButton->getContentSize().height/2 + 12));
        
        Singleton<GameManager>::GetInst()->hongkyButton->setPosition(ccp(Singleton<GameManager>::GetInst()->electricButton->getPositionX()+ Singleton<GameManager>::GetInst()->electricButton->getContentSize().width+10, -CCDirector::sharedDirector()->getWinSize().height/2 + Singleton<GameManager>::GetInst()->acousticButton->getContentSize().height/2 + 12));
        
        Singleton<GameManager>::GetInst()->rhodesButton->setPosition(ccp(Singleton<GameManager>::GetInst()->hongkyButton->getPositionX()+ Singleton<GameManager>::GetInst()->hongkyButton->getContentSize().width+10, -CCDirector::sharedDirector()->getWinSize().height/2 + Singleton<GameManager>::GetInst()->acousticButton->getContentSize().height/2 + 12));
        
        
        
        
        //��쇱����몄�대�몄��������
        
        Singleton<GameManager>::GetInst()->pianoRainbowButton->setPosition(ccp(842,410));
        Singleton<GameManager>::GetInst()->pianoMarkButton->setPosition(ccp(842,Singleton<GameManager>::GetInst()->pianoRainbowButton->getPositionY()-Singleton<GameManager>::GetInst()->pianoRainbowButton->getContentSize().height-10));
        Singleton<GameManager>::GetInst()->pianoNormalButton->setPosition(842,Singleton<GameManager>::GetInst()->pianoMarkButton->getPositionY()-Singleton<GameManager>::GetInst()->pianoMarkButton->getContentSize().height-10);
        
        
        
       
        
       
        
        
        
        
        Singleton<GameManager>::GetInst()->comboImg->setVisible(false);

        Singleton<GameManager>::GetInst()->comboImg->setAnchorPoint(ccp(0.0f, 0.0f));
        Singleton<GameManager>::GetInst()->comboImg->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2-Singleton<GameManager>::GetInst()->comboImg->getContentSize().width/2, CCDirector::sharedDirector()->getWinSize().height/2 + CCDirector::sharedDirector()->getWinSize().height/4 + 20));
        this->addChild(Singleton<GameManager>::GetInst()->comboImg,-3);
        
        
        
        
        Singleton<GameManager>::GetInst()->comboBackImg1->setVisible(false);
        Singleton<GameManager>::GetInst()->comboBackImg1->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2-10,
                                                                             Singleton<GameManager>::GetInst()->comboImg->getPositionY() - 10));
        
        //Singleton<GameManager>::GetInst()->comboBackImg3->setPosition(ccp(120,180));
        this->addChild(Singleton<GameManager>::GetInst()->comboBackImg1,-2);
        
        
        Singleton<GameManager>::GetInst()->comboBackImg2->setVisible(false);
        Singleton<GameManager>::GetInst()->comboBackImg2->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2-10,
                                                                             Singleton<GameManager>::GetInst()->comboImg->getPositionY() - 10));
        
        //Singleton<GameManager>::GetInst()->comboBackImg3->setPosition(ccp(120,180));
        this->addChild(Singleton<GameManager>::GetInst()->comboBackImg2,-2);
        
        
        
        
        Singleton<GameManager>::GetInst()->comboBackImg3->setVisible(false);
        Singleton<GameManager>::GetInst()->comboBackImg3->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2-10,
                                                                             Singleton<GameManager>::GetInst()->comboImg->getPositionY() - 10));
        
        //Singleton<GameManager>::GetInst()->comboBackImg3->setPosition(ccp(120,180));
        this->addChild(Singleton<GameManager>::GetInst()->comboBackImg3,-2);
        
        
        
        
        
        
        
        
        Singleton<GameManager>::GetInst()->combo_count_label->setVisible(false);
        Singleton<GameManager>::GetInst()->combo_count_label->setString("0");
        
        Singleton<GameManager>::GetInst()->combo_count_label->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2-Singleton<GameManager>::GetInst()->combo_count_label->getContentSize().width/2-10,
                                                                                 Singleton<GameManager>::GetInst()->comboImg->getPositionY()-Singleton<GameManager>::GetInst()->combo_count_label->getContentSize().height/2-70));


        this->addChild(Singleton<GameManager>::GetInst()->combo_count_label,-1);

        
      
        
        
        
        Singleton<GameManager>::GetInst()->grade->setVisible(false);
        Singleton<GameManager>::GetInst()->grade->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2,CCDirector::sharedDirector()->getWinSize().height/2-50));
        
        Singleton<GameManager>::GetInst()->grade->setScale(2.0);
        this->addChild(Singleton<GameManager>::GetInst()->grade,0);
        
        
        
        
        
        
        
        Singleton<GameManager>::GetInst()->hp_bar->setPosition(ccp(385,CCDirector::sharedDirector()->getWinSize().height-125));
        this->addChild(Singleton<GameManager>::GetInst()->hp_bar,0);
        
        

        Singleton<GameManager>::GetInst()->energy_bar->setPosition(ccp(194,CCDirector::sharedDirector()->getWinSize().height-190));
        this->addChild(Singleton<GameManager>::GetInst()->energy_bar,1);
      
        
        Singleton<GameManager>::GetInst()->timeBar->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2+26,76));
        //Singleton<GameManager>::GetInst()->timeBar->runAction(Singleton<GameManager>::GetInst()->progressToZero);
        
        
        
        
        
        Singleton<GameManager>::GetInst()->pianoEffectInit(this);
        
        
        
        /*
        Singleton<GameManager>::GetInst()->start_count->setScale(2);
        Singleton<GameManager>::GetInst()->start_count->setString("3");
        Singleton<GameManager>::GetInst()->start_count->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2-Singleton<GameManager>::GetInst()->start_count->getContentSize().width,CCDirector::sharedDirector()->getVisibleSize().height/2-Singleton<GameManager>::GetInst()->start_count->getContentSize().height-20));
        
        this->addChild(Singleton<GameManager>::GetInst()->start_count,3);
        */
        
        
        Singleton<GameManager>::GetInst()->perfect_count_bottom_label->setString("0");
        
        Singleton<GameManager>::GetInst()->perfect_count_bottom_label->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2-Singleton<GameManager>::GetInst()->perfect_count_bottom_label->getContentSize().width/2-180,
                                                                                19));
        
       
        
        
        
        
        Singleton<GameManager>::GetInst()->good_count_bottom_label->setString("0");
        
        Singleton<GameManager>::GetInst()->good_count_bottom_label->setPosition(ccp(Singleton<GameManager>::GetInst()->perfect_count_bottom_label->getPositionX()+ Singleton<GameManager>::GetInst()->perfect_count_bottom_label->getContentSize().width+140, 19));
        
        
        
        
        Singleton<GameManager>::GetInst()->bad_count_bottom_label->setString("0");
        
        Singleton<GameManager>::GetInst()->bad_count_bottom_label->setPosition(ccp(Singleton<GameManager>::GetInst()->good_count_bottom_label->getPositionX()+ Singleton<GameManager>::GetInst()->good_count_bottom_label->getContentSize().width+130, 19));
        
        

        
        
        
        Singleton<GameManager>::GetInst()->miss_count_bottom_label->setString("0");
        Singleton<GameManager>::GetInst()->miss_count_bottom_label->setPosition(ccp(Singleton<GameManager>::GetInst()->bad_count_bottom_label->getPositionX()+ Singleton<GameManager>::GetInst()->bad_count_bottom_label->getContentSize().width+130,
                                                                                          19));
        
        
        
        
        
        
        //泥���� 踰���쇱��移�
        Singleton<GameManager>::GetInst()->remoteOverImage(Singleton<GameManager>::GetInst()->remotePosition);
        Singleton<GameManager>::GetInst()->remoteController(Singleton<GameManager>::GetInst()->remotePosition);
        
        
        
        //��쇱����� 誘몃━ ������
        if(Singleton<GameManager>::GetInst()->pianoSelectValue == ACOUSTIC_MODE)
        {
            Singleton<GameManager>::GetInst()->acousticButtonPress();
        }
        else if(Singleton<GameManager>::GetInst()->pianoSelectValue == BRIGHT_MODE)
        {
            Singleton<GameManager>::GetInst()->brightButtonPress();
        }
        else if(Singleton<GameManager>::GetInst()->pianoSelectValue == CHORUS_MODE)
        {
            Singleton<GameManager>::GetInst()->chorusButtonPress();
        }
        else if(Singleton<GameManager>::GetInst()->pianoSelectValue == ELECTRIC_MODE)
        {
            Singleton<GameManager>::GetInst()->electricButtonPress();
        }
        else if(Singleton<GameManager>::GetInst()->pianoSelectValue == HONGKY_MODE)
        {
            Singleton<GameManager>::GetInst()->hongkyButtonPress();
        }
        else if(Singleton<GameManager>::GetInst()->pianoSelectValue == RHODES_MODE)
        {
            Singleton<GameManager>::GetInst()->rhodesButtonPress();
        }
        else
        {
            Singleton<GameManager>::GetInst()->acousticButtonPress();
        }
        
        
        if(Singleton<GameManager>::GetInst()->gameSpeedValue == X1_MODE)
        {
            Singleton<GameManager>::GetInst()->x1SpeedButtonPress();
        }
        else if(Singleton<GameManager>::GetInst()->gameSpeedValue == X2_MODE)
        {
            Singleton<GameManager>::GetInst()->x2SpeedButtonPress();
        }
        else if(Singleton<GameManager>::GetInst()->gameSpeedValue == X12_MODE)
        {
            Singleton<GameManager>::GetInst()->x12SpeedButtonPress();
        }
        else if(Singleton<GameManager>::GetInst()->gameSpeedValue == X14_MODE)
        {
            Singleton<GameManager>::GetInst()->x14SpeedButtonPress();
        }
        else
        {
            Singleton<GameManager>::GetInst()->x1SpeedButtonPress();
        }
        
        
        
        
        /*
        Singleton<GameManager>::GetInst()->max_combo_label->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width-170,
                                                                                       CCDirector::sharedDirector()->getWinSize().height-185));
        
        
        this->addChild(Singleton<GameManager>::GetInst()->max_combo_label,6);

        
        Singleton<GameManager>::GetInst()->total_score_label->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width-300,
                                                                               Singleton<GameManager>::GetInst()->max_combo_label->getPositionY()+Singleton<GameManager>::GetInst()->max_combo_label->getContentSize().height));
        
        
        this->addChild(Singleton<GameManager>::GetInst()->total_score_label,6);
        */
        
        
        
        
        

        
        
        
        
        
        
        
        
        /*
        Singleton<GameManager>::GetInst()->remoteFocus->setPosition(ccp(380, 50));
        
        this->addChild(Singleton<GameManager>::GetInst()->remoteFocus,7);
*/
        /*
        Singleton<GameManager>::GetInst()->keyboard->setPosition(ccp(0,300));
        Singleton<GameManager>::GetInst()->keyboard->setScale(2.0f);
        this->addChild(Singleton<GameManager>::GetInst()->keyboard,7);
        */
        
       
        
    }
    
    
    
    
    
    return true;
}

void PlayUILayer::combo_hidden()
{
    Singleton<GameManager>::GetInst()->combo_count_label->setVisible(false);
    Singleton<GameManager>::GetInst()->comboImg->setVisible(false);
    
    Singleton<GameManager>::GetInst()->comboBackImg1->setVisible(false);
    Singleton<GameManager>::GetInst()->comboBackImg2->setVisible(false);
    Singleton<GameManager>::GetInst()->comboBackImg3->setVisible(false);
}
void PlayUILayer::grade_hidden()
{
    Singleton<GameManager>::GetInst()->grade->setVisible(false);
}

void PlayUILayer::update(float dt)
{
    
    if(Singleton<GameManager>::GetInst()->comboImg->isVisible() && !combo_printing)
    {
        combo_printing = true;
        
        CCDelayTime *delayAction = CCDelayTime::create(2);
        CCCallFuncN *callSelectorAction = CCCallFuncN::create(this, callfuncN_selector(PlayUILayer::combo_hidden));
        this->runAction(CCSequence::create(delayAction, callSelectorAction, NULL));
    }
    if(Singleton<GameManager>::GetInst()->grade->isVisible() && !grade_printing)
    {
        grade_printing = true;
        
        CCDelayTime *delayAction = CCDelayTime::create(2);
        CCCallFuncN *callSelectorAction = CCCallFuncN::create(this, callfuncN_selector(PlayUILayer::grade_hidden));
        this->runAction(CCSequence::create(delayAction, callSelectorAction, NULL));
    }

    
    
    /*
    sprintf(str, "%05d",Singleton<GameManager>::GetInst()->maxScore);
    Singleton<GameManager>::GetInst()->total_score_label->setString(str);
*/
    
    sprintf(str, "%d", Singleton<GameManager>::GetInst()->combo_count);
	Singleton<GameManager>::GetInst()->combo_count_label->setString(str);
    
    sprintf(str, "%d",Singleton<GameManager>::GetInst()->perfectSocre + Singleton<GameManager>::GetInst()->perfectSocre_copy);
    Singleton<GameManager>::GetInst()->perfect_count_bottom_label->setString(str);

    sprintf(str, "%d",Singleton<GameManager>::GetInst()->goodSocre + Singleton<GameManager>::GetInst()->goodSocre_copy);
    Singleton<GameManager>::GetInst()->good_count_bottom_label->setString(str);

    sprintf(str, "%d",Singleton<GameManager>::GetInst()->badSocre + Singleton<GameManager>::GetInst()->badSocre_copy);
    Singleton<GameManager>::GetInst()->bad_count_bottom_label->setString(str);

    
    sprintf(str, "%d",Singleton<GameManager>::GetInst()->missSocre + Singleton<GameManager>::GetInst()->missSocre_copy);
    Singleton<GameManager>::GetInst()->miss_count_bottom_label->setString(str);
    /*
    sprintf(str, "%d",Singleton<GameManager>::GetInst()->max_combo_count);
    Singleton<GameManager>::GetInst()->max_combo_label->setString(str);
    */
    
    /*
    if(Singleton<GameManager>::GetInst()->printNoteCount > 0)
    {
        Block *target =  dynamic_cast<Block*>(Singleton<GameManager>::GetInst()->_collision_boxes->objectAtIndex(0));
        if(!target->guideVisible)
        {
            target->guideVisible = true;
            CCLOG("print target->Child : %d",target->Child);
            Singleton<GameManager>::GetInst()->pianoGuideVisible(target->lineNum);
            
            int childNum = target->Child;
            while (childNum != -1)
            {
                Block *child =  dynamic_cast<Block*>(Singleton<GameManager>::GetInst()->_collision_boxes->objectAtIndex(childNum));
                child->guideVisible = true;
                childNum = child->Child;
                Singleton<GameManager>::GetInst()->pianoGuideVisible(child->lineNum);
            }
            
        }
    }
    */
    
    /*
    sprintf(str, "%d", Singleton<GameManager>::GetInst()->score);
    score->setString(str);
    
    sprintf(str, "%d", Singleton<GameManager>::GetInst()->meter);
    meter->setString(str);
    */
    /*
    if(!scoreBoard_visiable)
    {
        if(Singleton<Player>::getPointer()->drill->getPosition().y > CCDirector::sharedDirector()->getWinSize().height)
        {
            scoreBoard_visiable = true;
            this->showResultWindow();
        }
    }
     */
}
void PlayUILayer::showCombo()
{

    
        
//    Singleton<GameManager>::GetInst()->combo_count_label->setString("");
   // Singleton<GameManager>::GetInst()->comboImg->setVisible(true);
    CCLog("showResultWindow");

}


