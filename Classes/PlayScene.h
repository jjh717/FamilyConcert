#ifndef __PLAYSCENE_H__
#define __PLAYSCENE_H__
 
#include "cocos2d.h"
#include "GameManager.h"

#include "PlayBgLayer.h"
#include "PlayBgLayer_Copy.h"
#include "PlayControllLayer.h"
#include "PlayControllLayer_Copy.h"

#include "PlayBlockLayer.h"
#include "PlayBlockLayer_Copy.h"


#include "PlayUILayer.h"
#include "PlayUILayer_Copy.h"

#include "PlayLineLayer.h"
#include "PlayLineLayer_Copy.h"

#include "PlayEffectLayer.h"
#include "PlayEffectLayer_Copy.h"
using namespace cocos2d;
class PlayScene : public CCScene
{
    public:
        
    
        PlayBgLayer*            _bg_layer;
        PlayBgLayer_Copy*           _bg_layer_copy;
    
        PlayControllLayer*      _controll_layer;
        PlayControllLayer_Copy*     _controll_layer_copy;
    
        PlayBlockLayer*         _block_layer;
        PlayBlockLayer_Copy*         _block_layer_copy;
    
        PlayUILayer*            _ui_layer;
        PlayUILayer_Copy*            _ui_layer_copy;
    
        PlayLineLayer*          _line_layer;
        PlayLineLayer_Copy*          _line_layer_copy;
    
        PlayEffectLayer*        _effect_layer;
        PlayEffectLayer_Copy*        _effect_layer_copy;

        std::map< double, Block * >::iterator Iter_Pos;
            
        //int nodePrintCount;         //�꾩옱 肉뚮젮吏�퀬 �덈뒗 �몃뱶 移댁슫��        //int nodePrintCount_copy;    //�꾩옱 肉뚮젮吏�퀬 �덈뒗 �몃뱶 移댁슫��        double total_timeMillis;
        double total_timeMillis_copy;
        PlayScene();
        ~PlayScene();
        bool init();
    
      //  virtual void keypadDown(int keyCode, int deviceID);
      //  virtual void keypadUp(int keyCode, int deviceID);
        
    //    virtual void keyBackClicked();
     //   virtual void keyMenuClicked();
        
        float      delay_Time;
        double    _distance;
        double    _interval;
        double    _interval_inverse;
        int start_count_num;
        int start_count_num_copy;
        char str[100];
    
        void update(float dt);
        void update_copy(float dt);
        void updatefree(float dt);

        void tutorial_display();
        void topLayer();
        //void makeCollisinoBoxes_update(CCNode* sender, void *data);
        
       // void makeCollisinoBoxes_update_copy(CCNode* sender, int channel);
    
       // void noPrintNode();
       // void noPrintNode_copy();
    
           
        void start_count_display_copy();
        void endDelay();
        //void printNode_copy(int nodeCount2, int channel);
        void feverReturn();
    CREATE_FUNC(PlayScene);
    

};

#endif
