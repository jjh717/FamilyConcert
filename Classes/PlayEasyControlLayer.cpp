#include "PlayEasyControlLayer.h"

 


PlayEasyControlLayer::PlayEasyControlLayer()
{
    
}

PlayEasyControlLayer::~PlayEasyControlLayer()
{
    
}


bool PlayEasyControlLayer::init()
{
    Singleton<GameManager>::GetInst()->tutorialMode = true;
    setIosKeyEnabled(true);
    return true;
}


void PlayEasyControlLayer::update(float dt)
{
    
    
}


void PlayEasyControlLayer::keypadDown(int keyCode, int deviceID)
{
    //Singleton<GameManager>::GetInst()->doremipasolasi(keyCode);
    
    Singleton<GameManager>::GetInst()->practice_logo->setVisible(false);
    
    this->doremipasolasi_print(Singleton<GameManager>::GetInst()->doremipasolasi(keyCode));
    
    
    
    if(Singleton<GameManager>::GetInst()->firstDeviceID < deviceID)
    {
        //나중에 들어온거
        CCLOG("plz/....");
        
    }
    else
    {
        
    }
}

void PlayEasyControlLayer::keypadUp(int keyCode, int deviceID)
{
    
    if(Singleton<GameManager>::GetInst()->firstDeviceID < deviceID)
    {
        //나중에 들어온거
        if(Singleton<GameManager>::GetInst()->gameMode == ANG_GAME || Singleton<GameManager>::GetInst()->gameMode == ANG_FREE)
        {
            //_ui_layer_copy->keypadDown(keyCode, deviceID);
        }
        
    }
    else
    {
        // _ui_layer->keypadDown(keyCode, deviceID);
        
    }
}
void PlayEasyControlLayer::doremipasolasi_print(int keyCode)
{
    if(keyCode == 0) //도
    {
        Singleton<GameManager>::GetInst()->image_do->setVisible(true);
        Singleton<GameManager>::GetInst()->image_re->setVisible(false);
        Singleton<GameManager>::GetInst()->image_mi->setVisible(false);
        Singleton<GameManager>::GetInst()->image_fa->setVisible(false);
        Singleton<GameManager>::GetInst()->image_so->setVisible(false);
        Singleton<GameManager>::GetInst()->image_ra->setVisible(false);
        Singleton<GameManager>::GetInst()->image_si->setVisible(false);
        Singleton<GameManager>::GetInst()->practice_btn_exit_press->setVisible(false);
        
        
        Singleton<GameManager>::GetInst()->text_do->setVisible(true);
        Singleton<GameManager>::GetInst()->text_re->setVisible(false);
        Singleton<GameManager>::GetInst()->text_mi->setVisible(false);
        Singleton<GameManager>::GetInst()->text_fa->setVisible(false);
        Singleton<GameManager>::GetInst()->text_so->setVisible(false);
        Singleton<GameManager>::GetInst()->text_la->setVisible(false);
        Singleton<GameManager>::GetInst()->text_ti->setVisible(false);
        
    }
    else if(keyCode == 1) //레
    {
        Singleton<GameManager>::GetInst()->image_do->setVisible(false);
        Singleton<GameManager>::GetInst()->image_re->setVisible(true);
        Singleton<GameManager>::GetInst()->image_mi->setVisible(false);
        Singleton<GameManager>::GetInst()->image_fa->setVisible(false);
        Singleton<GameManager>::GetInst()->image_so->setVisible(false);
        Singleton<GameManager>::GetInst()->image_ra->setVisible(false);
        Singleton<GameManager>::GetInst()->image_si->setVisible(false);
        Singleton<GameManager>::GetInst()->practice_btn_exit_press->setVisible(false);
        
        
        
        Singleton<GameManager>::GetInst()->text_do->setVisible(false);
        Singleton<GameManager>::GetInst()->text_re->setVisible(true);
        Singleton<GameManager>::GetInst()->text_mi->setVisible(false);
        Singleton<GameManager>::GetInst()->text_fa->setVisible(false);
        Singleton<GameManager>::GetInst()->text_so->setVisible(false);
        Singleton<GameManager>::GetInst()->text_la->setVisible(false);
        Singleton<GameManager>::GetInst()->text_ti->setVisible(false);
    }
    else if(keyCode == 2) //미
    {
        Singleton<GameManager>::GetInst()->image_do->setVisible(false);
        Singleton<GameManager>::GetInst()->image_re->setVisible(false);
        Singleton<GameManager>::GetInst()->image_mi->setVisible(true);
        Singleton<GameManager>::GetInst()->image_fa->setVisible(false);
        Singleton<GameManager>::GetInst()->image_so->setVisible(false);
        Singleton<GameManager>::GetInst()->image_ra->setVisible(false);
        Singleton<GameManager>::GetInst()->image_si->setVisible(false);
        Singleton<GameManager>::GetInst()->practice_btn_exit_press->setVisible(false);
        
        
        Singleton<GameManager>::GetInst()->text_do->setVisible(false);
        Singleton<GameManager>::GetInst()->text_re->setVisible(false);
        Singleton<GameManager>::GetInst()->text_mi->setVisible(true);
        Singleton<GameManager>::GetInst()->text_fa->setVisible(false);
        Singleton<GameManager>::GetInst()->text_so->setVisible(false);
        Singleton<GameManager>::GetInst()->text_la->setVisible(false);
        Singleton<GameManager>::GetInst()->text_ti->setVisible(false);
    }
    
    else if(keyCode == 3) //파
    {
        Singleton<GameManager>::GetInst()->image_do->setVisible(false);
        Singleton<GameManager>::GetInst()->image_re->setVisible(false);
        Singleton<GameManager>::GetInst()->image_mi->setVisible(false);
        Singleton<GameManager>::GetInst()->image_fa->setVisible(true);
        Singleton<GameManager>::GetInst()->image_so->setVisible(false);
        Singleton<GameManager>::GetInst()->image_ra->setVisible(false);
        Singleton<GameManager>::GetInst()->image_si->setVisible(false);
        Singleton<GameManager>::GetInst()->practice_btn_exit_press->setVisible(false);
        
        
        Singleton<GameManager>::GetInst()->text_do->setVisible(false);
        Singleton<GameManager>::GetInst()->text_re->setVisible(false);
        Singleton<GameManager>::GetInst()->text_mi->setVisible(false);
        Singleton<GameManager>::GetInst()->text_fa->setVisible(true);
        Singleton<GameManager>::GetInst()->text_so->setVisible(false);
        Singleton<GameManager>::GetInst()->text_la->setVisible(false);
        Singleton<GameManager>::GetInst()->text_ti->setVisible(false);
    }
    
    else if(keyCode == 4) //솔
    {
        Singleton<GameManager>::GetInst()->image_do->setVisible(false);
        Singleton<GameManager>::GetInst()->image_re->setVisible(false);
        Singleton<GameManager>::GetInst()->image_mi->setVisible(false);
        Singleton<GameManager>::GetInst()->image_fa->setVisible(false);
        Singleton<GameManager>::GetInst()->image_so->setVisible(true);
        Singleton<GameManager>::GetInst()->image_ra->setVisible(false);
        Singleton<GameManager>::GetInst()->image_si->setVisible(false);
        Singleton<GameManager>::GetInst()->practice_btn_exit_press->setVisible(false);
        
        
        Singleton<GameManager>::GetInst()->text_do->setVisible(false);
        Singleton<GameManager>::GetInst()->text_re->setVisible(false);
        Singleton<GameManager>::GetInst()->text_mi->setVisible(false);
        Singleton<GameManager>::GetInst()->text_fa->setVisible(false);
        Singleton<GameManager>::GetInst()->text_so->setVisible(true);
        Singleton<GameManager>::GetInst()->text_la->setVisible(false);
        Singleton<GameManager>::GetInst()->text_ti->setVisible(false);
    }
    
    else if(keyCode == 5) //라
    {
        Singleton<GameManager>::GetInst()->image_do->setVisible(false);
        Singleton<GameManager>::GetInst()->image_re->setVisible(false);
        Singleton<GameManager>::GetInst()->image_mi->setVisible(false);
        Singleton<GameManager>::GetInst()->image_fa->setVisible(false);
        Singleton<GameManager>::GetInst()->image_so->setVisible(false);
        Singleton<GameManager>::GetInst()->image_ra->setVisible(true);
        Singleton<GameManager>::GetInst()->image_si->setVisible(false);
        Singleton<GameManager>::GetInst()->practice_btn_exit_press->setVisible(false);
        
        
        Singleton<GameManager>::GetInst()->text_do->setVisible(false);
        Singleton<GameManager>::GetInst()->text_re->setVisible(false);
        Singleton<GameManager>::GetInst()->text_mi->setVisible(false);
        Singleton<GameManager>::GetInst()->text_fa->setVisible(false);
        Singleton<GameManager>::GetInst()->text_so->setVisible(false);
        Singleton<GameManager>::GetInst()->text_la->setVisible(true);
        Singleton<GameManager>::GetInst()->text_ti->setVisible(false);

    }
    else if(keyCode == 6) //시
    {
        Singleton<GameManager>::GetInst()->image_do->setVisible(false);
        Singleton<GameManager>::GetInst()->image_re->setVisible(false);
        Singleton<GameManager>::GetInst()->image_mi->setVisible(false);
        Singleton<GameManager>::GetInst()->image_fa->setVisible(false);
        Singleton<GameManager>::GetInst()->image_so->setVisible(false);
        Singleton<GameManager>::GetInst()->image_ra->setVisible(false);
        Singleton<GameManager>::GetInst()->image_si->setVisible(true);
        Singleton<GameManager>::GetInst()->practice_btn_exit_press->setVisible(false);
        
        Singleton<GameManager>::GetInst()->text_do->setVisible(false);
        Singleton<GameManager>::GetInst()->text_re->setVisible(false);
        Singleton<GameManager>::GetInst()->text_mi->setVisible(false);
        Singleton<GameManager>::GetInst()->text_fa->setVisible(false);
        Singleton<GameManager>::GetInst()->text_so->setVisible(false);
        Singleton<GameManager>::GetInst()->text_la->setVisible(false);
        Singleton<GameManager>::GetInst()->text_ti->setVisible(true);
    }
    
    
}
void PlayEasyControlLayer::iosKeypadDown(const char *keyCode)
{
    if(Singleton<GameManager>::GetInst()->tutorialMode)
    {
        Singleton<GameManager>::GetInst()->practice_logo->setVisible(false);
        
        int keyStringCode;
        if(strcmp(keyCode,"q") == 0)
        {
            keyStringCode = Singleton<GameManager>::GetInst()->doremipasolasi(39);
        }
        if(strcmp(keyCode,"w") == 0)
        {
            keyStringCode = Singleton<GameManager>::GetInst()->doremipasolasi(41);
        }
        if(strcmp(keyCode,"e") == 0)
        {
            keyStringCode = Singleton<GameManager>::GetInst()->doremipasolasi(43);
        }
        if(strcmp(keyCode,"r") == 0)
        {
            keyStringCode = Singleton<GameManager>::GetInst()->doremipasolasi(44);
        }
        if(strcmp(keyCode,"t") == 0)
        {
            keyStringCode = Singleton<GameManager>::GetInst()->doremipasolasi(46);
        }
        if(strcmp(keyCode,"y") == 0)
        {
            keyStringCode = Singleton<GameManager>::GetInst()->doremipasolasi(48);
        }
        if(strcmp(keyCode,"u") == 0)
        {
            keyStringCode = Singleton<GameManager>::GetInst()->doremipasolasi(50);
        }
        
        this->doremipasolasi_print(keyStringCode);
    }
    
    
}

