#ifndef __PLAYCONTROLL_LAYER_COPY_H__
#define __PLAYCONTROLL_LAYER_COPY_H__

#include "cocos2d.h"
#include "GameManager.h"
#define TAG_PLAY_CONTROLL_LAYER 0
using namespace cocos2d;

class PlayControllLayer_Copy : public CCLayer
{
    protected:
        PlayControllLayer_Copy();
    private:
        ~PlayControllLayer_Copy();
    
    public:
        
        char str[100];
        bool init();
        void pianoSpriteInit();
//        void pianoSpritePositionSet();
        //void loadPercent(float dt);
        void keypadDown(int keyCode, int deviceID);
        void keypadUp(int keyCode, int deviceID);
        //void keyBackClicked();
       // void keyMenuClicked();

        virtual void iosKeypadDown(const char *keyCode);
        virtual void iosKeypadUp(const char *keyCode);
    
    
        
       // void update(float dt);
    /*
        bool ccTouchBegan(CCTouch* touch, CCEvent* event);
        void ccTouchMoved(CCTouch* touch, CCEvent* event);
        void ccTouchEnded(CCTouch* touch, CCEvent* event);
    */

    
    CREATE_FUNC(PlayControllLayer_Copy);

};

#endif



 