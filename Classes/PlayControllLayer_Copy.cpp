 
#include "PlayControllLayer_Copy.h"

/*
 #if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
 CCLOG("CC_PLATFORM_IOS");
 
 #endif
 #if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
 CCLOG("CC_PLATFORM_WIN32");
 
 #endif
 
 
 #if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
 CCLOG("CC_PLATFORM_ANDROID");
 #endif
 */


PlayControllLayer_Copy::PlayControllLayer_Copy()
{
    
}


PlayControllLayer_Copy::~PlayControllLayer_Copy()
{
 //   CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}


bool PlayControllLayer_Copy::init()
{
    setIosKeyEnabled(true);
    
    Singleton<GameManager>::GetInst()->SetControllLayer_copy(this);
    //this->schedule( schedule_selector(PlayControllLayer::loadPercent));
    return true;
}

void PlayControllLayer_Copy::keypadDown(int keyCode, int deviceID)
{
    
    
    
    
    if(Singleton<GameManager>::GetInst()->firstDeviceID < deviceID)
    {
        //나중에 들어온거
        CCLOG("plz/....");
        if(Singleton<GameManager>::GetInst()->pianoMode == RAINBOW_MODE)
        {
            Singleton<GameManager>::GetInst()->piano_rainbow_press_sprite_copy[keyCode]->setVisible(true);
        }
        else
        {
            Singleton<GameManager>::GetInst()->piano_press_sprite_copy[keyCode]->setVisible(true);
        }
        Singleton<GameManager>::GetInst()->checkCollisionBox_copy(keyCode);
        
    }
    else
    {
        if(Singleton<GameManager>::GetInst()->pianoMode == RAINBOW_MODE)
        {
            Singleton<GameManager>::GetInst()->piano_rainbow_press_sprite[keyCode]->setVisible(true);
        }
        else
        {
            Singleton<GameManager>::GetInst()->piano_press_sprite[keyCode]->setVisible(true);
        }
        Singleton<GameManager>::GetInst()->checkCollisionBox(keyCode);
    }

 
}

void PlayControllLayer_Copy::keypadUp(int keyCode, int deviceID)
{
    if(Singleton<GameManager>::GetInst()->firstDeviceID < deviceID)
    {
        //나중에 들어온거
        if(Singleton<GameManager>::GetInst()->pianoMode == RAINBOW_MODE)
        {
            Singleton<GameManager>::GetInst()->piano_rainbow_press_sprite_copy[keyCode]->setVisible(false);
        }
        else
        {
            Singleton<GameManager>::GetInst()->piano_press_sprite_copy[keyCode]->setVisible(false);
        }
        
    }
    else
    {
        if(Singleton<GameManager>::GetInst()->pianoMode == RAINBOW_MODE)
        {
            Singleton<GameManager>::GetInst()->piano_rainbow_press_sprite[keyCode]->setVisible(false);
        }
        else
        {
            Singleton<GameManager>::GetInst()->piano_press_sprite[keyCode]->setVisible(false);
        }
        
    }}

/*
void PlayControllLayer_Copy::keyBackClicked()
{
    CCLOG("keyBackClicked");
    //Singleton<GameManager>::GetInst()->piano_press_sprite[4]->setVisible(true);

    //CCDirector::sharedDirector()->end();
}
void PlayControllLayer_Copy::keyMenuClicked()
{
    CCLOG("keyMenuClicked");
   // Singleton<GameManager>::GetInst()->piano_press_sprite[83]->setVisible(true);
    
    
    //CCDirector::sharedDirector()->end();
}*/


void PlayControllLayer_Copy::iosKeypadUp(const char *keyCode)
{
//  //  CCLOG("iosKeypadUp %s", keyCode);
//	if((int)keyCode - 8 > 0 && (int)keyCode - 8 < 98){
//
//
//
    if(strcmp(keyCode,"q") == 0)
    {
        if(Singleton<GameManager>::GetInst()->pianoMode == RAINBOW_MODE)
        {
            Singleton<GameManager>::GetInst()->piano_rainbow_press_sprite[0]->setVisible(false);
        }
        else
        {
            Singleton<GameManager>::GetInst()->piano_press_sprite[0]->setVisible(false);
        }
    }
    else if(strcmp(keyCode,"w") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[1]->setVisible(false);
    }
    else if(strcmp(keyCode,"e") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[2]->setVisible(false);
    }
    else if(strcmp(keyCode,"r") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[3]->setVisible(false);
    }
    else if(strcmp(keyCode,"t") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[4]->setVisible(false);
    }
    else if(strcmp(keyCode,"y") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[5]->setVisible(false);
    }
    else if(strcmp(keyCode,"u") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[6]->setVisible(false);
    }
    else if(strcmp(keyCode,"i") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[7]->setVisible(false);
    }
    else if(strcmp(keyCode,"o") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[8]->setVisible(false);
    }
    else if(strcmp(keyCode,"p") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[9]->setVisible(false);
    }
    else if(strcmp(keyCode,"[") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[10]->setVisible(false);
    }
    else if(strcmp(keyCode,"]") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[11]->setVisible(false);
    }
    else if(strcmp(keyCode,"a") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[12]->setVisible(false);
    }
    else if(strcmp(keyCode,"s") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[13]->setVisible(false);
    }
    else if(strcmp(keyCode,"d") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[14]->setVisible(false);
    }
    else if(strcmp(keyCode,"f") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[15]->setVisible(false);
    }
    else if(strcmp(keyCode,"g") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[16]->setVisible(false);
    }
    else if(strcmp(keyCode,"h") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[17]->setVisible(false);
    }
    else if(strcmp(keyCode,"j") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[18]->setVisible(false);
    }
    else if(strcmp(keyCode,"k") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[19]->setVisible(false);
    }
    else if(strcmp(keyCode,"l") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[20]->setVisible(false);
    }
    else if(strcmp(keyCode,";") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[21]->setVisible(false);
    }
    else if(strcmp(keyCode,"'") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[22]->setVisible(false);
    }
    else if(strcmp(keyCode,"z") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[23]->setVisible(false);
    }
    else if(strcmp(keyCode,"x") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[24]->setVisible(false);
    }
    else if(strcmp(keyCode,"c") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[25]->setVisible(false);
    }
    else if(strcmp(keyCode,"v") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[26]->setVisible(false);
    }
    else if(strcmp(keyCode,"b") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[27]->setVisible(false);
    }
    else if(strcmp(keyCode,"n") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[28]->setVisible(false);
    }
    else if(strcmp(keyCode,"m") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[29]->setVisible(false);
    }
    else if(strcmp(keyCode,",") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[30]->setVisible(false);
    }
    else if(strcmp(keyCode,".") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[31]->setVisible(false);
    }
    else if(strcmp(keyCode,"/") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[32]->setVisible(false);
    }
    else if(strcmp(keyCode,"`") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[33]->setVisible(false);
    }
    else if(strcmp(keyCode,"1") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[34]->setVisible(false);
    }
    else if(strcmp(keyCode,"2") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[35]->setVisible(false);
    }
    else if(strcmp(keyCode,"3") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[36]->setVisible(false);
    }
    else if(strcmp(keyCode,"4") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[37]->setVisible(false);
    }
    else if(strcmp(keyCode,"5") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[38]->setVisible(false);
    }
    else if(strcmp(keyCode,"6") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[39]->setVisible(false);
    }
    else if(strcmp(keyCode,"7") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[40]->setVisible(false);
    }
    else if(strcmp(keyCode,"8") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[41]->setVisible(false);
    }
    else if(strcmp(keyCode,"9") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[42]->setVisible(false);
    }
    else if(strcmp(keyCode,"0") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[43]->setVisible(false);
    }
    else if(strcmp(keyCode,"-") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[44]->setVisible(false);
    }
    else if(strcmp(keyCode,"=") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[45]->setVisible(false);
    }
//
//
    
//	}
    /*
     switch (keyCode)
     {
     case "q":
     
     break;
     
     default:
     break;
     }
     */
    //strcmp(keyCode,"q");
}

void PlayControllLayer_Copy::iosKeypadDown(const char *keyCode)
{

    Singleton<GameManager>::GetInst()->checkCollisionBox(keyCode);
    
  //  sprintf(str, "piano/%d.wav", 1);
  //  CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(str);
    CCLOG("iosKeypadDown : %s",keyCode);
  //   CCLOG("aa %s", keyCode);
/*
    switch (keyCode)
    {
        case "q":
            
            break;
            
        default:
            break;
    }
*/
//
    if(strcmp(keyCode,"q") == 0) //switch 臾몄�濡�諛�씀��
    {
        if(Singleton<GameManager>::GetInst()->pianoMode == RAINBOW_MODE)
        {
            Singleton<GameManager>::GetInst()->piano_rainbow_press_sprite[0]->setVisible(true);
        }
        else
        {
            Singleton<GameManager>::GetInst()->piano_press_sprite[0]->setVisible(true);
        }
    }
    else if(strcmp(keyCode,"w") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[1]->setVisible(true);
    }
    else if(strcmp(keyCode,"e") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[2]->setVisible(true);
    }
    else if(strcmp(keyCode,"r") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[3]->setVisible(true);
    }
    else if(strcmp(keyCode,"t") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[4]->setVisible(true);
    }
    else if(strcmp(keyCode,"y") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[5]->setVisible(true);
    }
    else if(strcmp(keyCode,"u") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[6]->setVisible(true);
    }
    else if(strcmp(keyCode,"i") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[7]->setVisible(true);
    }
    else if(strcmp(keyCode,"o") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[8]->setVisible(true);
    }
    else if(strcmp(keyCode,"p") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[9]->setVisible(true);
    }
    else if(strcmp(keyCode,"[") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[10]->setVisible(true);
    }
    else if(strcmp(keyCode,"]") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[11]->setVisible(true);
    }
    else if(strcmp(keyCode,"a") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[12]->setVisible(true);
    }
    else if(strcmp(keyCode,"s") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[13]->setVisible(true);
    }
    else if(strcmp(keyCode,"d") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[14]->setVisible(true);
    }
    else if(strcmp(keyCode,"f") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[15]->setVisible(true);
    }
    else if(strcmp(keyCode,"g") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[16]->setVisible(true);
    }
    else if(strcmp(keyCode,"h") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[17]->setVisible(true);
    }
    else if(strcmp(keyCode,"j") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[18]->setVisible(true);
    }
    else if(strcmp(keyCode,"k") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[19]->setVisible(true);
    }
    else if(strcmp(keyCode,"l") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[20]->setVisible(true);
    }
    else if(strcmp(keyCode,";") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[21]->setVisible(true);
    }
    else if(strcmp(keyCode,"'") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[22]->setVisible(true);
    }
    else if(strcmp(keyCode,"z") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[23]->setVisible(true);
    }
    else if(strcmp(keyCode,"x") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[24]->setVisible(true);
    }
    else if(strcmp(keyCode,"c") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[25]->setVisible(true);
    }
    else if(strcmp(keyCode,"v") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[26]->setVisible(true);
    }
    else if(strcmp(keyCode,"b") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[27]->setVisible(true);
    }
    else if(strcmp(keyCode,"n") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[28]->setVisible(true);
    }
    else if(strcmp(keyCode,"m") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[29]->setVisible(true);
    }
    else if(strcmp(keyCode,",") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[30]->setVisible(true);
    }
    else if(strcmp(keyCode,".") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[31]->setVisible(true);
    }
    else if(strcmp(keyCode,"/") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[32]->setVisible(true);
    }
    else if(strcmp(keyCode,"`") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[33]->setVisible(true);
    }
    else if(strcmp(keyCode,"1") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[34]->setVisible(true);
    }
    else if(strcmp(keyCode,"2") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[35]->setVisible(true);
    }
    else if(strcmp(keyCode,"3") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[36]->setVisible(true);
    }
    else if(strcmp(keyCode,"4") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[37]->setVisible(true);
    }
    else if(strcmp(keyCode,"5") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[38]->setVisible(true);
    }
    else if(strcmp(keyCode,"6") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[39]->setVisible(true);
    }
    else if(strcmp(keyCode,"7") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[40]->setVisible(true);
    }
    else if(strcmp(keyCode,"8") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[41]->setVisible(true);
    }
    else if(strcmp(keyCode,"9") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[42]->setVisible(true);
    }
    else if(strcmp(keyCode,"0") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[43]->setVisible(true);
    }
    else if(strcmp(keyCode,"-") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[44]->setVisible(true);
    }
    else if(strcmp(keyCode,"=") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[45]->setVisible(true);
    }
//
//
//
    
    
    /*
    if(strcmp(keyCode,"q") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[46]->setVisible(true);
    }
    else if(strcmp(keyCode,"w") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[47]->setVisible(true);
    }
    else if(strcmp(keyCode,"e") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[48]->setVisible(true);
    }
    else if(strcmp(keyCode,"r") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[49]->setVisible(true);
    }
    else if(strcmp(keyCode,"t") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[50]->setVisible(true);
    }
    else if(strcmp(keyCode,"y") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[51]->setVisible(true);
    }
    else if(strcmp(keyCode,"u") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[52]->setVisible(true);
    }
    else if(strcmp(keyCode,"i") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[53]->setVisible(true);
    }
    else if(strcmp(keyCode,"o") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[54]->setVisible(true);
    }
    else if(strcmp(keyCode,"p") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[55]->setVisible(true);
    }
    else if(strcmp(keyCode,"[") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[56]->setVisible(true);
    }
    else if(strcmp(keyCode,"]") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[57]->setVisible(true);
    }
    else if(strcmp(keyCode,"a") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[58]->setVisible(true);
    }
    else if(strcmp(keyCode,"s") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[59]->setVisible(true);
    }
    else if(strcmp(keyCode,"d") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[60]->setVisible(true);
    }
    else if(strcmp(keyCode,"f") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[61]->setVisible(true);
    }
    else if(strcmp(keyCode,"g") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[62]->setVisible(true);
    }
    else if(strcmp(keyCode,"h") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[63]->setVisible(true);
    }
    else if(strcmp(keyCode,"j") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[64]->setVisible(true);
    }
    else if(strcmp(keyCode,"k") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[65]->setVisible(true);
    }
    else if(strcmp(keyCode,"l") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[66]->setVisible(true);
    }
    else if(strcmp(keyCode,";") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[67]->setVisible(true);
    }
    else if(strcmp(keyCode,"'") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[68]->setVisible(true);
    }
    else if(strcmp(keyCode,"z") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[69]->setVisible(true);
    }
    else if(strcmp(keyCode,"x") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[70]->setVisible(true);
    }
    else if(strcmp(keyCode,"c") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[71]->setVisible(true);
    }
    else if(strcmp(keyCode,"v") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[72]->setVisible(true);
    }
    else if(strcmp(keyCode,"b") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[73]->setVisible(true);
    }
    else if(strcmp(keyCode,"n") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[74]->setVisible(true);
    }
    else if(strcmp(keyCode,"m") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[75]->setVisible(true);
    }
    else if(strcmp(keyCode,",") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[76]->setVisible(true);
    }
    else if(strcmp(keyCode,".") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[77]->setVisible(true);
    }
    else if(strcmp(keyCode,"/") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[78]->setVisible(true);
    }
    else if(strcmp(keyCode,"`") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[79]->setVisible(true);
    }
    else if(strcmp(keyCode,"1") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[80]->setVisible(true);
    }
    else if(strcmp(keyCode,"2") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[81]->setVisible(true);
    }
    else if(strcmp(keyCode,"3") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[82]->setVisible(true);
    }
    else if(strcmp(keyCode,"4") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[83]->setVisible(true);
    }
    else if(strcmp(keyCode,"5") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[84]->setVisible(true);
    }
    else if(strcmp(keyCode,"6") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[85]->setVisible(true);
    }
    else if(strcmp(keyCode,"7") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[86]->setVisible(true);
    }
    else if(strcmp(keyCode,"8") == 0)
    {
        Singleton<GameManager>::GetInst()->piano_press_sprite[87]->setVisible(true);
    }
    */
 
}

 /*
void PlayControllLayer::processWin32KeyPress(UINT message, WPARAM wParam, LPARAM lParam)
{
	CCLog("%d",wParam);
   
	if( WM_KEYDOWN == message )
	{
		if(wParam == 77){//m
			PlayMusic::sharedMusic()->playmainlayer_music(40);
		}
		if(wParam == 81){//q
			PlayMusic::sharedMusic()->playmainlayer_music(42);
		}
		if(wParam == 87){//w
			PlayMusic::sharedMusic()->playmainlayer_music(44);
		}
		if(wParam == 69){//e
			PlayMusic::sharedMusic()->playmainlayer_music(45);
		}
		if(wParam == 82){//r
			PlayMusic::sharedMusic()->playmainlayer_music(47);
		}
		if(wParam == 84){//t
			PlayMusic::sharedMusic()->playmainlayer_music(49);
		}
		if(wParam == 89){//y
			PlayMusic::sharedMusic()->playmainlayer_music(51);
		}
		if(wParam == 85){//u
			PlayMusic::sharedMusic()->playmainlayer_music(52);
		}
		if(wParam == 73){//i
			PlayMusic::sharedMusic()->playmainlayer_music(54);
		}
		if(wParam == 79){//o
			PlayMusic::sharedMusic()->playmainlayer_music(56);
		}
		if(wParam == 80){//p
			PlayMusic::sharedMusic()->playmainlayer_music(57);
		}
		if(wParam == 65){//a
			PlayMusic::sharedMusic()->playmainlayer_music(59);
		}
		if(wParam == 83){//s
			PlayMusic::sharedMusic()->playmainlayer_music(61);
		}
		if(wParam == 68){//d
			PlayMusic::sharedMusic()->playmainlayer_music(63);
		}
		if(wParam == 70){//f
			PlayMusic::sharedMusic()->playmainlayer_music(64);
		}
		if(wParam == 71){//g
			PlayMusic::sharedMusic()->playmainlayer_music(66);
		}
		if(wParam == 72){//h
			PlayMusic::sharedMusic()->playmainlayer_music(68);
		}
		if(wParam == 74){//j
			PlayMusic::sharedMusic()->playmainlayer_music(69);
		}
		if(wParam == 75){//k
			PlayMusic::sharedMusic()->playmainlayer_music(71);
		}
		if(wParam == 76){//l
			PlayMusic::sharedMusic()->playmainlayer_music(73);
		}
		if(wParam == 90){//z
			PlayMusic::sharedMusic()->playmainlayer_music(76);
		}
		if(wParam == 88){//x
			PlayMusic::sharedMusic()->playmainlayer_music(78);
		}
		if(wParam == 67){//c
			PlayMusic::sharedMusic()->playmainlayer_music(37);
		}
		if(wParam == 86){//v
			PlayMusic::sharedMusic()->playmainlayer_music(38);
		}
		if(wParam == 66){//b
			PlayMusic::sharedMusic()->playmainlayer_music(81);
		}
		if(wParam == 78){//n
			PlayMusic::sharedMusic()->playmainlayer_music(83);
		}
		if(wParam == 49){//1
			PlayMusic::sharedMusic()->playmainlayer_music(201);
		}
		if(wParam == 50){//2
			PlayMusic::sharedMusic()->playmainlayer_music(202);
		}
		if(wParam == 51){//3
			PlayMusic::sharedMusic()->playmainlayer_music(203);
		}
		if(wParam == 52){//4
			PlayMusic::sharedMusic()->playmainlayer_music(204);
		}
		if(wParam == 53){//5
			PlayMusic::sharedMusic()->playmainlayer_music(205);
		}
		if(wParam == 54){//6
			PlayMusic::sharedMusic()->playmainlayer_music(206);
		}
		if(wParam == 55){//7
			PlayMusic::sharedMusic()->playmainlayer_music(207);
		}
	}
	if( WM_KEYUP == message )
	{
		if(wParam == VK_LEFT )
		{
			//PlayMusic::sharedMusic()->pausemainlayer_music();
		}
	}
    
}
 */


 /*

void PlayControllLayer::update(float dt)
{
    Singleton<PianoLayer>::getPointer()->update(dt);
    
    
}

  */
/*

bool PlayControllLayer::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
    start_point = touch->getLocation();
    return true;
}


void PlayControllLayer::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
   // CCLog("ccTouchMoved");
}

void PlayControllLayer::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
    float x_dir = start_point.x - touch->getLocation().x;
    float y_dir = start_point.y - touch->getLocation().y;
    float x_dist = abs(x_dir);
    float y_dist = abs(y_dir);
    
    if(x_dist > y_dist)
    {
        if(x_dir > 0)
        {
            CCLog("�쇱そ");
            if(Singleton<Piano>::getPointer()->state == PLAYER_STATE_IDLE)
            {
                Singleton<GameManager>::GetInst()->arrowMatching(TOUCH_LEFT);
            }
        }
        else
        {
            CCLog("�ㅻⅨ履�);
            if(Singleton<Piano>::getPointer()->state == PLAYER_STATE_IDLE)
            {
                Singleton<GameManager>::GetInst()->arrowMatching(TOUCH_RIGHT);
            }
        }
      //  CCLog("dist : %f   %f   %f",x_dist,y_dist,x_dir);
    }
    else
    {
        if(y_dir > 0)
        {
            CCLog("���");
            if(Singleton<Piano>::getPointer()->state == PLAYER_STATE_IDLE)
            {
                Singleton<GameManager>::GetInst()->arrowMatching(TOUCH_DOWN);
            }
        }
        else
        {
            CCLog("��);
            if(Singleton<Piano>::getPointer()->state == PLAYER_STATE_IDLE)
            {
                Singleton<GameManager>::GetInst()->arrowMatching(TOUCH_UP);
            }
        }
    }
 
}
*/
