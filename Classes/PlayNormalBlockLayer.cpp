#include "PlayNormalBlockLayer.H"

 


PlayNormalBlockLayer::PlayNormalBlockLayer()
{
    
}

PlayNormalBlockLayer::~PlayNormalBlockLayer()
{
    
}


bool PlayNormalBlockLayer::init()
{
    setIosKeyEnabled(true);
    

    
    Singleton<GameManager>::GetInst()->coverLayer = CCLayer::create();
    
    //Singleton<GameManager>::GetInst()->coverLayer->setRotation(90);

    Singleton<GameManager>::GetInst()->coverLayer->setPositionX(Singleton<GameManager>::GetInst()->coverLayer->getPositionX()+200);
    //CCLog("Singleton<GameManager>::GetInst()->coverLayer->getPositionX() : %f",Singleton<GameManager>::GetInst()->coverLayer->getPositionX());
    Singleton<GameManager>::GetInst()->coverLayer->setAnchorPoint(ccp(0.5, 0.5));
    
    
    this->addChild(Singleton<GameManager>::GetInst()->coverLayer);
    
    
    minX = -200;


    Singleton<GameManager>::GetInst()->SetNormalBlockLayer(Singleton<GameManager>::GetInst()->coverLayer,this);
     
    return true;
}

 

void PlayNormalBlockLayer::update(float dt)
{
    Singleton<GameManager>::GetInst()->printNode(5);

//
    Singleton<GameManager>::GetInst()->coverLayer->setPositionX(Singleton<GameManager>::GetInst()->coverLayer->getPositionX() - (PianoSpeed*dt*Singleton<GameManager>::GetInst()->gameSpeed));
    
    Iter_Pos = Singleton<GameManager>::GetInst()->_guide_print_blocks.begin();
    Iter_Erase_Pos = Singleton<GameManager>::GetInst()->_erase_print_blocks.begin();
    if(Singleton<GameManager>::GetInst()->_erase_print_blocks.size() > 0)
    {
        
            /*
            if(Singleton<GameManager>::GetInst()->_guide_print_blocks.size() > 0)
            {
                Block *target = Iter_Pos->second;
                
                if(target->body != NULL)
                {
                    float blockPosY = target->body->getPositionY() + Singleton<GameManager>::GetInst()->coverLayer->getPositionX(); // 실제 블럭 위치
                 //   CCLog("blockPosY : %f",blockPosY);
                    if( blockPosY < minX)
                    {
                        if(!target->nextGuide)
                        {
                            // CCLog("blockPosY : %f",blockPosY);
                            target->nextGuide = true;
                            
                            Singleton<GameManager>::GetInst()->_guide_print_blocks.erase(Iter_Pos);
                            Iter_Pos = Singleton<GameManager>::GetInst()->_guide_print_blocks.begin();
                            ++Singleton<GameManager>::GetInst()->guideCount.at(0);
                            
                            this->nextGuide(target);
                        }
                    }
                }
                else
                {
                    float blockPosY = target->tail->getPositionY() + Singleton<GameManager>::GetInst()->coverLayer->getPositionX(); // 실제 블럭 위치
                    
                    if( blockPosY < minX)
                    {
                        if(!target->nextGuide)
                        {
                            target->nextGuide = true;
                            
                            Singleton<GameManager>::GetInst()->_guide_print_blocks.erase(Iter_Pos);
                            Iter_Pos = Singleton<GameManager>::GetInst()->_guide_print_blocks.begin();
                            ++Singleton<GameManager>::GetInst()->guideCount.at(0);
                            
                            this->nextGuide(target);
                        }
                    }
                }
                // ++Iter_Pos;
            }
            */
            
            
            
            if(Singleton<GameManager>::GetInst()->_erase_print_blocks.size() > 0)
            {
                Iter_Erase_Pos = Singleton<GameManager>::GetInst()->_erase_print_blocks.begin();
                Block *target = Iter_Erase_Pos->second;
                
               // CCLog("target->doremipasolasi : %d",target->doremipasolasi);
                
                if(target->body != NULL)
                {
                    float blockPosY = target->body->getPositionX() + Singleton<GameManager>::GetInst()->coverLayer->getPositionX(); // 실제 블럭 위치
                    
                    if(minX < blockPosY && !target->endPointCol)
                    {
                        
                    }
                    else
                    {
                        target->endPointCol = true;
                        
                        
                      //  CCLog("Singleton<GameManager>::GetInst()->_erase_print_blocks : %d",Singleton<GameManager>::GetInst()->_erase_print_blocks.size());
                        //if(!target->breaking)
                       // {
                            Iter_Erase_Pos = Singleton<GameManager>::GetInst()->_erase_print_blocks.begin();
                            Singleton<GameManager>::GetInst()->_erase_print_blocks.erase(Iter_Erase_Pos);
                            ++Singleton<GameManager>::GetInst()->eraseCount.at(0);
                            Iter_Erase_Pos = Singleton<GameManager>::GetInst()->_erase_print_blocks.begin();
                            
                            
                            Singleton<GameManager>::GetInst()->MoveFinished(target); //싱글노트 삭제
                       // }
                    }
                }
                else
                {
                    float blockPosY = target->tail->getPositionX() + Singleton<GameManager>::GetInst()->coverLayer->getPositionX(); // 실제 블럭 위치
                    
                    if(minX < blockPosY && !target->endPointCol)
                    {
                        
                        
                    }
                    else
                    {
                        target->endPointCol = true;
                      //  if(!target->breaking)
                      //  {
                            Iter_Erase_Pos = Singleton<GameManager>::GetInst()->_erase_print_blocks.begin();
                            Singleton<GameManager>::GetInst()->_erase_print_blocks.erase(Iter_Erase_Pos);
                            ++Singleton<GameManager>::GetInst()->eraseCount.at(0);
                            Iter_Erase_Pos = Singleton<GameManager>::GetInst()->_erase_print_blocks.begin();
                            
                            
                            Singleton<GameManager>::GetInst()->_9Sprite_MoveFinished(target); //롱노트 삭제
                       // }
                    }
                    
                }
                // ++Iter_Erase_Pos;
            }
            
        }
        
    
    
}




void PlayNormalBlockLayer::nextGuide(Block *destBlock)
{
    int channel = 0;
    CCArray *guide_Total_Array = Singleton<GameManager>::GetInst()->guide_Total_Array_channel.at(channel);
    // CCLOG("target->breakLine : %d   %d",target->breakLine,guide_Total_Array->count());
    CCArray *guide_Value_Array = dynamic_cast<CCArray*>( guide_Total_Array->objectAtIndex(destBlock->breakLine));
    
    for (int a=0; a<guide_Value_Array->count(); a++)
    {
        Block *target = (Block *)guide_Value_Array->objectAtIndex(a);
        
        //Singleton<GameManager>::GetInst()->piano_guid_sprite[target->lineNum]->setVisible(false);
        //Singleton<GameManager>::GetInst()->draw_line[target->lineNum]->setOpacity(LINE_OPACITY);
        ++Singleton<GameManager>::GetInst()->deleteGuideCount.at(channel);
        
        
        if(Singleton<GameManager>::GetInst()->musicPlayLine != destBlock->breakLine) //해당 라인에 있는거 전부 소리 나게..
        {


        }
        
        
        //  CCLOG("dele : %d   %d",target->lineNum,destBlock->breakLine);
    }
    
    Singleton<GameManager>::GetInst()->musicPlayLine = destBlock->breakLine; //이미 이 라인은 소리 출력했으니 같은 라인은.. 출력 안하게

    
    if(guide_Total_Array->count() > destBlock->breakLine+1)
    {
        guide_Value_Array = dynamic_cast<CCArray*>( guide_Total_Array->objectAtIndex(destBlock->breakLine+1));
        
        for (int a=0; a<guide_Value_Array->count(); a++)
        {
            //Block *target = (Block *)guide_Value_Array->objectAtIndex(a);
            //Singleton<GameManager>::GetInst()->pianoGuideVisible(target->lineNum);
        }
    }
}



