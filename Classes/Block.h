//
//  Block.h
//  HelloCpp
//
//  Created by iLab on 13. 2. 27..
//
//

#ifndef __HelloCpp__Block__
#define __HelloCpp__Block__

#include "cocos2d.h"
//#include "GUI/CCControlExtension/CCScale9Sprite.h"
#include "cocos-ext.h"
 
using namespace cocos2d;
using namespace extension;
enum block_arrow {
    BLOCK_NONE = 0,
    BLOCK_UP,
    BLOCK_RIGHT,
    BLOCK_DOWN,
    BLOCK_LEFT,
    BLOCK_R_UP,
    BLOCK_R_RIGHT,
    BLOCK_R_DOWN,
    BLOCK_R_LEFT

};




class Block : public CCObject
{
    public:
        Block(cocos2d::CCSize size,cocos2d::CCPoint pos,float scale,const char *_9spriteName,CCTexture2D *tex,double degree,int blockDivision,int midiDivision,int _velocity,float _elapsedMillis,double _timeMillis,float rotate);
        ~Block() {}
    
        void move(int y);
        CCSprite *body;
        CCScale9Sprite *tail;
        float elapsedMillis;
        int block_Division;
        double _NodeLong;
        double timeMillis; //순수 위치
        double durationMillis;  //눌려야 되는 시간
        double NowDurationMillis;  //눌린 시간
        int velocity;
        int arrow_state;
        float Ypos;
        bool nextGuide; //가이드 출력 여부
        CCLayer *print_layer;
        int tag;
        int lineNum;
        int doremipasolasi;
        bool guideVisible;         //媛���대�� 嫄대����� 蹂댁�ъ��怨� ������吏�
        int breakLine; 
        bool col_check;
        bool endPointCol;   //라인 끝까지 갔을때
        bool breaking; //뿌셔지는중
        CCPoint EndPoint;
        
        int channelNum;
    
        void resizeTo(CCSize theSize);
        void changeOpacity(int opa);
};

#endif /* defined(__HelloCpp__Block__) */
