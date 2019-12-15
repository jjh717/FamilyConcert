#ifndef __PLAY_BG_LAYER_COPY_H__
#define __PLAY_BG_LAYER_COPY_H__

#include "cocos2d.h"
#include "GameManager.h"
using namespace cocos2d;

class PlayBgLayer_Copy : public CCLayer
{
    protected:
        PlayBgLayer_Copy();
    private:
        ~PlayBgLayer_Copy();
    public:
        bool init();

        
       
        void update(float dt);
   
       
           
    
    CREATE_FUNC(PlayBgLayer_Copy);
    

};

#endif