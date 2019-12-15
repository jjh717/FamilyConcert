#ifndef __PLAY_LINE_LAYER_COPY_H__
#define __PLAY_LINE_LAYER_COPY_H__

#include "cocos2d.h"
#include "GameManager.h"


#include <math.h>

using namespace cocos2d;

class PlayLineLayer_Copy : public CCLayer
{
    protected:
        PlayLineLayer_Copy();
    private:
        ~PlayLineLayer_Copy();
    public:
        bool init();
        void update(float dt);
        CREATE_FUNC(PlayLineLayer_Copy);
};

#endif