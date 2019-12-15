 
#include "PlayUIScore.h"



PlayUIScore::PlayUIScore()
{
    
}


PlayUIScore::~PlayUIScore()
{
}


bool PlayUIScore::init()
{
    /*
    comboImg = CCSprite::create("combo.png");
    comboImg->setPosition(ccp(0,0));
    this->addChild(comboImg,-3);
    */
    
    

    
    /*
    combo_number1 = CCSprite::create("combo_number/combo_number_0.png");
    combo_number1->setPosition(ccp(-combo_number1->getContentSize().width/2,-comboImg->getContentSize().height/2));
    
    this->addChild(combo_number1,-2);
    
    
    combo_number2 = CCSprite::create("combo_number/combo_number_2.png");
    combo_number2->setPosition(ccp(0,combo_number1->getPosition().y));
    
    this->addChild(combo_number2,-2);
    
    combo_number3 = CCSprite::create("combo_number/combo_number_9.png");
    combo_number3->setPosition(ccp(combo_number1->getContentSize().width/2,combo_number1->getPosition().y));
    
    this->addChild(combo_number3,-2);
    */
           
    
    return true;
}

void PlayUIScore::combo_value_input(int value)
{
    if(value < 10)
    {
       // combo_number3 = CCSprite::create("combo_number/combo_number_1.png");
       // CCLOG("value : %d",value);
    }
}


 

void PlayUIScore::update(float dt)
{
    
}

