#ifndef __PLAY_UI_LAYER_COPY_H__
#define __PLAY_UI_LAYER_COPY_H__

#include "cocos2d.h"
#include "GameManager.h"
 
#define TAG_PLAY_CONTROLL_LAYER 0
using namespace cocos2d;

class PlayUILayer_Copy : public CCLayer
{
    protected:
        PlayUILayer_Copy();
    private:
        ~PlayUILayer_Copy();
    
    public:
            
        bool init();
        void update(float dt);
        void showCombo();
        char str_copy[100];

    CREATE_FUNC(PlayUILayer_Copy);

};

#endif



 