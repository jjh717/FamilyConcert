#ifndef __PLAY_UI_SCORE_H__
#define __PLAY_UI_SCORE_H__

#include "cocos2d.h"
#include "GameManager.h"

using namespace cocos2d;

class PlayUIScore : public CCNode
{
    protected:
        PlayUIScore();
    private:
        ~PlayUIScore();
    
    public:
    
        
       // CCSprite *comboImg;
    
       
    
        bool init();
        void update(float dt);
        void combo_value_input(int value);
      
    CREATE_FUNC(PlayUIScore);

};

#endif



 