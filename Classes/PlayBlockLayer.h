#ifndef __PLAY_BLOCK_LAYER_H__
#define __PLAY_BLOCK_LAYER_H__

#include "cocos2d.h"
#include "GameManager.h"

#include "PlayUIScore.h"
 
#include <math.h>

using namespace cocos2d;

class PlayBlockLayer : public CCLayer
{
    protected:
        PlayBlockLayer();
    private:
        ~PlayBlockLayer();
    public:
        
    
        
        bool init();
//        void makeCollisinoBoxes(float dt);

        std::map< double, Block * >::iterator Iter_Pos;
        std::map< double, Block * >::iterator Iter_Next_Pos;
        std::map< double, Block * >::iterator Iter_Erase_Pos;
        
        void update(float dt);

        int blockcc;
     
        
        int blackInPos(int index);
        
        float halfLineXPostion(int index);
        
        
        cocos2d::CCSet *set;
    
        void nodeMidiOff(CCNode* sender, int channel);
        void nextGuide(Block *destBlock);
    
        //void draw();
        CREATE_FUNC(PlayBlockLayer);
        
    
};

#endif