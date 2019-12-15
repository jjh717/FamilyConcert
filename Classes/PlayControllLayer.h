#ifndef __PLAYCONTROLL_LAYER_H__
#define __PLAYCONTROLL_LAYER_H__

#include "cocos2d.h"
#include "GameManager.h"
#include "CCShake.h"

#define TAG_PLAY_CONTROLL_LAYER 0
using namespace cocos2d;

class PlayControllLayer : public CCLayer
{
    protected:
        PlayControllLayer();
    private:
        ~PlayControllLayer();
    
    public:
        CCShake *p_shake[88];
        
    
        bool keyPressVale[88];
        int key_type;
        char str[100];
        bool init();
        void pianoSpriteInit();
//        void pianoSpritePositionSet();
        //void loadPercent(float dt);
        virtual void keypadDown(int keyCode, int deviceID);
        virtual void keypadUp(int keyCode, int deviceID);
    
      //  void keyBackClicked();
      //  void keyMenuClicked();

        virtual void iosKeypadDown(const char *keyCode);
        virtual void iosKeypadUp(const char *keyCode);
        void tutorial_display_end();
        //void start_display();
        
        void shakeUpdate(CCNode* sender, int keyCode);
       // void update(float dt);
    
       // void update(float dt);
    /*
        bool ccTouchBegan(CCTouch* touch, CCEvent* event);
        void ccTouchMoved(CCTouch* touch, CCEvent* event);
        void ccTouchEnded(CCTouch* touch, CCEvent* event);
    */

    
    CREATE_FUNC(PlayControllLayer);

};

#endif



 