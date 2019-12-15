#ifndef __PLAY_EASY_BG_LAYER_H__
#define __PLAY_EASY_BG_LAYER_H__

#include "cocos2d.h"
#include "GameManager.h"
using namespace cocos2d;

class PlayEasyBgLayer : public CCLayer
{
    protected:
        PlayEasyBgLayer();
    private:
        ~PlayEasyBgLayer();
    public:
        bool init();

        
       
        void update(float dt);
 
    
    CREATE_FUNC(PlayEasyBgLayer);
    

};

#endif