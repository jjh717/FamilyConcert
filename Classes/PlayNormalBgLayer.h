#ifndef __PLAY_NORMAL_BG_LAYER_COPY_H__
#define __PLAY_NORMAL_BG_LAYER_COPY_H__

#include "cocos2d.h"
#include "GameManager.h"
using namespace cocos2d;

class PlayNormalBgLayer : public CCLayer
{
    protected:
        PlayNormalBgLayer();
    private:
        ~PlayNormalBgLayer();
    public:
        bool init();
        char str[100];
        CCLabelTTF *tutorialMent;
    
        void update(float dt);
   
    /*
        virtual void keypadDown(int keyCode, int deviceID);
        virtual void keypadUp(int keyCode, int deviceID);
        
        virtual void iosKeypadDown(const char *keyCode);
     */
        //virtual void iosKeypadUp(const char *keyCode);
        
        void tutorial_display_end();
        void tutorial_display();
    
        
    CREATE_FUNC(PlayNormalBgLayer);
    

};

#endif