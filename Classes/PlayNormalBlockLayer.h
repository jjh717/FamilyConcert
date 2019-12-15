#ifndef __PLAY_NORMAL_BLOCK_LAYER_COPY_H__
#define __PLAY_NORMAL_BLOCK_LAYER_COPY_H__

#include "cocos2d.h"
#include "GameManager.h"
using namespace cocos2d;

class PlayNormalBlockLayer : public CCLayer
{
    protected:
        PlayNormalBlockLayer();
    private:
        ~PlayNormalBlockLayer();
    public:
        bool init();
    
        float minX;
    
        std::map< double, Block * >::iterator Iter_Pos;
        std::map< double, Block * >::iterator Iter_Next_Pos;
        std::map< double, Block * >::iterator Iter_Erase_Pos;
    
        void nextGuide(Block *destBlock);
        void update(float dt);
         
    CREATE_FUNC(PlayNormalBlockLayer);
    

};

#endif