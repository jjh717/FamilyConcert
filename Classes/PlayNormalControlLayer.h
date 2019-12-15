#ifndef __PLAY_NORMAL_CONTROL_LAYER_H__
#define __PLAY_NORMAL_CONTROL_LAYER_H__

#include "cocos2d.h"
#include "GameManager.h"
using namespace cocos2d;

class PlayNormalControlLayer : public CCLayer
{
    protected:
        PlayNormalControlLayer();
    private:
        ~PlayNormalControlLayer();
    public:
        bool init();

    
        virtual void keypadDown(int keyCode, int deviceID);
        virtual void keypadUp(int keyCode, int deviceID);
        
        virtual void iosKeypadDown(const char *keyCode);

        
        void update(float dt);
   
        char str[100];
    CREATE_FUNC(PlayNormalControlLayer);
 
};

#endif