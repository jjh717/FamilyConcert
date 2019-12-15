#include "LoadBgLayer.H"

#include <stdlib.h>


LoadBgLayer::LoadBgLayer()
{
    
}

LoadBgLayer::~LoadBgLayer()
{
    
}


bool LoadBgLayer::init()
{
    pianoLoadCount = 0;
    pianoLoadCount_copy = 0;

    Singleton<GameManager>::GetInst()->LoadBG->setAnchorPoint(ccp(0.0f, 0.0f));
    Singleton<GameManager>::GetInst()->LoadBG->setPosition(ccp(0.0f,0.0f));
    
    this->addChild(Singleton<GameManager>::GetInst()->LoadBG, 0);
    
    if(Singleton<GameManager>::GetInst()->gameMode == NORMAL_GAME)
    {
        //
        Singleton<GameManager>::GetInst()->load_timeBar_gaze->setAnchorPoint(ccp(0.0f, 0.0f));
        Singleton<GameManager>::GetInst()->load_timeBar_gaze->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2-280,89));
        
        this->addChild(Singleton<GameManager>::GetInst()->load_timeBar_gaze, 0);
    }
    else if(Singleton<GameManager>::GetInst()->gameMode == EASY_GAME)
    {
        aniCount = 17;
        for(int i=0;i<aniCount;i++)
        {
            loadPer[i] = 0;
        }
        
        Singleton<GameManager>::GetInst()->load_line->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2-20,CCDirector::sharedDirector()->getWinSize().height/2 - 100 + 47));
        this->addChild(Singleton<GameManager>::GetInst()->load_line,1);
        
        
        Singleton<GameManager>::GetInst()->load_timer_gaze[0]->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2-295,CCDirector::sharedDirector()->getWinSize().height/2 - 100 + 68));
        this->addChild(Singleton<GameManager>::GetInst()->load_timer_gaze[0],2);
        
        
        
        Singleton<GameManager>::GetInst()->load_timer_gaze[1]->setTexture(Singleton<GameManager>::GetInst()->load_timer_gaze_tex[3]);
        Singleton<GameManager>::GetInst()->load_timer_gaze[1]->setPosition(ccp(Singleton<GameManager>::GetInst()->load_timer_gaze[0]->getPositionX()+30,CCDirector::sharedDirector()->getWinSize().height/2 - 100 + 43));
        this->addChild(Singleton<GameManager>::GetInst()->load_timer_gaze[1],2);
        
        
        Singleton<GameManager>::GetInst()->load_timer_gaze[2]->setTexture(Singleton<GameManager>::GetInst()->load_timer_gaze_tex[0]);
        Singleton<GameManager>::GetInst()->load_timer_gaze[2]->setPosition(ccp(Singleton<GameManager>::GetInst()->load_timer_gaze[1]->getPositionX()+35,CCDirector::sharedDirector()->getWinSize().height/2 - 100 + 30));
        this->addChild(Singleton<GameManager>::GetInst()->load_timer_gaze[2],2);
        
        
        Singleton<GameManager>::GetInst()->load_timer_gaze[3]->setTexture(Singleton<GameManager>::GetInst()->load_timer_gaze_tex[1]);
        Singleton<GameManager>::GetInst()->load_timer_gaze[3]->setPosition(ccp(Singleton<GameManager>::GetInst()->load_timer_gaze[2]->getPositionX()+35,CCDirector::sharedDirector()->getWinSize().height/2 - 100 + 83));
        this->addChild(Singleton<GameManager>::GetInst()->load_timer_gaze[3],2);
        
        
        Singleton<GameManager>::GetInst()->load_timer_gaze[4]->setTexture(Singleton<GameManager>::GetInst()->load_timer_gaze_tex[2]);
        Singleton<GameManager>::GetInst()->load_timer_gaze[4]->setPosition(ccp(Singleton<GameManager>::GetInst()->load_timer_gaze[3]->getPositionX()+35,CCDirector::sharedDirector()->getWinSize().height/2 - 100 + 60));
        this->addChild(Singleton<GameManager>::GetInst()->load_timer_gaze[4],2);
        
        
        Singleton<GameManager>::GetInst()->load_timer_gaze[5]->setTexture(Singleton<GameManager>::GetInst()->load_timer_gaze_tex[3]);
        Singleton<GameManager>::GetInst()->load_timer_gaze[5]->setRotation(10);
        Singleton<GameManager>::GetInst()->load_timer_gaze[5]->setPosition(ccp(Singleton<GameManager>::GetInst()->load_timer_gaze[4]->getPositionX()+35,CCDirector::sharedDirector()->getWinSize().height/2 - 100 + 94));
        this->addChild(Singleton<GameManager>::GetInst()->load_timer_gaze[5],2);
        
        
        Singleton<GameManager>::GetInst()->load_timer_gaze[6]->setTexture(Singleton<GameManager>::GetInst()->load_timer_gaze_tex[1]);
        Singleton<GameManager>::GetInst()->load_timer_gaze[6]->setRotation(140);
        Singleton<GameManager>::GetInst()->load_timer_gaze[6]->setPosition(ccp(Singleton<GameManager>::GetInst()->load_timer_gaze[5]->getPositionX()+35,CCDirector::sharedDirector()->getWinSize().height/2 - 100 + 50));
        this->addChild(Singleton<GameManager>::GetInst()->load_timer_gaze[6],2);
        
        
        Singleton<GameManager>::GetInst()->load_timer_gaze[7]->setTexture(Singleton<GameManager>::GetInst()->load_timer_gaze_tex[0]);
        Singleton<GameManager>::GetInst()->load_timer_gaze[7]->setRotation(20);
        Singleton<GameManager>::GetInst()->load_timer_gaze[7]->setPosition(ccp(Singleton<GameManager>::GetInst()->load_timer_gaze[6]->getPositionX()+22,CCDirector::sharedDirector()->getWinSize().height/2 - 100 + 75));
        this->addChild(Singleton<GameManager>::GetInst()->load_timer_gaze[7],2);
        
        
        Singleton<GameManager>::GetInst()->load_timer_gaze[8]->setTexture(Singleton<GameManager>::GetInst()->load_timer_gaze_tex[2]);
        Singleton<GameManager>::GetInst()->load_timer_gaze[8]->setRotation(200);
        Singleton<GameManager>::GetInst()->load_timer_gaze[8]->setPosition(ccp(Singleton<GameManager>::GetInst()->load_timer_gaze[7]->getPositionX()+22,CCDirector::sharedDirector()->getWinSize().height/2 - 100 + 35));
        this->addChild(Singleton<GameManager>::GetInst()->load_timer_gaze[8],2);
        
        
        Singleton<GameManager>::GetInst()->load_timer_gaze[9]->setTexture(Singleton<GameManager>::GetInst()->load_timer_gaze_tex[1]);
        Singleton<GameManager>::GetInst()->load_timer_gaze[9]->setRotation(-40);
        Singleton<GameManager>::GetInst()->load_timer_gaze[9]->setPosition(ccp(Singleton<GameManager>::GetInst()->load_timer_gaze[8]->getPositionX()+22,CCDirector::sharedDirector()->getWinSize().height/2 - 100 + 60));
        this->addChild(Singleton<GameManager>::GetInst()->load_timer_gaze[9],2);
        
        
        Singleton<GameManager>::GetInst()->load_timer_gaze[10]->setTexture(Singleton<GameManager>::GetInst()->load_timer_gaze_tex[0]);
        Singleton<GameManager>::GetInst()->load_timer_gaze[10]->setRotation(10);
        Singleton<GameManager>::GetInst()->load_timer_gaze[10]->setPosition(ccp(Singleton<GameManager>::GetInst()->load_timer_gaze[9]->getPositionX()+40,CCDirector::sharedDirector()->getWinSize().height/2 - 100 + 60));
        this->addChild(Singleton<GameManager>::GetInst()->load_timer_gaze[10],2);
        
        
        Singleton<GameManager>::GetInst()->load_timer_gaze[11]->setTexture(Singleton<GameManager>::GetInst()->load_timer_gaze_tex[3]);
        Singleton<GameManager>::GetInst()->load_timer_gaze[11]->setRotation(200);
        Singleton<GameManager>::GetInst()->load_timer_gaze[11]->setPosition(ccp(Singleton<GameManager>::GetInst()->load_timer_gaze[10]->getPositionX()+40,CCDirector::sharedDirector()->getWinSize().height/2 - 100 + 45));
        this->addChild(Singleton<GameManager>::GetInst()->load_timer_gaze[11],2);
        
        
        Singleton<GameManager>::GetInst()->load_timer_gaze[12]->setTexture(Singleton<GameManager>::GetInst()->load_timer_gaze_tex[0]);
        Singleton<GameManager>::GetInst()->load_timer_gaze[12]->setRotation(180);
        Singleton<GameManager>::GetInst()->load_timer_gaze[12]->setPosition(ccp(Singleton<GameManager>::GetInst()->load_timer_gaze[11]->getPositionX()+35,CCDirector::sharedDirector()->getWinSize().height/2 - 100 + 20));
        this->addChild(Singleton<GameManager>::GetInst()->load_timer_gaze[12],2);
        
        
        Singleton<GameManager>::GetInst()->load_timer_gaze[13]->setTexture(Singleton<GameManager>::GetInst()->load_timer_gaze_tex[2]);
        Singleton<GameManager>::GetInst()->load_timer_gaze[13]->setRotation(-10);
        Singleton<GameManager>::GetInst()->load_timer_gaze[13]->setPosition(ccp(Singleton<GameManager>::GetInst()->load_timer_gaze[12]->getPositionX()+35,CCDirector::sharedDirector()->getWinSize().height/2 - 100 + 50));
        this->addChild(Singleton<GameManager>::GetInst()->load_timer_gaze[13],2);
        
        
        Singleton<GameManager>::GetInst()->load_timer_gaze[14]->setTexture(Singleton<GameManager>::GetInst()->load_timer_gaze_tex[1]);
        Singleton<GameManager>::GetInst()->load_timer_gaze[14]->setRotation(140);
        Singleton<GameManager>::GetInst()->load_timer_gaze[14]->setPosition(ccp(Singleton<GameManager>::GetInst()->load_timer_gaze[13]->getPositionX()+30,CCDirector::sharedDirector()->getWinSize().height/2 - 100 + 26));
        this->addChild(Singleton<GameManager>::GetInst()->load_timer_gaze[14],2);
        
        
        Singleton<GameManager>::GetInst()->load_timer_gaze[15]->setTexture(Singleton<GameManager>::GetInst()->load_timer_gaze_tex[0]);
        Singleton<GameManager>::GetInst()->load_timer_gaze[15]->setRotation(20);
        Singleton<GameManager>::GetInst()->load_timer_gaze[15]->setPosition(ccp(Singleton<GameManager>::GetInst()->load_timer_gaze[14]->getPositionX()+30,CCDirector::sharedDirector()->getWinSize().height/2 - 100 + 55));
        this->addChild(Singleton<GameManager>::GetInst()->load_timer_gaze[15],2);
        
        
        Singleton<GameManager>::GetInst()->load_timer_gaze[16]->setTexture(Singleton<GameManager>::GetInst()->load_timer_gaze_tex[1]);
        Singleton<GameManager>::GetInst()->load_timer_gaze[16]->setRotation(10);
        Singleton<GameManager>::GetInst()->load_timer_gaze[16]->setPosition(ccp(Singleton<GameManager>::GetInst()->load_timer_gaze[15]->getPositionX()+30,CCDirector::sharedDirector()->getWinSize().height/2 - 100 + 45));
        this->addChild(Singleton<GameManager>::GetInst()->load_timer_gaze[16],2);
        
        
        Singleton<GameManager>::GetInst()->load_timer_gaze[17]->setTexture(Singleton<GameManager>::GetInst()->load_timer_gaze_tex[3]);
        Singleton<GameManager>::GetInst()->load_timer_gaze[17]->setRotation(150);
        Singleton<GameManager>::GetInst()->load_timer_gaze[17]->setPosition(ccp(Singleton<GameManager>::GetInst()->load_timer_gaze[16]->getPositionX()+35,CCDirector::sharedDirector()->getWinSize().height/2 - 100 + 60));
        this->addChild(Singleton<GameManager>::GetInst()->load_timer_gaze[17],2);
    }
    else
    {
        aniCount = 17;
        for(int i=0;i<aniCount;i++)
        {
            loadPer[i] = 0;
        }
        
        Singleton<GameManager>::GetInst()->load_line->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2-20,47));
        this->addChild(Singleton<GameManager>::GetInst()->load_line,1);
        
        
        Singleton<GameManager>::GetInst()->load_timer_gaze[0]->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2-295,68));
        this->addChild(Singleton<GameManager>::GetInst()->load_timer_gaze[0],2);
     
        
        
        Singleton<GameManager>::GetInst()->load_timer_gaze[1]->setTexture(Singleton<GameManager>::GetInst()->load_timer_gaze_tex[3]);
        Singleton<GameManager>::GetInst()->load_timer_gaze[1]->setPosition(ccp(Singleton<GameManager>::GetInst()->load_timer_gaze[0]->getPositionX()+30,43));
        this->addChild(Singleton<GameManager>::GetInst()->load_timer_gaze[1],2);
        
        
        Singleton<GameManager>::GetInst()->load_timer_gaze[2]->setTexture(Singleton<GameManager>::GetInst()->load_timer_gaze_tex[0]);
        Singleton<GameManager>::GetInst()->load_timer_gaze[2]->setPosition(ccp(Singleton<GameManager>::GetInst()->load_timer_gaze[1]->getPositionX()+35,30));
        this->addChild(Singleton<GameManager>::GetInst()->load_timer_gaze[2],2);

        
        Singleton<GameManager>::GetInst()->load_timer_gaze[3]->setTexture(Singleton<GameManager>::GetInst()->load_timer_gaze_tex[1]);
        Singleton<GameManager>::GetInst()->load_timer_gaze[3]->setPosition(ccp(Singleton<GameManager>::GetInst()->load_timer_gaze[2]->getPositionX()+35,83));
        this->addChild(Singleton<GameManager>::GetInst()->load_timer_gaze[3],2);
        
        
        Singleton<GameManager>::GetInst()->load_timer_gaze[4]->setTexture(Singleton<GameManager>::GetInst()->load_timer_gaze_tex[2]);
        Singleton<GameManager>::GetInst()->load_timer_gaze[4]->setPosition(ccp(Singleton<GameManager>::GetInst()->load_timer_gaze[3]->getPositionX()+35,60));
        this->addChild(Singleton<GameManager>::GetInst()->load_timer_gaze[4],2);

        
        Singleton<GameManager>::GetInst()->load_timer_gaze[5]->setTexture(Singleton<GameManager>::GetInst()->load_timer_gaze_tex[3]);
        Singleton<GameManager>::GetInst()->load_timer_gaze[5]->setRotation(10);
        Singleton<GameManager>::GetInst()->load_timer_gaze[5]->setPosition(ccp(Singleton<GameManager>::GetInst()->load_timer_gaze[4]->getPositionX()+35,94));
        this->addChild(Singleton<GameManager>::GetInst()->load_timer_gaze[5],2);

        
        Singleton<GameManager>::GetInst()->load_timer_gaze[6]->setTexture(Singleton<GameManager>::GetInst()->load_timer_gaze_tex[1]);
        Singleton<GameManager>::GetInst()->load_timer_gaze[6]->setRotation(140);
        Singleton<GameManager>::GetInst()->load_timer_gaze[6]->setPosition(ccp(Singleton<GameManager>::GetInst()->load_timer_gaze[5]->getPositionX()+35,50));
        this->addChild(Singleton<GameManager>::GetInst()->load_timer_gaze[6],2);
        
        
        Singleton<GameManager>::GetInst()->load_timer_gaze[7]->setTexture(Singleton<GameManager>::GetInst()->load_timer_gaze_tex[0]);
        Singleton<GameManager>::GetInst()->load_timer_gaze[7]->setRotation(20);
        Singleton<GameManager>::GetInst()->load_timer_gaze[7]->setPosition(ccp(Singleton<GameManager>::GetInst()->load_timer_gaze[6]->getPositionX()+22,75));
        this->addChild(Singleton<GameManager>::GetInst()->load_timer_gaze[7],2);
        
        
        Singleton<GameManager>::GetInst()->load_timer_gaze[8]->setTexture(Singleton<GameManager>::GetInst()->load_timer_gaze_tex[2]);
        Singleton<GameManager>::GetInst()->load_timer_gaze[8]->setRotation(200);
        Singleton<GameManager>::GetInst()->load_timer_gaze[8]->setPosition(ccp(Singleton<GameManager>::GetInst()->load_timer_gaze[7]->getPositionX()+22,35));
        this->addChild(Singleton<GameManager>::GetInst()->load_timer_gaze[8],2);
        
        
        Singleton<GameManager>::GetInst()->load_timer_gaze[9]->setTexture(Singleton<GameManager>::GetInst()->load_timer_gaze_tex[1]);
        Singleton<GameManager>::GetInst()->load_timer_gaze[9]->setRotation(-40);
        Singleton<GameManager>::GetInst()->load_timer_gaze[9]->setPosition(ccp(Singleton<GameManager>::GetInst()->load_timer_gaze[8]->getPositionX()+22,60));
        this->addChild(Singleton<GameManager>::GetInst()->load_timer_gaze[9],2);
        
        
        Singleton<GameManager>::GetInst()->load_timer_gaze[10]->setTexture(Singleton<GameManager>::GetInst()->load_timer_gaze_tex[0]);
        Singleton<GameManager>::GetInst()->load_timer_gaze[10]->setRotation(10);
        Singleton<GameManager>::GetInst()->load_timer_gaze[10]->setPosition(ccp(Singleton<GameManager>::GetInst()->load_timer_gaze[9]->getPositionX()+40,60));
        this->addChild(Singleton<GameManager>::GetInst()->load_timer_gaze[10],2);
        
        
        Singleton<GameManager>::GetInst()->load_timer_gaze[11]->setTexture(Singleton<GameManager>::GetInst()->load_timer_gaze_tex[3]);
        Singleton<GameManager>::GetInst()->load_timer_gaze[11]->setRotation(200);
        Singleton<GameManager>::GetInst()->load_timer_gaze[11]->setPosition(ccp(Singleton<GameManager>::GetInst()->load_timer_gaze[10]->getPositionX()+40,45));
        this->addChild(Singleton<GameManager>::GetInst()->load_timer_gaze[11],2);
        
        
        Singleton<GameManager>::GetInst()->load_timer_gaze[12]->setTexture(Singleton<GameManager>::GetInst()->load_timer_gaze_tex[0]);
        Singleton<GameManager>::GetInst()->load_timer_gaze[12]->setRotation(180);
        Singleton<GameManager>::GetInst()->load_timer_gaze[12]->setPosition(ccp(Singleton<GameManager>::GetInst()->load_timer_gaze[11]->getPositionX()+35,20));
        this->addChild(Singleton<GameManager>::GetInst()->load_timer_gaze[12],2);
        
        
        Singleton<GameManager>::GetInst()->load_timer_gaze[13]->setTexture(Singleton<GameManager>::GetInst()->load_timer_gaze_tex[2]);
        Singleton<GameManager>::GetInst()->load_timer_gaze[13]->setRotation(-10);
        Singleton<GameManager>::GetInst()->load_timer_gaze[13]->setPosition(ccp(Singleton<GameManager>::GetInst()->load_timer_gaze[12]->getPositionX()+35,50));
        this->addChild(Singleton<GameManager>::GetInst()->load_timer_gaze[13],2);
        
        
        Singleton<GameManager>::GetInst()->load_timer_gaze[14]->setTexture(Singleton<GameManager>::GetInst()->load_timer_gaze_tex[1]);
        Singleton<GameManager>::GetInst()->load_timer_gaze[14]->setRotation(140);
        Singleton<GameManager>::GetInst()->load_timer_gaze[14]->setPosition(ccp(Singleton<GameManager>::GetInst()->load_timer_gaze[13]->getPositionX()+30,26));
        this->addChild(Singleton<GameManager>::GetInst()->load_timer_gaze[14],2);
        
        
        Singleton<GameManager>::GetInst()->load_timer_gaze[15]->setTexture(Singleton<GameManager>::GetInst()->load_timer_gaze_tex[0]);
        Singleton<GameManager>::GetInst()->load_timer_gaze[15]->setRotation(20);
        Singleton<GameManager>::GetInst()->load_timer_gaze[15]->setPosition(ccp(Singleton<GameManager>::GetInst()->load_timer_gaze[14]->getPositionX()+30,55));
        this->addChild(Singleton<GameManager>::GetInst()->load_timer_gaze[15],2);
        
        
        Singleton<GameManager>::GetInst()->load_timer_gaze[16]->setTexture(Singleton<GameManager>::GetInst()->load_timer_gaze_tex[1]);
        Singleton<GameManager>::GetInst()->load_timer_gaze[16]->setRotation(10);
        Singleton<GameManager>::GetInst()->load_timer_gaze[16]->setPosition(ccp(Singleton<GameManager>::GetInst()->load_timer_gaze[15]->getPositionX()+30,45));
        this->addChild(Singleton<GameManager>::GetInst()->load_timer_gaze[16],2);

        
        Singleton<GameManager>::GetInst()->load_timer_gaze[17]->setTexture(Singleton<GameManager>::GetInst()->load_timer_gaze_tex[3]);
        Singleton<GameManager>::GetInst()->load_timer_gaze[17]->setRotation(150);
        Singleton<GameManager>::GetInst()->load_timer_gaze[17]->setPosition(ccp(Singleton<GameManager>::GetInst()->load_timer_gaze[16]->getPositionX()+35,60));
        this->addChild(Singleton<GameManager>::GetInst()->load_timer_gaze[17],2);
    }
    
    this->loadingData();
    
    
    
    
    
    return true;
}
void LoadBgLayer::loadingData()
{
    if(Singleton<GameManager>::GetInst()->gameMode == ANG_GAME)
    {
        Singleton<GameManager>::GetInst()->resourceGameSceneLoad();
        this->schedule( schedule_selector(LoadBgLayer::loadPercent_copy), 0.0001f);
        this->schedule( schedule_selector(LoadBgLayer::loadPercent), 0.0001f);
    }
    else if(Singleton<GameManager>::GetInst()->gameMode == SINGE_FREE)
    {
        Singleton<GameManager>::GetInst()->resourceFreeGameSceneLoad();
        this->schedule( schedule_selector(LoadBgLayer::loadPercent), 0.0001f);
    }
    else if(Singleton<GameManager>::GetInst()->gameMode == ANG_FREE)
    {
        Singleton<GameManager>::GetInst()->resourceFreeGameSceneLoad();
        this->schedule( schedule_selector(LoadBgLayer::loadPercent_copy), 0.0001f);
        this->schedule( schedule_selector(LoadBgLayer::loadPercent), 0.0001f);
    }
    else if(Singleton<GameManager>::GetInst()->gameMode == EASY_GAME)
    {
        Singleton<GameManager>::GetInst()->resourceEasyGameSceneLoad();
        this->schedule( schedule_selector(LoadBgLayer::loadPercent), 0.0001f);
    }
    else if(Singleton<GameManager>::GetInst()->gameMode == NORMAL_GAME)
    {
        Singleton<GameManager>::GetInst()->resourceNormalGameSceneLoad();
        this->schedule( schedule_selector(LoadBgLayer::loadPercent), 0.0001f);
    }
    else
    {
        Singleton<GameManager>::GetInst()->resourceGameSceneLoad();  //이미지 로딩 종료후 gameScene 만들기  즉 printNode 도 한다는 소리
        this->schedule( schedule_selector(LoadBgLayer::loadPercent), 0.0001f);
    }
}





void LoadBgLayer::loadPercent(float dt)
{
    if(Singleton<GameManager>::GetInst()->loding_complete)
    {
        if(Singleton<GameManager>::GetInst()->gameMode == NORMAL_GAME) // free mode
        {
            if(pianoLoadCount < TOTAL_PIANO_COUNT)
            {
                Singleton<GameManager>::GetInst()->downBlockPosInit(pianoLoadCount);
                ++pianoLoadCount;
                Singleton<GameManager>::GetInst()->load_timeBar = (50 + (float)pianoLoadCount / (float)TOTAL_PIANO_COUNT * 100.0f/2);
            }
            else
            {
                this->unschedule(schedule_selector(LoadBgLayer::loadPercent));
                
                CCLOG("midi_load?? : %d",Singleton<GameManager>::GetInst()->gameMode);
                Singleton<GameManager>::GetInst()->Midi_Load();
                
                Singleton<GameManager>::GetInst()->printNodeInit();
                
                Singleton<GameManager>::GetInst()->runScene(GAME_NORMAL_SCENE_PLAY);
            }
            return;
        }
        if(Singleton<GameManager>::GetInst()->gameMode == EASY_GAME) // free mode
        {
            this->unschedule(schedule_selector(LoadBgLayer::loadPercent));
            Singleton<GameManager>::GetInst()->runScene(GAME_EASY_SCENE_PLAY);
            
            return;
        }
        
        if(Singleton<GameManager>::GetInst()->gameMode == SINGE_FREE) // free mode
        {
            if(pianoLoadCount < TOTAL_PIANO_COUNT)
            {
                Singleton<GameManager>::GetInst()->pianoSpriteInit(pianoLoadCount);
                ++pianoLoadCount;
                Singleton<GameManager>::GetInst()->load_timeBar = (50 + (float)pianoLoadCount / (float)TOTAL_PIANO_COUNT * 100.0f/2);
            }
            else
            {
                Singleton<GameManager>::GetInst()->pianoSpritePositionSet();
                this->unschedule(schedule_selector(LoadBgLayer::loadPercent));
                
                
                if(Singleton<GameManager>::GetInst()->pianoCoverValue == RAINBOW_MODE)
                {
                    Singleton<GameManager>::GetInst()->pianoRainbowButtonPress(); //처음 선택표시 위해
                }
                else if(Singleton<GameManager>::GetInst()->pianoCoverValue == MARK_MODE)
                {
                    Singleton<GameManager>::GetInst()->pianoMarkButtonPress(); //처음 선택표시 위해
                }
                else if(Singleton<GameManager>::GetInst()->pianoCoverValue == NORMAL_MODE)
                {
                    Singleton<GameManager>::GetInst()->pianoNormalButtonPress(); //처음 선택표시 위해
                }
                else
                {
                    Singleton<GameManager>::GetInst()->pianoRainbowButtonPress(); //처음 선택표시 위해
                }

                
                
                
                Singleton<GameManager>::GetInst()->runScene(GAME_SCENE_PLAY);
            }
            return;
        }
        
 
        if(pianoLoadCount < TOTAL_PIANO_COUNT)
        {
            Singleton<GameManager>::GetInst()->pianoSpriteInit(pianoLoadCount);
            ++pianoLoadCount;
            Singleton<GameManager>::GetInst()->load_timeBar = (50 + (float)pianoLoadCount / (float)TOTAL_PIANO_COUNT * 100.0f/2 ); // 40~80
        }
        else
        {
            
            Singleton<GameManager>::GetInst()->pianoSpritePositionSet();
            
            CCLOG("midi_load?? : %d",Singleton<GameManager>::GetInst()->gameMode);
            Singleton<GameManager>::GetInst()->Midi_Load();
            
            CCLOG("printNodeInit start");
            
            Singleton<GameManager>::GetInst()->printNodeInit();
            
            CCLOG("printNodeInit end");
            
            if(Singleton<GameManager>::GetInst()->pianoCoverValue == RAINBOW_MODE)
            {
                Singleton<GameManager>::GetInst()->pianoRainbowButtonPress(); //처음 선택표시 위해
            }
            else if(Singleton<GameManager>::GetInst()->pianoCoverValue == MARK_MODE)
            {
                Singleton<GameManager>::GetInst()->pianoMarkButtonPress(); //처음 선택표시 위해
            }
            else if(Singleton<GameManager>::GetInst()->pianoCoverValue == NORMAL_MODE)
            {
                Singleton<GameManager>::GetInst()->pianoNormalButtonPress(); //처음 선택표시 위해
            }
            else
            {
                Singleton<GameManager>::GetInst()->pianoRainbowButtonPress(); //처음 선택표시 위해
            }

            
            
            
            Singleton<GameManager>::GetInst()->start_count_display();//튜토리얼 시작
            
            this->unschedule(schedule_selector(LoadBgLayer::loadPercent));
            Singleton<GameManager>::GetInst()->runScene(GAME_SCENE_PLAY);
        }
    }
}
void LoadBgLayer::loadPercent_copy(float dt)
{
    /*
    if(Singleton<GameManager>::GetInst()->loding_complete)
    {
        if(Singleton<GameManager>::GetInst()->gameMode == ANG_FREE)
        {
            if(pianoLoadCount_copy < TOTAL_PIANO_COUNT)
            {
                Singleton<GameManager>::GetInst()->pianoSpriteInit(pianoLoadCount_copy);
                Singleton<GameManager>::GetInst()->pianoSpriteInit_copy(pianoLoadCount_copy);
                ++pianoLoadCount_copy;
            }
            else
            {
                Singleton<GameManager>::GetInst()->pianoSpritePositionSet();
                Singleton<GameManager>::GetInst()->pianoSpritePositionSet_copy();
                
                this->unschedule(schedule_selector(LoadBgLayer::loadPercent));
                Singleton<GameManager>::GetInst()->runScene(GAME_SCENE_PLAY);
            }
            return;
        }

        
        if(pianoLoadCount_copy < TOTAL_PIANO_COUNT)
        {
            Singleton<GameManager>::GetInst()->pianoSpriteInit_copy(pianoLoadCount_copy);
            ++pianoLoadCount_copy;
        }
        else
        {
            Singleton<GameManager>::GetInst()->pianoSpritePositionSet_copy();
            this->unschedule(schedule_selector(LoadBgLayer::loadPercent_copy));
        }
    }
     */
}


void LoadBgLayer::update(float dt)
{
    if(Singleton<GameManager>::GetInst()->gameMode == NORMAL_GAME)
    {
        Singleton<GameManager>::GetInst()->load_timeBar_gaze->setPercentage(Singleton<GameManager>::GetInst()->load_timeBar);
    }
    else
    {
        if(Singleton<GameManager>::GetInst()->load_timeBar > 75.0f)
        {
          //  this->aniPrint(17);
        }
        if(Singleton<GameManager>::GetInst()->load_timeBar > 68.0f)
        {
            this->aniPrint(16);
        }
        if(Singleton<GameManager>::GetInst()->load_timeBar > 64.0f)
        {
            this->aniPrint(15);
        }
        if(Singleton<GameManager>::GetInst()->load_timeBar > 60.0f)
        {
            this->aniPrint(14);
        }
        if(Singleton<GameManager>::GetInst()->load_timeBar > 56.0f)
        {
            this->aniPrint(13);
        }
        if(Singleton<GameManager>::GetInst()->load_timeBar > 52.0f)
        {
            this->aniPrint(12);
        }
        if(Singleton<GameManager>::GetInst()->load_timeBar > 48.0f)
        {
            this->aniPrint(11);
        }
        if(Singleton<GameManager>::GetInst()->load_timeBar > 44.0f)
        {
            this->aniPrint(10);
        }
        if(Singleton<GameManager>::GetInst()->load_timeBar > 40.0f)
        {
            this->aniPrint(9);
        }
        if(Singleton<GameManager>::GetInst()->load_timeBar > 36.0f)
        {
            this->aniPrint(8);
        }
        if(Singleton<GameManager>::GetInst()->load_timeBar > 32.0f)
        {
            this->aniPrint(7);
        }
        if(Singleton<GameManager>::GetInst()->load_timeBar > 28.0f)
        {
            this->aniPrint(6);
        }
        if(Singleton<GameManager>::GetInst()->load_timeBar > 24.0f)
        {
            this->aniPrint(5);
        }
        if(Singleton<GameManager>::GetInst()->load_timeBar > 20.0f)
        {
            this->aniPrint(4);
        }
        if(Singleton<GameManager>::GetInst()->load_timeBar > 16.0f)
        {
            this->aniPrint(3);
        }
        if(Singleton<GameManager>::GetInst()->load_timeBar > 12.0f)
        {
            this->aniPrint(2);
        }
        if(Singleton<GameManager>::GetInst()->load_timeBar > 8.0f)
        {
            this->aniPrint(1);
        }
        if(Singleton<GameManager>::GetInst()->load_timeBar > 4.0f)
        {
            this->aniPrint(0);
        }
    }
}

//CCDirector::sharedDirector()->getWinSize().height/2 - 50 -
void LoadBgLayer::aniPrint(int index)
{
    
    if(!loadPer[index])
    {
        loadPer[index] = true;
//        CCLog("aniPrint11 : %d  %f",index,Singleton<GameManager>::GetInst()->load_timeBar);
        CCActionInterval*  actionTo = CCJumpTo::create(1, ccp(Singleton<GameManager>::GetInst()->load_timer_gaze[index+1]->getPositionX(),Singleton<GameManager>::GetInst()->load_timer_gaze[index+1]->getPositionY()), 80, 1);
        Singleton<GameManager>::GetInst()->load_timer_gaze[index+1]->runAction(actionTo);
        Singleton<GameManager>::GetInst()->load_timer_gaze[index+1]->setVisible(true);
    }
}
