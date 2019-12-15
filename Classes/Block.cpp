//
//  Block.cpp
//  HelloCpp
//
//  Created by iLab on 13. 2. 27..
//
//

#include "Block.h"
 


Block::Block(cocos2d::CCSize size,cocos2d::CCPoint pos,float scale,const char *_9spriteName, CCTexture2D *tex,double nodeLong,int blockDivision,int midiDivision,int _velocity,float _elapsedMillis,double _timeMillis,float rotate)
{
    //CCLog("block pos : %f",pos.y/10);
    doremipasolasi = -1;
    timeMillis = _timeMillis;
    elapsedMillis = _elapsedMillis;
    block_Division = blockDivision;
    print_layer = NULL;
    body = NULL;
    tail = NULL;
    guideVisible = false;
    breakLine = -1;
    endPointCol = false; 
    EndPoint = CCPoint(0, 0);
    nextGuide = false;
    channelNum = -1;
    velocity = _velocity;
    breaking = false;
    _NodeLong = nodeLong;
    durationMillis = _NodeLong/1000;
    NowDurationMillis = 0;
   // CCLOG("_velocity : %d",_velocity);
    
    if(size.height != 0)
    {
        float height = _NodeLong/500;//(float)blockDivision/(float)midiDivision;
      //  CCLog("_NodeLong : %f",_NodeLong/500);
//        CCLog("height : %f",height);
//        CCLog("size.height : %f",size.height);
        tail = CCScale9Sprite::create(_9spriteName);
                                      //, CCRectMake(0, 15, 32, 35));
        tail->setPreferredSize(CCSizeMake(32, 20));
        tail->setContentSize(CCSizeMake(tail->getContentSize().width, size.height*height));
        tail->setPosition(pos);
        tail->setAnchorPoint(ccp(0.5f, 0.0f));
        tail->setScaleX(scale);
        tail->setScaleY(scale);
        
        
        
        tail->retain();
    }
    else
    {
        body = CCSprite::create(_9spriteName);
        body->setTexture(tex);
        body->setAnchorPoint(ccp(0.5f, 0.0f));
        body->setPosition(pos);
        body->setRotation(rotate);//0~360
        body->setScaleX(scale);
        body->setScaleY(scale);
        
       // CCLog("body->getContentSize().height : %f",body->getContentSize().height);
        
        body->retain();
        //CCLog("Block body : %f",body->getContentSize().width);
    }
    
    col_check = false;
}




void Block::resizeTo(CCSize theSize)
{
    float newWidth = theSize.width;
    float newHeight = theSize.height;
    
    
    float startWidth = body->getContentSize().width;
    float startHeight = body->getContentSize().height;
    
    float newScaleX = newWidth/startWidth;
    float newScaleY = newHeight/startHeight;
  
    body->setScaleX(newScaleX);
    body->setScaleY(newScaleY);
}



/*
Block::Block(cocos2d::CCSize size,cocos2d::CCPoint pos,float scale,const char *imgName,int degree)
{
    sprite = CCSprite::create(imgName,CCRectMake(0,0,size.width,size.height));
    sprite->setAnchorPoint(ccp(0.0f, 0.0f));
    sprite->setPosition(pos);
    sprite->setRotation(0);//0~360
    sprite->setScale(scale);
 
    col_check = false;
}
*/

void Block::changeOpacity(int opa)
{
    body->setOpacity(opa);
}


void Block::move(int y)
{
    body->setPosition(ccp(body->getPosition().x,body->getPosition().y + y));
}
 
