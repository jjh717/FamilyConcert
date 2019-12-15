#ifndef __PLAY_BLOCK_LAYER_COPY_H__
#define __PLAY_BLOCK_LAYER_COPY_H__

#include "cocos2d.h"
#include "GameManager.h"

#include "PlayUIScore.h"
 
#include <math.h>

using namespace cocos2d;

class PlayBlockLayer_Copy : public CCLayer
{
    protected:
        PlayBlockLayer_Copy();
    private:
        ~PlayBlockLayer_Copy();
    public:
    
        
    
        bool init();
//        void makeCollisinoBoxes(float dt);

    
        void update(float dt);

        int blockcc;
     
        
        int blackInPos(int index);
        
        float halfLineXPostion(int index);
        
                
        
        cocos2d::CCSet *set;
    
        
        //void draw();
        CREATE_FUNC(PlayBlockLayer_Copy);
        
    
};

#endif