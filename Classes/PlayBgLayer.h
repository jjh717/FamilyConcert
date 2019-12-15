#ifndef __PLAY_BG_LAYER_H__
#define __PLAY_BG_LAYER_H__

#include "cocos2d.h"
#include "GameManager.h"
using namespace cocos2d;

class PlayBgLayer : public CCLayer
{
    protected:
        PlayBgLayer();
    private:
        ~PlayBgLayer();
    public:
        bool init();

        
       
        void update(float dt);
   
       
    
    CREATE_FUNC(PlayBgLayer);
    

};

#endif