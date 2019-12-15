#ifndef __PLAY_NORMAL_UI_LAYER_H__
#define __PLAY_NORMAL_UI_LAYER_H__

#include "cocos2d.h"
#include "GameManager.h"
using namespace cocos2d;

class PlayNormalUiLayer : public CCLayer
{
    protected:
        PlayNormalUiLayer();
    private:
        ~PlayNormalUiLayer();
    public:
        bool init();

    
        void update(float dt);
   
        char str[100];
        int start_count_num;
        void start_count_display();
    
        bool combo_printing;
        bool grade_printing;
    
        void combo_hidden();

        void grade_hidden();
    CREATE_FUNC(PlayNormalUiLayer);
    

};

#endif