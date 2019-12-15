#include "PlayNormalControlLayer.h"

 


PlayNormalControlLayer::PlayNormalControlLayer()
{
    
}

PlayNormalControlLayer::~PlayNormalControlLayer()
{
    
}


bool PlayNormalControlLayer::init()
{
    setIosKeyEnabled(true);
    
    
    return true;
}



void PlayNormalControlLayer::update(float dt)
{
}





void PlayNormalControlLayer::keypadDown(int keyCode, int deviceID)
{
    if(Singleton<GameManager>::GetInst()->doremipasolasi(keyCode) != -1)
    {
        Singleton<GameManager>::GetInst()->beginner_syllable_image->setVisible(true);
        
        int doremi = Singleton<GameManager>::GetInst()->doremipasolasi(keyCode);
        if(doremi == 0)
        {
            Singleton<GameManager>::GetInst()->beginner_syllable_image->setTexture(Singleton<GameManager>::GetInst()->beginner_image_do);
            sprintf(Singleton<GameManager>::GetInst()->pianoStr_do, "DO");
            //Singleton<GameManager>::GetInst()->pianoKeyCode_do->setString("DO");
        }
        else if(doremi == 1)
        {
            Singleton<GameManager>::GetInst()->beginner_syllable_image->setTexture(Singleton<GameManager>::GetInst()->beginner_image_re);
            sprintf(Singleton<GameManager>::GetInst()->pianoStr_do, "RE");
            //Singleton<GameManager>::GetInst()->pianoKeyCode_do->setString("RE");
        }
        else if(doremi == 2)
        {
            Singleton<GameManager>::GetInst()->beginner_syllable_image->setTexture(Singleton<GameManager>::GetInst()->beginner_image_mi);
            sprintf(Singleton<GameManager>::GetInst()->pianoStr_do, "MI");
            //Singleton<GameManager>::GetInst()->pianoKeyCode_do->setString("MI");
        }
        else if(doremi == 3)
        {
            Singleton<GameManager>::GetInst()->beginner_syllable_image->setTexture(Singleton<GameManager>::GetInst()->beginner_image_fa);
            sprintf(Singleton<GameManager>::GetInst()->pianoStr_do, "FA");
            //Singleton<GameManager>::GetInst()->pianoKeyCode_do->setString("FA");
        }
        else if(doremi == 4)
        {
            Singleton<GameManager>::GetInst()->beginner_syllable_image->setTexture(Singleton<GameManager>::GetInst()->beginner_image_sol);
            sprintf(Singleton<GameManager>::GetInst()->pianoStr_do, "SO");
            //Singleton<GameManager>::GetInst()->pianoKeyCode_do->setString("SO");
        }
        else if(doremi == 5)
        {
            Singleton<GameManager>::GetInst()->beginner_syllable_image->setTexture(Singleton<GameManager>::GetInst()->beginner_image_la);
            sprintf(Singleton<GameManager>::GetInst()->pianoStr_do, "LA");
            //Singleton<GameManager>::GetInst()->pianoKeyCode_do->setString("LA");
        }
        else if(doremi == 6)
        {
            Singleton<GameManager>::GetInst()->beginner_syllable_image->setTexture(Singleton<GameManager>::GetInst()->beginner_image_ti);
            sprintf(Singleton<GameManager>::GetInst()->pianoStr_do, "TI");
            //Singleton<GameManager>::GetInst()->pianoKeyCode_do->setString("TI");
        }
        else
        {
            Singleton<GameManager>::GetInst()->beginner_syllable_image->setVisible(false);
        }
        Singleton<GameManager>::GetInst()->pianoStr_a0 = Singleton<GameManager>::GetInst()->keyCheck(keyCode);
        
        //Singleton<GameManager>::GetInst()->pianoKeyCode_a0->setString(Singleton<GameManager>::GetInst()->keyCheck(keyCode).c_str());
        
        
        Singleton<GameManager>::GetInst()->checkNomalCollisionBox(doremi);
    }
}

void PlayNormalControlLayer::keypadUp(int keyCode, int deviceID)
{
   }

void PlayNormalControlLayer::iosKeypadDown(const char *keyCode)
{
    if(Singleton<GameManager>::GetInst()->doremipasolasi(43) != -1)
    {
        Singleton<GameManager>::GetInst()->beginner_syllable_image->setVisible(true);
        
        int doremi = Singleton<GameManager>::GetInst()->doremipasolasi(0);
        if(doremi == 0)
        {
            Singleton<GameManager>::GetInst()->beginner_syllable_image->setTexture(Singleton<GameManager>::GetInst()->beginner_image_do);
            Singleton<GameManager>::GetInst()->pianoKeyCode_do->setString("DO");
        }
        else if(doremi == 1)
        {
            Singleton<GameManager>::GetInst()->beginner_syllable_image->setTexture(Singleton<GameManager>::GetInst()->beginner_image_re);
            Singleton<GameManager>::GetInst()->pianoKeyCode_do->setString("RE");
        }
        else if(doremi == 2)
        {
            Singleton<GameManager>::GetInst()->beginner_syllable_image->setTexture(Singleton<GameManager>::GetInst()->beginner_image_mi);
            Singleton<GameManager>::GetInst()->pianoKeyCode_do->setString("MI");
        }
        else if(doremi == 3)
        {
            Singleton<GameManager>::GetInst()->beginner_syllable_image->setTexture(Singleton<GameManager>::GetInst()->beginner_image_fa);
            Singleton<GameManager>::GetInst()->pianoKeyCode_do->setString("FA");
        }
        else if(doremi == 4)
        {
            Singleton<GameManager>::GetInst()->beginner_syllable_image->setTexture(Singleton<GameManager>::GetInst()->beginner_image_sol);
            Singleton<GameManager>::GetInst()->pianoKeyCode_do->setString("SO");
        }
        else if(doremi == 5)
        {
            Singleton<GameManager>::GetInst()->beginner_syllable_image->setTexture(Singleton<GameManager>::GetInst()->beginner_image_la);
            Singleton<GameManager>::GetInst()->pianoKeyCode_do->setString("LA");
        }
        else if(doremi == 6)
        {
            Singleton<GameManager>::GetInst()->beginner_syllable_image->setTexture(Singleton<GameManager>::GetInst()->beginner_image_ti);
            Singleton<GameManager>::GetInst()->pianoKeyCode_do->setString("TI");
        }
        else
        {
            Singleton<GameManager>::GetInst()->beginner_syllable_image->setVisible(false);
        }
        
        Singleton<GameManager>::GetInst()->pianoKeyCode_a0->setString(Singleton<GameManager>::GetInst()->keyCheck(3).c_str());
        
        
        Singleton<GameManager>::GetInst()->checkNomalCollisionBox(doremi);
        
        
    
        
        
    }
    
   
}
