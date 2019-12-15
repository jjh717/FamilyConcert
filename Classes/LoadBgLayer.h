#ifndef __LOAD_BG_LAYER_H__
#define __LOAD_BG_LAYER_H__

#include "cocos2d.h"

#include "GameManager.h"
using namespace cocos2d;

 

class LoadBgLayer : public CCLayer
{
    protected:
        LoadBgLayer();
    private:
        ~LoadBgLayer();
    public:
        bool loadPer[17];
        int aniCount;
        int pianoLoadCount;
        int pianoLoadCount_copy;
        bool init();

        void update(float dt);
        void loadingData();
       
        void loadPercent(float dt);
        void loadPercent_copy(float dt);
    
        void aniPrint(int index);
    CREATE_FUNC(LoadBgLayer);
    

};

#endif