#ifndef __PLAY_EASY_SCENE_H__
#define __PLAY_EASY_SCENE_H__
 
#include "cocos2d.h"
#include "GameManager.h"
#include "PlayEasyBgLayer.h"
#include "PlayEasyControlLayer.h"
using namespace cocos2d;

 
class PlayEasyScene : public CCScene
{
    public:
        PlayEasyBgLayer*            _BgLayer;
        PlayEasyControlLayer*       _control_layer;
        PlayEasyScene();
        ~PlayEasyScene();
        bool init();
    
        
        void update(float dt);
        void endDelay();
    CREATE_FUNC(PlayEasyScene);
    

};

#endif