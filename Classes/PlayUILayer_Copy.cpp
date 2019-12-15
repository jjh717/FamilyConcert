 
#include "PlayUILayer_Copy.h"



PlayUILayer_Copy::PlayUILayer_Copy()
{
    
}


PlayUILayer_Copy::~PlayUILayer_Copy()
{
}


bool PlayUILayer_Copy::init()
{
    if(Singleton<GameManager>::GetInst()->gameMode == SINGE_FREE)
    {
        Singleton<GameManager>::GetInst()->FreeremoteController(1);
    
        Singleton<GameManager>::GetInst()->escButton->setVisible(false);
        Singleton<GameManager>::GetInst()->pauseButton->setVisible(false);
       
        Singleton<GameManager>::GetInst()->x12SpeedButton->setVisible(false);
        Singleton<GameManager>::GetInst()->x1SpeedButton->setVisible(false);
        Singleton<GameManager>::GetInst()->x2SpeedButton->setVisible(false);
        Singleton<GameManager>::GetInst()->x14SpeedButton->setVisible(false);
        
        Singleton<GameManager>::GetInst()->acousticButton->setPosition(ccp(400, CCDirector::sharedDirector()->getWinSize().height/2 - Singleton<GameManager>::GetInst()->acousticButton->getContentSize().height/2 - 22));
        
        Singleton<GameManager>::GetInst()->brightButton->setPosition(ccp(Singleton<GameManager>::GetInst()->acousticButton->getPositionX()+ Singleton<GameManager>::GetInst()->acousticButton->getContentSize().width+10, CCDirector::sharedDirector()->getWinSize().height/2 - Singleton<GameManager>::GetInst()->acousticButton->getContentSize().height/2 - 22));
        
        Singleton<GameManager>::GetInst()->chorusButton->setPosition(ccp(Singleton<GameManager>::GetInst()->brightButton->getPositionX()+ Singleton<GameManager>::GetInst()->brightButton->getContentSize().width+10, CCDirector::sharedDirector()->getWinSize().height/2 - Singleton<GameManager>::GetInst()->acousticButton->getContentSize().height/2 - 22));
        
        Singleton<GameManager>::GetInst()->electricButton->setPosition(ccp(Singleton<GameManager>::GetInst()->chorusButton->getPositionX()+ Singleton<GameManager>::GetInst()->chorusButton->getContentSize().width+10, CCDirector::sharedDirector()->getWinSize().height/2 - Singleton<GameManager>::GetInst()->acousticButton->getContentSize().height/2 - 22));
        
        Singleton<GameManager>::GetInst()->hongkyButton->setPosition(ccp(Singleton<GameManager>::GetInst()->electricButton->getPositionX()+ Singleton<GameManager>::GetInst()->electricButton->getContentSize().width+10, CCDirector::sharedDirector()->getWinSize().height/2 - Singleton<GameManager>::GetInst()->acousticButton->getContentSize().height/2 - 22));
        
        Singleton<GameManager>::GetInst()->rhodesButton->setPosition(ccp(Singleton<GameManager>::GetInst()->hongkyButton->getPositionX()+ Singleton<GameManager>::GetInst()->hongkyButton->getContentSize().width+10, CCDirector::sharedDirector()->getWinSize().height/2 - Singleton<GameManager>::GetInst()->acousticButton->getContentSize().height/2 - 22));
        
        this->addChild(Singleton<GameManager>::GetInst()->menu_copy,-4);
    }
    else if(Singleton<GameManager>::GetInst()->gameMode == ANG_FREE)
    {
        
    }
    else
    {
        
        Singleton<GameManager>::GetInst()->hitLine_copy->setAnchorPoint(ccp(0.0f, 0.0f));
        Singleton<GameManager>::GetInst()->hitLine_copy->setPosition(ccp(22,HIT_LINE));
        
        this->addChild(Singleton<GameManager>::GetInst()->hitLine_copy,-5);
        
        /*
        Singleton<GameManager>::GetInst()->escButton_copy->setPosition(ccp(-CCDirector::sharedDirector()->getWinSize().width/2 + Singleton<GameManager>::GetInst()->escButton_copy->getContentSize().width/2 + 10, -CCDirector::sharedDirector()->getWinSize().height/2 + Singleton<GameManager>::GetInst()->escButton_copy->getContentSize().height/2 + 10));
        
        Singleton<GameManager>::GetInst()->pauseButton_copy->setPosition(ccp(Singleton<GameManager>::GetInst()->escButton_copy->getPositionX()+ Singleton<GameManager>::GetInst()->escButton_copy->getContentSize().width+10, -CCDirector::sharedDirector()->getWinSize().height/2 + Singleton<GameManager>::GetInst()->pauseButton_copy->getContentSize().height/2 + 10));
        Singleton<GameManager>::GetInst()->resumeButton_copy->setPosition(ccp(Singleton<GameManager>::GetInst()->escButton_copy->getPositionX()+ Singleton<GameManager>::GetInst()->escButton_copy->getContentSize().width+10, -CCDirector::sharedDirector()->getWinSize().height/2 + Singleton<GameManager>::GetInst()->resumeButton_copy->getContentSize().height/2 + 10));
        
        Singleton<GameManager>::GetInst()->x3SpeedButton_copy->setPosition(ccp(Singleton<GameManager>::GetInst()->pauseButton_copy->getPositionX()+ Singleton<GameManager>::GetInst()->pauseButton_copy->getContentSize().width+10, -CCDirector::sharedDirector()->getWinSize().height/2 + Singleton<GameManager>::GetInst()->x3SpeedButton_copy->getContentSize().height/2 + 12));
        
        Singleton<GameManager>::GetInst()->x1SpeedButton_copy->setPosition(ccp(Singleton<GameManager>::GetInst()->x3SpeedButton_copy->getPositionX()+ Singleton<GameManager>::GetInst()->x3SpeedButton_copy->getContentSize().width+10, -CCDirector::sharedDirector()->getWinSize().height/2 + Singleton<GameManager>::GetInst()->x1SpeedButton_copy->getContentSize().height/2 + 12));
        
        Singleton<GameManager>::GetInst()->x1SpeedButton_copy->selected();
        
        Singleton<GameManager>::GetInst()->x2SpeedButton_copy->setPosition(ccp(Singleton<GameManager>::GetInst()->x1SpeedButton_copy->getPositionX()+ Singleton<GameManager>::GetInst()->x1SpeedButton_copy->getContentSize().width+10, -CCDirector::sharedDirector()->getWinSize().height/2 + Singleton<GameManager>::GetInst()->x2SpeedButton_copy->getContentSize().height/2 + 12));
        
        Singleton<GameManager>::GetInst()->x4SpeedButton_copy->setPosition(ccp(Singleton<GameManager>::GetInst()->x2SpeedButton_copy->getPositionX()+ Singleton<GameManager>::GetInst()->x2SpeedButton_copy->getContentSize().width+10, -CCDirector::sharedDirector()->getWinSize().height/2 + Singleton<GameManager>::GetInst()->x4SpeedButton_copy->getContentSize().height/2 + 12));
        
        this->addChild(Singleton<GameManager>::GetInst()->menu_copy,-4);
        */
        
       
        
       
        
        
        
        
        Singleton<GameManager>::GetInst()->comboImg_copy->setVisible(false);

        Singleton<GameManager>::GetInst()->comboImg_copy->setAnchorPoint(ccp(0.0f, 0.0f));
        Singleton<GameManager>::GetInst()->comboImg_copy->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2-Singleton<GameManager>::GetInst()->comboImg_copy->getContentSize().width/2, CCDirector::sharedDirector()->getWinSize().height/2 + CCDirector::sharedDirector()->getWinSize().height/4 + 20));
        this->addChild(Singleton<GameManager>::GetInst()->comboImg_copy,-3);
        
        
        
        
        Singleton<GameManager>::GetInst()->comboBackImg1_copy->setVisible(false);
        Singleton<GameManager>::GetInst()->comboBackImg1_copy->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2-10,
                                                                             Singleton<GameManager>::GetInst()->comboImg_copy->getPositionY() - 10));
        
        this->addChild(Singleton<GameManager>::GetInst()->comboBackImg1_copy,-2);
        
        
        Singleton<GameManager>::GetInst()->comboBackImg2_copy->setVisible(false);
        Singleton<GameManager>::GetInst()->comboBackImg2_copy->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2-10,
                                                                             Singleton<GameManager>::GetInst()->comboImg_copy->getPositionY() - 10));
        
        this->addChild(Singleton<GameManager>::GetInst()->comboBackImg2_copy,-2);
        
        
        
        
        Singleton<GameManager>::GetInst()->comboBackImg3_copy->setVisible(false);
        Singleton<GameManager>::GetInst()->comboBackImg3_copy->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2-10,
                                                                             Singleton<GameManager>::GetInst()->comboImg_copy->getPositionY() - 10));
        
        this->addChild(Singleton<GameManager>::GetInst()->comboBackImg3_copy,-2);
        
        
        
        
        
        
        
        
        Singleton<GameManager>::GetInst()->combo_count_label_copy->setVisible(false);
        Singleton<GameManager>::GetInst()->combo_count_label_copy->setString("0");
        
        Singleton<GameManager>::GetInst()->combo_count_label_copy->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2-Singleton<GameManager>::GetInst()->combo_count_label_copy->getContentSize().width/2-10,
                                                                                 Singleton<GameManager>::GetInst()->comboImg_copy->getPositionY()-Singleton<GameManager>::GetInst()->combo_count_label_copy->getContentSize().height/2-70));


        this->addChild(Singleton<GameManager>::GetInst()->combo_count_label_copy,-1);

        
      
        
        
        
        Singleton<GameManager>::GetInst()->grade_copy->setVisible(false);
        Singleton<GameManager>::GetInst()->grade_copy->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2,CCDirector::sharedDirector()->getWinSize().height/2-50));
        
        Singleton<GameManager>::GetInst()->grade_copy->setScale(2.0);
        this->addChild(Singleton<GameManager>::GetInst()->grade_copy,0);
        
        
        
        
        
        
        
        Singleton<GameManager>::GetInst()->hp_bar_copy->setPosition(ccp(385,CCDirector::sharedDirector()->getWinSize().height-125));
        this->addChild(Singleton<GameManager>::GetInst()->hp_bar_copy,0);
        
        

        Singleton<GameManager>::GetInst()->energy_bar_copy->setPosition(ccp(195,CCDirector::sharedDirector()->getWinSize().height-190));
        this->addChild(Singleton<GameManager>::GetInst()->energy_bar_copy,1);
      
     
        Singleton<GameManager>::GetInst()->timeBar_copy->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2-20,47));
        //Singleton<GameManager>::GetInst()->timeBar_copy->runAction(Singleton<GameManager>::GetInst()->progressToZero_copy);
        this->addChild(Singleton<GameManager>::GetInst()->timeBar_copy,2);
        
        Singleton<GameManager>::GetInst()->pianoEffectInit(this);
        
        
        /*
        Singleton<GameManager>::GetInst()->start_count_copy->setScale(2);
        Singleton<GameManager>::GetInst()->start_count_copy->setString("3");
        Singleton<GameManager>::GetInst()->start_count_copy->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2-Singleton<GameManager>::GetInst()->start_count_copy->getContentSize().width,CCDirector::sharedDirector()->getVisibleSize().height/2-Singleton<GameManager>::GetInst()->start_count_copy->getContentSize().height-20));
        
        this->addChild(Singleton<GameManager>::GetInst()->start_count_copy,3);
        
        */
      
                 
        
        
        /*
        
        Singleton<GameManager>::GetInst()->perfect_count_bottom_label_copy->setString("0");
        
        Singleton<GameManager>::GetInst()->perfect_count_bottom_label_copy->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2-Singleton<GameManager>::GetInst()->perfect_count_bottom_label_copy->getContentSize().width/2+410,
                                                                                36));
        
        
        this->addChild(Singleton<GameManager>::GetInst()->perfect_count_bottom_label_copy,4);
        
        
        
        
        Singleton<GameManager>::GetInst()->good_count_bottom_label_copy->setString("0");
        
        Singleton<GameManager>::GetInst()->good_count_bottom_label_copy->setPosition(ccp(Singleton<GameManager>::GetInst()->perfect_count_bottom_label_copy->getPositionX()+ Singleton<GameManager>::GetInst()->perfect_count_bottom_label_copy->getContentSize().width+140, 36));
        
        this->addChild(Singleton<GameManager>::GetInst()->good_count_bottom_label_copy,4);
        
        
        
        Singleton<GameManager>::GetInst()->bad_count_bottom_label_copy->setString("0");
        
        Singleton<GameManager>::GetInst()->bad_count_bottom_label_copy->setPosition(ccp(Singleton<GameManager>::GetInst()->good_count_bottom_label_copy->getPositionX()+ Singleton<GameManager>::GetInst()->good_count_bottom_label_copy->getContentSize().width+130, 36));
        
        this->addChild(Singleton<GameManager>::GetInst()->bad_count_bottom_label_copy,4);

        
        
        
        Singleton<GameManager>::GetInst()->miss_count_bottom_label_copy->setString("0");
        Singleton<GameManager>::GetInst()->miss_count_bottom_label_copy->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width-110,
                                                                                          36));
        
        
        this->addChild(Singleton<GameManager>::GetInst()->miss_count_bottom_label_copy,5);
        */
        
        
        
        Singleton<GameManager>::GetInst()->max_combo_label_copy->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width-170,
                                                                                       CCDirector::sharedDirector()->getWinSize().height-185));
        
        
        this->addChild(Singleton<GameManager>::GetInst()->max_combo_label_copy,6);

        
        Singleton<GameManager>::GetInst()->total_score_label_copy->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width-300,
                                                                               Singleton<GameManager>::GetInst()->max_combo_label_copy->getPositionY()+Singleton<GameManager>::GetInst()->max_combo_label_copy->getContentSize().height));
        
        
        this->addChild(Singleton<GameManager>::GetInst()->total_score_label_copy,6);
    }
    
    
    
    
    return true;
}

 

void PlayUILayer_Copy::update(float dt)
{
    
    sprintf(str_copy, "%05d",Singleton<GameManager>::GetInst()->maxScore_copy);
    Singleton<GameManager>::GetInst()->total_score_label_copy->setString(str_copy);
/*
    sprintf(str_copy, "%d",Singleton<GameManager>::GetInst()->perfectSocre_copy);
    Singleton<GameManager>::GetInst()->perfect_count_bottom_label_copy->setString(str_copy);

    sprintf(str_copy, "%d",Singleton<GameManager>::GetInst()->goodSocre_copy);
    Singleton<GameManager>::GetInst()->good_count_bottom_label_copy->setString(str_copy);

    sprintf(str_copy, "%d",Singleton<GameManager>::GetInst()->badSocre_copy);
    Singleton<GameManager>::GetInst()->bad_count_bottom_label_copy->setString(str_copy);

    
    sprintf(str_copy, "%d",Singleton<GameManager>::GetInst()->missSocre_copy);
    Singleton<GameManager>::GetInst()->miss_count_bottom_label_copy->setString(str_copy);
    */
    sprintf(str_copy, "%d",Singleton<GameManager>::GetInst()->max_combo_count_copy);
    Singleton<GameManager>::GetInst()->max_combo_label_copy->setString(str_copy);
 
    
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
void PlayUILayer_Copy::showCombo()
{

    
        
//    Singleton<GameManager>::GetInst()->combo_count_label->setString("");
   // Singleton<GameManager>::GetInst()->comboImg->setVisible(true);
    CCLog("showResultWindow");

}


