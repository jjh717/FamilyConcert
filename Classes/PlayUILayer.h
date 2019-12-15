#ifndef __PLAY_UI_LAYER_H__
#define __PLAY_UI_LAYER_H__

#include "cocos2d.h"
#include "GameManager.h"
 
#define TAG_PLAY_CONTROLL_LAYER 0
using namespace cocos2d;

class PlayUILayer : public CCLayer
{
    protected:
        PlayUILayer();
    private:
        ~PlayUILayer();
    
    public:
            
        bool init();
        void update(float dt);
        void showCombo();
        char str[100];

        bool combo_printing;
        bool grade_printing;
        
        void combo_hidden();
        
        void grade_hidden();
        
    CREATE_FUNC(PlayUILayer);

};

#endif



 