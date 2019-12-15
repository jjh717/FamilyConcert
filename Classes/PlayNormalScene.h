#ifndef __PLAY_NORMAL_SCENE_H__
#define __PLAY_NORMAL_SCENE_H__
 
#include "cocos2d.h"
#include "GameManager.h"
#include "PlayNormalBgLayer.h"

#include "PlayNormalBlockLayer.h"

#include "PlayNormalUiLayer.h"

#include "PlayNormalControlLayer.h"
using namespace cocos2d;
class PlayNormalScene : public CCScene
{
    public:
        PlayNormalBgLayer*            _BgLayer;
        PlayNormalBlockLayer*         _block_layer;
        PlayNormalUiLayer*            _ui_layer;
        PlayNormalControlLayer*       _control_layer;
        PlayNormalScene();
        ~PlayNormalScene();
        bool init();
    
        float totalttt;
        void update(float dt);
        void endDelay();
    CREATE_FUNC(PlayNormalScene);
    

};

#endif