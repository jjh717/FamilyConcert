#ifndef __PLAY_EFFECT_LAYER_H__
#define __PLAY_EFFECT_LAYER_H__

#include "cocos2d.h"
#include "GameManager.h"
using namespace cocos2d;

class PlayEffectLayer : public CCLayer
{
    protected:
        PlayEffectLayer();
    private:
        ~PlayEffectLayer();
    public:
        bool init();

        
       
        void update(float dt);
   
       
    
    CREATE_FUNC(PlayEffectLayer);
    

};

#endif