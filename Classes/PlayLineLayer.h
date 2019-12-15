#ifndef __PLAY_LINE_LAYER_H__
#define __PLAY_LINE_LAYER_H__

#include "cocos2d.h"
#include "GameManager.h"


#include <math.h>

using namespace cocos2d;

class PlayLineLayer : public CCLayer
{
    protected:
        PlayLineLayer();
    private:
        ~PlayLineLayer();
    public:
        bool init();
        void update(float dt);
        CREATE_FUNC(PlayLineLayer);
};

#endif