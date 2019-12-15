#ifndef __PLAY_EASY_CONTROL_LAYER_H__
#define __PLAY_EASY_CONTROL_LAYER_H__

#include "cocos2d.h"
#include "GameManager.h"
using namespace cocos2d;

class PlayEasyControlLayer : public CCLayer
{
    protected:
        PlayEasyControlLayer();
    private:
        ~PlayEasyControlLayer();
    public:
        bool init();

        
        virtual void keypadDown(int keyCode, int deviceID);
        virtual void keypadUp(int keyCode, int deviceID);
        
        virtual void iosKeypadDown(const char *keyCode);
        
        void doremipasolasi_print(int keyCode);
    
        void update(float dt);
 
    
    CREATE_FUNC(PlayEasyControlLayer);
    

};

#endif