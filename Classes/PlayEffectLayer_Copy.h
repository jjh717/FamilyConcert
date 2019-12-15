#ifndef __PLAY_EFFECT_LAYER_COPY_H__
#define __PLAY_EFFECT_LAYER_COPY_H__

#include "cocos2d.h"
#include "GameManager.h"
using namespace cocos2d;

class PlayEffectLayer_Copy : public CCLayer
{
    protected:
        PlayEffectLayer_Copy();
    private:
        ~PlayEffectLayer_Copy();
    public:
        bool init();

        
       
        void update(float dt);
   
       
    
    CREATE_FUNC(PlayEffectLayer_Copy);
    

};

#endif