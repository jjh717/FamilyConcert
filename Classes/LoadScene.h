#ifndef __LOADSCENE_H__
#define __LOADSCENE_H__
 
#include "cocos2d.h"
#include "GameManager.h"
#include "LoadBgLayer.h"

using namespace cocos2d;
class LoadScene : public CCScene
{
    public:
        LoadBgLayer*            _load_bg_layer;
    
        LoadScene();
        ~LoadScene();
        bool init();
        
    
        void update(float dt);
    
    CREATE_FUNC(LoadScene);
    

};

#endif