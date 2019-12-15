

#include "PlayScene.h" 

PlayScene::PlayScene()
{
    
}



PlayScene::~PlayScene()
{
    
    CCLOG("~PlayScene");
}
bool PlayScene::init()
{
   if( CCScene::init() )
   {
        start_count_num = start_count_num_copy = 3;
        
        
        _bg_layer = NULL;
        _bg_layer_copy = NULL;
        
        _controll_layer = NULL;
        _controll_layer_copy = NULL;
        
        _block_layer = NULL;
        _block_layer_copy = NULL;
        
        _ui_layer = NULL;
        _ui_layer_copy = NULL;
        
        _line_layer = NULL;
        _line_layer_copy = NULL;
        
        _effect_layer = NULL;
        _effect_layer_copy = NULL;

        
        
        
        if(Singleton<GameManager>::GetInst()->gameMode == ANG_GAME)
        {
            _bg_layer = PlayBgLayer::create();
            _bg_layer->retain();
            _bg_layer->setScaleY(0.5);
            _bg_layer->setPosition(ccp(_bg_layer->getPositionX(),CCDirector::sharedDirector()->getVisibleSize().height/2));
            this->addChild(_bg_layer, -5);

            _bg_layer_copy = PlayBgLayer_Copy::create();
            _bg_layer_copy->retain();
            _bg_layer_copy->setScaleY(0.5);
            _bg_layer_copy->setPosition(ccp(_bg_layer_copy->getPositionX(),0));
            this->addChild(_bg_layer_copy, -7);
            
            _line_layer = PlayLineLayer::create();
            _line_layer->retain();
            _line_layer->setScaleY(0.5);
            _line_layer->setPosition(ccp(_line_layer->getPositionX(),CCDirector::sharedDirector()->getVisibleSize().height/2));
            this->addChild(_line_layer, -4);
            
            _line_layer_copy = PlayLineLayer_Copy::create();
            _line_layer_copy->retain();
            _line_layer_copy->setScaleY(0.5);
            _line_layer_copy->setPosition(ccp(_line_layer_copy->getPositionX(),0));
            this->addChild(_line_layer, -4);
            
            
            _controll_layer = PlayControllLayer::create();
            _controll_layer->retain();
            _controll_layer->setScaleY(0.5);
            _controll_layer->setPosition(ccp(_controll_layer->getPositionX(),CCDirector::sharedDirector()->getVisibleSize().height/2));
            this->addChild(_controll_layer, -3);
            
            _controll_layer_copy = PlayControllLayer_Copy::create();
            _controll_layer_copy->retain();
            _controll_layer_copy->setScaleY(0.5);
            _controll_layer_copy->setPosition(ccp(_controll_layer_copy->getPositionX(),0));
            this->addChild(_controll_layer_copy, -3);

            

            //CCDirector::sharedDirector()->getVisibleSize().height/8
            
            _block_layer = PlayBlockLayer::create();
            _block_layer->retain();
            _block_layer->setContentSize(CCSize(this->getContentSize().width*2,this->getContentSize().height*2));
            _block_layer->setPosition(0,0);
            this->addChild(_block_layer,-2);
             
             _block_layer_copy = PlayBlockLayer_Copy::create();
             _block_layer_copy->retain();
             _block_layer_copy->setContentSize(CCSize(this->getContentSize().width*2,this->getContentSize().height*2));
             _block_layer_copy->setPosition(_block_layer_copy->getPositionX(),CCDirector::sharedDirector()->getVisibleSize().height/8);
             this->addChild(_block_layer_copy,-6);  //-6
            
            
            /*
            _block_layer_copy = PlayBlockLayer_Copy::create();
            _block_layer_copy->setContentSize(CCSize(this->getContentSize().width*2,this->getContentSize().height*2));
            _block_layer_copy->setPosition(ccp(_block_layer_copy->getPositionX(),-60));
         //   _block_layer_copy->setVisible(false);
            this->addChild(_block_layer_copy,-2);//�꾩뿉爰�..
       
            _block_layer = PlayBlockLayer::create();
            _block_layer->setContentSize(CCSize(this->getContentSize().width*2,this->getContentSize().height*2));
            _block_layer->setPosition(_block_layer->getPositionX(),CCDirector::sharedDirector()->getVisibleSize().height/8-280);
 
          //  CCLOG("CCDirector::sharedDirector()->getVisibleSize().height/8 : %f",CCDirector::sharedDirector()->getVisibleSize().height/8); //135
            this->addChild(_block_layer,-6);  //-6
*/
            
            
            
            
            
            _ui_layer = PlayUILayer::create();
            _ui_layer->retain();
            _ui_layer->setScaleY(0.5);
            _ui_layer->setPosition(ccp(_ui_layer->getPositionX(),CCDirector::sharedDirector()->getVisibleSize().height/2));
            this->addChild(_ui_layer, -1);
            
            _ui_layer_copy = PlayUILayer_Copy::create();
            _ui_layer_copy->retain();
            _ui_layer_copy->setScaleY(0.5);
            _ui_layer_copy->setPosition(ccp(_ui_layer_copy->getPositionX(),0));
            this->addChild(_ui_layer_copy, -1);
            
            
            
            
            
            this->schedule( schedule_selector(PlayScene::update));
            this->schedule( schedule_selector(PlayScene::update_copy));
            
            
      //      this->start_count_display();
      //      this->start_count_display_copy();
        }
        
        else if(Singleton<GameManager>::GetInst()->gameMode == SINGE_FREE)
        {
            _bg_layer = PlayBgLayer::create();
            _bg_layer->retain();
            this->addChild(_bg_layer, -1);
           
            _controll_layer = PlayControllLayer::create();
            _controll_layer->retain();
            this->addChild(_controll_layer, 0);

            _ui_layer = PlayUILayer::create();
            _ui_layer->retain();
            this->addChild(_ui_layer, 1);
            
            this->schedule( schedule_selector(PlayScene::update));
        }
        else if(Singleton<GameManager>::GetInst()->gameMode == ANG_FREE)
        {
            _bg_layer = PlayBgLayer::create();
            _bg_layer->retain();
           // _bg_layer->setScaleY(0.5);
            _bg_layer->setPosition(ccp(_bg_layer->getPositionX(),0));
            this->addChild(_bg_layer, -3);
            
            _controll_layer = PlayControllLayer::create();
            _controll_layer->retain();
           // _controll_layer->setScaleY(0.5);
            _controll_layer->setPosition(ccp(_controll_layer->getPositionX(),235));
            this->addChild(_controll_layer, -2);
            
            _ui_layer = PlayUILayer::create();
            _ui_layer->retain();
           // _ui_layer->setScaleY(0.5);
            _ui_layer->setPosition(ccp(_ui_layer->getPositionX(),0));
            this->addChild(_ui_layer, 0);
            
            
            
            
            
            /*
            _bg_layer_copy = PlayBgLayer_Copy::create();
            //_bg_layer_copy->setScaleY(0.5);
            _bg_layer_copy->setPosition(ccp(_bg_layer_copy->getPositionX(),0));
            this->addChild(_bg_layer_copy, 0);
            */
            _controll_layer_copy = PlayControllLayer_Copy::create();
            _controll_layer_copy->retain();
           // _controll_layer_copy->setScaleY(0.5);
            _controll_layer_copy->setPosition(ccp(_controll_layer->getPositionX(),0));
            this->addChild(_controll_layer_copy, -2);
            /*
            _ui_layer_copy = PlayUILayer_Copy::create();
            //_ui_layer_copy->setScaleY(0.5);
            _ui_layer_copy->setPosition(ccp(_ui_layer->getPositionX(),0));
            this->addChild(_ui_layer_copy, -1);
            */
            
            
            this->schedule( schedule_selector(PlayScene::updatefree));
        }
        else
        {
            _bg_layer = PlayBgLayer::create();
            _bg_layer->retain();
            this->addChild(_bg_layer, -5);
            
            _line_layer = PlayLineLayer::create();
            _line_layer->retain();
            _line_layer->setContentSize(CCSize(this->getContentSize().width*2,this->getContentSize().height*2));
            _line_layer->setPosition(CCPoint(0,0));
            this->addChild(_line_layer, -4);
            
            _controll_layer = PlayControllLayer::create();
            _controll_layer->retain();
            this->addChild(_controll_layer, -3);
            
            _ui_layer = PlayUILayer::create();
            _ui_layer->retain();
            this->addChild(_ui_layer, -2);
            
            _block_layer = PlayBlockLayer::create();
            _block_layer->retain();
            //_block_layer->setAnchorPoint(ccp(0.0f, 0.0f));
            _block_layer->setContentSize(CCSize(this->getContentSize().width*2,this->getContentSize().height*2));
            _block_layer->setPosition(CCPoint(0,0));
     
            this->addChild(_block_layer,-1);
            
            
            this->topLayer();
            
            
            
            _effect_layer = PlayEffectLayer::create();
            _effect_layer->retain();
            this->addChild(_effect_layer,0);
            
            
            Singleton<GameManager>::GetInst()->stopButton->setAnchorPoint(ccp(0, 0));
            Singleton<GameManager>::GetInst()->stopButton->setPosition(ccp(0,0));
            Singleton<GameManager>::GetInst()->stopButton->setVisible(false);
            this->addChild(Singleton<GameManager>::GetInst()->stopButton,1);
            
            
            this->tutorial_display();
        
            this->schedule( schedule_selector(PlayScene::update));
        }
		return true;
	}
	else
	{
		return false;
	}
}

void PlayScene::topLayer()
{
    Singleton<GameManager>::GetInst()->pianoBG->setAnchorPoint(ccp(0.0f, 0.0f));
    Singleton<GameManager>::GetInst()->pianoBG->setPosition(ccp(20,122));
    this->addChild(Singleton<GameManager>::GetInst()->pianoBG, 0);
    
    Singleton<GameManager>::GetInst()->blackcover->setAnchorPoint(ccp(0.0f, 0.0f));
    Singleton<GameManager>::GetInst()->blackcover->setPosition(ccp(0.0f,0.0f));
    this->addChild(Singleton<GameManager>::GetInst()->blackcover, 0);
    
    this->addChild(Singleton<GameManager>::GetInst()->timeBar,0);
    this->addChild(Singleton<GameManager>::GetInst()->perfect_count_bottom_label,0);
    this->addChild(Singleton<GameManager>::GetInst()->good_count_bottom_label,0);
    this->addChild(Singleton<GameManager>::GetInst()->miss_count_bottom_label,0);
    this->addChild(Singleton<GameManager>::GetInst()->bad_count_bottom_label,0);
    this->addChild(Singleton<GameManager>::GetInst()->menu,0);

}
void PlayScene::tutorial_display()
{
    Singleton<GameManager>::GetInst()->tutorial_bg->setAnchorPoint(ccp(0, 0));
    Singleton<GameManager>::GetInst()->tutorial_bg->setPosition(ccp(0,0));
    this->addChild(Singleton<GameManager>::GetInst()->tutorial_bg,1);
    
    
    
    
    Singleton<GameManager>::GetInst()->tutorial_piano[0]->setAnchorPoint(ccp(0, 0));
    Singleton<GameManager>::GetInst()->tutorial_piano[0]->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2-124,CCDirector::sharedDirector()->getVisibleSize().height/2-Singleton<GameManager>::GetInst()->tutorial_piano[0]->getContentSize().height/2-192));
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
    
    

    Singleton<GameManager>::GetInst()->tutorialMent1->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2,CCDirector::sharedDirector()->getVisibleSize().height/2));
    Singleton<GameManager>::GetInst()->tutorialMent1->setColor(ccc3(255,255,255));
    this->addChild(Singleton<GameManager>::GetInst()->tutorialMent1,3);

    Singleton<GameManager>::GetInst()->tutorialMent2->setVisible(false);
    Singleton<GameManager>::GetInst()->tutorialMent2->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2,CCDirector::sharedDirector()->getVisibleSize().height/2));
    Singleton<GameManager>::GetInst()->tutorialMent2->setColor(ccc3(255,255,255));
    this->addChild(Singleton<GameManager>::GetInst()->tutorialMent2,3);

    Singleton<GameManager>::GetInst()->tutorialMent3->setVisible(false);
    Singleton<GameManager>::GetInst()->tutorialMent3->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2,CCDirector::sharedDirector()->getVisibleSize().height/2));
    Singleton<GameManager>::GetInst()->tutorialMent3->setColor(ccc3(255,255,255));
    this->addChild(Singleton<GameManager>::GetInst()->tutorialMent3,3);

    Singleton<GameManager>::GetInst()->tutorialMent4->setVisible(false);
    Singleton<GameManager>::GetInst()->tutorialMent4->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2,CCDirector::sharedDirector()->getVisibleSize().height/2));
    Singleton<GameManager>::GetInst()->tutorialMent4->setColor(ccc3(255,255,255));
    this->addChild(Singleton<GameManager>::GetInst()->tutorialMent4,3);

    Singleton<GameManager>::GetInst()->tutorialMent5->setVisible(false);
    Singleton<GameManager>::GetInst()->tutorialMent5->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2,CCDirector::sharedDirector()->getVisibleSize().height/2));
    Singleton<GameManager>::GetInst()->tutorialMent5->setColor(ccc3(255,255,255));
    this->addChild(Singleton<GameManager>::GetInst()->tutorialMent5,3);

    Singleton<GameManager>::GetInst()->tutorialMent6->setVisible(false);
    Singleton<GameManager>::GetInst()->tutorialMent6->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2,CCDirector::sharedDirector()->getVisibleSize().height/2));
    Singleton<GameManager>::GetInst()->tutorialMent6->setColor(ccc3(255,255,255));
    this->addChild(Singleton<GameManager>::GetInst()->tutorialMent6,3);

    Singleton<GameManager>::GetInst()->tutorialMent7->setVisible(false);
    Singleton<GameManager>::GetInst()->tutorialMent7->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2,CCDirector::sharedDirector()->getVisibleSize().height/2));
    Singleton<GameManager>::GetInst()->tutorialMent7->setColor(ccc3(255,255,255));
    this->addChild(Singleton<GameManager>::GetInst()->tutorialMent7,3);

    Singleton<GameManager>::GetInst()->tutorialMent8->setVisible(false);
    Singleton<GameManager>::GetInst()->tutorialMent8->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2,CCDirector::sharedDirector()->getVisibleSize().height/2));
    Singleton<GameManager>::GetInst()->tutorialMent8->setColor(ccc3(255,255,255));
    this->addChild(Singleton<GameManager>::GetInst()->tutorialMent8,3);
}
  /*
void PlayScene::printNode_copy(int nodeCount2, int channel)
{
    // nodePrintLayer_copy = dstlayer2;
  
    std::vector<Block *> _collision_boxes_copy = _collision_boxes_Channel_copy.at(channel);
    Block *target2 =  _collision_boxes_copy.at(nodeCount2);
    
    target2->print_layer = _block_layer;
    if(target2->body == NULL)
    {
        dstlayer2->addChild(target2->tail,0,nodeCount2);
    }
    else
    {
        dstlayer2->addChild(target2->body,0,nodeCount2);
    }
   
}
  */


void PlayScene::start_count_display_copy()
{
    /*
    --start_count_num_copy;
    sprintf(str, "%d", start_count_num_copy);
    Singleton<GameManager>::GetInst()->start_count_copy->setString(str);
    
    if(start_count_num_copy == -1)
    {
        //泥レ쨪 媛�씠���쇱씤
        //泥レ쨪 媛�씠���쇱씤
        
        int index = 0;
        for(int midiCHCount = 0; midiCHCount < Singleton<GameManager>::GetInst()->midiChannel.size(); midiCHCount++)
        {
            std::vector<noteData> midiEvents = Singleton<GameManager>::GetInst()->midiChannel.at(midiCHCount);
            
            noteData firstNote = midiEvents.at(index);
            while (firstNote.timeMillis == 0.0f)
            {
                Singleton<GameManager>::GetInst()->pianoGuideVisible_copy(firstNote.pitch);
                ++index;
                firstNote = midiEvents.at(index);
            }
        }
        
        Singleton<GameManager>::GetInst()->start_count_copy->setVisible(false);
    }
    else
    {
        CCDelayTime *delayAction = CCDelayTime::create(1);
        CCCallFuncN *callSelectorAction = CCCallFuncN::create(this, callfuncN_selector(PlayScene::start_count_display_copy));
        Singleton<GameManager>::GetInst()->start_count_copy->runAction(CCSequence::create(delayAction, callSelectorAction, NULL));
    }
     */
}
//void PlayScene::makeCollisinoBoxes_update(CCNode* sender, int channel)
/*
void PlayScene::noPrintNode()
{
    CCLOG("noPrintNode");
    
}

void PlayScene::makeCollisinoBoxes_update_copy(CCNode* sender, int channel)
{
    
    std::vector<noteData> midiEvents = Singleton<GameManager>::GetInst()->midiChannel.at(channel);
    
    if(Singleton<GameManager>::GetInst()->nodePrintCount_Channel_copy.at(channel) < midiEvents.size())
    {
        CCArray *guide_Total_Array = Singleton<GameManager>::GetInst()->guide_Total_Array_channel_copy.at(channel);
        
        CCArray *guide_Value_Array = CCArray::create();
        
        
        noteData Node = midiEvents.at(Singleton<GameManager>::GetInst()->nodePrintCount_Channel_copy.at(channel));
        
        Singleton<GameManager>::GetInst()->printNode_copy(Singleton<GameManager>::GetInst()->nodePrintCount_Channel_copy.at(channel),_block_layer_copy,channel);

        guide_Value_Array->addObject(CCInteger::create(Singleton<GameManager>::GetInst()->nodePrintCount_Channel_copy.at(channel)));
        std::vector<Block *> _collision_boxes = Singleton<GameManager>::GetInst()->_collision_boxes_Channel_copy.at(channel);
        Block *target =  _collision_boxes.at(Singleton<GameManager>::GetInst()->nodePrintCount_Channel_copy.at(channel));
        target->breakLine = guide_Total_Array->count();
        ++Singleton<GameManager>::GetInst()->nodePrintCount_Channel_copy.at(channel);
        if(Singleton<GameManager>::GetInst()->nodePrintCount_Channel_copy.at(channel) != midiEvents.size())
        {
            Node = midiEvents.at(Singleton<GameManager>::GetInst()->nodePrintCount_Channel_copy.at(channel));
            while(Node.elapsedMillis == 0.0f)
            {
                Singleton<GameManager>::GetInst()->printNode_copy(Singleton<GameManager>::GetInst()->nodePrintCount_Channel_copy.at(channel),_block_layer_copy,channel);
                
                guide_Value_Array->addObject(CCInteger::create(Singleton<GameManager>::GetInst()->nodePrintCount_Channel_copy.at(channel)));
                Block *target =  _collision_boxes.at(Singleton<GameManager>::GetInst()->nodePrintCount_Channel_copy.at(channel));
                target->breakLine = guide_Total_Array->count();
                ++Singleton<GameManager>::GetInst()->nodePrintCount_Channel_copy.at(channel);
                if(Singleton<GameManager>::GetInst()->nodePrintCount_Channel_copy.at(channel) == midiEvents.size())
                {
                    break;
                }
                Node = midiEvents.at(Singleton<GameManager>::GetInst()->nodePrintCount_Channel_copy.at(channel));
            }
        }
        
        
        
        
        if(guide_Value_Array->count() > 0)
        {
            guide_Total_Array->addObject(guide_Value_Array);
        }
        
        
        
        
        CCDelayTime *delay = CCDelayTime::create(Node.elapsedMillis);
        CCCallFuncND *func = CCCallFuncND::create(this, callfuncND_selector(PlayScene::makeCollisinoBoxes_update_copy), (void*)channel);
        cocos2d::CCSequence * seq = CCSequence::createWithTwoActions(delay, func);
        this->runAction(seq);
    }
 
 
}


void PlayScene::noPrintNode_copy()
{
    CCLOG("noPrintNode_copy");
    
}
*/





void PlayScene::update_copy(float dt)
{
    
}

void PlayScene::feverReturn()
{
    Singleton<GameManager>::GetInst()->feverTimer = false;
    Singleton<GameManager>::GetInst()->feverMode = false;
    Singleton<GameManager>::GetInst()->energy_bar->setPercentage(ENERGY_INIT); 
    CCLog("feverMode : %d",Singleton<GameManager>::GetInst()->feverMode);
}
void PlayScene::endDelay()
{
    
    if(Singleton<GameManager>::GetInst()->gameMode == SINGE_GAME)
    {
        CC_SAFE_RELEASE_NULL(_bg_layer);
        CC_SAFE_RELEASE_NULL(_controll_layer);
        CC_SAFE_RELEASE_NULL(_block_layer);
        CC_SAFE_RELEASE_NULL(_ui_layer);
        CC_SAFE_RELEASE_NULL(_line_layer);
        CC_SAFE_RELEASE_NULL(_effect_layer);
    }
    else if(Singleton<GameManager>::GetInst()->gameMode == SINGE_FREE)
    {
        CC_SAFE_RELEASE_NULL(_bg_layer);
        CC_SAFE_RELEASE_NULL(_controll_layer);
        CC_SAFE_RELEASE_NULL(_ui_layer);
    }
    else
    {
        CC_SAFE_RELEASE_NULL(_bg_layer);
        CC_SAFE_RELEASE_NULL(_bg_layer_copy);
        
        CC_SAFE_RELEASE_NULL(_controll_layer);
        CC_SAFE_RELEASE_NULL(_controll_layer_copy);
        
        CC_SAFE_RELEASE_NULL(_block_layer);
        CC_SAFE_RELEASE_NULL(_block_layer_copy);
        
        CC_SAFE_RELEASE_NULL(_ui_layer);
        CC_SAFE_RELEASE_NULL(_ui_layer_copy);
        
        CC_SAFE_RELEASE_NULL(_line_layer);
        CC_SAFE_RELEASE_NULL(_line_layer_copy);
        
        CC_SAFE_RELEASE_NULL(_effect_layer);
        CC_SAFE_RELEASE_NULL(_effect_layer_copy);
    }
    
    
    Singleton<GameManager>::GetInst()->game_end();
}
void PlayScene::update(float dt)
{
    if(Singleton<GameManager>::GetInst()->gameEnding == END_DELAY)
    {
        Singleton<GameManager>::GetInst()->gameEnding = true;
        
        CCDelayTime *delay = CCDelayTime::create(0.5);
        CCCallFuncN *callSelectorAction = CCCallFuncN::create(this, callfuncN_selector(PlayScene::endDelay));
        cocos2d::CCSequence * seq = CCSequence::createWithTwoActions(delay, callSelectorAction);
        this->runAction(seq);
        //
    }
    
    if(Singleton<GameManager>::GetInst()->gameStart &&
       Singleton<GameManager>::GetInst()->gameEnding == END_FALSE)
    {
        Singleton<GameManager>::GetInst()->timeBar->setPercentage(Singleton<GameManager>::GetInst()->timeBar->getPercentage() - ( 100 / (Singleton<GameManager>::GetInst()->maxTime + TIMEDELAY + Singleton<GameManager>::GetInst()->PIANO_FINISH_TIME))*dt*Singleton<GameManager>::GetInst()->gameSpeed);
        
        if(Singleton<GameManager>::GetInst()->feverTimer)
        {
            Singleton<GameManager>::GetInst()->feverTimer = false;
            Singleton<GameManager>::GetInst()->feverMode = true;
            CCLog("feverMode : %d",Singleton<GameManager>::GetInst()->feverMode);
            CCDelayTime *delay = CCDelayTime::create(FEVERTIME);
            CCCallFuncN *callSelectorAction = CCCallFuncN::create(this, callfuncN_selector(PlayScene::feverReturn));
            cocos2d::CCSequence * seq = CCSequence::createWithTwoActions(delay, callSelectorAction);
            this->runAction(seq);
        }
        
        
        
        delay_Time = dt;
       
        if(Singleton<GameManager>::GetInst()->hp_bar->getTextureRect().size.width <= 0)
        {
            if(Singleton<GameManager>::GetInst()->gameEnding == END_FALSE)
            {
                Singleton<GameManager>::GetInst()->game_wait_end();
            }
        }
        if(Singleton<GameManager>::GetInst()->timeBar->getPercentage() <= 0)
        {
            if(Singleton<GameManager>::GetInst()->gameEnding == END_FALSE)
            {
                Singleton<GameManager>::GetInst()->game_wait_end();
            }
        }
        _ui_layer->update(dt);
        if(Singleton<GameManager>::GetInst()->gameMode == ANG_GAME)
        {
            _ui_layer_copy->update(dt);
        }
        
        _block_layer->update(dt);  //釉붾윮 �대룞
    }
}

void PlayScene::updatefree(float dt)
{
    
}



 




