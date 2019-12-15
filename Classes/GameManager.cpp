#include "GameManager.h"
#include "PlayScene.h"
#include "PlayEasyScene.h"
#include "LoadScene.h"
#include "PlayNormalScene.h"

//getStaticMethodInfo

using namespace std;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)


#ifdef __cplusplus
extern "C" {
#endif

    JNIEXPORT void JNICALL Java_com_shfactory_musicblood_solo_SimpleGame_initBridge(JNIEnv *env, jobject jobj){
        Singleton<GameManager>::GetInst()->javaObj = env->NewGlobalRef(jobj);

        return;
    }

    void Java_com_shfactory_musicblood_solo_SimpleGame_buttonInit(JNIEnv* env, jobject thisObj, jstring pianoSelectValue, jstring pianoCoverValue, jstring gameSpeedValue)
    {
        /*
         //0. default  1. ang  2. free
         char psCha[256];
         const char *sz = env->GetStringUTFChars(pianoSelectValue, 0);
         strcpy(psCha, sz);
         env->ReleaseStringUTFChars(pianoSelectValue, sz);

         char pcCha[256];
         const char *sz = env->GetStringUTFChars(pianoCoverValue, 0);
         strcpy(pcCha, sz);
         env->ReleaseStringUTFChars(pianoCoverValue, sz);

         char gsCha[256];
         const char *sz = env->GetStringUTFChars(gameSpeedValue, 0);
         strcpy(gsCha, sz);
         env->ReleaseStringUTFChars(gameSpeedValue, sz);


         CCString *ps = CCString::create(psCha);
         CCString *pc = CCString::create(pcCha);
         CCString *gs = CCString::create(gsCha);

         CCLOG("pianoSelect : %s",psCha);
         CCLOG("in pianoSelect : %d",ps->intValue());

         CCLOG("pianoCover : %s",pcCha);
         CCLOG("in pianoCover : %d",pc->intValue());

         CCLOG("gameSpeedValue : %s",gsCha);
         CCLOG("in gameSpeedValue : %d",gs->intValue());
         Singleton<GameManager>::GetInst()->pianoSelectValue=ps->intValue();
         Singleton<GameManager>::GetInst()->pianoCoverValue=pc->intValue();
         Singleton<GameManager>::GetInst()->gameSpeedValue=gs->intValue();
         */
    }


    void Java_com_shfactory_musicblood_solo_SimpleGame_firstInputDeviceCocosfunc(JNIEnv* env, jobject thisObj, jstring deviceID)
    {
        //0. default  1. ang  2. free
    	char modeCha[256];
    	const char *sz = env->GetStringUTFChars(deviceID, 0);
    	strcpy(modeCha, sz);
    	env->ReleaseStringUTFChars(deviceID, sz);

        CCString *cst_mode = CCString::create(modeCha);

        CCLOG("deviceID : %s",modeCha);
        CCLOG("in deviceID : %d",cst_mode->intValue());
        Singleton<GameManager>::GetInst()->firstDeviceID=cst_mode->intValue();
    }

    void Java_com_shfactory_musicblood_solo_MultipleGame_firstInputDeviceCocosfunc(JNIEnv* env, jobject thisObj, jstring deviceID)
    {
        //0. default  1. ang  2. free
    	char modeCha[256];
    	const char *sz = env->GetStringUTFChars(deviceID, 0);
    	strcpy(modeCha, sz);
    	env->ReleaseStringUTFChars(deviceID, sz);

        CCString *cst_mode = CCString::create(modeCha);

        CCLOG("deviceID : %s",modeCha);
        CCLOG("in deviceID : %d",cst_mode->intValue());
        Singleton<GameManager>::GetInst()->firstDeviceID=cst_mode->intValue();
    }



    void Java_com_shfactory_musicblood_solo_SimpleGame_modeSettingCocosfunc(JNIEnv* env, jobject thisObj, jstring mode)
    {
        //0. default  1. ang  2. free
    	char modeCha[256];
    	const char *sz = env->GetStringUTFChars(mode, 0);
    	strcpy(modeCha, sz);
    	env->ReleaseStringUTFChars(mode, sz);

        CCString *cst_mode = CCString::create(modeCha);
        CCLOG("modeCha : %s",modeCha);
        if(!strcmp(modeCha,"free"))
        {
        	CCLOG("in modecha : %s",modeCha);
        	Singleton<GameManager>::GetInst()->gameMode=SINGE_FREE;
        }
        else if(!strcmp(modeCha,"game"))
        {
            CCLOG("in modecha : %s",modeCha);
            Singleton<GameManager>::GetInst()->gameMode=SINGE_GAME;
        }
        else if(!strcmp(modeCha,"ensenble"))
        {
            CCLOG("in modecha : %s",modeCha);
            Singleton<GameManager>::GetInst()->gameMode=ANG_GAME;
        }
        else if(!strcmp(modeCha,"practice"))
        {
            CCLOG("in modecha : %s",modeCha);
            Singleton<GameManager>::GetInst()->gameMode=EASY_GAME;
        }
        else if(!strcmp(modeCha,"beginner"))
        {
            CCLOG("in modecha : %s",modeCha);
            Singleton<GameManager>::GetInst()->gameMode=NORMAL_GAME;
        }
    }


    void Java_com_shfactory_musicblood_solo_SimpleGame_remoteCocosfunc(JNIEnv* env, jobject thisObj, jstring remote)
    {
        //0. default  1. ang  2. free
    	char remoteCha[256];
    	const char *sz = env->GetStringUTFChars(remote, 0);
    	strcpy(remoteCha, sz);
    	env->ReleaseStringUTFChars(remote, sz);

        CCLOG("remoteCha : %s",remoteCha);
        if(!strcmp(remoteCha,"left"))
        {
            if(Singleton<GameManager>::GetInst()->gameMode == EASY_GAME) //free
            {
                Singleton<GameManager>::GetInst()->practice_btn_exit_press->setVisible(true);
            }
            else if(Singleton<GameManager>::GetInst()->gameMode == SINGE_FREE || Singleton<GameManager>::GetInst()->gameMode == ANG_FREE) //free
            {
                if(Singleton<GameManager>::GetInst()->remotePosition > 0)
                {
                    --Singleton<GameManager>::GetInst()->remotePosition;
                    Singleton<GameManager>::GetInst()->FreeremoteController(Singleton<GameManager>::GetInst()->remotePosition);
                    Singleton<GameManager>::GetInst()->remoteOverImageFree(Singleton<GameManager>::GetInst()->remotePosition);

                }
            }
            else
            {
                if(Singleton<GameManager>::GetInst()->remotePosition > 0 && Singleton<GameManager>::GetInst()->gameMode != SINGE_FREE && Singleton<GameManager>::GetInst()->gameMode != ANG_FREE)
                {
                    Singleton<GameManager>::GetInst()->remoteUpDownOverImage(Singleton<GameManager>::GetInst()->remoteUpDownPosition);
                    Singleton<GameManager>::GetInst()->remoteUpDownPosition = 0;


                    --Singleton<GameManager>::GetInst()->remotePosition;
                    Singleton<GameManager>::GetInst()->remoteController(Singleton<GameManager>::GetInst()->remotePosition);
                    Singleton<GameManager>::GetInst()->remoteOverImage(Singleton<GameManager>::GetInst()->remotePosition);
                }
            }
        }
        else if(!strcmp(remoteCha,"right"))
        {
            if(Singleton<GameManager>::GetInst()->gameMode == EASY_GAME) //free
            {
                Singleton<GameManager>::GetInst()->practice_btn_exit_press->setVisible(true);
            }

            else if(Singleton<GameManager>::GetInst()->gameMode == SINGE_FREE || Singleton<GameManager>::GetInst()->gameMode == ANG_FREE) //free
            {
                if(Singleton<GameManager>::GetInst()->remotePosition < 8)
                {
                    ++Singleton<GameManager>::GetInst()->remotePosition;
                    Singleton<GameManager>::GetInst()->FreeremoteController(Singleton<GameManager>::GetInst()->remotePosition);
                    Singleton<GameManager>::GetInst()->remoteOverImageFree(Singleton<GameManager>::GetInst()->remotePosition);
                }
            }
            else
            {
                if(Singleton<GameManager>::GetInst()->remotePosition < 11 && Singleton<GameManager>::GetInst()->gameMode != SINGE_FREE && Singleton<GameManager>::GetInst()->gameMode != ANG_FREE)
                {
                    Singleton<GameManager>::GetInst()->remoteUpDownOverImage(Singleton<GameManager>::GetInst()->remoteUpDownPosition);
                    Singleton<GameManager>::GetInst()->remoteUpDownPosition = 0;

                    ++Singleton<GameManager>::GetInst()->remotePosition;

                    Singleton<GameManager>::GetInst()->remoteController(Singleton<GameManager>::GetInst()->remotePosition);
                    Singleton<GameManager>::GetInst()->remoteOverImage(Singleton<GameManager>::GetInst()->remotePosition);
                }
            }
        }
        else if(!strcmp(remoteCha,"up"))
        {
			CCLog("test : %d",Singleton<GameManager>::GetInst()->remoteUpDownPosition);
        	if(Singleton<GameManager>::GetInst()->gameMode == NORMAL_GAME)
        	{
        	}
        	else
        	{
				if(Singleton<GameManager>::GetInst()->gameMode == EASY_GAME) //free
				{
					Singleton<GameManager>::GetInst()->practice_btn_exit_press->setVisible(true);
				}
				else if(Singleton<GameManager>::GetInst()->remoteUpDownPosition < 3 && Singleton<GameManager>::GetInst()->gameMode != SINGE_FREE && Singleton<GameManager>::GetInst()->gameMode != ANG_FREE)
				{
					++Singleton<GameManager>::GetInst()->remoteUpDownPosition;

					Singleton<GameManager>::GetInst()->remoteUpDownController(Singleton<GameManager>::GetInst()->remoteUpDownPosition);
					Singleton<GameManager>::GetInst()->remoteUpDownOverImage(Singleton<GameManager>::GetInst()->remoteUpDownOverPosition);
					Singleton<GameManager>::GetInst()->remoteController(-1);
					Singleton<GameManager>::GetInst()->remoteOverImage(-1);
				}
				else if(Singleton<GameManager>::GetInst()->remoteUpDownPosition < 1 && Singleton<GameManager>::GetInst()->gameMode == SINGE_FREE)
				{
					++Singleton<GameManager>::GetInst()->remoteUpDownPosition;
					CCLog("remoteUpDownPosition : %d",Singleton<GameManager>::GetInst()->remoteUpDownPosition);
					Singleton<GameManager>::GetInst()->FreeremoteController(-1);
					Singleton<GameManager>::GetInst()->remoteOverImageFree(-1);
				}
        	}
        }
        else if(!strcmp(remoteCha,"down"))
        {
        	if(Singleton<GameManager>::GetInst()->gameMode == NORMAL_GAME)
        	{
        	}
        	else
        	{
				if(Singleton<GameManager>::GetInst()->gameMode == EASY_GAME) //free
				{
					Singleton<GameManager>::GetInst()->practice_btn_exit_press->setVisible(true);
				}
				else if(Singleton<GameManager>::GetInst()->remoteUpDownPosition > 0 && Singleton<GameManager>::GetInst()->gameMode != SINGE_FREE && Singleton<GameManager>::GetInst()->gameMode != ANG_FREE)
				{
					--Singleton<GameManager>::GetInst()->remoteUpDownPosition;
					Singleton<GameManager>::GetInst()->remoteUpDownController(Singleton<GameManager>::GetInst()->remoteUpDownPosition);
					Singleton<GameManager>::GetInst()->remoteUpDownOverImage(Singleton<GameManager>::GetInst()->remoteUpDownOverPosition);
					Singleton<GameManager>::GetInst()->remoteController(-1);
					Singleton<GameManager>::GetInst()->remoteOverImage(-1);

					/*
                     if(Singleton<GameManager>::GetInst()->remoteUpDownPosition == 0)
                     {
                     Singleton<GameManager>::GetInst()->remoteUpDownOverImage(Singleton<GameManager>::GetInst()->remoteUpDownPosition);
                     Singleton<GameManager>::GetInst()->remoteUpDownPosition = 0;

                     Singleton<GameManager>::GetInst()->remoteController(Singleton<GameManager>::GetInst()->remotePosition);
                     Singleton<GameManager>::GetInst()->remoteOverImage(Singleton<GameManager>::GetInst()->remotePosition);
                     }
					 */

				}

				else if(Singleton<GameManager>::GetInst()->remoteUpDownPosition == 0 && Singleton<GameManager>::GetInst()->gameMode != SINGE_FREE && Singleton<GameManager>::GetInst()->gameMode != ANG_FREE)
				{
					Singleton<GameManager>::GetInst()->remoteController(Singleton<GameManager>::GetInst()->remotePosition);
					Singleton<GameManager>::GetInst()->remoteOverImage(Singleton<GameManager>::GetInst()->remotePosition);
				}
				else if(Singleton<GameManager>::GetInst()->remoteUpDownPosition > 0 && Singleton<GameManager>::GetInst()->gameMode == SINGE_FREE)
				{
					--Singleton<GameManager>::GetInst()->remoteUpDownPosition;
					CCLog("remoteUpDownPosition : %d",Singleton<GameManager>::GetInst()->remoteUpDownPosition);
					Singleton<GameManager>::GetInst()->FreeremoteController(Singleton<GameManager>::GetInst()->remotePosition);
					Singleton<GameManager>::GetInst()->remoteOverImageFree(Singleton<GameManager>::GetInst()->remotePosition);
				}
        	}
        }

        else if(!strcmp(remoteCha,"ok"))
        {
            CCLog("remoteUpDownPosition : %d",Singleton<GameManager>::GetInst()->remoteUpDownPosition);
            if(Singleton<GameManager>::GetInst()->gameMode == EASY_GAME) //free
            {



                if(Singleton<GameManager>::GetInst()->practice_btn_exit_press->isVisible())
                {
                	Singleton<GameManager>::GetInst()->game_end();
                }

            }
            else
            {
				if(Singleton<GameManager>::GetInst()->remoteUpDownPosition == 0)
				{
					int position = Singleton<GameManager>::GetInst()->remotePosition;
					CCLog("position : %d",position);
					if(Singleton<GameManager>::GetInst()->gameMode == SINGE_FREE || Singleton<GameManager>::GetInst()->gameMode == ANG_FREE) //free
					{
						if(position == 0)
						{
							Singleton<GameManager>::GetInst()->remoteOverPosition[0] = Singleton<GameManager>::GetInst()->remotePosition;
							Singleton<GameManager>::GetInst()->acousticButtonPress();
						}
						if(position == 1)
						{
							Singleton<GameManager>::GetInst()->remoteOverPosition[0] = Singleton<GameManager>::GetInst()->remotePosition;
							Singleton<GameManager>::GetInst()->brightButtonPress();
						}
						if(position == 2)
						{
							Singleton<GameManager>::GetInst()->remoteOverPosition[0] = Singleton<GameManager>::GetInst()->remotePosition;
							Singleton<GameManager>::GetInst()->chorusButtonPress();
						}
						if(position == 3)
						{
							Singleton<GameManager>::GetInst()->remoteOverPosition[0] = Singleton<GameManager>::GetInst()->remotePosition;
							Singleton<GameManager>::GetInst()->electricButtonPress();
						}
						if(position == 4)
						{
							Singleton<GameManager>::GetInst()->remoteOverPosition[0] = Singleton<GameManager>::GetInst()->remotePosition;
							Singleton<GameManager>::GetInst()->hongkyButtonPress();
						}
						if(position == 5)
						{
							Singleton<GameManager>::GetInst()->remoteOverPosition[0] = Singleton<GameManager>::GetInst()->remotePosition;
							Singleton<GameManager>::GetInst()->rhodesButtonPress();
						}


						if(position == 6)
						{
							Singleton<GameManager>::GetInst()->remoteOverPosition[1] = Singleton<GameManager>::GetInst()->remotePosition;
							Singleton<GameManager>::GetInst()->pianoRainbowButtonPress();
						}
						if(position == 7)
						{
							Singleton<GameManager>::GetInst()->remoteOverPosition[1] = Singleton<GameManager>::GetInst()->remotePosition;
							Singleton<GameManager>::GetInst()->pianoMarkButtonPress();
						}
						if(position == 8)
						{
							Singleton<GameManager>::GetInst()->remoteOverPosition[1] = Singleton<GameManager>::GetInst()->remotePosition;
							Singleton<GameManager>::GetInst()->pianoNormalButtonPress();
						}

					}
					else
					{
						if(Singleton<GameManager>::GetInst()->remotePosition == 0)
						{
							Singleton<GameManager>::GetInst()->escButtonPress();
						}
						if(position == 1)
						{
							Singleton<GameManager>::GetInst()->pauseButtonPress();
						}
						if(position == 2)
						{
							Singleton<GameManager>::GetInst()->remoteOverPosition[0] = position;
							Singleton<GameManager>::GetInst()->x14SpeedButtonPress();
						}
						if(position == 3)
						{
                            Singleton<GameManager>::GetInst()->remoteOverPosition[0] = position;
							Singleton<GameManager>::GetInst()->x12SpeedButtonPress();
						}
						if(position == 4)
						{
                            Singleton<GameManager>::GetInst()->remoteOverPosition[0] = position;
							Singleton<GameManager>::GetInst()->x1SpeedButtonPress();
						}
						if(position == 5)
						{
                            Singleton<GameManager>::GetInst()->remoteOverPosition[0] = position;
							Singleton<GameManager>::GetInst()->x2SpeedButtonPress();
						}




						if(position == 6)
						{
							Singleton<GameManager>::GetInst()->remoteOverPosition[1] = Singleton<GameManager>::GetInst()->remotePosition;
							Singleton<GameManager>::GetInst()->acousticButtonPress();
						}
						if(position == 7)
						{
							Singleton<GameManager>::GetInst()->remoteOverPosition[1] = Singleton<GameManager>::GetInst()->remotePosition;
							Singleton<GameManager>::GetInst()->brightButtonPress();
						}
						if(position == 8)
						{
							Singleton<GameManager>::GetInst()->remoteOverPosition[1] = Singleton<GameManager>::GetInst()->remotePosition;
							Singleton<GameManager>::GetInst()->chorusButtonPress();
						}
						if(position == 9)
						{
							Singleton<GameManager>::GetInst()->remoteOverPosition[1] = Singleton<GameManager>::GetInst()->remotePosition;
							Singleton<GameManager>::GetInst()->electricButtonPress();
						}
						if(position == 10)
						{
							Singleton<GameManager>::GetInst()->remoteOverPosition[1] = Singleton<GameManager>::GetInst()->remotePosition;
							Singleton<GameManager>::GetInst()->hongkyButtonPress();
						}
						if(position == 11)
						{
							Singleton<GameManager>::GetInst()->remoteOverPosition[1] = Singleton<GameManager>::GetInst()->remotePosition;
							Singleton<GameManager>::GetInst()->rhodesButtonPress();
						}
					}
				}
				else
				{
					if(Singleton<GameManager>::GetInst()->gameMode == SINGE_FREE)
					{
						Singleton<GameManager>::GetInst()->escButtonPress();
					}
					else
					{
						if(Singleton<GameManager>::GetInst()->remoteUpDownPosition == 1)
						{
							Singleton<GameManager>::GetInst()->remoteUpDownOverPosition = Singleton<GameManager>::GetInst()->remoteUpDownPosition;
							Singleton<GameManager>::GetInst()->pianoNormalButtonPress();
						}
						else if(Singleton<GameManager>::GetInst()->remoteUpDownPosition == 2)
						{
							Singleton<GameManager>::GetInst()->remoteUpDownOverPosition = Singleton<GameManager>::GetInst()->remoteUpDownPosition;
							Singleton<GameManager>::GetInst()->pianoMarkButtonPress();
						}
						else if(Singleton<GameManager>::GetInst()->remoteUpDownPosition == 3)
						{
							Singleton<GameManager>::GetInst()->remoteUpDownOverPosition = Singleton<GameManager>::GetInst()->remoteUpDownPosition;
							Singleton<GameManager>::GetInst()->pianoRainbowButtonPress();
						}
					}

				}
            }
        }
    }


    void Java_com_shfactory_musicblood_solo_SimpleGame_nativeCppFunc(JNIEnv* env, jobject thisObj, jstring path)
    {
    	//char midiPath[256];
    	const char *sz = env->GetStringUTFChars(path, 0);
    	strcpy(Singleton<GameManager>::GetInst()->midiPath, sz);
    	env->ReleaseStringUTFChars(path, sz);

        CCLOG("midiPath : %s",Singleton<GameManager>::GetInst()->midiPath);

        //CCMessageBox( "Call me From Java", "JNI Test" );
    }









    void Java_com_shfactory_musicblood_solo_MultipleGame_MultipleModeSettingCocosfunc(JNIEnv* env, jobject thisObj, jstring mode)
    {
        //0. default  1. ang  2. free
    	char modeCha[256];
    	const char *sz = env->GetStringUTFChars(mode, 0);
    	strcpy(modeCha, sz);
    	env->ReleaseStringUTFChars(mode, sz);

        CCString *cst_mode = CCString::create(modeCha);
        CCLOG("modeCha : %s",modeCha);
        if(!strcmp(modeCha,"free"))
        {
        	CCLOG("in modecha : %s",modeCha);
        	Singleton<GameManager>::GetInst()->gameMode=SINGE_FREE;
        }
        else if(!strcmp(modeCha,"game"))
        {
            CCLOG("in modecha : %s",modeCha);
            Singleton<GameManager>::GetInst()->gameMode=SINGE_GAME;
        }
        else if(!strcmp(modeCha,"ensenble"))
        {
            CCLOG("in modecha : %s",modeCha);
            Singleton<GameManager>::GetInst()->gameMode=ANG_GAME;
        }
        else if(!strcmp(modeCha,"ensenbleFree"))
        {
            CCLOG("in modecha : %s",modeCha);
            Singleton<GameManager>::GetInst()->gameMode=ANG_FREE;
        }

    }


    void Java_com_shfactory_musicblood_solo_MultipleGame_MultipleRemoteCocosfunc(JNIEnv* env, jobject thisObj, jstring remote)
    {
        //0. default  1. ang  2. free
    	char remoteCha[256];
    	const char *sz = env->GetStringUTFChars(remote, 0);
    	strcpy(remoteCha, sz);
    	env->ReleaseStringUTFChars(remote, sz);

        CCLOG("remoteCha : %s",remoteCha);
        if(!strcmp(remoteCha,"left"))
        {
            CCLOG("in remoteCha : %s",remoteCha);
            if(Singleton<GameManager>::GetInst()->gameMode == SINGE_FREE || Singleton<GameManager>::GetInst()->gameMode == ANG_FREE) //free
            {
                if(Singleton<GameManager>::GetInst()->remotePosition > 0)
                {
                    --Singleton<GameManager>::GetInst()->remotePosition;
                    Singleton<GameManager>::GetInst()->FreeremoteController(Singleton<GameManager>::GetInst()->remotePosition);
                    Singleton<GameManager>::GetInst()->remoteOverImage(Singleton<GameManager>::GetInst()->remotePosition);
                }

            }
            else
            {
                if(Singleton<GameManager>::GetInst()->remotePosition > 0 && Singleton<GameManager>::GetInst()->gameMode != SINGE_FREE && Singleton<GameManager>::GetInst()->gameMode != ANG_FREE)
                {
                    --Singleton<GameManager>::GetInst()->remotePosition;
                    Singleton<GameManager>::GetInst()->remoteController(Singleton<GameManager>::GetInst()->remotePosition);
                    Singleton<GameManager>::GetInst()->remoteOverImage(Singleton<GameManager>::GetInst()->remotePosition);
                }
            }
        }
        else if(!strcmp(remoteCha,"right"))
        {
            CCLOG("in remoteCha : %s",remoteCha);
            if(Singleton<GameManager>::GetInst()->gameMode == SINGE_FREE || Singleton<GameManager>::GetInst()->gameMode == ANG_FREE) //free
            {
                if(Singleton<GameManager>::GetInst()->remotePosition < 8)
                {
                    ++Singleton<GameManager>::GetInst()->remotePosition;
                    Singleton<GameManager>::GetInst()->FreeremoteController(Singleton<GameManager>::GetInst()->remotePosition);
                    Singleton<GameManager>::GetInst()->remoteOverImage(Singleton<GameManager>::GetInst()->remotePosition);

                }
            }
            else
            {
                if(Singleton<GameManager>::GetInst()->remotePosition < 11 && Singleton<GameManager>::GetInst()->gameMode != SINGE_FREE && Singleton<GameManager>::GetInst()->gameMode != ANG_FREE)
                {
                    ++Singleton<GameManager>::GetInst()->remotePosition;
                    Singleton<GameManager>::GetInst()->remoteController(Singleton<GameManager>::GetInst()->remotePosition);
                    Singleton<GameManager>::GetInst()->remoteOverImage(Singleton<GameManager>::GetInst()->remotePosition);
                }
            }
        }
        else if(!strcmp(remoteCha,"ok"))
        {
            CCLOG("in remoteCha : %s    %d",remoteCha, Singleton<GameManager>::GetInst()->remotePosition);

            if(Singleton<GameManager>::GetInst()->remotePosition == 0)
            {
                Singleton<GameManager>::GetInst()->escButtonPress();
            }
            if(Singleton<GameManager>::GetInst()->remotePosition == 1)
            {
                CCLOG("ok remoteCha : %s",remoteCha);
                Singleton<GameManager>::GetInst()->pauseButtonPress();
            }
            if(Singleton<GameManager>::GetInst()->remotePosition == 2)
            {
                Singleton<GameManager>::GetInst()->remoteOverPosition[0] = Singleton<GameManager>::GetInst()->remotePosition;
                Singleton<GameManager>::GetInst()->x14SpeedButtonPress();
            }
            if(Singleton<GameManager>::GetInst()->remotePosition == 3)
            {
                Singleton<GameManager>::GetInst()->remoteOverPosition[0] = Singleton<GameManager>::GetInst()->remotePosition;
                Singleton<GameManager>::GetInst()->x12SpeedButtonPress();
            }
            if(Singleton<GameManager>::GetInst()->remotePosition == 4)
            {
                Singleton<GameManager>::GetInst()->remoteOverPosition[0] = Singleton<GameManager>::GetInst()->remotePosition;
                Singleton<GameManager>::GetInst()->x1SpeedButtonPress();
            }
            if(Singleton<GameManager>::GetInst()->remotePosition == 5)
            {
                Singleton<GameManager>::GetInst()->remoteOverPosition[0] = Singleton<GameManager>::GetInst()->remotePosition;
                Singleton<GameManager>::GetInst()->x2SpeedButtonPress();
            }




            if(Singleton<GameManager>::GetInst()->remotePosition == 6)
            {
                Singleton<GameManager>::GetInst()->remoteOverPosition[1] = Singleton<GameManager>::GetInst()->remotePosition;
                Singleton<GameManager>::GetInst()->acousticButtonPress();
            }
            if(Singleton<GameManager>::GetInst()->remotePosition == 7)
            {
                Singleton<GameManager>::GetInst()->remoteOverPosition[1] = Singleton<GameManager>::GetInst()->remotePosition;
                Singleton<GameManager>::GetInst()->brightButtonPress();
            }
            if(Singleton<GameManager>::GetInst()->remotePosition == 8)
            {
                Singleton<GameManager>::GetInst()->remoteOverPosition[1] = Singleton<GameManager>::GetInst()->remotePosition;
                Singleton<GameManager>::GetInst()->chorusButtonPress();
            }
            if(Singleton<GameManager>::GetInst()->remotePosition == 9)
            {
                Singleton<GameManager>::GetInst()->remoteOverPosition[1] = Singleton<GameManager>::GetInst()->remotePosition;
                Singleton<GameManager>::GetInst()->electricButtonPress();
            }
            if(Singleton<GameManager>::GetInst()->remotePosition == 10)
            {
                Singleton<GameManager>::GetInst()->remoteOverPosition[1] = Singleton<GameManager>::GetInst()->remotePosition;
                Singleton<GameManager>::GetInst()->hongkyButtonPress();
            }
            if(Singleton<GameManager>::GetInst()->remotePosition == 11)
            {
                Singleton<GameManager>::GetInst()->remoteOverPosition[1] = Singleton<GameManager>::GetInst()->remotePosition;
                Singleton<GameManager>::GetInst()->rhodesButtonPress();
            }


        }

    }


    void Java_com_shfactory_musicblood_solo_MultipleGame_MultipleNativeCppFunc(JNIEnv* env, jobject thisObj, jstring path)
    {
    	//char midiPath[256];
    	const char *sz = env->GetStringUTFChars(path, 0);
    	strcpy(Singleton<GameManager>::GetInst()->midiPath, sz);
    	env->ReleaseStringUTFChars(path, sz);

        CCLOG("midiPath : %s",Singleton<GameManager>::GetInst()->midiPath);

        //CCMessageBox( "Call me From Java", "JNI Test" );
    }





#ifdef __cplusplus
}
#endif



#endif
void GameManager::remoteOverImageFree(int value)
{
    CCLog("remoteOverPosition[0] : %d",remoteOverPosition[0]);
    CCLog("remoteOverPosition[0] : %d",remoteOverPosition[1]);
    if(remoteOverPosition[0] == 0)
    {
        Singleton<GameManager>::GetInst()->acousticButton->setNormalImage(CCSprite::create("hd/btn_acoustic_grand_piano_press.png"));
    }
    if(remoteOverPosition[0] == 1)
    {
        Singleton<GameManager>::GetInst()->brightButton->setNormalImage(CCSprite::create("hd/btn_bright_acoustic_piano_press.png"));
    }
    if(remoteOverPosition[0] == 2)
    {
        Singleton<GameManager>::GetInst()->chorusButton->setNormalImage(CCSprite::create("hd/btn_chorus_piano_press.png"));
    }
    if(remoteOverPosition[0] == 3)
    {
        Singleton<GameManager>::GetInst()->electricButton->setNormalImage(CCSprite::create("hd/btn_electric_piano_press.png"));
    }
    if(remoteOverPosition[0] == 4)
    {
        Singleton<GameManager>::GetInst()->hongkyButton->setNormalImage(CCSprite::create("hd/btn_hongky_tonky_piano_press.png"));
    }
    if(remoteOverPosition[0] == 5)
    {
        Singleton<GameManager>::GetInst()->rhodesButton->setNormalImage(CCSprite::create("hd/btn_Rhodes_piano_press.png"));
    }




    if(remoteOverPosition[1] == 6)
    {
        Singleton<GameManager>::GetInst()->pianoRainbowButton->setNormalImage(CCSprite::create("hd/btn_color_press.png"));
    }
    if(remoteOverPosition[1] == 7)
    {
        Singleton<GameManager>::GetInst()->pianoMarkButton->setNormalImage(CCSprite::create("hd/btn_mark_press.png"));
    }
    if(remoteOverPosition[1] == 8)
    {
        Singleton<GameManager>::GetInst()->pianoNormalButton->setNormalImage(CCSprite::create("hd/btn_nomal_press.png"));
    }

}
void GameManager::remoteOverImage(int value)
{
    if(remoteOverPosition[0] == 2)
    {
        Singleton<GameManager>::GetInst()->x14SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x14_press.png"));
    }
    if(remoteOverPosition[0] == 3)
    {
        Singleton<GameManager>::GetInst()->x12SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x12_press.png"));
    }

    if(remoteOverPosition[0] == 4)
    {
        Singleton<GameManager>::GetInst()->x1SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x1_press.png"));
    }
    if(remoteOverPosition[0] == 5)
    {
        Singleton<GameManager>::GetInst()->x2SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x2_press.png"));
    }



    if(remoteOverPosition[1] == 6)
    {
        Singleton<GameManager>::GetInst()->acousticButton->setNormalImage(CCSprite::create("hd/btn_acoustic_grand_piano_press.png"));
    }
    if(remoteOverPosition[1] == 7)
    {
        Singleton<GameManager>::GetInst()->brightButton->setNormalImage(CCSprite::create("hd/btn_bright_acoustic_piano_press.png"));
    }
    if(remoteOverPosition[1] == 8)
    {
        Singleton<GameManager>::GetInst()->chorusButton->setNormalImage(CCSprite::create("hd/btn_chorus_piano_press.png"));
    }
    if(remoteOverPosition[1] == 9)
    {
        Singleton<GameManager>::GetInst()->electricButton->setNormalImage(CCSprite::create("hd/btn_electric_piano_press.png"));
    }
    if(remoteOverPosition[1] == 10)
    {
        Singleton<GameManager>::GetInst()->hongkyButton->setNormalImage(CCSprite::create("hd/btn_hongky_tonky_piano_press.png"));
    }
    if(remoteOverPosition[1] == 11)
    {
        Singleton<GameManager>::GetInst()->rhodesButton->setNormalImage(CCSprite::create("hd/btn_Rhodes_piano_press.png"));
    }


}
void GameManager::remoteUpDownOverImage(int value)
{
    if(remoteUpDownOverPosition == 1)
    {
        Singleton<GameManager>::GetInst()->pianoNormalButton->setNormalImage(CCSprite::create("hd/btn_nomal_press.png"));
    }
    else if(remoteUpDownOverPosition == 2)
    {
        Singleton<GameManager>::GetInst()->pianoMarkButton->setNormalImage(CCSprite::create("hd/btn_mark_press.png"));
    }
    else if(remoteUpDownOverPosition == 3)
    {
        Singleton<GameManager>::GetInst()->pianoRainbowButton->setNormalImage(CCSprite::create("hd/btn_color_press.png"));
    }

    /*
     if(Singleton<GameManager>::GetInst()->gameMode == SINGE_FREE)
     {
     if(remoteUpDownOverPosition == 3 && remoteUpDownOverPosition != value)
     {
     Singleton<GameManager>::GetInst()->pianoNormalButton->setNormalImage(CCSprite::create("hd/btn_nomal_press.png"));
     }
     else if(remoteUpDownOverPosition == 2 && remoteUpDownOverPosition != value)
     {
     Singleton<GameManager>::GetInst()->pianoMarkButton->setNormalImage(CCSprite::create("hd/btn_mark_press.png"));
     }
     else if(remoteUpDownOverPosition == 1 && remoteUpDownOverPosition != value)
     {
     Singleton<GameManager>::GetInst()->pianoRainbowButton->setNormalImage(CCSprite::create("hd/btn_color_press.png"));
     }
     }
     else
     {
     }
     */
}
void GameManager::remoteUpDownController(int value)
{
    if(value == 0)
    {
        Singleton<GameManager>::GetInst()->pianoRainbowButton->setNormalImage(CCSprite::create("hd/btn_color.png"));
        Singleton<GameManager>::GetInst()->pianoMarkButton->setNormalImage(CCSprite::create("hd/btn_mark.png"));
        Singleton<GameManager>::GetInst()->pianoNormalButton->setNormalImage(CCSprite::create("hd/btn_nomal.png"));
    }
    else if(value == 1)
    {
        Singleton<GameManager>::GetInst()->pianoRainbowButton->setNormalImage(CCSprite::create("hd/btn_color.png"));
        Singleton<GameManager>::GetInst()->pianoMarkButton->setNormalImage(CCSprite::create("hd/btn_mark.png"));
        Singleton<GameManager>::GetInst()->pianoNormalButton->setNormalImage(CCSprite::create("hd/btn_nomal_focus.png"));
    }
    else if(value == 2)
    {
        Singleton<GameManager>::GetInst()->pianoRainbowButton->setNormalImage(CCSprite::create("hd/btn_color.png"));
        Singleton<GameManager>::GetInst()->pianoMarkButton->setNormalImage(CCSprite::create("hd/btn_mark_focus.png"));
        Singleton<GameManager>::GetInst()->pianoNormalButton->setNormalImage(CCSprite::create("hd/btn_nomal.png"));
    }

    else if(value == 3)
    {
        Singleton<GameManager>::GetInst()->pianoRainbowButton->setNormalImage(CCSprite::create("hd/btn_color_focus.png"));
        Singleton<GameManager>::GetInst()->pianoMarkButton->setNormalImage(CCSprite::create("hd/btn_mark.png"));
        Singleton<GameManager>::GetInst()->pianoNormalButton->setNormalImage(CCSprite::create("hd/btn_nomal.png"));
    }


    /*
     if(Singleton<GameManager>::GetInst()->gameMode == SINGE_FREE)
     {
     if(value == 3)
     {
     Singleton<GameManager>::GetInst()->pianoRainbowButton->setNormalImage(CCSprite::create("hd/btn_color.png"));
     Singleton<GameManager>::GetInst()->pianoMarkButton->setNormalImage(CCSprite::create("hd/btn_mark.png"));
     Singleton<GameManager>::GetInst()->pianoNormalButton->setNormalImage(CCSprite::create("hd/btn_nomal.png"));
     }
     else if(value == 2)
     {
     Singleton<GameManager>::GetInst()->pianoRainbowButton->setNormalImage(CCSprite::create("hd/btn_color.png"));
     Singleton<GameManager>::GetInst()->pianoMarkButton->setNormalImage(CCSprite::create("hd/btn_mark.png"));
     Singleton<GameManager>::GetInst()->pianoNormalButton->setNormalImage(CCSprite::create("hd/btn_nomal_focus.png"));
     }
     else if(value == 1)
     {
     Singleton<GameManager>::GetInst()->pianoRainbowButton->setNormalImage(CCSprite::create("hd/btn_color.png"));
     Singleton<GameManager>::GetInst()->pianoMarkButton->setNormalImage(CCSprite::create("hd/btn_mark_focus.png"));
     Singleton<GameManager>::GetInst()->pianoNormalButton->setNormalImage(CCSprite::create("hd/btn_nomal.png"));
     }

     else if(value == 0)
     {
     Singleton<GameManager>::GetInst()->pianoRainbowButton->setNormalImage(CCSprite::create("hd/btn_color_focus.png"));
     Singleton<GameManager>::GetInst()->pianoMarkButton->setNormalImage(CCSprite::create("hd/btn_mark.png"));
     Singleton<GameManager>::GetInst()->pianoNormalButton->setNormalImage(CCSprite::create("hd/btn_nomal.png"));
     }

     }
     else
     {
     }
     */
}
void GameManager::remoteController(int value)
{
    if(value == -1)
    {
        Singleton<GameManager>::GetInst()->escButton->setNormalImage(CCSprite::create("hd/btn_esc_non.png"));
        Singleton<GameManager>::GetInst()->pauseButton->setNormalImage(CCSprite::create("hd/btn_pause_non.png"));

        Singleton<GameManager>::GetInst()->x1SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x1_non.png"));
        Singleton<GameManager>::GetInst()->x2SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x2_non.png"));
        Singleton<GameManager>::GetInst()->x12SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x12_non.png"));
        Singleton<GameManager>::GetInst()->x14SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x14_non.png"));

        Singleton<GameManager>::GetInst()->acousticButton->setNormalImage(CCSprite::create("hd/btn_acoustic_grand_piano.png"));
        Singleton<GameManager>::GetInst()->brightButton->setNormalImage(CCSprite::create("hd/btn_bright_acoustic_piano.png"));
        Singleton<GameManager>::GetInst()->chorusButton->setNormalImage(CCSprite::create("hd/btn_chorus_piano.png"));
        Singleton<GameManager>::GetInst()->electricButton->setNormalImage(CCSprite::create("hd/btn_electric_piano.png"));
        Singleton<GameManager>::GetInst()->hongkyButton->setNormalImage(CCSprite::create("hd/btn_hongky_tonky_piano.png"));
        Singleton<GameManager>::GetInst()->rhodesButton->setNormalImage(CCSprite::create("hd/btn_Rhodes_piano.png"));
    }


    if(value == 0)
    {
        Singleton<GameManager>::GetInst()->escButton->setNormalImage(CCSprite::create("hd/btn_esc_over.png"));
        Singleton<GameManager>::GetInst()->pauseButton->setNormalImage(CCSprite::create("hd/btn_pause_non.png"));

        Singleton<GameManager>::GetInst()->x1SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x1_non.png"));
        Singleton<GameManager>::GetInst()->x2SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x2_non.png"));
        Singleton<GameManager>::GetInst()->x12SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x12_non.png"));
        Singleton<GameManager>::GetInst()->x14SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x14_non.png"));

        Singleton<GameManager>::GetInst()->acousticButton->setNormalImage(CCSprite::create("hd/btn_acoustic_grand_piano.png"));
        Singleton<GameManager>::GetInst()->brightButton->setNormalImage(CCSprite::create("hd/btn_bright_acoustic_piano.png"));
        Singleton<GameManager>::GetInst()->chorusButton->setNormalImage(CCSprite::create("hd/btn_chorus_piano.png"));
        Singleton<GameManager>::GetInst()->electricButton->setNormalImage(CCSprite::create("hd/btn_electric_piano.png"));
        Singleton<GameManager>::GetInst()->hongkyButton->setNormalImage(CCSprite::create("hd/btn_hongky_tonky_piano.png"));
        Singleton<GameManager>::GetInst()->rhodesButton->setNormalImage(CCSprite::create("hd/btn_Rhodes_piano.png"));
    }
    if(value == 1)
    {
        Singleton<GameManager>::GetInst()->escButton->setNormalImage(CCSprite::create("hd/btn_esc_non.png"));
        Singleton<GameManager>::GetInst()->pauseButton->setNormalImage(CCSprite::create("hd/btn_pause_over.png"));

        Singleton<GameManager>::GetInst()->x1SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x1_non.png"));
        Singleton<GameManager>::GetInst()->x2SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x2_non.png"));
        Singleton<GameManager>::GetInst()->x12SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x12_non.png"));
        Singleton<GameManager>::GetInst()->x14SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x14_non.png"));

        Singleton<GameManager>::GetInst()->acousticButton->setNormalImage(CCSprite::create("hd/btn_acoustic_grand_piano.png"));
        Singleton<GameManager>::GetInst()->brightButton->setNormalImage(CCSprite::create("hd/btn_bright_acoustic_piano.png"));
        Singleton<GameManager>::GetInst()->chorusButton->setNormalImage(CCSprite::create("hd/btn_chorus_piano.png"));
        Singleton<GameManager>::GetInst()->electricButton->setNormalImage(CCSprite::create("hd/btn_electric_piano.png"));
        Singleton<GameManager>::GetInst()->hongkyButton->setNormalImage(CCSprite::create("hd/btn_hongky_tonky_piano.png"));
        Singleton<GameManager>::GetInst()->rhodesButton->setNormalImage(CCSprite::create("hd/btn_Rhodes_piano.png"));

    }
    if(value == 2)
    {
        Singleton<GameManager>::GetInst()->escButton->setNormalImage(CCSprite::create("hd/btn_esc_non.png"));
        Singleton<GameManager>::GetInst()->pauseButton->setNormalImage(CCSprite::create("hd/btn_pause_non.png"));

        Singleton<GameManager>::GetInst()->x14SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x14_over.png"));
        Singleton<GameManager>::GetInst()->x12SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x12_non.png"));
        Singleton<GameManager>::GetInst()->x1SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x1_non.png"));
        Singleton<GameManager>::GetInst()->x2SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x2_non.png"));



        Singleton<GameManager>::GetInst()->acousticButton->setNormalImage(CCSprite::create("hd/btn_acoustic_grand_piano.png"));
        Singleton<GameManager>::GetInst()->brightButton->setNormalImage(CCSprite::create("hd/btn_bright_acoustic_piano.png"));
        Singleton<GameManager>::GetInst()->chorusButton->setNormalImage(CCSprite::create("hd/btn_chorus_piano.png"));
        Singleton<GameManager>::GetInst()->electricButton->setNormalImage(CCSprite::create("hd/btn_electric_piano.png"));
        Singleton<GameManager>::GetInst()->hongkyButton->setNormalImage(CCSprite::create("hd/btn_hongky_tonky_piano.png"));
        Singleton<GameManager>::GetInst()->rhodesButton->setNormalImage(CCSprite::create("hd/btn_Rhodes_piano.png"));
    }
    if(value == 3)
    {
        Singleton<GameManager>::GetInst()->escButton->setNormalImage(CCSprite::create("hd/btn_esc_non.png"));
        Singleton<GameManager>::GetInst()->pauseButton->setNormalImage(CCSprite::create("hd/btn_pause_non.png"));

        Singleton<GameManager>::GetInst()->x14SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x14_non.png"));
        Singleton<GameManager>::GetInst()->x12SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x12_over.png"));
        Singleton<GameManager>::GetInst()->x1SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x1_non.png"));
        Singleton<GameManager>::GetInst()->x2SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x2_non.png"));

        Singleton<GameManager>::GetInst()->acousticButton->setNormalImage(CCSprite::create("hd/btn_acoustic_grand_piano.png"));
        Singleton<GameManager>::GetInst()->brightButton->setNormalImage(CCSprite::create("hd/btn_bright_acoustic_piano.png"));
        Singleton<GameManager>::GetInst()->chorusButton->setNormalImage(CCSprite::create("hd/btn_chorus_piano.png"));
        Singleton<GameManager>::GetInst()->electricButton->setNormalImage(CCSprite::create("hd/btn_electric_piano.png"));
        Singleton<GameManager>::GetInst()->hongkyButton->setNormalImage(CCSprite::create("hd/btn_hongky_tonky_piano.png"));
        Singleton<GameManager>::GetInst()->rhodesButton->setNormalImage(CCSprite::create("hd/btn_Rhodes_piano.png"));
    }
    if(value == 4)
    {
        Singleton<GameManager>::GetInst()->escButton->setNormalImage(CCSprite::create("hd/btn_esc_non.png"));
        Singleton<GameManager>::GetInst()->pauseButton->setNormalImage(CCSprite::create("hd/btn_pause_non.png"));

        Singleton<GameManager>::GetInst()->x14SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x14_non.png"));
        Singleton<GameManager>::GetInst()->x12SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x12_non.png"));
        Singleton<GameManager>::GetInst()->x1SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x1_over.png"));
        Singleton<GameManager>::GetInst()->x2SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x2_non.png"));



        Singleton<GameManager>::GetInst()->acousticButton->setNormalImage(CCSprite::create("hd/btn_acoustic_grand_piano.png"));
        Singleton<GameManager>::GetInst()->brightButton->setNormalImage(CCSprite::create("hd/btn_bright_acoustic_piano.png"));
        Singleton<GameManager>::GetInst()->chorusButton->setNormalImage(CCSprite::create("hd/btn_chorus_piano.png"));
        Singleton<GameManager>::GetInst()->electricButton->setNormalImage(CCSprite::create("hd/btn_electric_piano.png"));
        Singleton<GameManager>::GetInst()->hongkyButton->setNormalImage(CCSprite::create("hd/btn_hongky_tonky_piano.png"));
        Singleton<GameManager>::GetInst()->rhodesButton->setNormalImage(CCSprite::create("hd/btn_Rhodes_piano.png"));
    }
    if(value == 5)
    {
        Singleton<GameManager>::GetInst()->escButton->setNormalImage(CCSprite::create("hd/btn_esc_non.png"));
        Singleton<GameManager>::GetInst()->pauseButton->setNormalImage(CCSprite::create("hd/btn_pause_non.png"));

        Singleton<GameManager>::GetInst()->x14SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x14_non.png"));
        Singleton<GameManager>::GetInst()->x12SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x12_non.png"));
        Singleton<GameManager>::GetInst()->x1SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x1_non.png"));
        Singleton<GameManager>::GetInst()->x2SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x2_over.png"));



        Singleton<GameManager>::GetInst()->acousticButton->setNormalImage(CCSprite::create("hd/btn_acoustic_grand_piano.png"));
        Singleton<GameManager>::GetInst()->brightButton->setNormalImage(CCSprite::create("hd/btn_bright_acoustic_piano.png"));
        Singleton<GameManager>::GetInst()->chorusButton->setNormalImage(CCSprite::create("hd/btn_chorus_piano.png"));
        Singleton<GameManager>::GetInst()->electricButton->setNormalImage(CCSprite::create("hd/btn_electric_piano.png"));
        Singleton<GameManager>::GetInst()->hongkyButton->setNormalImage(CCSprite::create("hd/btn_hongky_tonky_piano.png"));
        Singleton<GameManager>::GetInst()->rhodesButton->setNormalImage(CCSprite::create("hd/btn_Rhodes_piano.png"));

    }
    if(value == 6)
    {
        Singleton<GameManager>::GetInst()->escButton->setNormalImage(CCSprite::create("hd/btn_esc_non.png"));
        Singleton<GameManager>::GetInst()->pauseButton->setNormalImage(CCSprite::create("hd/btn_pause_non.png"));

        Singleton<GameManager>::GetInst()->x1SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x1_non.png"));
        Singleton<GameManager>::GetInst()->x2SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x2_non.png"));
        Singleton<GameManager>::GetInst()->x12SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x12_non.png"));
        Singleton<GameManager>::GetInst()->x14SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x14_non.png"));

        Singleton<GameManager>::GetInst()->acousticButton->setNormalImage(CCSprite::create("hd/btn_acoustic_grand_piano_over.png"));
        Singleton<GameManager>::GetInst()->brightButton->setNormalImage(CCSprite::create("hd/btn_bright_acoustic_piano.png"));
        Singleton<GameManager>::GetInst()->chorusButton->setNormalImage(CCSprite::create("hd/btn_chorus_piano.png"));
        Singleton<GameManager>::GetInst()->electricButton->setNormalImage(CCSprite::create("hd/btn_electric_piano.png"));
        Singleton<GameManager>::GetInst()->hongkyButton->setNormalImage(CCSprite::create("hd/btn_hongky_tonky_piano.png"));
        Singleton<GameManager>::GetInst()->rhodesButton->setNormalImage(CCSprite::create("hd/btn_Rhodes_piano.png"));
    }
    if(value == 7)
    {
        Singleton<GameManager>::GetInst()->escButton->setNormalImage(CCSprite::create("hd/btn_esc_non.png"));
        Singleton<GameManager>::GetInst()->pauseButton->setNormalImage(CCSprite::create("hd/btn_pause_non.png"));

        Singleton<GameManager>::GetInst()->x1SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x1_non.png"));
        Singleton<GameManager>::GetInst()->x2SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x2_non.png"));
        Singleton<GameManager>::GetInst()->x12SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x12_non.png"));
        Singleton<GameManager>::GetInst()->x14SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x14_non.png"));

        Singleton<GameManager>::GetInst()->acousticButton->setNormalImage(CCSprite::create("hd/btn_acoustic_grand_piano.png"));
        Singleton<GameManager>::GetInst()->brightButton->setNormalImage(CCSprite::create("hd/btn_bright_acoustic_piano_over.png"));
        Singleton<GameManager>::GetInst()->chorusButton->setNormalImage(CCSprite::create("hd/btn_chorus_piano.png"));
        Singleton<GameManager>::GetInst()->electricButton->setNormalImage(CCSprite::create("hd/btn_electric_piano.png"));
        Singleton<GameManager>::GetInst()->hongkyButton->setNormalImage(CCSprite::create("hd/btn_hongky_tonky_piano.png"));
        Singleton<GameManager>::GetInst()->rhodesButton->setNormalImage(CCSprite::create("hd/btn_Rhodes_piano.png"));

    }
    if(value == 8)
    {
        Singleton<GameManager>::GetInst()->escButton->setNormalImage(CCSprite::create("hd/btn_esc_non.png"));
        Singleton<GameManager>::GetInst()->pauseButton->setNormalImage(CCSprite::create("hd/btn_pause_non.png"));

        Singleton<GameManager>::GetInst()->x1SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x1_non.png"));
        Singleton<GameManager>::GetInst()->x2SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x2_non.png"));
        Singleton<GameManager>::GetInst()->x12SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x12_non.png"));
        Singleton<GameManager>::GetInst()->x14SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x14_non.png"));

        Singleton<GameManager>::GetInst()->acousticButton->setNormalImage(CCSprite::create("hd/btn_acoustic_grand_piano.png"));
        Singleton<GameManager>::GetInst()->brightButton->setNormalImage(CCSprite::create("hd/btn_bright_acoustic_piano.png"));
        Singleton<GameManager>::GetInst()->chorusButton->setNormalImage(CCSprite::create("hd/btn_chorus_piano_over.png"));
        Singleton<GameManager>::GetInst()->electricButton->setNormalImage(CCSprite::create("hd/btn_electric_piano.png"));
        Singleton<GameManager>::GetInst()->hongkyButton->setNormalImage(CCSprite::create("hd/btn_hongky_tonky_piano.png"));
        Singleton<GameManager>::GetInst()->rhodesButton->setNormalImage(CCSprite::create("hd/btn_Rhodes_piano.png"));
    }
    if(value == 9)
    {
        Singleton<GameManager>::GetInst()->escButton->setNormalImage(CCSprite::create("hd/btn_esc_non.png"));
        Singleton<GameManager>::GetInst()->pauseButton->setNormalImage(CCSprite::create("hd/btn_pause_non.png"));

        Singleton<GameManager>::GetInst()->x1SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x1_non.png"));
        Singleton<GameManager>::GetInst()->x2SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x2_non.png"));
        Singleton<GameManager>::GetInst()->x12SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x12_non.png"));
        Singleton<GameManager>::GetInst()->x14SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x14_non.png"));

        Singleton<GameManager>::GetInst()->acousticButton->setNormalImage(CCSprite::create("hd/btn_acoustic_grand_piano.png"));
        Singleton<GameManager>::GetInst()->brightButton->setNormalImage(CCSprite::create("hd/btn_bright_acoustic_piano.png"));
        Singleton<GameManager>::GetInst()->chorusButton->setNormalImage(CCSprite::create("hd/btn_chorus_piano.png"));
        Singleton<GameManager>::GetInst()->electricButton->setNormalImage(CCSprite::create("hd/btn_electric_piano_over.png"));
        Singleton<GameManager>::GetInst()->hongkyButton->setNormalImage(CCSprite::create("hd/btn_hongky_tonky_piano.png"));
        Singleton<GameManager>::GetInst()->rhodesButton->setNormalImage(CCSprite::create("hd/btn_Rhodes_piano.png"));
    }
    if(value == 10)
    {
        Singleton<GameManager>::GetInst()->escButton->setNormalImage(CCSprite::create("hd/btn_esc_non.png"));
        Singleton<GameManager>::GetInst()->pauseButton->setNormalImage(CCSprite::create("hd/btn_pause_non.png"));

        Singleton<GameManager>::GetInst()->x1SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x1_non.png"));
        Singleton<GameManager>::GetInst()->x2SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x2_non.png"));
        Singleton<GameManager>::GetInst()->x12SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x12_non.png"));
        Singleton<GameManager>::GetInst()->x14SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x14_non.png"));

        Singleton<GameManager>::GetInst()->acousticButton->setNormalImage(CCSprite::create("hd/btn_acoustic_grand_piano.png"));
        Singleton<GameManager>::GetInst()->brightButton->setNormalImage(CCSprite::create("hd/btn_bright_acoustic_piano.png"));
        Singleton<GameManager>::GetInst()->chorusButton->setNormalImage(CCSprite::create("hd/btn_chorus_piano.png"));
        Singleton<GameManager>::GetInst()->electricButton->setNormalImage(CCSprite::create("hd/btn_electric_piano.png"));
        Singleton<GameManager>::GetInst()->hongkyButton->setNormalImage(CCSprite::create("hd/btn_hongky_tonky_piano_over.png"));
        Singleton<GameManager>::GetInst()->rhodesButton->setNormalImage(CCSprite::create("hd/btn_Rhodes_piano.png"));
    }
    if(value == 11)
    {
        Singleton<GameManager>::GetInst()->escButton->setNormalImage(CCSprite::create("hd/btn_esc_non.png"));
        Singleton<GameManager>::GetInst()->pauseButton->setNormalImage(CCSprite::create("hd/btn_pause_non.png"));

        Singleton<GameManager>::GetInst()->x1SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x1_non.png"));
        Singleton<GameManager>::GetInst()->x2SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x2_non.png"));
        Singleton<GameManager>::GetInst()->x12SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x12_non.png"));
        Singleton<GameManager>::GetInst()->x14SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x14_non.png"));

        Singleton<GameManager>::GetInst()->acousticButton->setNormalImage(CCSprite::create("hd/btn_acoustic_grand_piano.png"));
        Singleton<GameManager>::GetInst()->brightButton->setNormalImage(CCSprite::create("hd/btn_bright_acoustic_piano.png"));
        Singleton<GameManager>::GetInst()->chorusButton->setNormalImage(CCSprite::create("hd/btn_chorus_piano.png"));
        Singleton<GameManager>::GetInst()->electricButton->setNormalImage(CCSprite::create("hd/btn_electric_piano.png"));
        Singleton<GameManager>::GetInst()->hongkyButton->setNormalImage(CCSprite::create("hd/btn_hongky_tonky_piano.png"));
        Singleton<GameManager>::GetInst()->rhodesButton->setNormalImage(CCSprite::create("hd/btn_Rhodes_piano_over.png"));
    }
}





void GameManager::FreeremoteController(int value)
{
    CCLog("FreeremoteController : %d",value);
    if(value == -1)
    {
        Singleton<GameManager>::GetInst()->exitButton->setNormalImage(CCSprite::create("hd/btn_exit_over.png"));

        Singleton<GameManager>::GetInst()->acousticButton->setNormalImage(CCSprite::create("hd/btn_acoustic_grand_piano.png"));
        Singleton<GameManager>::GetInst()->brightButton->setNormalImage(CCSprite::create("hd/btn_bright_acoustic_piano.png"));
        Singleton<GameManager>::GetInst()->chorusButton->setNormalImage(CCSprite::create("hd/btn_chorus_piano.png"));
        Singleton<GameManager>::GetInst()->electricButton->setNormalImage(CCSprite::create("hd/btn_electric_piano.png"));
        Singleton<GameManager>::GetInst()->hongkyButton->setNormalImage(CCSprite::create("hd/btn_hongky_tonky_piano.png"));
        Singleton<GameManager>::GetInst()->rhodesButton->setNormalImage(CCSprite::create("hd/btn_Rhodes_piano.png"));

        Singleton<GameManager>::GetInst()->pianoRainbowButton->setNormalImage(CCSprite::create("hd/btn_color.png"));
        Singleton<GameManager>::GetInst()->pianoMarkButton->setNormalImage(CCSprite::create("hd/btn_mark.png"));
        Singleton<GameManager>::GetInst()->pianoNormalButton->setNormalImage(CCSprite::create("hd/btn_nomal.png"));
    }


    if(value == 0)
    {
        CCLog("in FreeremoteController : %d",value);
        Singleton<GameManager>::GetInst()->exitButton->setNormalImage(CCSprite::create("hd/btn_exit.png"));

        Singleton<GameManager>::GetInst()->acousticButton->setNormalImage(CCSprite::create("hd/btn_acoustic_grand_piano_over.png"));
        Singleton<GameManager>::GetInst()->brightButton->setNormalImage(CCSprite::create("hd/btn_bright_acoustic_piano.png"));
        Singleton<GameManager>::GetInst()->chorusButton->setNormalImage(CCSprite::create("hd/btn_chorus_piano.png"));
        Singleton<GameManager>::GetInst()->electricButton->setNormalImage(CCSprite::create("hd/btn_electric_piano.png"));
        Singleton<GameManager>::GetInst()->hongkyButton->setNormalImage(CCSprite::create("hd/btn_hongky_tonky_piano.png"));
        Singleton<GameManager>::GetInst()->rhodesButton->setNormalImage(CCSprite::create("hd/btn_Rhodes_piano.png"));
    }
    if(value == 1)
    {
        CCLog("in FreeremoteController : %d",value);
        Singleton<GameManager>::GetInst()->exitButton->setNormalImage(CCSprite::create("hd/btn_exit.png"));

        Singleton<GameManager>::GetInst()->acousticButton->setNormalImage(CCSprite::create("hd/btn_acoustic_grand_piano.png"));
        Singleton<GameManager>::GetInst()->brightButton->setNormalImage(CCSprite::create("hd/btn_bright_acoustic_piano_over.png"));
        Singleton<GameManager>::GetInst()->chorusButton->setNormalImage(CCSprite::create("hd/btn_chorus_piano.png"));
        Singleton<GameManager>::GetInst()->electricButton->setNormalImage(CCSprite::create("hd/btn_electric_piano.png"));
        Singleton<GameManager>::GetInst()->hongkyButton->setNormalImage(CCSprite::create("hd/btn_hongky_tonky_piano.png"));
        Singleton<GameManager>::GetInst()->rhodesButton->setNormalImage(CCSprite::create("hd/btn_Rhodes_piano.png"));
    }
    if(value == 2)
    {
        CCLog("in FreeremoteController : %d",value);
        Singleton<GameManager>::GetInst()->exitButton->setNormalImage(CCSprite::create("hd/btn_exit.png"));

        Singleton<GameManager>::GetInst()->acousticButton->setNormalImage(CCSprite::create("hd/btn_acoustic_grand_piano.png"));
        Singleton<GameManager>::GetInst()->brightButton->setNormalImage(CCSprite::create("hd/btn_bright_acoustic_piano.png"));
        Singleton<GameManager>::GetInst()->chorusButton->setNormalImage(CCSprite::create("hd/btn_chorus_piano_over.png"));
        Singleton<GameManager>::GetInst()->electricButton->setNormalImage(CCSprite::create("hd/btn_electric_piano.png"));
        Singleton<GameManager>::GetInst()->hongkyButton->setNormalImage(CCSprite::create("hd/btn_hongky_tonky_piano.png"));
        Singleton<GameManager>::GetInst()->rhodesButton->setNormalImage(CCSprite::create("hd/btn_Rhodes_piano.png"));
    }
    if(value == 3)
    {
        CCLog("in FreeremoteController : %d",value);
        Singleton<GameManager>::GetInst()->exitButton->setNormalImage(CCSprite::create("hd/btn_exit.png"));

        Singleton<GameManager>::GetInst()->acousticButton->setNormalImage(CCSprite::create("hd/btn_acoustic_grand_piano.png"));
        Singleton<GameManager>::GetInst()->brightButton->setNormalImage(CCSprite::create("hd/btn_bright_acoustic_piano.png"));
        Singleton<GameManager>::GetInst()->chorusButton->setNormalImage(CCSprite::create("hd/btn_chorus_piano.png"));
        Singleton<GameManager>::GetInst()->electricButton->setNormalImage(CCSprite::create("hd/btn_electric_piano_over.png"));
        Singleton<GameManager>::GetInst()->hongkyButton->setNormalImage(CCSprite::create("hd/btn_hongky_tonky_piano.png"));
        Singleton<GameManager>::GetInst()->rhodesButton->setNormalImage(CCSprite::create("hd/btn_Rhodes_piano.png"));
    }
    if(value == 4)
    {
        CCLog("in FreeremoteController : %d",value);
        Singleton<GameManager>::GetInst()->exitButton->setNormalImage(CCSprite::create("hd/btn_exit.png"));

        Singleton<GameManager>::GetInst()->acousticButton->setNormalImage(CCSprite::create("hd/btn_acoustic_grand_piano.png"));
        Singleton<GameManager>::GetInst()->brightButton->setNormalImage(CCSprite::create("hd/btn_bright_acoustic_piano.png"));
        Singleton<GameManager>::GetInst()->chorusButton->setNormalImage(CCSprite::create("hd/btn_chorus_piano.png"));
        Singleton<GameManager>::GetInst()->electricButton->setNormalImage(CCSprite::create("hd/btn_electric_piano.png"));
        Singleton<GameManager>::GetInst()->hongkyButton->setNormalImage(CCSprite::create("hd/btn_hongky_tonky_piano_over.png"));
        Singleton<GameManager>::GetInst()->rhodesButton->setNormalImage(CCSprite::create("hd/btn_Rhodes_piano.png"));
    }
    if(value == 5)
    {
        CCLog("in FreeremoteController : %d",value);
        Singleton<GameManager>::GetInst()->exitButton->setNormalImage(CCSprite::create("hd/btn_exit.png"));

        Singleton<GameManager>::GetInst()->acousticButton->setNormalImage(CCSprite::create("hd/btn_acoustic_grand_piano.png"));
        Singleton<GameManager>::GetInst()->brightButton->setNormalImage(CCSprite::create("hd/btn_bright_acoustic_piano.png"));
        Singleton<GameManager>::GetInst()->chorusButton->setNormalImage(CCSprite::create("hd/btn_chorus_piano.png"));
        Singleton<GameManager>::GetInst()->electricButton->setNormalImage(CCSprite::create("hd/btn_electric_piano.png"));
        Singleton<GameManager>::GetInst()->hongkyButton->setNormalImage(CCSprite::create("hd/btn_hongky_tonky_piano.png"));
        Singleton<GameManager>::GetInst()->rhodesButton->setNormalImage(CCSprite::create("hd/btn_Rhodes_piano_over.png"));
    }
    if(value == 6)
    {
        CCLog("in FreeremoteController : %d",value);
        Singleton<GameManager>::GetInst()->exitButton->setNormalImage(CCSprite::create("hd/btn_exit.png"));

        Singleton<GameManager>::GetInst()->acousticButton->setNormalImage(CCSprite::create("hd/btn_acoustic_grand_piano.png"));
        Singleton<GameManager>::GetInst()->brightButton->setNormalImage(CCSprite::create("hd/btn_bright_acoustic_piano.png"));
        Singleton<GameManager>::GetInst()->chorusButton->setNormalImage(CCSprite::create("hd/btn_chorus_piano.png"));
        Singleton<GameManager>::GetInst()->electricButton->setNormalImage(CCSprite::create("hd/btn_electric_piano.png"));
        Singleton<GameManager>::GetInst()->hongkyButton->setNormalImage(CCSprite::create("hd/btn_hongky_tonky_piano.png"));
        Singleton<GameManager>::GetInst()->rhodesButton->setNormalImage(CCSprite::create("hd/btn_Rhodes_piano.png"));

        Singleton<GameManager>::GetInst()->pianoRainbowButton->setNormalImage(CCSprite::create("hd/btn_color_focus.png"));
        Singleton<GameManager>::GetInst()->pianoMarkButton->setNormalImage(CCSprite::create("hd/btn_mark.png"));
        Singleton<GameManager>::GetInst()->pianoNormalButton->setNormalImage(CCSprite::create("hd/btn_nomal.png"));
    }
    if(value == 7)
    {
        CCLog("in FreeremoteController : %d",value);
        Singleton<GameManager>::GetInst()->exitButton->setNormalImage(CCSprite::create("hd/btn_exit.png"));

        Singleton<GameManager>::GetInst()->acousticButton->setNormalImage(CCSprite::create("hd/btn_acoustic_grand_piano.png"));
        Singleton<GameManager>::GetInst()->brightButton->setNormalImage(CCSprite::create("hd/btn_bright_acoustic_piano.png"));
        Singleton<GameManager>::GetInst()->chorusButton->setNormalImage(CCSprite::create("hd/btn_chorus_piano.png"));
        Singleton<GameManager>::GetInst()->electricButton->setNormalImage(CCSprite::create("hd/btn_electric_piano.png"));
        Singleton<GameManager>::GetInst()->hongkyButton->setNormalImage(CCSprite::create("hd/btn_hongky_tonky_piano.png"));
        Singleton<GameManager>::GetInst()->rhodesButton->setNormalImage(CCSprite::create("hd/btn_Rhodes_piano.png"));

        Singleton<GameManager>::GetInst()->pianoRainbowButton->setNormalImage(CCSprite::create("hd/btn_color.png"));
        Singleton<GameManager>::GetInst()->pianoMarkButton->setNormalImage(CCSprite::create("hd/btn_mark_focus.png"));
        Singleton<GameManager>::GetInst()->pianoNormalButton->setNormalImage(CCSprite::create("hd/btn_nomal.png"));
    }
    if(value == 8)
    {
        CCLog("in FreeremoteController : %d",value);
        Singleton<GameManager>::GetInst()->exitButton->setNormalImage(CCSprite::create("hd/btn_exit.png"));

        Singleton<GameManager>::GetInst()->acousticButton->setNormalImage(CCSprite::create("hd/btn_acoustic_grand_piano.png"));
        Singleton<GameManager>::GetInst()->brightButton->setNormalImage(CCSprite::create("hd/btn_bright_acoustic_piano.png"));
        Singleton<GameManager>::GetInst()->chorusButton->setNormalImage(CCSprite::create("hd/btn_chorus_piano.png"));
        Singleton<GameManager>::GetInst()->electricButton->setNormalImage(CCSprite::create("hd/btn_electric_piano.png"));
        Singleton<GameManager>::GetInst()->hongkyButton->setNormalImage(CCSprite::create("hd/btn_hongky_tonky_piano.png"));
        Singleton<GameManager>::GetInst()->rhodesButton->setNormalImage(CCSprite::create("hd/btn_Rhodes_piano.png"));

        Singleton<GameManager>::GetInst()->pianoRainbowButton->setNormalImage(CCSprite::create("hd/btn_color.png"));
        Singleton<GameManager>::GetInst()->pianoMarkButton->setNormalImage(CCSprite::create("hd/btn_mark.png"));
        Singleton<GameManager>::GetInst()->pianoNormalButton->setNormalImage(CCSprite::create("hd/btn_nomal_focus.png"));
    }
}



GameManager::GameManager()
{
}

GameManager::~GameManager()
{
    
}

bool GameManager::init()
{
    //처음
	pianoStr_a0 = "";
	//pianoStr_do = "";
	sprintf(pianoStr_do,"");
	copy_target = NULL;
    equalLineBlockCount = 0;
    nodeGuidingCount = 0;

    playNormalScene = false;
    playEasyScene = false;
    playAngFreeScene = false;
    playFreeScene = false;
    playGameScene = false;
    playAngGameScene = false;

    LoadImageCount = 0;
    load_timeBar = 0;
    totalLoadImage = 0;

    pianoSelectValue = -1;
    pianoCoverValue = -1;
    gameSpeedValue = -1;

    tutorialMode = false;
    gameStart = false;
    musicPlayLine = -1;
    firstPrintNodeCount = 300;
    minTime = 0;
    maxTime = 0;
    stateTime = 0;
    gameSpeed = 1.0f;
    feverMode = false;
    feverTimer = false;

    dataIndex = -1;
    dataIndex_copy = -1;
    channelState = false;

    loding_complete = false;
    pianoMode = RAINBOW_MODE;
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    //gameMode = ANG_GAME;
    gameMode = SINGE_GAME;
    //gameMode = SINGE_FREE;
    //gameMode = EASY_GAME;
    //gameMode = NORMAL_GAME;
#endif
    printRealNoteCount = -123456;
    gameEnding = END_FALSE;
    if(gameMode == SINGE_FREE || gameMode == ANG_FREE)
    {
        remotePosition = 0; //playUILayer
        remoteUpDownPosition = 0;
        remoteOverPosition[0] = 0;
        remoteOverPosition[1] = 6;
    }
    else if(gameMode == NORMAL_GAME)
    {
        PIANO_FINISH_TIME = 32;

        remoteUpDownPosition = 0;
        remotePosition = 4; //playUILayer

        remoteOverPosition[0] = remotePosition;
        remoteOverPosition[1] = 6;
    }
    else
    {
        PIANO_FINISH_TIME = 6;

        remoteUpDownPosition = 0;
        remotePosition = 4;

        remoteOverPosition[0] = remotePosition;
        remoteOverPosition[1] = 6;
    }

    maxScore = 0;
    max_combo_count = 0;
    block_count = 0;
    perfectSocre = 0;
    missSocre = 0;
    goodSocre = 0;
    badSocre = 0;

    maxScore_copy = 0;
    max_combo_count_copy = 0;
    block_count_copy = 0;
    perfectSocre_copy = 0;
    missSocre_copy = 0;
    goodSocre_copy = 0;
    badSocre_copy = 0;

    nodePrintingCount = 0; //������ 異���λ��怨� ������ ��몃�� 移댁�댄��
    nodeGuidingCount = 0; //������ 媛���대�� 怨���곕��怨� ������ ��몃�� 移댁�댄��
    totalNodeCount = 0; //���泥� ��몃�� ���
    matchingNodeCount = 0;

    line_block_collect_array = CCArray::create();
    line_block_collect_array->retain();

    for(int a=0;a<88;a++)
    {
        CCArray *Value_Array = CCArray::create();
        line_block_collect_array->addObject(Value_Array);
    }

    line_block_collect_array_copy = CCArray::create();
    line_block_collect_array_copy->retain();

    for(int a=0;a<88;a++)
    {
        CCArray *Value_Array = CCArray::create();
        line_block_collect_array_copy->addObject(Value_Array);
    }



    missSocre = 0;
    perfectSocre = 0;
    combo_count = 0;
    WinSize = cocos2d::CCSize(CCDirector::sharedDirector()->getVisibleSize().width-37*2,
                              CCDirector::sharedDirector()->getVisibleSize().height);

    block_WinSize = cocos2d::CCSize(CCDirector::sharedDirector()->getVisibleSize().width-300,
                                    CCDirector::sharedDirector()->getVisibleSize().height);
    //CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    //jdm
    //CCDirector::sharedDirector()->getVisibleSize();
    block_WinOrign = CCPoint(block_WinSize.width/4+155,0);
    WinOrign = CCPoint(37,0);
    BlockCenterPoint = block_WinSize.width/2 - (block_WinSize.width/WHITE_PIANO_COUNT) + 70;


    //    WHITE_BlockWidth = this->calSize(CCSize((winSize.width/WHITE_PIANO_COUNT),5)).width;   //���占쏙옙 占싼�由�
    //    BLACK_BlockWidth = this->calSize(CCSize((winSize.width/WHITE_PIANO_COUNT),5)).width;   //���占쏙옙 占싼�由�
    //BLACK_BlockWidth -= (BLACK_BlockWidth/6);
    //��몃��異���λ�����
    if(Singleton<GameManager>::GetInst()->gameMode == ANG_GAME)
    {
        startBlockPoint = (CCDirector::sharedDirector()->getVisibleSize().height+100); //���占쏙옙 占쏙옙占� 占쏙옙占�
        startBlockPoint_copy = startBlockPoint;//(CCDirector::sharedDirector()->getVisibleSize().height+0); //���占쏙옙 占쏙옙占� 占쏙옙占�
    }
    if(Singleton<GameManager>::GetInst()->gameMode == NORMAL_GAME)
    {
        startBlockPoint = (CCDirector::sharedDirector()->getVisibleSize().height); //���占쏙옙 占쏙옙占� 占쏙옙占�
    }
    else
    {
        startBlockPoint = CCDirector::sharedDirector()->getVisibleSize().height; //���占쏙옙 占쏙옙占� 占쏙옙占�
        startBlockPoint_copy = CCDirector::sharedDirector()->getVisibleSize().height; //���占쏙옙 占쏙옙占� 占쏙옙占�
    }


    SCREEN_SIZE_WHITE_BlockWidth = block_WinSize.width/WHITE_PIANO_COUNT;  //占쎌�곤옙 占쏙옙���占쏙옙占� ���占쏙옙 占쏙옙媛� 占쏙옙占�
    SCREEN_2X_SIZE_WHITE_BlockWidth = block_WinSize.width/2/WHITE_PIANO_COUNT;  //2x占쏙옙���占쏙옙���占쏙옙 占쏙옙媛� 占쏙옙占�

    //SCREEN_SIZE_WHITE_halfBlockWidth = 9.6;//this->calSize(CCSize(17,5)).width; //占쏙옙���占쏙옙占� ���占쏙옙 占쏙옙占� 占쏙옙占�


    //    centerPoint -= SCREEN_SIZE_WHITE_halfBlockWidth;


    // WHITE_halfBlockWidth = WHITE_BlockWidth/2;

    // halfLineStartPoint = cocos2d::CCPoint(centerPoint+winOrign.x-(SCREEN_SIZE_WHITE_halfBlockWidth*44), winSize.height-280);

    //CCLOG("aaa : %f",CCDirector::sharedDirector()->getVisibleSize().width);


    halfLineEndPoint = cocos2d::CCPoint(BlockCenterPoint+(BlockCenterPoint/2), block_WinSize.height-280);


    if(Singleton<GameManager>::GetInst()->gameMode == SINGE_FREE || Singleton<GameManager>::GetInst()->gameMode == ANG_FREE) // free
    {
        EndLineStartPoint = cocos2d::CCPoint(0,FREE_MODE_PIANO_HEIGHT);
    }
    else if(Singleton<GameManager>::GetInst()->gameMode == SINGE_GAME)
    {
        EndLineStartPoint = cocos2d::CCPoint(0,PIANO_HEIGHT);
    }
    else if(Singleton<GameManager>::GetInst()->gameMode == ANG_GAME)
    {
        EndLineStartPoint = cocos2d::CCPoint(0,PIANO_HEIGHT);
    }
    EndLineEndPoint = cocos2d::CCPoint(block_WinSize.width,PIANO_HEIGHT);


    return true;
}

void GameManager::SetEffectLayer(CCLayer *layer)
{
    effect_layer = layer;
    effect_layer->addChild(spritebatch);//hit_effect animation..
}
void GameManager::SetEffectLayer_copy(CCLayer *layer)
{
    effect_layer_copy = layer;
    effect_layer_copy->addChild(spritebatch); //������ ��댄����� ������留ㅼ�댁��..
}
void GameManager::SetControllLayer(CCLayer *layer)
{
    controll_layer = layer;

}
void GameManager::SetControllLayer_copy(CCLayer *layer)
{
    controll_layer_copy = layer;

}

void GameManager::SetLineLayer(CCLayer *layer)
{
    line_layer = layer;
}
void GameManager::SetLineLayer_copy(CCLayer *layer)
{
    line_layer_copy = layer;
}

void GameManager::SetBlockLayer(CCLayer *layer)
{
    block_layer = layer;
}
void GameManager::SetNormalBlockLayer(CCLayer *layer,CCLayer *nomalBlocklayer)
{
    normal_block_cover_layer = layer;
    normal_block_layer = nomalBlocklayer;
}
void GameManager::resourceMenuSceneLoad()
{

}

void GameManager::pianoEffectInit(CCLayer *layer)
{
    /*
     for(int i=0;i<52;i++)
     {
     piano_white_match[i] =  new cocos2d::CCSprite();
     piano_white_match[i]->initWithFile("hd/hit_effect_yellow.png");
     //piano_white_match[i]->setVisible(false);

     float EndLineXPostion = effectPosX[i] + piano_white_match[i]->getContentSize().width;
     CCLOG("EndLineXPostion : %f",EndLineXPostion);
     piano_white_match[i]->setPosition(ccp(EndLineXPostion, hitLine->getPositionY() + piano_white_match[i]->getContentSize().height/2));
     layer->addChild( piano_white_match[i],3);
     }
     */
}

void GameManager::game_wait_end()
{
    //  this->game_end();
    gameEnding = END_DELAY;
}
void GameManager::game_end()
{
	CCDirector::sharedDirector()->stopAnimation();
    CCLog("game_end : %d",totalNodeCount);

    gameEnding = END_TRUE;

    this->all_Cleanup();

    if(gameMode == EASY_GAME) // free
    {

#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

        JniMethodInfo t;
        if (JniHelper::getMethodInfo(t
                                     , "com/shfactory/musicblood/solo/SimpleGame"
                                     , "JavaJniTestFunc"
                                     , "(IIIIIII)V"))
        {
            ///< 占썩�ο옙 占쎈��占�
            //perfectSocre
            CCLog("here 1");
            t.env->CallVoidMethod(Singleton<GameManager>::GetInst()->javaObj, t.methodID, 1, 1, 1, 1, 1, 1,9);
            //,pianoSelectValue,pianoCoverValue,-1);
            CCLog("here 2");
            ///< Release
            t.env->DeleteLocalRef(t.classID);
            CCLog("here 3");
        }

#endif

    }

    if(gameMode == NORMAL_GAME) // free
    {

#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

        JniMethodInfo t;
        if (JniHelper::getMethodInfo(t
                                     , "com/shfactory/musicblood/solo/SimpleGame"
                                     , "JavaJniTestFunc"
                                     , "(IIIIIII)V"))
        {
            ///< 占썩�ο옙 占쎈��占�
            //perfectSocre
            CCLog("here 1");
            t.env->CallVoidMethod(Singleton<GameManager>::GetInst()->javaObj, t.methodID, 1, 1, 1, 1, 1, 1,9);
            //,pianoSelectValue,pianoCoverValue,-1);
            CCLog("here 2");
            ///< Release
            t.env->DeleteLocalRef(t.classID);
            CCLog("here 3");
        }

#endif

    }

    
    if(gameMode == SINGE_FREE) // free
    {


#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

        JniMethodInfo t;
        if (JniHelper::getMethodInfo(t
                                     , "com/shfactory/musicblood/solo/SimpleGame"
                                     , "JavaJniTestFunc"
                                     , "(IIIIIII)V"))
        {
            ///< 占썩�ο옙 占쎈��占�
            //perfectSocre
            CCLog("here 1");
            t.env->CallVoidMethod(Singleton<GameManager>::GetInst()->javaObj, t.methodID, perfectSocre, goodSocre, badSocre, missSocre, matchingNodeCount, Singleton<GameManager>::GetInst()->totalNodeCount,9);
            //,pianoSelectValue,pianoCoverValue,-1);
            CCLog("here 2");
            ///< Release
            t.env->DeleteLocalRef(t.classID);
            CCLog("here 3");
        }
        
#endif
        
    }
    else if(gameMode == ANG_FREE)
    {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        
        JniMethodInfo t;
        if (JniHelper::getMethodInfo(t
                                     , "com/shfactory/musicblood/solo/MultipleGame"
                                     , "JavaJniTestFunc"
                                     , "(IIIIIII)V"))
        {
            ///< 占썩�ο옙 占쎈��占�
            //perfectSocre
            CCLog("here 2");
            t.env->CallVoidMethod(Singleton<GameManager>::GetInst()->javaObj, t.methodID, perfectSocre, goodSocre, badSocre, missSocre, matchingNodeCount, Singleton<GameManager>::GetInst()->totalNodeCount,9);
            ///< Release
            t.env->DeleteLocalRef(t.classID);
        }
        
#endif
    }
    else if(gameMode == SINGE_GAME)//
    {

        
        
        
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        
        JniMethodInfo t;
        if (JniHelper::getMethodInfo(t
                                     , "com/shfactory/musicblood/solo/SimpleGame"
                                     , "JavaJniTestFunc"
                                     , "(IIIIIII)V"))
        {
            ///< 占썩�ο옙 占쎈��占�
            //perfectSocre
            t.env->CallVoidMethod(Singleton<GameManager>::GetInst()->javaObj, t.methodID, perfectSocre, goodSocre, badSocre, missSocre, matchingNodeCount, Singleton<GameManager>::GetInst()->totalNodeCount,0);
            //,pianoSelectValue,pianoCoverValue,gameSpeedValue);
            ///< Release
            t.env->DeleteLocalRef(t.classID);
        }
        
#endif
    }

    Singleton<GameManager>::DestroyInst();

    CCDirector::sharedDirector()->end();
}



void GameManager::resourceLoadSceneLoad()
{
    if(gameMode == NORMAL_GAME)
    {
        LoadBG = CCSprite::create("hd/beginner_loding_bg.png");
        LoadBG->retain();
        
        load_timeBar_gaze = CCProgressTimer::create(CCSprite::create("hd/beginner-yellow.png"));
        load_timeBar_gaze->retain();
        load_timeBar_gaze->setType(kCCProgressTimerTypeBar);
        load_timeBar_gaze->setMidpoint(ccp(0,0.5));
        load_timeBar_gaze->setBarChangeRate(ccp(1,0));
        load_timeBar_gaze->setPercentage(0);
    }
    else
    {
        if(gameMode == EASY_GAME)
        {
            LoadBG = CCSprite::create("hd/practice_loadiing_bg.png");
            LoadBG->retain();
        }
        else
        {
            LoadBG = CCSprite::create("hd/loading.png");
            LoadBG->retain();
        }
        load_timer_gaze[0] = CCSprite::create("hd/GameLoading_image_1.png");
        load_timer_gaze[0]->retain();
        load_timer_gaze[1] = CCSprite::create("hd/GameLoading_image_2.png");
        load_timer_gaze[1]->retain();
        load_timer_gaze[2] = CCSprite::create("hd/GameLoading_image_3.png");
        load_timer_gaze[2]->retain();
        load_timer_gaze[3] = CCSprite::create("hd/GameLoading_image_4.png");
        load_timer_gaze[3]->retain();
        load_timer_gaze[4] = CCSprite::create("hd/GameLoading_image_5.png");
        load_timer_gaze[4]->retain();
        
        
        load_timer_gaze[1]->setVisible(false);
        load_timer_gaze[2]->setVisible(false);
        load_timer_gaze[3]->setVisible(false);
        load_timer_gaze[4]->setVisible(false);
        for(int i = 5;i<18;i++)
        {
            load_timer_gaze[i] = CCSprite::create("hd/GameLoading_image_5.png");
            load_timer_gaze[i]->retain();
            load_timer_gaze[i]->setVisible(false);
        }
        
        
        load_timer_gaze_tex[0] = load_timer_gaze[1]->getTexture();
        load_timer_gaze_tex[0]->retain();
        load_timer_gaze_tex[1] = load_timer_gaze[2]->getTexture();
        load_timer_gaze_tex[1]->retain();
        load_timer_gaze_tex[2] = load_timer_gaze[3]->getTexture();
        load_timer_gaze_tex[2]->retain();
        load_timer_gaze_tex[3] = load_timer_gaze[4]->getTexture();
        load_timer_gaze_tex[3]->retain();
        
        load_line = CCSprite::create("hd/GameLoading_line.png");
        load_line->retain();
    }




    /*
     load_timeBar = CCProgressTimer::create(load_timer_gaze[0]);
     load_timeBar->setType(kCCProgressTimerTypeBar);
     load_timeBar->setMidpoint(ccp(0,0.5));
     load_timeBar->setBarChangeRate(ccp(1,0));
     load_timeBar->setPercentage(0);
     */
}
void asdf(void *arg)
{
    CCLOG("asdf");

}

void* ThreadFunction(void* arg)
{
    // pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);

    //  pthread_cleanup_push(asdf, (void *)NULL);

    pthread_mutex_lock(&mutex);

    CCLOG("ThreadFunction");
    //Start_Loading_Structure* args = (Start_Loading_Structure*)arg;


    //  delete args;

    pthread_mutex_unlock(&mutex);



    // CCPoolManager::CCPoolManager::sharedPoolManager()->pause(false);
    // pthread_cleanup_pop(0);
    //    pthread_exit((void *)0);
    return NULL;
}
void GameManager::playNormalSceneMaker()
{
    if(!playNormalScene)
    {
        playNormalScene = true;
        this->NormalGameScene_Init();
        GameScene = PlayNormalScene::create();
        GameScene->retain();
    }

}
void GameManager::playEasySceneMaker()
{
    if(!playEasyScene)
    {
        playEasyScene = true;
        this->EasyGameScene_Init();
        GameScene = PlayEasyScene::create();
        GameScene->retain();
    }
}
void GameManager::playAngFreeSceneMaker()
{
    if(playAngFreeScene)
    {
        playAngFreeScene = true;
        this->FreeGameScene_Init();
        GameScene = PlayScene::create();
        GameScene->retain();
        
    }
}
void GameManager::playFreeSceneMaker()
{
    if(!playFreeScene)
    {
        playFreeScene = true;
        this->FreeGameScene_Init();
        GameScene = PlayScene::create();
        GameScene->retain();
    }
}
void GameManager::playGameSceneMaker()
{
    if(!playGameScene)
    {
        playGameScene = true;
        this->GameScene_Init();
        GameScene = PlayScene::create();
        GameScene->retain();
    }
}
void GameManager::playAngGameSceneMaker()
{
    if(!playAngGameScene)
    {
        playAngGameScene = true;
        this->GameScene_Init();
        GameScene = PlayScene::create();
        GameScene->retain();
    }
}
void GameManager::ImageloadingCallBack(CCObject *obj)
{
    ++LoadImageCount;

    if(LoadImageCount == totalLoadImage)
    {
        if(Singleton<GameManager>::GetInst()->gameMode == ANG_GAME)
        {
            Singleton<GameManager>::GetInst()->playAngGameSceneMaker();
        }
        else
        {
            Singleton<GameManager>::GetInst()->playGameSceneMaker();
        }

        loding_complete = true;
    }

    load_timeBar = ((float)LoadImageCount / (float)totalLoadImage * 100.0f / 2); //0~40%
}


void GameManager::FreeImageloadingCallBack(CCObject *obj)
{
    ++LoadImageCount;
    //  CCLog("LoadImageCount : %d   %d",LoadImageCount,totalLoadImage);
    if(LoadImageCount == totalLoadImage)
    {
        if(Singleton<GameManager>::GetInst()->gameMode == SINGE_FREE)
        {
            Singleton<GameManager>::GetInst()->playFreeSceneMaker();
        }
        else
        {
            Singleton<GameManager>::GetInst()->playAngFreeSceneMaker();
        }

        loding_complete = true;
    }


    load_timeBar = ((float)LoadImageCount / (float)totalLoadImage * 100.0f / 2); //0~40%
}
void GameManager::NormalImageloadingCallBack(CCObject *obj)
{
    ++LoadImageCount;

    if(LoadImageCount == totalLoadImage)
    {
        Singleton<GameManager>::GetInst()->playNormalSceneMaker();

        loding_complete = true;
    }

    load_timeBar = ((float)LoadImageCount / (float)totalLoadImage * 100.0f / 2); //0~40%
}
void GameManager::EasyImageloadingCallBack(CCObject *obj)
{
    ++LoadImageCount;

    if(LoadImageCount == totalLoadImage)
    {
        Singleton<GameManager>::GetInst()->playEasySceneMaker();

        loding_complete = true;
    }


    load_timeBar = ((float)LoadImageCount / (float)totalLoadImage * 100.0f); //0~40%
}
void GameManager::EasyGameScene_Init()
{
    image_do = CCSprite::create("hd/image_do.png");
    image_do->retain();
    image_re = CCSprite::create("hd/image_re.png");
    image_re->retain();
    image_mi = CCSprite::create("hd/image_mi.png");
    image_mi->retain();
    image_fa = CCSprite::create("hd/image_fa.png");
    image_fa->retain();
    image_so = CCSprite::create("hd/image_so.png");
    image_so->retain();
    image_ra = CCSprite::create("hd/image_ra.png");
    image_ra->retain();
    image_si = CCSprite::create("hd/image_si.png");
    image_si->retain();

    practice_bg = CCSprite::create("hd/practice_bg.png");
    practice_bg->retain();
    practice_frame = CCSprite::create("hd/practice_frame.png");
    practice_frame->retain();
    practice_btn_exit_over = CCSprite::create("hd/practice_btn_exit_over.png");
    practice_btn_exit_over->retain();
    practice_btn_exit_press = CCSprite::create("hd/practice_btn_exit_press.png");
    practice_btn_exit_press->retain();
    practice_logo = CCSprite::create("hd/practice_logo.png");
    practice_logo->retain();

    text_do = CCSprite::create("hd/text_do.png");
    text_do->retain();
    text_re = CCSprite::create("hd/text_re.png");
    text_re->retain();
    text_mi = CCSprite::create("hd/text_mi.png");
    text_mi->retain();
    text_fa = CCSprite::create("hd/text_fa.png");
    text_fa->retain();
    text_so = CCSprite::create("hd/text_so.png");
    text_so->retain();
    text_la = CCSprite::create("hd/text_la.png");
    text_la->retain();
    text_ti = CCSprite::create("hd/text_ti.png");
    text_ti->retain();
}
void GameManager::NormalGameScene_Init()
{
	//asdf1
    beginner_image_do = CCTextureCache::sharedTextureCache()->addImage("hd/beginner_image_do.png");
    beginner_image_do->retain();

    beginner_image_fa = CCTextureCache::sharedTextureCache()->addImage("hd/beginner_image_fa.png");
    beginner_image_fa->retain();

    beginner_image_la = CCTextureCache::sharedTextureCache()->addImage("hd/beginner_image_la.png");
    beginner_image_la->retain();

    beginner_image_mi = CCTextureCache::sharedTextureCache()->addImage("hd/beginner_image_mi.png");
    beginner_image_mi->retain();

    beginner_image_re = CCTextureCache::sharedTextureCache()->addImage("hd/beginner_image_re.png");
    beginner_image_re->retain();

    beginner_image_sol = CCTextureCache::sharedTextureCache()->addImage("hd/beginner_image_sol.png");
    beginner_image_sol->retain();

    beginner_image_ti = CCTextureCache::sharedTextureCache()->addImage("hd/beginner_image_ti.png");
    beginner_image_ti->retain();

    beginner_syllable_image = CCSprite::createWithTexture(beginner_image_do);
    beginner_syllable_image->retain();

    beginner_syllable_names_bg = CCSprite::create("hd/beginner_syllable_names_bg.png");
    beginner_syllable_names_bg->retain();




    pianoKeyCode_a0 = CCLabelTTF::create("", "Arial", 50);
    pianoKeyCode_a0->retain();
    pianoKeyCode_do = CCLabelTTF::create("", "Arial", 80);
    pianoKeyCode_do->retain();


    note_do_nomal = CCTextureCache::sharedTextureCache()->addImage("hd/dragon_note/note_do_nomal.png");
    note_do_nomal->retain();
    note_do_smile = CCTextureCache::sharedTextureCache()->addImage("hd/dragon_note/note_do_smile.png");
    note_do_smile->retain();

    note_fa_nomal = CCTextureCache::sharedTextureCache()->addImage("hd/dragon_note/note_fa_nomal.png");
    note_fa_nomal->retain();
    note_fa_smile = CCTextureCache::sharedTextureCache()->addImage("hd/dragon_note/note_fa_smile.png");
    note_fa_smile->retain();

    note_la_nomal = CCTextureCache::sharedTextureCache()->addImage("hd/dragon_note/note_la_nomal.png");
    note_la_nomal->retain();
    note_la_smile = CCTextureCache::sharedTextureCache()->addImage("hd/dragon_note/note_la_smile.png");
    note_la_smile->retain();

    note_mi_nomal = CCTextureCache::sharedTextureCache()->addImage("hd/dragon_note/note_mi_nomal.png");
    note_mi_nomal->retain();
    note_mi_smile = CCTextureCache::sharedTextureCache()->addImage("hd/dragon_note/note_mi_smile.png");
    note_mi_smile->retain();

    note_re_nomal = CCTextureCache::sharedTextureCache()->addImage("hd/dragon_note/note_re_nomal.png");
    note_re_nomal->retain();
    note_re_smile = CCTextureCache::sharedTextureCache()->addImage("hd/dragon_note/note_re_smile.png");
    note_re_smile->retain();

    note_so_nomal = CCTextureCache::sharedTextureCache()->addImage("hd/dragon_note/note_so_nomal.png");
    note_so_nomal->retain();
    note_so_smile = CCTextureCache::sharedTextureCache()->addImage("hd/dragon_note/note_so_smile.png");
    note_so_smile->retain();

    note_ti_nomal = CCTextureCache::sharedTextureCache()->addImage("hd/dragon_note/note_ti_nomal.png");
  	note_ti_nomal->retain();
    note_ti_smile = CCTextureCache::sharedTextureCache()->addImage("hd/dragon_note/note_ti_smile.png");
    note_ti_smile->retain();



    stopButton = CCSprite::create("hd/btn_play_over.png");
    stopButton->retain();
    normal_bg = CCSprite::create("hd/normal_bg.png");
    normal_bg->retain();



    comboImg = CCSprite::create("hd/combo.png");
    comboImg->retain();
    comboBackImg1 = CCSprite::create("hd/effect_1.png");
    comboBackImg1->retain();
    comboBackImg2 = CCSprite::create("hd/effect_2.png");
    comboBackImg2->retain();
    comboBackImg3 = CCSprite::create("hd/effect_3.png");
    comboBackImg3->retain();

    grade = CCSprite::create("hd/miss.png");
    grade->retain();
    perfect = CCTextureCache::sharedTextureCache()->addImage("hd/perfect.png");
    perfect->retain();
    miss = CCTextureCache::sharedTextureCache()->addImage("hd/miss.png");
    miss->retain();
    good = CCTextureCache::sharedTextureCache()->addImage("hd/good.png");
    good->retain();
    bad = CCTextureCache::sharedTextureCache()->addImage("hd/bad.png");
    bad->retain();

    combo_count_label = CCLabelAtlas::create("0", "hd/combo_number/combo_list.png", 76, 233, '0');
    combo_count_label->retain();
    perfect_count_bottom_label = CCLabelAtlas::create("0", "hd/score_number/score_number_list.png", 14, 19, '0');
    perfect_count_bottom_label->retain();

    good_count_bottom_label = CCLabelAtlas::create("0", "hd/score_number/score_number_list.png", 14, 19, '0');
    good_count_bottom_label->retain();
    bad_count_bottom_label = CCLabelAtlas::create("0", "hd/score_number/score_number_list.png", 14, 19, '0');
    bad_count_bottom_label->retain();

    miss_count_bottom_label = CCLabelAtlas::create("0", "hd/score_number/score_number_list.png", 14, 19, '0');
    miss_count_bottom_label->retain();
    max_combo_label = CCLabelAtlas::create("0", "hd/max_combo_number/max_combo_number_list.png", 50, 88, '0');
    max_combo_label->retain();
    total_score_label = CCLabelAtlas::create("0", "hd/max_combo_number/max_combo_number_list.png", 50, 88, '0');
    total_score_label->retain();
    timer_gaze = CCSprite::create("hd/time_bar.png");
    timer_gaze->retain();

    timeBar = CCProgressTimer::create(timer_gaze);
    timeBar->retain();
    timeBar->setType(kCCProgressTimerTypeBar);
    timeBar->setPercentage(100.0f);
    timeBar->setMidpoint(ccp(0,0.5));
    timeBar->setBarChangeRate(ccp(1,0));

    bar_yellow = CCTextureCache::sharedTextureCache()->addImage("hd/bar_yellow/bar_yellow.png");
    bar_yellow->retain();
    bar_yellow_long = CCTextureCache::sharedTextureCache()->addImage("hd/bar_yellow/bar_yellow_long_1.png");
    bar_yellow_long->retain();


    bar_blue = CCTextureCache::sharedTextureCache()->addImage("hd/bar_blue/bar_blue.png");
    bar_blue->retain();
    bar_blue_long = CCTextureCache::sharedTextureCache()->addImage("hd/bar_blue/bar_blue_long_1.png");
    bar_blue_long->retain();


    hp_bar = CCSprite::create("hd/hp_bar.png");
    hp_bar->retain();

    acousticButton = CCMenuItemImage::create("hd/btn_acoustic_grand_piano.png", "hd/btn_acoustic_grand_piano_press.png", this, menu_selector(GameManager::acousticButtonPress));
    brightButton = CCMenuItemImage::create("hd/btn_bright_acoustic_piano.png", "hd/btn_bright_acoustic_piano_press.png", this, menu_selector(GameManager::brightButtonPress));
    chorusButton = CCMenuItemImage::create("hd/btn_chorus_piano.png", "hd/btn_chorus_piano_press.png",  this, menu_selector(GameManager::chorusButtonPress));
    electricButton = CCMenuItemImage::create("hd/btn_electric_piano.png", "hd/btn_electric_piano_press.png", this, menu_selector(GameManager::electricButtonPress));
    hongkyButton = CCMenuItemImage::create("hd/btn_hongky_tonky_piano.png", "hd/btn_hongky_tonky_piano_press.png",  this, menu_selector(GameManager::hongkyButtonPress));
    rhodesButton = CCMenuItemImage::create("hd/btn_Rhodes_piano.png", "hd/btn_Rhodes_piano_press.png",  this, menu_selector(GameManager::rhodesButtonPress));

    escButton = CCMenuItemImage::create("hd/btn_esc_non.png", "hd/btn_esc_press.png", this, menu_selector(GameManager::escButtonPress));
    escButton_copy = CCMenuItemImage::create("hd/btn_esc_non.png", "hd/btn_esc_press.png",  this, menu_selector(GameManager::escButtonPress));

    pauseButton = CCMenuItemImage::create("hd/btn_pause_non.png", "hd/btn_pause_press.png", this, menu_selector(GameManager::pauseButtonPress));
    pauseButton_copy = CCMenuItemImage::create("hd/btn_pause_non.png", "hd/btn_pause_press.png",this, menu_selector(GameManager::pauseButtonPress));


    x1SpeedButton = CCMenuItemImage::create("hd/btn_speed_x1_non.png", "hd/btn_speed_x1_press.png",  this, menu_selector(GameManager::x1SpeedButtonPress));
    x2SpeedButton = CCMenuItemImage::create("hd/btn_speed_x2_non.png", "hd/btn_speed_x2_press.png",  this, menu_selector(GameManager::x2SpeedButtonPress));

    x12SpeedButton = CCMenuItemImage::create("hd/btn_speed_x12_non.png", "hd/btn_speed_x12_press.png", this, menu_selector(GameManager::x12SpeedButtonPress));
    x14SpeedButton = CCMenuItemImage::create("hd/btn_speed_x14_non.png", "hd/btn_speed_x14_press.png",  this, menu_selector(GameManager::x14SpeedButtonPress));

    menu = CCMenu::create(escButton, pauseButton, x14SpeedButton, x12SpeedButton, x1SpeedButton, x2SpeedButton, acousticButton, brightButton, chorusButton,
                          electricButton, hongkyButton, rhodesButton, exitButton, NULL);
    menu->retain();




    start_count = CCLabelAtlas::create("0", "hd/combo_number/combo_list.png", 76, 233, '0');
    start_count->retain();



    block_way = CCSprite::create("hd/block_way.png");
    block_way->retain();


    redBlock = CCSprite::create("hd/btn_bad.png");
    redBlock->retain();
    yellowBlock = CCSprite::create("hd/btn_good.png");
    yellowBlock->retain();
    greenBlock = CCSprite::create("hd/btn_perfect.png");
    greenBlock->retain();

    redBlock_Press = CCSprite::create("hd/btn_bad_press.png");
    redBlock_Press->retain();
    yellowBlock_Press = CCSprite::create("hd/btn_good_press.png");
    yellowBlock_Press->retain();
    greenBlock_Press = CCSprite::create("hd/btn_perfect_press.png");
    greenBlock_Press->retain();




    CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();
    cache->addSpriteFramesWithFile("character/dragon_dance.plist");
    CCSpriteFrameCache* cache1 = CCSpriteFrameCache::sharedSpriteFrameCache();
    cache1->addSpriteFramesWithFile("character/dragon_dance_green.plist");
    CCSpriteFrameCache* cache2 = CCSpriteFrameCache::sharedSpriteFrameCache();
    cache2->addSpriteFramesWithFile("character/dragon_dance_pink.plist");

    npc_sprite = CCSprite::createWithSpriteFrameName("dragon_dance_1.png");
    npc_sprite->retain();
    npc_sprite_green = CCSprite::createWithSpriteFrameName("dragon_dance_green1.png");
    npc_sprite_green->retain();
    npc_sprite_pink = CCSprite::createWithSpriteFrameName("dragon_dance_pink1.png");
    npc_sprite_pink->retain();

    npc_spritebatch = CCSpriteBatchNode::create("character/dragon_dance.png");
    npc_spritebatch->retain();
    npc_spritebatch_green = CCSpriteBatchNode::create("character/dragon_dance_green.png");
    npc_spritebatch_green->retain();
    npc_spritebatch_pink = CCSpriteBatchNode::create("character/dragon_dance_pink.png");
    npc_spritebatch_pink->retain();

    npc_spritebatch->addChild(npc_sprite);
    npc_spritebatch_green->addChild(npc_sprite_green);
    npc_spritebatch_pink->addChild(npc_sprite_pink);
    // this->addChild(spritebatch);




    CCArray *ani = CCArray::createWithCapacity(17);
    ani->retain();
    CCArray *ani_green = CCArray::createWithCapacity(17);
    ani_green->retain();
    CCArray *ani_pink = CCArray::createWithCapacity(17);
    ani_pink->retain();

    char str[100] = {0};
    for(int i = 1; i < 17; i++)
    {
        sprintf(str, "dragon_dance_%d.png", i);
        CCSpriteFrame* frame = cache->spriteFrameByName( str );
       // frame->retain();
        ani->addObject(frame);

        sprintf(str, "dragon_dance_green%d.png", i);
        CCSpriteFrame* frame1 = cache1->spriteFrameByName( str );
      //  frame1->retain();
        ani_green->addObject(frame1);

        sprintf(str, "dragon_dance_pink%d.png", i);
        CCSpriteFrame* frame2 = cache2->spriteFrameByName( str );
    //    frame2->retain();
        ani_pink->addObject(frame2);
    }

    idle_animate = CCAnimate::create(CCAnimation::createWithSpriteFrames(ani, 0.2f));
    idle_animate->retain();
    npc_sprite->runAction( CCRepeatForever::create( idle_animate ) );
    ani->release();

    idle_animate_green = CCAnimate::create(CCAnimation::createWithSpriteFrames(ani_green, 0.2f));
    idle_animate_green->retain();
    npc_sprite_green->runAction( CCRepeatForever::create( idle_animate_green ) );
    ani_green->release();

    idle_animate_pink = CCAnimate::create(CCAnimation::createWithSpriteFrames(ani_pink, 0.2f));
    idle_animate_pink->retain();
    npc_sprite_pink->runAction( CCRepeatForever::create( idle_animate_pink ) );
    ani_pink->release();




    ani = CCArray::createWithCapacity(4);

    for(int i = 1; i < 5; i++)
    {
        sprintf(str, "cry_%d.png", i);

        CCSpriteFrame* frame = cache->spriteFrameByName( str );
//        frame->retain();
        ani->addObject(frame);

    }

    cry_animate = CCAnimate::create(CCAnimation::createWithSpriteFrames(ani, 0.5f));
    cry_animate->retain();
   // ani->release();



    npc_sprite->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2  ,
                                CCDirector::sharedDirector()->getWinSize().height+100));

    npc_state = Npc_STATE_IDLE;
    npc_state_green = Npc_STATE_IDLE;
    npc_state_pink = Npc_STATE_IDLE;






}
void GameManager::FreeGameScene_Init()
{
    btn_key_yellow_press_1 = CCTextureCache::sharedTextureCache()->addImage("hd/btn_key_yellow_press_1.png");
    btn_key_yellow_press_1->retain();
    btn_key_yellow_press_2 = CCTextureCache::sharedTextureCache()->addImage("hd/btn_key_yellow_press_2.png");
    btn_key_yellow_press_2->retain();
    btn_key_yellow_press_3 = CCTextureCache::sharedTextureCache()->addImage("hd/btn_key_yellow_press_3.png");
    btn_key_yellow_press_3->retain();
    btn_key_yellow_press_4 = CCTextureCache::sharedTextureCache()->addImage("hd/btn_key_yellow_press_4.png");
    btn_key_yellow_press_4->retain();
    btn_black_key_press = CCTextureCache::sharedTextureCache()->addImage("hd/btn_black_key_press.png");
    btn_black_key_press->retain();

    LoadBG_Free = CCSprite::create("hd/loading_free.png");
    LoadBG_Free->retain();

    acousticButton = CCMenuItemImage::create("hd/btn_acoustic_grand_piano.png", "hd/btn_acoustic_grand_piano_press.png", this, menu_selector(GameManager::acousticButtonPress));
    brightButton = CCMenuItemImage::create("hd/btn_bright_acoustic_piano.png", "hd/btn_bright_acoustic_piano_press.png", this, menu_selector(GameManager::brightButtonPress));
    chorusButton = CCMenuItemImage::create("hd/btn_chorus_piano.png", "hd/btn_chorus_piano_press.png",  this, menu_selector(GameManager::chorusButtonPress));
    electricButton = CCMenuItemImage::create("hd/btn_electric_piano.png", "hd/btn_electric_piano_press.png", this, menu_selector(GameManager::electricButtonPress));
    hongkyButton = CCMenuItemImage::create("hd/btn_hongky_tonky_piano.png", "hd/btn_hongky_tonky_piano_press.png",  this, menu_selector(GameManager::hongkyButtonPress));
    rhodesButton = CCMenuItemImage::create("hd/btn_Rhodes_piano.png", "hd/btn_Rhodes_piano_press.png",  this, menu_selector(GameManager::rhodesButtonPress));

    exitButton = CCMenuItemImage::create("hd/btn_exit.png", "hd/btn_exit_press.png", this, menu_selector(GameManager::escButtonPress));



    pianoNormalButton = CCMenuItemImage::create("hd/btn_nomal.png", "hd/btn_nomal_press.png",  this, menu_selector(GameManager::pianoNormalButtonPress));
    pianoMarkButton = CCMenuItemImage::create("hd/btn_mark.png", "hd/btn_mark_press.png",  this, menu_selector(GameManager::pianoMarkButtonPress));
    pianoRainbowButton = CCMenuItemImage::create("hd/btn_color.png", "hd/btn_color_press.png",  this, menu_selector(GameManager::pianoRainbowButtonPress));

    pianoBG = CCSprite::create("hd/keyboard_nomal.png");;
    pianoBG->retain();
    pianoBG_copy = CCSprite::create("hd/keyboard_nomal.png");;
    pianoBG_copy->retain();

    pianoBG_tex[0] = CCTextureCache::sharedTextureCache()->addImage("hd/keyboard_color.png");
    pianoBG_tex[0]->retain();
    pianoBG_tex[1] = CCTextureCache::sharedTextureCache()->addImage("hd/keyboard_mark.png");
    pianoBG_tex[1]->retain();
    pianoBG_tex[2] = CCTextureCache::sharedTextureCache()->addImage("hd/keyboard_nomal.png");
    pianoBG_tex[2]->retain();


    menu = CCMenu::create(acousticButton, pianoNormalButton, pianoMarkButton, pianoRainbowButton, brightButton, chorusButton, electricButton, hongkyButton, rhodesButton, exitButton, NULL);
    menu->retain();

}
void GameManager::GameScene_Init()
{
    start_count = CCLabelAtlas::create("0", "hd/combo_number/combo_list.png", 76, 233, '0');
    start_count->retain();

    tutorial_bg = CCSprite::create("hd/game_tutorial.png");
    tutorial_bg->retain();
    tutorial_piano[0] = CCSprite::create("hd/btn_key_yellow_press_1.png"); //��쇱そ
    tutorial_piano[0]->retain();
    tutorial_piano[1] = CCSprite::create("hd/btn_key_yellow_press_3.png"); //以�媛�
    tutorial_piano[1]->retain();
    tutorial_piano[2] = CCSprite::create("hd/btn_key_yellow_press_2.png"); //��ㅻⅨ履�
    tutorial_piano[2]->retain();
    tutorial_piano[3] = CCSprite::create("hd/btn_key_yellow_press_1.png"); //��쇱そ
    tutorial_piano[3]->retain();
    tutorial_piano[4] = CCSprite::create("hd/btn_key_yellow_press_3.png"); //以�媛�
    tutorial_piano[4]->retain();
    tutorial_piano[5] = CCSprite::create("hd/btn_key_yellow_press_3.png"); //以�媛�
    tutorial_piano[5]->retain();
    tutorial_piano[6] = CCSprite::create("hd/btn_key_yellow_press_2.png"); //��ㅻⅨ履�
    tutorial_piano[6]->retain();

    tutorialMent1 = CCLabelTTF::create("Press C3 key..", "fonts/Cartoon_Regular.ttf", 50);
    tutorialMent1->retain();
    tutorialMent2 = CCLabelTTF::create("Press D3 key..", "fonts/Cartoon_Regular.ttf", 50);
    tutorialMent2->retain();
    tutorialMent3 = CCLabelTTF::create("Press E3 key..", "fonts/Cartoon_Regular.ttf", 50);
    tutorialMent3->retain();
    tutorialMent4 = CCLabelTTF::create("Press F3 key..", "fonts/Cartoon_Regular.ttf", 50);
    tutorialMent4->retain();
    tutorialMent5 = CCLabelTTF::create("Press G3 key..", "fonts/Cartoon_Regular.ttf", 50);
    tutorialMent5->retain();
    tutorialMent6 = CCLabelTTF::create("Press A3 key..", "fonts/Cartoon_Regular.ttf", 50);
    tutorialMent6->retain();
    tutorialMent7 = CCLabelTTF::create("Press B3 key..", "fonts/Cartoon_Regular.ttf", 50);
    tutorialMent7->retain();
    tutorialMent8 = CCLabelTTF::create("Tutorial Complete", "fonts/Cartoon_Regular.ttf", 50);
    tutorialMent8->retain();


    blackcover = CCSprite::create("hd/bg02.png");
    blackcover->retain();

    GameBG = CCSprite::create("hd/bg01.png");
    GameBG->retain();
    GameBG_copy = CCSprite::create("hd/bg01.png");
    GameBG_copy->retain();
    hitLine_copy = CCSprite::create("hd/hit_line.png");
    hitLine_copy->retain();
    hitLine = CCSprite::create("hd/hit_line.png");
    hitLine->retain();
    comboImg_copy = CCSprite::create("hd/combo.png");
    comboImg_copy->retain();
    comboImg = CCSprite::create("hd/combo.png");
    comboImg->retain();
    comboBackImg1_copy = CCSprite::create("hd/effect_1.png");
    comboBackImg1_copy->retain();
    comboBackImg1 = CCSprite::create("hd/effect_1.png");
    comboBackImg1->retain();
    comboBackImg2_copy = CCSprite::create("hd/effect_2.png");
    comboBackImg2_copy->retain();
    comboBackImg2 = CCSprite::create("hd/effect_2.png");
    comboBackImg2->retain();
    comboBackImg3_copy = CCSprite::create("hd/effect_3.png");
    comboBackImg3_copy->retain();
    comboBackImg3 = CCSprite::create("hd/effect_3.png");
    comboBackImg3->retain();

    grade_copy = CCSprite::create("hd/miss.png");
    grade_copy->retain();
    grade = CCSprite::create("hd/miss.png");
    grade->retain();
    perfect = CCTextureCache::sharedTextureCache()->addImage("hd/perfect.png");
    perfect->retain();
    miss = CCTextureCache::sharedTextureCache()->addImage("hd/miss.png");
    miss->retain();
    good = CCTextureCache::sharedTextureCache()->addImage("hd/good.png");
    good->retain();
    bad = CCTextureCache::sharedTextureCache()->addImage("hd/bad.png");
    bad->retain();

    combo_count_label_copy = CCLabelAtlas::create("0", "hd/combo_number/combo_list.png", 76, 233, '0');
    combo_count_label_copy->retain();
    combo_count_label = CCLabelAtlas::create("0", "hd/combo_number/combo_list.png", 76, 233, '0');
    combo_count_label->retain();
    perfect_count_bottom_label_copy = CCLabelAtlas::create("0", "hd/score_number/score_number_list.png", 14, 19, '0');
    perfect_count_bottom_label_copy->retain();
    perfect_count_bottom_label = CCLabelAtlas::create("0", "hd/score_number/score_number_list.png", 14, 19, '0');
    perfect_count_bottom_label->retain();

    good_count_bottom_label_copy = CCLabelAtlas::create("0", "hd/score_number/score_number_list.png", 14, 19, '0');
    good_count_bottom_label_copy->retain();
    good_count_bottom_label = CCLabelAtlas::create("0", "hd/score_number/score_number_list.png", 14, 19, '0');
    good_count_bottom_label->retain();
    bad_count_bottom_label_copy = CCLabelAtlas::create("0", "hd/score_number/score_number_list.png", 14, 19, '0');
    bad_count_bottom_label_copy->retain();
    bad_count_bottom_label = CCLabelAtlas::create("0", "hd/score_number/score_number_list.png", 14, 19, '0');
    bad_count_bottom_label->retain();

    miss_count_bottom_label_copy = CCLabelAtlas::create("0", "hd/score_number/score_number_list.png", 14, 19, '0');
    miss_count_bottom_label_copy->retain();
    miss_count_bottom_label = CCLabelAtlas::create("0", "hd/score_number/score_number_list.png", 14, 19, '0');
    miss_count_bottom_label->retain();
    max_combo_label_copy = CCLabelAtlas::create("0", "hd/max_combo_number/max_combo_number_list.png", 50, 88, '0');
    max_combo_label_copy->retain();
    max_combo_label = CCLabelAtlas::create("0", "hd/max_combo_number/max_combo_number_list.png", 50, 88, '0');
    max_combo_label->retain();
    total_score_label_copy = CCLabelAtlas::create("0", "hd/max_combo_number/max_combo_number_list.png", 50, 88, '0');
    total_score_label_copy->retain();
    total_score_label = CCLabelAtlas::create("0", "hd/max_combo_number/max_combo_number_list.png", 50, 88, '0');
    total_score_label->retain();
    timer_gaze = CCSprite::create("hd/time_bar.png");
    timer_gaze->retain();

    timeBar = CCProgressTimer::create(timer_gaze);
    timeBar->retain();
    timeBar->setType(kCCProgressTimerTypeBar);
    timeBar->setPercentage(100.0f);
    timeBar->setMidpoint(ccp(0,0.5));
    timeBar->setBarChangeRate(ccp(1,0));

    timeBar_copy = CCProgressTimer::create(timer_gaze);
    timeBar_copy->retain();
    timeBar_copy->setType(kCCProgressTimerTypeBar);
    timeBar_copy->setPercentage(100.0f);
    timeBar_copy->setMidpoint(ccp(0,0.5));
    timeBar_copy->setBarChangeRate(ccp(1,0));

    energy_bar = CCProgressTimer::create(CCSprite::create("hd/energy_bar.png"));
    energy_bar->retain();

    energy_bar->setType(kCCProgressTimerTypeRadial);
    energy_bar->setReverseProgress(true);// 紐⑥��.....
    energy_bar->setMidpoint(ccp(0.9,0.9));
    energy_bar->setPercentage(ENERGY_INIT);  //������吏� 珥�湲고��   1/4

    hp_bar = CCSprite::create("hd/hp_bar.png");
    hp_bar->retain();
    hp_bar_copy= CCSprite::create("hd/hp_bar.png");
    hp_bar_copy->retain();



    acousticButton = CCMenuItemImage::create("hd/btn_acoustic_grand_piano.png", "hd/btn_acoustic_grand_piano_press.png", this, menu_selector(GameManager::acousticButtonPress));
    brightButton = CCMenuItemImage::create("hd/btn_bright_acoustic_piano.png", "hd/btn_bright_acoustic_piano_press.png", this, menu_selector(GameManager::brightButtonPress));
    chorusButton = CCMenuItemImage::create("hd/btn_chorus_piano.png", "hd/btn_chorus_piano_press.png",  this, menu_selector(GameManager::chorusButtonPress));
    electricButton = CCMenuItemImage::create("hd/btn_electric_piano.png", "hd/btn_electric_piano_press.png", this, menu_selector(GameManager::electricButtonPress));
    hongkyButton = CCMenuItemImage::create("hd/btn_hongky_tonky_piano.png", "hd/btn_hongky_tonky_piano_press.png",  this, menu_selector(GameManager::hongkyButtonPress));
    rhodesButton = CCMenuItemImage::create("hd/btn_Rhodes_piano.png", "hd/btn_Rhodes_piano_press.png",  this, menu_selector(GameManager::rhodesButtonPress));


    pianoNormalButton = CCMenuItemImage::create("hd/btn_nomal.png", "hd/btn_nomal_press.png",  this, menu_selector(GameManager::pianoNormalButtonPress));
    pianoMarkButton = CCMenuItemImage::create("hd/btn_mark.png", "hd/btn_mark_press.png",  this, menu_selector(GameManager::pianoMarkButtonPress));
    pianoRainbowButton = CCMenuItemImage::create("hd/btn_color.png", "hd/btn_color_press.png",  this, menu_selector(GameManager::pianoRainbowButtonPress));

    escButton = CCMenuItemImage::create("hd/btn_esc_non.png", "hd/btn_esc_press.png", this, menu_selector(GameManager::escButtonPress));
    escButton_copy = CCMenuItemImage::create("hd/btn_esc_non.png", "hd/btn_esc_press.png",  this, menu_selector(GameManager::escButtonPress));

    pauseButton = CCMenuItemImage::create("hd/btn_pause_non.png", "hd/btn_pause_press.png", this, menu_selector(GameManager::pauseButtonPress));
    pauseButton_copy = CCMenuItemImage::create("hd/btn_pause_non.png", "hd/btn_pause_press.png",this, menu_selector(GameManager::pauseButtonPress));


    x1SpeedButton = CCMenuItemImage::create("hd/btn_speed_x1_non.png", "hd/btn_speed_x1_press.png",  this, menu_selector(GameManager::x1SpeedButtonPress));
    x1SpeedButton_copy = CCMenuItemImage::create("hd/btn_speed_x1_non.png", "hd/btn_speed_x1_press.png",  this, menu_selector(GameManager::x1SpeedButtonPress_copy));
    x2SpeedButton = CCMenuItemImage::create("hd/btn_speed_x2_non.png", "hd/btn_speed_x2_press.png",  this, menu_selector(GameManager::x2SpeedButtonPress));
    x2SpeedButton_copy = CCMenuItemImage::create("hd/btn_speed_x2_non.png", "hd/btn_speed_x2_press.png", this, menu_selector(GameManager::x2SpeedButtonPress_copy));

    x12SpeedButton = CCMenuItemImage::create("hd/btn_speed_x12_non.png", "hd/btn_speed_x12_press.png", this, menu_selector(GameManager::x12SpeedButtonPress));
    x14SpeedButton = CCMenuItemImage::create("hd/btn_speed_x14_non.png", "hd/btn_speed_x14_press.png",  this, menu_selector(GameManager::x14SpeedButtonPress));



    btn_key_yellow_press_1 = CCTextureCache::sharedTextureCache()->addImage("hd/btn_key_yellow_press_1.png");
    btn_key_yellow_press_1->retain();
    btn_key_yellow_press_2 = CCTextureCache::sharedTextureCache()->addImage("hd/btn_key_yellow_press_2.png");
    btn_key_yellow_press_2->retain();
    btn_key_yellow_press_3 = CCTextureCache::sharedTextureCache()->addImage("hd/btn_key_yellow_press_3.png");
    btn_key_yellow_press_3->retain();
    btn_key_yellow_press_4 = CCTextureCache::sharedTextureCache()->addImage("hd/btn_key_yellow_press_4.png");
    btn_key_yellow_press_4->retain();
    btn_black_key_press = CCTextureCache::sharedTextureCache()->addImage("hd/btn_black_key_press.png");
    btn_black_key_press->retain();

    btn_key_guide_press_1 = CCTextureCache::sharedTextureCache()->addImage("hd/btn_key_guide_press_1.png");
    btn_key_guide_press_1->retain();
    btn_key_guide_press_2 = CCTextureCache::sharedTextureCache()->addImage("hd/btn_key_guide_press_2.png");
    btn_key_guide_press_2->retain();
    btn_key_guide_press_3 = CCTextureCache::sharedTextureCache()->addImage("hd/btn_key_guide_press_3.png");
    btn_key_guide_press_3->retain();
    btn_key_guide_press_4 = CCTextureCache::sharedTextureCache()->addImage("hd/btn_key_guide_press_4.png");
    btn_key_guide_press_4->retain();
    btn_black_key_guide_press = CCTextureCache::sharedTextureCache()->addImage("hd/btn_black_key_guide_press.png");
    btn_black_key_guide_press->retain();


    menu = CCMenu::create(escButton, pianoNormalButton, pianoMarkButton, pianoRainbowButton, pauseButton, x12SpeedButton, x1SpeedButton, x2SpeedButton, x14SpeedButton, acousticButton, brightButton, chorusButton, electricButton, hongkyButton, rhodesButton, exitButton, NULL);
    menu->retain();
    //menu_copy = CCMenu::create(escButton_copy, pauseButton_copy, x3SpeedButton_copy, x1SpeedButton_copy, x2SpeedButton_copy, x4SpeedButton_copy, NULL);
    //menu_copy->retain();

    bar_yellow = CCTextureCache::sharedTextureCache()->addImage("hd/bar_yellow/bar_yellow.png");
    bar_yellow->retain();
    bar_yellow_long = CCTextureCache::sharedTextureCache()->addImage("hd/bar_yellow/bar_yellow_long_1.png");
    bar_yellow_long->retain();


    bar_blue = CCTextureCache::sharedTextureCache()->addImage("hd/bar_blue/bar_blue.png");
    bar_blue->retain();
    bar_blue_long = CCTextureCache::sharedTextureCache()->addImage("hd/bar_blue/bar_blue_long_1.png");
    bar_blue_long->retain();


    stopButton = CCSprite::create("hd/btn_play_over.png");
    stopButton->retain();


    pianoBG = CCSprite::create("hd/keyboard_nomal.png");;
    pianoBG->retain();
    pianoBG_copy = CCSprite::create("hd/keyboard_nomal.png");;
    pianoBG_copy->retain();

    pianoBG_tex[0] = CCTextureCache::sharedTextureCache()->addImage("hd/keyboard_color.png");
    pianoBG_tex[0]->retain();
    pianoBG_tex[1] = CCTextureCache::sharedTextureCache()->addImage("hd/keyboard_mark.png");
    pianoBG_tex[1]->retain();
    pianoBG_tex[2] = CCTextureCache::sharedTextureCache()->addImage("hd/keyboard_nomal.png");
    pianoBG_tex[2]->retain();


    //��댄�����
    CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();
    cache->addSpriteFramesWithFile("hd/hit_effect.plist");

    spritebatch = CCSpriteBatchNode::create("hd/hit_effect.png");
    spritebatch->retain();
    //controll_layer->addChild(spritebatch); 諛������� ������..
    CCArray* animFrames = CCArray::createWithCapacity(5);

    char str[100] = {0};
    for(int i = 1; i < 6; i++)
    {

        sprintf(str, "hit_effect_yellow_%d.png", i);

        CCSpriteFrame* frame = cache->spriteFrameByName( str );
        animFrames->addObject(frame);

    }

    hit_effect_animate = CCAnimate::create(CCAnimation::createWithSpriteFrames(animFrames, 0.05f));
    hit_effect_animate->retain();
    animFrames->release();
}
void GameManager::hit_effect_visiable(int index)
{
    //   hit_yellow_effect[index]->setRotation(hit_yellow_effect_rotate[index]);   //��댄����� ������

    hit_yellow_effect[index]->setVisible(true);
    hit_yellow_effect[index]->stopAllActions();
    CCLog("hit_effect_visiable : %d",index);
    CCFiniteTimeAction* actionMoveDone = CCCallFuncND::create(this, callfuncND_selector(GameManager::hit_effect_end), (void*)index);
    actionMoveDone->retain();


    action = CCSequence::create(
                                                     hit_effect_animate,
                                                     actionMoveDone,
                                                     NULL);

    action->retain();


    hit_yellow_effect[index]->runAction( action );
}


void GameManager::hit_effect_end(CCNode* sender,int index)
{
    CCLog("hit_effect_end : %d",index);
    hit_yellow_effect[index]->setVisible(false);
}
void GameManager::hit_effect_visiable_copy(int index)
{
    hit_yellow_effect_copy[index]->setVisible(true);
    hit_yellow_effect_copy[index]->stopAllActions();

    hit_yellow_effect_copy[index]->setPosition(ccp(400,400));

    CCFiniteTimeAction* actionMoveDone = CCCallFuncND::create(this, callfuncND_selector(GameManager::hit_effect_end_copy), (void*)index);

    CCFiniteTimeAction*  action = CCSequence::create(
                                                     hit_effect_animate,
                                                     actionMoveDone,
                                                     NULL);




    hit_yellow_effect[index]->runAction( action );
}


void GameManager::hit_effect_end_copy(CCNode* sender,int index)
{
    CCLog("hit_effect_end_copy : %d",index);
    hit_yellow_effect_copy[index]->setVisible(false);
}
void GameManager::resourceEasyGameSceneLoad()
{
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/image_do.png", this, callfuncO_selector(GameManager::EasyImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/image_fa.png", this, callfuncO_selector(GameManager::EasyImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/image_mi.png", this, callfuncO_selector(GameManager::EasyImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/image_ra.png", this, callfuncO_selector(GameManager::EasyImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/image_re.png", this, callfuncO_selector(GameManager::EasyImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/image_si.png", this, callfuncO_selector(GameManager::EasyImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/practice_bg.png", this, callfuncO_selector(GameManager::EasyImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/practice_btn_exit_over.png", this, callfuncO_selector(GameManager::EasyImageloadingCallBack));

    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/practice_btn_exit_press.png", this, callfuncO_selector(GameManager::EasyImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/practice_frame.png", this, callfuncO_selector(GameManager::EasyImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/practice_logo.png", this, callfuncO_selector(GameManager::EasyImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/text_do.png", this, callfuncO_selector(GameManager::EasyImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/text_fa.png", this, callfuncO_selector(GameManager::EasyImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/text_la.png", this, callfuncO_selector(GameManager::EasyImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/text_mi.png", this, callfuncO_selector(GameManager::EasyImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/text_re.png", this, callfuncO_selector(GameManager::EasyImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/text_so.png", this, callfuncO_selector(GameManager::EasyImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/text_ti.png", this, callfuncO_selector(GameManager::EasyImageloadingCallBack));


}
void GameManager::resourceNormalGameSceneLoad()
{
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/beginner_image_do.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));

    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/beginner_image_fa.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));

    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/beginner_image_la.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));

    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/beginner_image_mi.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));

    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/beginner_image_re.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));

    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/beginner_image_sol.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));

    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/beginner_image_ti.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));

    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/beginner_syllable_names_bg.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));







    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_perfect_press.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_perfect.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_bad_press.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));

    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_bad.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_good_press.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_good.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));


    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/dragon_note/note_do_nomal.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/dragon_note/note_do_smile.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));

    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/dragon_note/note_re_nomal.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/dragon_note/note_re_smile.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));

    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/dragon_note/note_mi_nomal.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/dragon_note/note_mi_smile.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));

    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/dragon_note/note_fa_nomal.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/dragon_note/note_fa_smile.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));

    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/dragon_note/note_so_nomal.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/dragon_note/note_so_smile.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));

    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/dragon_note/note_la_nomal.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/dragon_note/note_la_smile.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));

    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/dragon_note/note_ti_nomal.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/dragon_note/note_ti_smile.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));






    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/normal_bg.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));

    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/combo.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));

    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/perfect.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/miss.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/good.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/bad.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));

    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/combo_number/combo_list.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/score_number/score_number_list.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/max_combo_number/max_combo_number_list.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/time_bar.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/hp_bar.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));

    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_esc_non.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_esc_press.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));

    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_pause_non.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_pause_press.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_play_non.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_play_press.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_speed_x12_non.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_speed_x12_press.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_speed_x1_non.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_speed_x1_press.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_speed_x2_non.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_speed_x2_press.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_speed_x14_non.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_speed_x14_press.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));

    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_esc_over.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_pause_over.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_play_over.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_speed_x12_over.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_speed_x1_over.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_speed_x2_over.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_speed_x14_over.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_acoustic_grand_piano.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_acoustic_grand_piano_over.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_bright_acoustic_piano.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_bright_acoustic_piano_over.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_chorus_piano.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_chorus_piano_over.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_electric_piano.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_electric_piano_over.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_hongky_tonky_piano.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_hongky_tonky_piano_over.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_Rhodes_piano.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_Rhodes_piano_over.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_acoustic_grand_piano_press.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_bright_acoustic_piano_press.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_chorus_piano_press.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_electric_piano_press.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_hongky_tonky_piano_press.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_Rhodes_piano_press.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));








    /*
     ++totalLoadImage;
     CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_key_yellow_press_1.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
     ++totalLoadImage;
     CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_key_yellow_press_2.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
     ++totalLoadImage;
     CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_key_yellow_press_3.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
     ++totalLoadImage;
     CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_key_yellow_press_4.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
     ++totalLoadImage;
     CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_black_key_press.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
     */




    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/bar_blue/bar_blue.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/bar_blue/bar_blue_long_1.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/bar_yellow/bar_yellow.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/bar_yellow/bar_yellow_long_1.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));






    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/block_way.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));

    /*
     ++totalLoadImage;
     CCTextureCache::sharedTextureCache()->addImageAsync("hd/perfect_inWay.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
     ++totalLoadImage;
     CCTextureCache::sharedTextureCache()->addImageAsync("hd/perfect_inWay_effect.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
     ++totalLoadImage;
     CCTextureCache::sharedTextureCache()->addImageAsync("hd/good_inWay.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
     ++totalLoadImage;
     CCTextureCache::sharedTextureCache()->addImageAsync("hd/good_inWay_effect.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
     ++totalLoadImage;
     CCTextureCache::sharedTextureCache()->addImageAsync("hd/bad_inWay.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
     ++totalLoadImage;
     CCTextureCache::sharedTextureCache()->addImageAsync("hd/bad_inWay_effect.png", this, callfuncO_selector(GameManager::NormalImageloadingCallBack));
     */



}
void GameManager::resourceFreeGameSceneLoad()
{
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/papi.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));

    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_color_focus.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_color_press.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_color.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_mark_focus.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_mark_press.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_mark.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_nomal_focus.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_nomal_press.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_nomal.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
    ++totalLoadImage;



    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_key_yellow_press_1.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_key_yellow_press_2.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_key_yellow_press_3.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_key_yellow_press_4.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_black_key_press.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
    ++totalLoadImage;



    CCTextureCache::sharedTextureCache()->addImageAsync("hd/loading_free.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
    ++totalLoadImage;


    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_acoustic_grand_piano.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_acoustic_grand_piano_over.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
    ++totalLoadImage;


    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_bright_acoustic_piano.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_bright_acoustic_piano_over.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
    ++totalLoadImage;


    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_chorus_piano.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_chorus_piano_over.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
    ++totalLoadImage;


    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_electric_piano.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_electric_piano_over.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
    ++totalLoadImage;


    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_hongky_tonky_piano.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_hongky_tonky_piano_over.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
    ++totalLoadImage;



    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_Rhodes_piano.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_Rhodes_piano_over.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
    ++totalLoadImage;

    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_exit.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_exit_press.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_exit_over.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
    ++totalLoadImage;

    CCTextureCache::sharedTextureCache()->addImageAsync("hd/loading_free_ang.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
    ++totalLoadImage;



    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_acoustic_grand_piano_press.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
    ++totalLoadImage;

    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_bright_acoustic_piano_press.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
    ++totalLoadImage;

    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_chorus_piano_press.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
    ++totalLoadImage;

    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_electric_piano_press.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
    ++totalLoadImage;

    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_hongky_tonky_piano_press.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
    ++totalLoadImage;

    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_Rhodes_piano_press.png", this, callfuncO_selector(GameManager::FreeImageloadingCallBack));
}

void GameManager::resourceGameSceneLoad()
{
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/bg02.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/game_tutorial.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/bg01.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/hit_line.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/combo.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/effect_1.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/effect_2.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/effect_3.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/perfect.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/miss.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/good.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/bad.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;



    CCTextureCache::sharedTextureCache()->addImageAsync("hd/combo_number/combo_list.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/score_number/score_number_list.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/max_combo_number/max_combo_number_list.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/time_bar.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/hp_bar.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/energy_bar.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_esc_non.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_esc_press.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_key_yellow_press_1.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_key_yellow_press_2.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_key_yellow_press_3.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_key_yellow_press_4.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_black_key_press.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;

    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_pause_non.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_pause_press.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_play_non.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_play_press.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_speed_x12_non.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_speed_x12_press.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_speed_x1_non.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_speed_x1_press.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_speed_x2_non.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_speed_x2_press.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_speed_x14_non.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_speed_x14_press.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_key_guide_press_1.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_key_guide_press_2.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_key_guide_press_3.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_key_guide_press_4.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_black_key_guide_press.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_key_miss_press_1.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_key_miss_press_2.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_key_miss_press_3.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_key_miss_press_4.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_black_key_miss.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;




    CCTextureCache::sharedTextureCache()->addImageAsync("hd/bar_blue/bar_blue.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/bar_blue/bar_blue_long_1.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;


    CCTextureCache::sharedTextureCache()->addImageAsync("hd/bar_yellow/bar_yellow.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/bar_yellow/bar_yellow_long_1.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;



    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_esc_over.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_pause_over.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_play_over.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_speed_x12_over.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_speed_x1_over.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_speed_x2_over.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_speed_x14_over.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;






    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_acoustic_grand_piano.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_acoustic_grand_piano_over.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;


    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_bright_acoustic_piano.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_bright_acoustic_piano_over.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;


    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_chorus_piano.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_chorus_piano_over.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;


    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_electric_piano.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_electric_piano_over.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;


    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_hongky_tonky_piano.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_hongky_tonky_piano_over.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;



    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_Rhodes_piano.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_Rhodes_piano_over.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;





    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_acoustic_grand_piano_press.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;

    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_bright_acoustic_piano_press.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;

    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_chorus_piano_press.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;

    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_electric_piano_press.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;

    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_hongky_tonky_piano_press.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;

    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_Rhodes_piano_press.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;


    CCTextureCache::sharedTextureCache()->addImageAsync("hd/line.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;


    CCTextureCache::sharedTextureCache()->addImageAsync("hd/hit_effect.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;





    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_color_focus.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_color_press.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_color.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_mark_focus.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_mark_press.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_mark.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_nomal_focus.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_nomal_press.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_nomal.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;






    CCTextureCache::sharedTextureCache()->addImageAsync("hd/keyboard_color.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/keyboard_mark.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/keyboard_nomal.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;

    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_ColorKeyboard_press_1.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_ColorKeyboard_press_2.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
    ++totalLoadImage;
    CCTextureCache::sharedTextureCache()->addImageAsync("hd/btn_ColorKeyboard_press_3.png", this, callfuncO_selector(GameManager::ImageloadingCallBack));
}

/*
 void GameManager::printNode(int nodeCount, int channel)
 {
 //CCLog("aa : %d   %d",channel,Singleton<GameManager>::GetInst()->_collision_boxes_Channel.at(channel).size());
 std::vector<Block *> _collision_boxes_printNode = Singleton<GameManager>::GetInst()->_collision_boxes_Channel.at(channel);

 Block *target =  _collision_boxes_printNode.at(nodeCount);

 target->print_layer = this->block_layer;

 if(target->body == NULL)
 {
 //CCLog("tail : %d   %d",nodeCount,channel);
 target->print_layer->addChild(target->tail,0,nodeCount);
 }
 else
 {
 //CCLog("body : %d   %d",nodeCount,channel);
 target->print_layer->addChild(target->body,0,nodeCount);
 }

 Singleton<GameManager>::GetInst()->_print_blocks.push_back(target);
 }
 */

void GameManager::makeCollisinoBoxes_update(CCNode* sender, int channel) //媛���대�� ��쇱�� 留���ㅺ린
{
    //
    if(nodeGuidingCount < _guide_print_blocks.size())
    {
        CCArray *guide_Total_Array = guide_Total_Array_channel.at(0);
        CCArray *guide_Value_Array = CCArray::create();

        Block *target =  Iter_Guide_Node_Pos->second;
        target->breakLine = guide_Total_Array->count();
        guide_Value_Array->addObject(target);


        ++nodeGuidingCount;
        if(nodeGuidingCount < _guide_print_blocks.size())
        {
            ++Iter_Guide_Node_Pos;
            Block *nextTarget =  Iter_Guide_Node_Pos->second;

            while((int)nextTarget->timeMillis == (int)target->timeMillis)
            {
                guide_Value_Array->addObject(nextTarget);
                nextTarget->breakLine = guide_Total_Array->count();

                ++nodeGuidingCount;

                ++Iter_Guide_Node_Pos;
                nextTarget =  Iter_Guide_Node_Pos->second;



                if(nodeGuidingCount > _guide_print_blocks.size())
                {
                    break;
                }
            }

        }
        if(guide_Value_Array->count() > 0)
        {
            guide_Total_Array->addObject(guide_Value_Array);
        }

        this->makeCollisinoBoxes_update(NULL, channel);

    }


    /*
     //梨����蹂� 媛���대�� ��쇱�� 留���ㅺ린..
     std::vector<noteData> midiEvents = Singleton<GameManager>::GetInst()->midiChannel.at(channel);

     if(Singleton<GameManager>::GetInst()->nodePrintCount_Channel.at(channel) < midiEvents.size())
     {
     CCArray *guide_Total_Array = Singleton<GameManager>::GetInst()->guide_Total_Array_channel.at(channel);

     CCArray *guide_Value_Array = CCArray::create();

     noteData JNode = midiEvents.at(Singleton<GameManager>::GetInst()->nodePrintCount_Channel.at(channel));

     //this->printNode(Singleton<GameManager>::GetInst()->nodePrintCount_Channel.at(channel),channel);

     guide_Value_Array->addObject(CCInteger::create(Singleton<GameManager>::GetInst()->nodePrintCount_Channel.at(channel)));

     std::vector<Block *> _collision_boxes = Singleton<GameManager>::GetInst()->_collision_boxes_Channel.at(channel);
     Block *target =  _collision_boxes.at(Singleton<GameManager>::GetInst()->nodePrintCount_Channel.at(channel));
     target->breakLine = guide_Total_Array->count();
     ++Singleton<GameManager>::GetInst()->nodePrintCount_Channel.at(channel);
     if(Singleton<GameManager>::GetInst()->nodePrintCount_Channel.at(channel) != midiEvents.size())
     {
     JNode = midiEvents.at(Singleton<GameManager>::GetInst()->nodePrintCount_Channel.at(channel));
     while(JNode.elapsedMillis == 0.0f)
     {
     //   this->printNode(Singleton<GameManager>::GetInst()->nodePrintCount_Channel.at(channel),channel);

     guide_Value_Array->addObject(CCInteger::create(Singleton<GameManager>::GetInst()->nodePrintCount_Channel.at(channel)));
     Block *target =  _collision_boxes.at(Singleton<GameManager>::GetInst()->nodePrintCount_Channel.at(channel));
     target->breakLine = guide_Total_Array->count();
     ++Singleton<GameManager>::GetInst()->nodePrintCount_Channel.at(channel);
     if(Singleton<GameManager>::GetInst()->nodePrintCount_Channel.at(channel) == midiEvents.size())
     {
     break;//
     }
     JNode = midiEvents.at(Singleton<GameManager>::GetInst()->nodePrintCount_Channel.at(channel));
     }
     }

     if(guide_Value_Array->count() > 0)
     {
     guide_Total_Array->addObject(guide_Value_Array);
     }

     this->makeCollisinoBoxes_update(NULL, channel);
     }

     */
}

void GameManager::makeCollisinoBoxes_copy(int nodeNum,double nodeLong,int blockDivision,int midiDivision,int ch,int _velocity,float elapsedMillis,double timePos)
{
    /*
     if(dataIndex_copy != ch)
     {
     dataIndex_copy = ch;
     _collision_boxes_Channel_copy.push_back(_collision_boxes_copy);
     }


     int randXPosition = nodeNum;//( rand() % TOTAL_PIANO_COUNT );// 0~87
     float halfLineXPostion;
     float EndLineXPostion;
     Block *block;

     if(piano_array[randXPosition])
     {
     //int white_index = whiteInPos(randXPosition-1);

     halfLineXPostion = BlockCenterPoint;// - (white_index*0.3);

     EndLineXPostion = DownBlockEndPosX[randXPosition];
     float xPos = EndLineXPostion;//+block->body->getContentSize().width*0.2f/2;
     float scale = 0.5f;


     if(nodeLong != 0)
     {
     block = new Block(cocos2d::CCSize(bar_blue->getContentSize().width,bar_blue->getContentSize().height),
     cocos2d::CCPoint(xPos,//halfLineXPostion
     startBlockPoint_copy ),
     scale,
     "hd/bar_blue/bar_blue_long_1.png",
     bar_blue,
     nodeLong,
     blockDivision,
     midiDivision);
     }
     else
     {
     block = new Block(cocos2d::CCSize(bar_blue->getContentSize().width,0),
     cocos2d::CCPoint(xPos,//halfLineXPostion
     startBlockPoint_copy ),
     scale,
     "",
     bar_blue,
     nodeLong,
     blockDivision,
     midiDivision);


     }

     block->lineNum = randXPosition;
     block->tag = block_count_copy;
     block->breakLine = breakLine;
     // Create the actions
     // Edited by AhnGun


     CCFiniteTimeAction* actionMove = CCMoveTo::create( (float)PianoSpeed,
     ccp(xPos,EndLineStartPoint.y-PIANO_BLOCK_DIST));

     CCCallFuncN::create( this,
     callfuncN_selector(GameManager::MoveFinished_copy));


     CCFiniteTimeAction* actionMoveDone = CCCallFuncND::create(this, callfuncND_selector(GameManager::MoveFinished_copy), (void*)(Singleton<GameManager>::GetInst()->_collision_boxes_Channel.size()));
     block->body->runAction( CCSequence::create(actionMove, actionMoveDone, NULL) );

     CCActionInterval*  actionBy = CCScaleBy::create(5, 0.2f, 0.2f);
     block->body->runAction( CCSequence::create(actionBy, NULL));

     block->body->setTag(block_count_copy);
     }
     else
     {
     //int white_index = whiteInPos(randXPosition);

     halfLineXPostion = BlockCenterPoint;// - (white_index*0.3);

     EndLineXPostion = DownBlockEndPosX[randXPosition];
     float xPos = EndLineXPostion;//+block->body->getContentSize().width*0.2f/2;
     float scale = 0.5f;

     if(nodeLong != 0)
     {
     block = new Block(cocos2d::CCSize(bar_yellow->getContentSize().width,bar_yellow->getContentSize().height),
     cocos2d::CCPoint(xPos,
     startBlockPoint_copy ),
     scale,
     "hd/bar_blue/bar_yellow_long_1.png",
     bar_yellow,
     nodeLong,
     blockDivision,
     midiDivision);
     }
     else
     {
     block = new Block(cocos2d::CCSize(bar_yellow->getContentSize().width,0),
     cocos2d::CCPoint(xPos,
     startBlockPoint_copy ),
     scale,
     "",
     bar_yellow,
     nodeLong,
     blockDivision,
     midiDivision);

     }


     block->lineNum = randXPosition;
     block->tag = block_count;
     block->breakLine = breakLine;


     CCFiniteTimeAction* actionMove = CCMoveTo::create( (float)PianoSpeed,
     ccp(xPos,EndLineStartPoint.y-PIANO_BLOCK_DIST));



     CCFiniteTimeAction* actionMoveDone = CCCallFuncND::create(this, callfuncND_selector(GameManager::MoveFinished_copy), (void*)Singleton<GameManager>::GetInst()->_collision_boxes_Channel.size());
     block->body->runAction( CCSequence::create(actionMove, actionMoveDone, NULL) );




     CCActionInterval*  actionBy = CCScaleBy::create(5, 0.2f, 0.2f);

     block->body->runAction( CCSequence::create(actionBy, NULL));


     block->body->setTag(block_count);
     }


     _collision_boxes_Channel.at(_collision_boxes_Channel.size()).push_back(block);
     // _collision_boxes_copy.push_back(block);
     //異���λ�� ��쇱�몃�� array ���以���� ��� ������ 留ㅼ묶��� �����댁��
     CCArray *line_block_collect_copy = dynamic_cast<CCArray*>(Singleton<GameManager>::GetInst()->line_block_collect_array_copy->objectAtIndex(nodeNum));
     line_block_collect_copy->addObject(block);
     ++block_count_copy;

     */
}
Block* GameManager::makeBlock(Block* block)
{
    if(block->doremipasolasi == 0)
    {
        block->body->setTexture(note_do_nomal);
    }
    else if(block->doremipasolasi == 1)
    {
        block->body->setTexture(note_re_nomal);
    }
    else if(block->doremipasolasi == 2)
    {
        block->body->setTexture(note_mi_nomal);
    }
    else if(block->doremipasolasi == 3)
    {
        block->body->setTexture(note_fa_nomal);
    }
    else if(block->doremipasolasi == 4)
    {
        block->body->setTexture(note_so_nomal);
    }
    else if(block->doremipasolasi == 5)
    {
        block->body->setTexture(note_la_nomal);
    }
    else if(block->doremipasolasi == 6)
    {
        block->body->setTexture(note_ti_nomal);
    }

    return block;
}
void GameManager::makeCollisinoBoxes(int nodeNum,double nodeLong,int blockDivision,int midiDivision,int ch,int _velocity,float elapsedMillis,double timePos)  // 1 : on   2 : off
{
    nodeYpos_timeMillis = (float)timePos/(float)10;
    //   CCLog("nodeYpos_timeMillis : %f",nodeYpos_timeMillis);
    //float nodeYpos_timeMillis = ((float)timePos/10);
    ++totalNodeCount;


    if(!channelState)
    {
        channelState = true;
        _collision_boxes_Channel.push_back(_collision_boxes);
    }

    if(blockDivision <= midiDivision)
    {
        //���留���� ��몃��
        //nodeLong = 0;
    }
    else
    {
        //湲� ��몃��
        //sprite 32 ��몃�� ��ъ�댁��
    }
    //������
    //CCLOG("makeCollisinoBoxes : %d   %f   ������ nodeLong ��쇰����� 0",nodeNum,nodeLong);
    //52/2 = 26
    //88

    int randXPosition = nodeNum;//( rand() % TOTAL_PIANO_COUNT );// 0~87
    float halfLineXPostion;
    float EndLineXPostion;
    Block *block;

    if(piano_array[randXPosition])
    {
        //        int white_index = whiteInPos(randXPosition-1);

        halfLineXPostion = BlockCenterPoint;// - (white_index*0.3);

        EndLineXPostion = DownBlockEndPosX[randXPosition];
        float xPos = EndLineXPostion;//+block->body->getContentSize().width*0.2f/2;
        //float scale = 2.0f;
        float scale = 0.5f;

        if(blockDivision > midiDivision)
        {
            if(Singleton<GameManager>::GetInst()->gameMode == NORMAL_GAME)
            {
                block = new Block(cocos2d::CCSize(bar_blue->getContentSize().width,0),
                                  cocos2d::CCPoint(CCDirector::sharedDirector()->getVisibleSize().width + nodeYpos_timeMillis,//halfLineXPostion
                                                   600),
                                  1,
                                  "hd/dragon_note/note_do_nomal.png",
                                  note_do_nomal,
                                  nodeLong,
                                  blockDivision,
                                  midiDivision,
                                  _velocity,
                                  elapsedMillis,
                                  timePos,
                                  0);

                block->print_layer = this->normal_block_cover_layer;
                block->doremipasolasi =  this->doremipasolasi(randXPosition);
                block->lineNum = block->doremipasolasi;
                block = this->makeBlock(block);
            }
            else
            {
                block = new Block(cocos2d::CCSize(bar_blue->getContentSize().width,bar_blue->getContentSize().height),
                                  cocos2d::CCPoint(xPos,//halfLineXPostion
                                                   startBlockPoint + nodeYpos_timeMillis),
                                  scale,
                                  "hd/bar_blue/bar_blue_long_1.png",
                                  bar_blue,
                                  nodeLong,
                                  blockDivision,
                                  midiDivision,
                                  _velocity,
                                  elapsedMillis,
                                  timePos,
                                  0);

                block->print_layer = this->block_layer;
                block->lineNum = randXPosition;

                block->EndPoint = CCPoint(xPos, EndLineStartPoint.y-PIANO_LONG_BLOCK_DIST);
            }
            // this->block_layer->addChild(block->tail);//���踰���� ���泥� ��몃�� �����곌린 ������
        }
        else
        {
            if(Singleton<GameManager>::GetInst()->gameMode == NORMAL_GAME)
            {
                block = new Block(cocos2d::CCSize(bar_blue->getContentSize().width,0),
                                  cocos2d::CCPoint(CCDirector::sharedDirector()->getVisibleSize().width + nodeYpos_timeMillis,//halfLineXPostion
                                                   600 ),
                                  1,
                                  "hd/dragon_note/note_do_nomal.png",
                                  note_do_nomal,
                                  nodeLong,
                                  blockDivision,
                                  midiDivision,
                                  _velocity,
                                  elapsedMillis,
                                  timePos,
                                  0);

                block->print_layer = this->normal_block_cover_layer;
                block->doremipasolasi =  this->doremipasolasi(randXPosition);
                block->lineNum = block->doremipasolasi;
                block = this->makeBlock(block);

            }
            else
            {
                block = new Block(cocos2d::CCSize(bar_blue->getContentSize().width,0),
                                  cocos2d::CCPoint(xPos,//halfLineXPostion
                                                   startBlockPoint + nodeYpos_timeMillis ),
                                  scale,
                                  "hd/bar_blue/bar_blue.png",
                                  bar_blue,
                                  nodeLong,
                                  blockDivision,
                                  midiDivision,
                                  _velocity,
                                  elapsedMillis,
                                  timePos,
                                  0);

                block->print_layer = this->block_layer;
                block->lineNum = randXPosition;

                block->EndPoint = CCPoint(xPos, EndLineStartPoint.y-PIANO_BLOCK_DIST);
            }
            //  this->block_layer->addChild(block->body);//���踰���� ���泥� ��몃�� �����곌린 ������
        }




        block->tag = block_count;
        block->breakLine = breakLine;
        block->channelNum = Singleton<GameManager>::GetInst()->_collision_boxes_Channel.size()-1;
    }
    else
    {
        //int white_index = whiteInPos(randXPosition);

        halfLineXPostion = BlockCenterPoint;// - (white_index*0.3);

        EndLineXPostion = DownBlockEndPosX[randXPosition];
        //        CCLog("EndLineXPostion : %f",EndLineXPostion);
        float xPos = EndLineXPostion;//+block->body->getContentSize().width*0.2f/2;
        //float scale = 2.0f;
        float scale = 0.5f;
        // CCLog("xPos : %f   %d",xPos,randXPosition);
        if(blockDivision > midiDivision)
        {
            if(Singleton<GameManager>::GetInst()->gameMode == NORMAL_GAME)
            {
                block = new Block(cocos2d::CCSize(bar_yellow->getContentSize().width,0),
                                  cocos2d::CCPoint(CCDirector::sharedDirector()->getVisibleSize().width + nodeYpos_timeMillis,
                                                   470 ),
                                  1,
                                  "hd/dragon_note/note_do_nomal.png",
                                  note_do_nomal,
                                  nodeLong,
                                  blockDivision,
                                  midiDivision,
                                  _velocity,
                                  elapsedMillis,
                                  timePos,
                                  0);

                block->print_layer = this->normal_block_cover_layer;
                block->doremipasolasi =  this->doremipasolasi(randXPosition);
                block->lineNum = block->doremipasolasi;
                block = this->makeBlock(block);
            }
            else
            {
                block = new Block(cocos2d::CCSize(bar_yellow->getContentSize().width,bar_yellow->getContentSize().height),
                                  cocos2d::CCPoint(xPos,
                                                   startBlockPoint + nodeYpos_timeMillis ),
                                  scale,
                                  "hd/bar_yellow/bar_yellow_long_1.png",
                                  bar_yellow,
                                  nodeLong,
                                  blockDivision,
                                  midiDivision,
                                  _velocity,
                                  elapsedMillis,
                                  timePos,
                                  0);

                block->print_layer = this->block_layer;
                block->lineNum = randXPosition;

                block->EndPoint = CCPoint(xPos, EndLineStartPoint.y-PIANO_LONG_BLOCK_DIST);
            }

            //  this->block_layer->addChild(block->tail); //���踰���� ���泥� ��몃�� �����곌린 ������

        }
        else
        {
            if(Singleton<GameManager>::GetInst()->gameMode == NORMAL_GAME)
            {
                block = new Block(cocos2d::CCSize(bar_yellow->getContentSize().width,0),
                                  cocos2d::CCPoint(CCDirector::sharedDirector()->getVisibleSize().width + nodeYpos_timeMillis,
                                                   470 ),
                                  1,
                                  "hd/dragon_note/note_do_nomal.png",
                                  note_do_nomal,
                                  nodeLong,
                                  blockDivision,
                                  midiDivision,
                                  _velocity,
                                  elapsedMillis,
                                  timePos,
                                  0);

                block->print_layer = this->normal_block_cover_layer;
                block->doremipasolasi =  this->doremipasolasi(randXPosition);
                block->lineNum = block->doremipasolasi;
                block = this->makeBlock(block);
            }
            else
            {
                block = new Block(cocos2d::CCSize(bar_yellow->getContentSize().width,0),
                                  cocos2d::CCPoint(xPos,
                                                   startBlockPoint + nodeYpos_timeMillis ),
                                  scale,
                                  "hd/bar_blue/bar_blue.png",
                                  bar_yellow,
                                  nodeLong,
                                  blockDivision,
                                  midiDivision,
                                  _velocity,
                                  elapsedMillis,
                                  timePos,
                                  0);

                block->print_layer = this->block_layer;
                block->lineNum = randXPosition;

                block->EndPoint = CCPoint(xPos, EndLineStartPoint.y-PIANO_BLOCK_DIST);

            }

            //  this->block_layer->addChild(block->body); //���踰���� ���泥� ��몃�� �����곌린 ������

        }
        
        
        block->tag = block_count;
        block->breakLine = breakLine;
        
        block->channelNum = Singleton<GameManager>::GetInst()->_collision_boxes_Channel.size()-1;
    }

    if(_erase_print_blocks[timePos] == 0)
    {
        _erase_print_blocks[timePos] = block;
        _guide_print_blocks[timePos] = block;
        _print_blocks[timePos] = block;
        equalLineBlockCount = 0;
    }
    else
    {
        ++equalLineBlockCount;
        timePos = timePos + (equalLineBlockCount * 0.0001);
        _erase_print_blocks[timePos] = block;
        _guide_print_blocks[timePos] = block;
        _print_blocks[timePos] = block;
    }


    _collision_boxes_Channel.at(_collision_boxes_Channel.size()-1).push_back(block);

    //異���λ�� ��쇱�몃�� array ���以���� ��� ������ 留ㅼ묶��� �����댁��

    if(gameMode == NORMAL_GAME)
    {
        CCArray *line_block_collect = dynamic_cast<CCArray*>(Singleton<GameManager>::GetInst()->line_block_collect_array->objectAtIndex(this->doremipasolasi(randXPosition)));
        line_block_collect->addObject(block);
        //CCLog("this->doremipasolasi(randXPosition) : %d",this->doremipasolasi(randXPosition));
    }
    else
    {
        
        CCArray *line_block_collect = dynamic_cast<CCArray*>(Singleton<GameManager>::GetInst()->line_block_collect_array->objectAtIndex(nodeNum));
        line_block_collect->addObject(block);
    }

    ++block_count;





}
void GameManager::_9Sprite_MoveFinished_copy(Block *destBlock)
{
    /*
     CCScale9Sprite *sprite = (CCScale9Sprite *)sender;
     nodePrintLayer_copy->removeChild(sprite, true);

     std::vector<Block *> _collision_boxes_copy = _collision_boxes_Channel_copy.at(channel);
     Block *target =  _collision_boxes_copy.at(removeNodeCount_copy.at(channel));

     if(deleteGuideCount_copy.at(channel) == removeNodeCount_copy.at(channel))
     {
     CCArray *guide_Total_Array_copy = guide_Total_Array_channel_copy.at(channel);
     CCArray *guide_Value_Array_copy = dynamic_cast<CCArray*>( guide_Total_Array_copy->objectAtIndex(target->breakLine));

     for (int a=0; a<guide_Value_Array_copy->count(); a++)
     {
     CCInteger *test = (CCInteger*)guide_Value_Array_copy->objectAtIndex(a);
     //CCLOG("test : %d",test->getValue());

     Block *target =  _collision_boxes_copy.at(test->getValue());

     piano_guid_sprite_copy[target->lineNum]->setVisible(false);
     ++deleteGuideCount_copy.at(channel);
     // CCLOG("dele : %d",target->lineNum);
     }

     if(guide_Total_Array_copy->count() > target->breakLine+1)
     {
     guide_Value_Array_copy = dynamic_cast<CCArray*>( guide_Total_Array_copy->objectAtIndex(target->breakLine+1));

     for (int a=0; a<guide_Value_Array_copy->count(); a++)
     {
     CCInteger *test = (CCInteger*)guide_Value_Array_copy->objectAtIndex(a);

     Block *target =  _collision_boxes_copy.at(test->getValue());

     this->pianoGuideVisible_copy(target->lineNum);

     //CCLOG("view : %d",target->lineNum);
     }
     }
     }





     CCArray *line_block_collect_copy = dynamic_cast<CCArray*>(Singleton<GameManager>::GetInst()->line_block_collect_array_copy->objectAtIndex(target->lineNum));
     line_block_collect_copy->removeObjectAtIndex(0);

     target->release();

     ++removeNodeCount_copy.at(channel);
     if(!target->col_check)
     {
     this->missMatch_copy();
     }



     CCFadeOut *fadeout = CCFadeOut::create(0.8);

     grade_copy->runAction( CCSequence::create(fadeout, NULL) );
     */
}
void GameManager::MoveFinished_copy(Block *destBlock)
{//醫�猷�
    /*
     CCSprite *sprite = (CCSprite *)sender;
     nodePrintLayer_copy->removeChild(sprite, true);

     std::vector<Block *> _collision_boxes_copy = _collision_boxes_Channel_copy.at(channel);
     Block *target =  _collision_boxes_copy.at(removeNodeCount_copy.at(channel));

     if(deleteGuideCount_copy.at(channel) == removeNodeCount_copy.at(channel))
     {
     CCArray *guide_Total_Array_copy = guide_Total_Array_channel_copy.at(channel);
     CCArray *guide_Value_Array_copy = dynamic_cast<CCArray*>( guide_Total_Array_copy->objectAtIndex(target->breakLine));

     for (int a=0; a<guide_Value_Array_copy->count(); a++)
     {
     CCInteger *test = (CCInteger*)guide_Value_Array_copy->objectAtIndex(a);
     //CCLOG("test : %d",test->getValue());

     Block *target =  _collision_boxes_copy.at(test->getValue());

     piano_guid_sprite_copy[target->lineNum]->setVisible(false);
     ++deleteGuideCount_copy.at(channel);
     // CCLOG("dele : %d",target->lineNum);
     }

     if(guide_Total_Array_copy->count() > target->breakLine+1)
     {
     guide_Value_Array_copy = dynamic_cast<CCArray*>( guide_Total_Array_copy->objectAtIndex(target->breakLine+1));

     for (int a=0; a<guide_Value_Array_copy->count(); a++)
     {
     CCInteger *test = (CCInteger*)guide_Value_Array_copy->objectAtIndex(a);

     Block *target =  _collision_boxes_copy.at(test->getValue());

     this->pianoGuideVisible_copy(target->lineNum);

     //CCLOG("view : %d",target->lineNum);
     }
     }
     }





     CCArray *line_block_collect_copy = dynamic_cast<CCArray*>(Singleton<GameManager>::GetInst()->line_block_collect_array_copy->objectAtIndex(target->lineNum));
     line_block_collect_copy->removeObjectAtIndex(0);

     target->release();

     ++removeNodeCount_copy.at(channel);
     if(!target->col_check)
     {
     this->missMatch_copy();
     }



     CCFadeOut *fadeout = CCFadeOut::create(0.8);

     grade_copy->runAction( CCSequence::create(fadeout, NULL) );
     */
}

void GameManager::_9Sprite_MoveFinished(Block *destBlock)
{

    //醫�猷�
    int channel = destBlock->channelNum;
    //CCLog("_9Sprite_MoveFinished channel : %d",channel);
	destBlock->print_layer->removeChild(destBlock->tail, true);

    std::vector<Block *> _collision_boxes_finish = _collision_boxes_Channel.at(channel);
    //��ъ�명�� 臾몄��..
    if(_collision_boxes_finish.size() > removeNodeCount.at(channel))
    {
        Block *deletetarget =  _collision_boxes_finish.at(removeNodeCount.at(channel));

        CCArray *line_block_collect = dynamic_cast<CCArray*>(Singleton<GameManager>::GetInst()->line_block_collect_array->objectAtIndex(deletetarget->lineNum));
        line_block_collect->removeObjectAtIndex(0);

        ++removeNodeCount.at(channel);
        if(gameMode != NORMAL_GAME)
        {
            if(!deletetarget->col_check)
            {
                this->missMatch();
            }

            CCFadeOut *fadeout = CCFadeOut::create(0.8);
            grade->runAction( CCSequence::create(fadeout, NULL) );
        }
    }
}
void GameManager::MoveFinished(Block *destBlock)
{
	this->missMatch();
	/*
    int channel = destBlock->channelNum;

    destBlock->print_layer->removeChild(destBlock->body, true);


    std::vector<Block *> _collision_boxes_finish = _collision_boxes_Channel.at(channel);

    if(_collision_boxes_finish.size() > removeNodeCount.at(channel))
    {
        Block *deletetarget =  _collision_boxes_finish.at(removeNodeCount.at(channel));


        CCArray *line_block_collect = dynamic_cast<CCArray*>(Singleton<GameManager>::GetInst()->line_block_collect_array->objectAtIndex(deletetarget->lineNum));
        line_block_collect->removeObjectAtIndex(0);
        
        
        CCFadeOut *fadeout = CCFadeOut::create(0.8);
        grade->runAction( CCSequence::create(fadeout, NULL) );
        
        
        ++removeNodeCount.at(channel);
        
        if(!deletetarget->col_check)
        {
            this->missMatch();
        }
    }
    CC_SAFE_RELEASE_NULL(destBlock->body);
    CC_SAFE_RELEASE_NULL(destBlock);
*/
}

void GameManager::gradeHide()
{
    CCLOG("gradeHide");
    grade->setVisible(false);
}
void GameManager::gradeHide_copy()
{
    CCLOG("grade_copy hide");
    grade_copy->setVisible(false);
}



void GameManager::x1SpeedButtonPress()
{
    x1SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x1_non.png"));
    x2SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x2_non.png"));
    x12SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x12_non.png"));
    x14SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x14_non.png"));


    x1SpeedButton->selected();
    x2SpeedButton->unselected();
    x12SpeedButton->unselected();
    x14SpeedButton->unselected();

    if(Singleton<GameManager>::GetInst()->gameMode==NORMAL_GAME)
    {
        gameSpeed = 2.0f;
    }
    else
    {
        gameSpeed = 1.0f;
    }

    /*
     progressToZero = CCProgressFromTo::create((maxTime + TIMEDELAY + PIANO_FINISH_TIME) * 8.0f - stateTime*8, Singleton<GameManager>::GetInst()->timeBar->getPercentage(), 0);
     Singleton<GameManager>::GetInst()->timeBar->runAction(Singleton<GameManager>::GetInst()->progressToZero);
     */
}

void GameManager::x2SpeedButtonPress()
{
    x1SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x1_non.png"));
    x2SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x2_non.png"));
    x12SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x12_non.png"));
    x14SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x14_non.png"));

    x1SpeedButton->unselected();
    x2SpeedButton->selected();
    x12SpeedButton->unselected();
    x14SpeedButton->unselected();

    if(Singleton<GameManager>::GetInst()->gameMode==NORMAL_GAME)
    {
        gameSpeed = 4.0f;
    }
    else
    {
        gameSpeed = 2.0f;
    }
    /*
     progressToZero = CCProgressFromTo::create((maxTime + TIMEDELAY + PIANO_FINISH_TIME) * 4.0f - stateTime*4, Singleton<GameManager>::GetInst()->timeBar->getPercentage(), 0);
     Singleton<GameManager>::GetInst()->timeBar->runAction(Singleton<GameManager>::GetInst()->progressToZero);
     */
}
void GameManager::x12SpeedButtonPress()
{
    x1SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x1_non.png"));
    x2SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x2_non.png"));
    x12SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x12_non.png"));
    x14SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x14_non.png"));

    x1SpeedButton->unselected();
    x2SpeedButton->unselected();
    x12SpeedButton->selected();
    x14SpeedButton->unselected();


    if(Singleton<GameManager>::GetInst()->gameMode==NORMAL_GAME)
    {
        gameSpeed = 1.0f;
    }
    else
    {
        gameSpeed = 0.5f;
    }

    /*
     progressToZero = CCProgressFromTo::create((maxTime + TIMEDELAY + PIANO_FINISH_TIME) * 2.0f - stateTime*2, Singleton<GameManager>::GetInst()->timeBar->getPercentage(), 0);
     Singleton<GameManager>::GetInst()->timeBar->runAction(Singleton<GameManager>::GetInst()->progressToZero);
     */


}
void GameManager::x14SpeedButtonPress()
{
    x1SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x1_non.png"));
    x2SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x2_non.png"));
    x12SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x12_non.png"));
    x14SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x14_non.png"));

    x1SpeedButton->unselected();
    x2SpeedButton->unselected();
    x12SpeedButton->unselected();
    x14SpeedButton->selected();

    if(Singleton<GameManager>::GetInst()->gameMode==NORMAL_GAME)
    {
        gameSpeed = 0.5f;
    }
    else
    {
        gameSpeed = 0.25f;
    }

    /*
     progressToZero = CCProgressFromTo::create(maxTime + TIMEDELAY + PIANO_FINISH_TIME - stateTime, Singleton<GameManager>::GetInst()->timeBar->getPercentage(), 0);
     Singleton<GameManager>::GetInst()->timeBar->runAction(Singleton<GameManager>::GetInst()->progressToZero);
     */
}

void GameManager::x1SpeedButtonPress_copy()
{
    /*
     x1SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x1_non.png"));
     x2SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x2_non.png"));
     x3SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x3_non.png"));
     x4SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x4_non.png"));

     x1SpeedButton->selected();
     x2SpeedButton->unselected();
     x3SpeedButton->unselected();
     x4SpeedButton->unselected();


     CCDirector::sharedDirector()->getScheduler()->setTimeScale(0.125);
     gameSpeed = 0.125f;
     */
}

void GameManager::x2SpeedButtonPress_copy()
{
    /*
     x1SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x1_non.png"));
     x2SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x2_non.png"));
     x3SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x3_non.png"));
     x4SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x4_non.png"));

     x1SpeedButton->unselected();
     x2SpeedButton->selected();
     x3SpeedButton->unselected();
     x4SpeedButton->unselected();

     CCDirector::sharedDirector()->getScheduler()->setTimeScale(0.25);
     gameSpeed = 0.25f;
     */
}
/*
 void GameManager::x3SpeedButtonPress_copy()
 {

 x1SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x1_non.png"));
 x2SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x2_non.png"));
 x3SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x3_non.png"));
 x4SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x4_non.png"));

 x1SpeedButton->unselected();
 x2SpeedButton->unselected();
 x3SpeedButton->selected();
 x4SpeedButton->unselected();

 CCDirector::sharedDirector()->getScheduler()->setTimeScale(0.5);
 gameSpeed = 0.5f;

 }
 void GameManager::x4SpeedButtonPress_copy()
 {
 x1SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x1_non.png"));
 x2SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x2_non.png"));
 x3SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x3_non.png"));
 x4SpeedButton->setNormalImage(CCSprite::create("hd/btn_speed_x4_non.png"));

 x1SpeedButton->unselected();
 x2SpeedButton->unselected();
 x3SpeedButton->unselected();
 x4SpeedButton->selected();

 CCDirector::sharedDirector()->getScheduler()->setTimeScale(1);
 gameSpeed = 1.0f;

 }
 */
void GameManager::pauseButtonPress()
{

    if(CCDirector::sharedDirector()->isPaused())
    {
        stopButton->setVisible(false);
        CCDirector::sharedDirector()->startAnimation();
        CCDirector::sharedDirector()->resume();
    }
    else
    {
        stopButton->setVisible(true);
        CCDirector::sharedDirector()->stopAnimation();
        CCDirector::sharedDirector()->pause();
    }
}
void GameManager::resumeButtonPress()
{

}
void GameManager::escButtonPress()
{
    this->game_wait_end();
}

void GameManager::pianoNormalButtonPress()
{
    CCLOG("pianoNormalButtonPress");
    //jdm
    remoteUpDownOverPosition = 1;

    pianoRainbowButton->setNormalImage(CCSprite::create("hd/btn_color.png"));
    pianoMarkButton->setNormalImage(CCSprite::create("hd/btn_mark.png"));
    pianoNormalButton->setNormalImage(CCSprite::create("hd/btn_nomal.png"));

    pianoRainbowButton->unselected();
    pianoMarkButton->unselected();
    pianoNormalButton->selected();

    pianoBG->setTexture(pianoBG_tex[2]);
    if(gameMode != SINGE_FREE)
    {
        for(int index = 0;index<88;index++)
        {
            draw_line[index]->setColor(ccc3(255, 255, 255));
        }
    }

}
void GameManager::pianoMarkButtonPress()
{
    CCLOG("pianoMarkButtonPress");

    remoteUpDownOverPosition = 2;

    pianoRainbowButton->setNormalImage(CCSprite::create("hd/btn_color.png"));
    pianoMarkButton->setNormalImage(CCSprite::create("hd/btn_mark.png"));
    pianoNormalButton->setNormalImage(CCSprite::create("hd/btn_nomal.png"));

    pianoRainbowButton->unselected();
    pianoMarkButton->selected();
    pianoNormalButton->unselected();

    pianoBG->setTexture(pianoBG_tex[1]);
    if(gameMode != SINGE_FREE)
    {
        for(int index = 0;index<88;index++)
        {
            draw_line[index]->setColor(ccc3(255, 255, 255));
        }
    }
}
void GameManager::pianoRainbowButtonPress()
{
    CCLOG("pianoRainbowButtonPress");

    remoteUpDownOverPosition = 3;


    pianoRainbowButton->setNormalImage(CCSprite::create("hd/btn_color.png"));
    pianoMarkButton->setNormalImage(CCSprite::create("hd/btn_mark.png"));
    pianoNormalButton->setNormalImage(CCSprite::create("hd/btn_nomal.png"));

    pianoRainbowButton->selected();
    pianoMarkButton->unselected();
    pianoNormalButton->unselected();

    pianoBG->setTexture(pianoBG_tex[0]);
    if(gameMode != SINGE_FREE)
    {
        for(int index = 0;index<88;index++)
        {
            this->rainbowColorInit(index);
        }
    }
}


void GameManager::acousticButtonPress()
{
    CCLOG("acousticButtonPress");

    acousticButton->setNormalImage(CCSprite::create("hd/btn_acoustic_grand_piano.png"));
    brightButton->setNormalImage(CCSprite::create("hd/btn_bright_acoustic_piano.png"));
    chorusButton->setNormalImage(CCSprite::create("hd/btn_chorus_piano.png"));
    electricButton->setNormalImage(CCSprite::create("hd/btn_electric_piano.png"));
    hongkyButton->setNormalImage(CCSprite::create("hd/btn_hongky_tonky_piano.png"));
    rhodesButton->setNormalImage(CCSprite::create("hd/btn_Rhodes_piano.png"));

    acousticButton->selected();
    brightButton->unselected();
    chorusButton->unselected();
    electricButton->unselected();
    hongkyButton->unselected();
    rhodesButton->unselected();

    if(gameMode == ANG_FREE || gameMode == ANG_GAME) // ang
    {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        JniMethodInfo t;
        if (JniHelper::getMethodInfo(t
                                     , "com/shfactory/musicblood/solo/MultipleGame"
                                     , "javaAcousticButtonPress"
                                     , "(I)V"))
        {
            ///< 占썩�ο옙 占쎈��占�
            //perfectSocre
            t.env->CallVoidMethod(Singleton<GameManager>::GetInst()->javaObj, t.methodID, 1);
            ///< Release
            t.env->DeleteLocalRef(t.classID);
        }
#endif
    }
    else
    {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        JniMethodInfo t;
        if (JniHelper::getMethodInfo(t
                                     , "com/shfactory/musicblood/solo/SimpleGame"
                                     , "javaAcousticButtonPress"
                                     , "(I)V"))
        {
            ///< 占썩�ο옙 占쎈��占�
            //perfectSocre
            t.env->CallVoidMethod(Singleton<GameManager>::GetInst()->javaObj, t.methodID, 1);
            ///< Release
            t.env->DeleteLocalRef(t.classID);
        }
#endif
    }



}
void GameManager::brightButtonPress()
{
    CCLOG("brightButtonPress");

    acousticButton->setNormalImage(CCSprite::create("hd/btn_acoustic_grand_piano.png"));
    brightButton->setNormalImage(CCSprite::create("hd/btn_bright_acoustic_piano.png"));
    chorusButton->setNormalImage(CCSprite::create("hd/btn_chorus_piano.png"));
    electricButton->setNormalImage(CCSprite::create("hd/btn_electric_piano.png"));
    hongkyButton->setNormalImage(CCSprite::create("hd/btn_hongky_tonky_piano.png"));
    rhodesButton->setNormalImage(CCSprite::create("hd/btn_Rhodes_piano.png"));

    acousticButton->unselected();
    brightButton->selected();
    chorusButton->unselected();
    electricButton->unselected();
    hongkyButton->unselected();
    rhodesButton->unselected();

    if(gameMode == ANG_FREE || gameMode == ANG_GAME) // ang
    {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        JniMethodInfo t;
        if (JniHelper::getMethodInfo(t
                                     , "com/shfactory/musicblood/solo/MultipleGame"
                                     , "javaBrightButtonPress"
                                     , "(I)V"))
        {
            ///< 占썩�ο옙 占쎈��占�
            //perfectSocre
            t.env->CallVoidMethod(Singleton<GameManager>::GetInst()->javaObj, t.methodID, 1);
            ///< Release
            t.env->DeleteLocalRef(t.classID);
        }
#endif
    }
    else
    {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        JniMethodInfo t;
        if (JniHelper::getMethodInfo(t
                                     , "com/shfactory/musicblood/solo/SimpleGame"
                                     , "javaBrightButtonPress"
                                     , "(I)V"))
        {
            ///< 占썩�ο옙 占쎈��占�
            //perfectSocre
            t.env->CallVoidMethod(Singleton<GameManager>::GetInst()->javaObj, t.methodID, 1);
            ///< Release
            t.env->DeleteLocalRef(t.classID);
        }
#endif
    }
}
void GameManager::chorusButtonPress()
{
    CCLOG("chorusButtonPress");
    acousticButton->setNormalImage(CCSprite::create("hd/btn_acoustic_grand_piano.png"));
    brightButton->setNormalImage(CCSprite::create("hd/btn_bright_acoustic_piano.png"));
    chorusButton->setNormalImage(CCSprite::create("hd/btn_chorus_piano.png"));
    electricButton->setNormalImage(CCSprite::create("hd/btn_electric_piano.png"));
    hongkyButton->setNormalImage(CCSprite::create("hd/btn_hongky_tonky_piano.png"));
    rhodesButton->setNormalImage(CCSprite::create("hd/btn_Rhodes_piano.png"));

    acousticButton->unselected();
    brightButton->unselected();
    chorusButton->selected();
    electricButton->unselected();
    hongkyButton->unselected();
    rhodesButton->unselected();

    if(gameMode == ANG_FREE || gameMode == ANG_GAME) // ang
    {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        JniMethodInfo t;
        if (JniHelper::getMethodInfo(t
                                     , "com/shfactory/musicblood/solo/MultipleGame"
                                     , "javaChorusButtonPress"
                                     , "(I)V"))
        {
            ///< 占썩�ο옙 占쎈��占�
            //perfectSocre
            t.env->CallVoidMethod(Singleton<GameManager>::GetInst()->javaObj, t.methodID, 1);
            ///< Release
            t.env->DeleteLocalRef(t.classID);
        }
#endif
    }
    else
    {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        JniMethodInfo t;
        if (JniHelper::getMethodInfo(t
                                     , "com/shfactory/musicblood/solo/SimpleGame"
                                     , "javaChorusButtonPress"
                                     , "(I)V"))
        {
            ///< 占썩�ο옙 占쎈��占�
            //perfectSocre
            t.env->CallVoidMethod(Singleton<GameManager>::GetInst()->javaObj, t.methodID, 1);
            ///< Release
            t.env->DeleteLocalRef(t.classID);
        }
#endif
        
    }
}
void GameManager::electricButtonPress()
{
    CCLOG("electricButtonPress");

    acousticButton->setNormalImage(CCSprite::create("hd/btn_acoustic_grand_piano.png"));
    brightButton->setNormalImage(CCSprite::create("hd/btn_bright_acoustic_piano.png"));
    chorusButton->setNormalImage(CCSprite::create("hd/btn_chorus_piano.png"));
    electricButton->setNormalImage(CCSprite::create("hd/btn_electric_piano.png"));
    hongkyButton->setNormalImage(CCSprite::create("hd/btn_hongky_tonky_piano.png"));
    rhodesButton->setNormalImage(CCSprite::create("hd/btn_Rhodes_piano.png"));

    acousticButton->unselected();
    brightButton->unselected();
    chorusButton->unselected();
    electricButton->selected();
    hongkyButton->unselected();
    rhodesButton->unselected();

    if(gameMode == ANG_FREE || gameMode == ANG_GAME) // ang
    {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        JniMethodInfo t;
        if (JniHelper::getMethodInfo(t
                                     , "com/shfactory/musicblood/solo/MultipleGame"
                                     , "javaElectricButtonPress"
                                     , "(I)V"))
        {
            ///< 占썩�ο옙 占쎈��占�
            //perfectSocre
            t.env->CallVoidMethod(Singleton<GameManager>::GetInst()->javaObj, t.methodID, 1);
            ///< Release
            t.env->DeleteLocalRef(t.classID);
        }
#endif
    }
    else
    {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        JniMethodInfo t;
        if (JniHelper::getMethodInfo(t
                                     , "com/shfactory/musicblood/solo/SimpleGame"
                                     , "javaElectricButtonPress"
                                     , "(I)V"))
        {
            ///< 占썩�ο옙 占쎈��占�
            //perfectSocre
            t.env->CallVoidMethod(Singleton<GameManager>::GetInst()->javaObj, t.methodID, 1);
            ///< Release
            t.env->DeleteLocalRef(t.classID);
        }
#endif
    }

}
void GameManager::hongkyButtonPress()
{
    CCLOG("hongkyButtonPress");

    acousticButton->setNormalImage(CCSprite::create("hd/btn_acoustic_grand_piano.png"));
    brightButton->setNormalImage(CCSprite::create("hd/btn_bright_acoustic_piano.png"));
    chorusButton->setNormalImage(CCSprite::create("hd/btn_chorus_piano.png"));
    electricButton->setNormalImage(CCSprite::create("hd/btn_electric_piano.png"));
    hongkyButton->setNormalImage(CCSprite::create("hd/btn_hongky_tonky_piano.png"));
    rhodesButton->setNormalImage(CCSprite::create("hd/btn_Rhodes_piano.png"));

    acousticButton->unselected();
    brightButton->unselected();
    chorusButton->unselected();
    electricButton->unselected();
    hongkyButton->selected();
    rhodesButton->unselected();

    if(gameMode == ANG_FREE || gameMode == ANG_GAME) // ang
    {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        JniMethodInfo t;
        if (JniHelper::getMethodInfo(t
                                     , "com/shfactory/musicblood/solo/MultipleGame"
                                     , "javaHongkyButtonPress"
                                     , "(I)V"))
        {
            ///< 占썩�ο옙 占쎈��占�
            //perfectSocre
            t.env->CallVoidMethod(Singleton<GameManager>::GetInst()->javaObj, t.methodID, 1);
            ///< Release
            t.env->DeleteLocalRef(t.classID);
        }
#endif
    }
    else
    {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        JniMethodInfo t;
        if (JniHelper::getMethodInfo(t
                                     , "com/shfactory/musicblood/solo/SimpleGame"
                                     , "javaHongkyButtonPress"
                                     , "(I)V"))
        {
            ///< 占썩�ο옙 占쎈��占�
            //perfectSocre
            t.env->CallVoidMethod(Singleton<GameManager>::GetInst()->javaObj, t.methodID, 1);
            ///< Release
            t.env->DeleteLocalRef(t.classID);
        }
#endif
    }
}
void GameManager::rhodesButtonPress()
{
    CCLOG("rhodesButtonPress");

    acousticButton->setNormalImage(CCSprite::create("hd/btn_acoustic_grand_piano.png"));
    brightButton->setNormalImage(CCSprite::create("hd/btn_bright_acoustic_piano.png"));
    chorusButton->setNormalImage(CCSprite::create("hd/btn_chorus_piano.png"));
    electricButton->setNormalImage(CCSprite::create("hd/btn_electric_piano.png"));
    hongkyButton->setNormalImage(CCSprite::create("hd/btn_hongky_tonky_piano.png"));
    rhodesButton->setNormalImage(CCSprite::create("hd/btn_Rhodes_piano.png"));

    acousticButton->unselected();
    brightButton->unselected();
    chorusButton->unselected();
    electricButton->unselected();
    hongkyButton->unselected();
    rhodesButton->selected();

    if(gameMode == ANG_FREE || gameMode == ANG_GAME) // ang
    {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        JniMethodInfo t;
        if (JniHelper::getMethodInfo(t
                                     , "com/shfactory/musicblood/solo/MultipleGame"
                                     , "javaRhodesButtonPress"
                                     , "(I)V"))
        {
            ///< 占썩�ο옙 占쎈��占�
            //perfectSocre
            t.env->CallVoidMethod(Singleton<GameManager>::GetInst()->javaObj, t.methodID, 1);
            ///< Release
            t.env->DeleteLocalRef(t.classID);
        }
#endif
    }
    else
    {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        JniMethodInfo t;
        if (JniHelper::getMethodInfo(t
                                     , "com/shfactory/musicblood/solo/SimpleGame"
                                     , "javaRhodesButtonPress"
                                     , "(I)V"))
        {
            ///< 占썩�ο옙 占쎈��占�
            //perfectSocre
            t.env->CallVoidMethod(Singleton<GameManager>::GetInst()->javaObj, t.methodID, 1);
            ///< Release
            t.env->DeleteLocalRef(t.classID);
        }
#endif
    }
}


void GameManager::resourceMenuSceneClean()
{


}
void GameManager::resourceLoadSceneClean()
{
    /*
     LoadBG->release();

     load_timer_gaze->release();
     load_timeBar->release();
     */
}
void GameManager::resourceGameSceneClean()
{
	_print_blocks.clear();
    CCLog("aaa1");
    std::vector<Block *>::iterator iter;
    for(iter = Singleton<GameManager>::GetInst()->_collision_boxes_copy.begin(); iter != Singleton<GameManager>::GetInst()->_collision_boxes_copy.end(); ++iter)
    {
        CC_SAFE_RELEASE_NULL((*iter)->body);
        CC_SAFE_RELEASE_NULL((*iter)->tail);
        delete (*iter);
    }
    _collision_boxes_copy.clear();

    for(iter = Singleton<GameManager>::GetInst()->_collision_boxes.begin(); iter != Singleton<GameManager>::GetInst()->_collision_boxes.end(); ++iter)
    {
        CC_SAFE_RELEASE_NULL((*iter)->body);
        CC_SAFE_RELEASE_NULL((*iter)->tail);
        delete (*iter);
    }
    _collision_boxes.clear();
    CCLog("aaa2");

    std::vector<int> intClear;
    midiChannel_seq.swap(intClear);
    midiChannel_seq.clear();

    removeNodeCount.swap(intClear);
    removeNodeCount.clear();

    removeNodeCount_copy.swap(intClear);
    removeNodeCount_copy.clear();

    printChannel.swap(intClear);
    printChannel.clear();

    deleteGuideCount.swap(intClear);
    deleteGuideCount.clear();

    deleteGuideCount_copy.swap(intClear);
    deleteGuideCount_copy.clear();

    nodePrintCount_Channel.swap(intClear);
    nodePrintCount_Channel.clear();

    nodePrintCount_Channel_copy.swap(intClear);
    nodePrintCount_Channel_copy.clear();

    CCLog("aaa3");

    std::vector<noteData> noteDataClear;
    for(int a=0;a<midiChannel.size();a++)
    {
        midiChannel.at(a).swap(noteDataClear);
        midiChannel.at(a).clear();
    }

    std::vector<std::vector<noteData> > noteDataClear1;
    midiChannel.swap(noteDataClear1);
    midiChannel.clear();

    CCLog("aaa4");
    for(int a=0;a<_collision_boxes_Channel.size();a++)
    {
        std::vector<Block *>::iterator iter;
        for(iter =  _collision_boxes_Channel.at(a).begin(); iter !=  _collision_boxes_Channel.at(a).end(); ++iter)
        {
            if((*iter)->body != NULL)
            {
                CC_SAFE_RELEASE_NULL((*iter)->body);
            }
            if((*iter)->tail != NULL)
            {
                CC_SAFE_RELEASE_NULL((*iter)->tail);
            }
            delete (*iter);

        }
        _collision_boxes_Channel.at(a).clear();
    }
    _collision_boxes_Channel.clear();


    for(int a=0;a<_collision_boxes_Channel_copy.size();a++)
    {
        std::vector<Block *>::iterator iter;
        for(iter =  _collision_boxes_Channel_copy.at(a).begin(); iter !=  _collision_boxes_Channel_copy.at(a).end(); ++iter)
        {
            if((*iter)->body != NULL)
            {
                CC_SAFE_RELEASE_NULL((*iter)->body);
            }
            if((*iter)->tail != NULL)
            {
                CC_SAFE_RELEASE_NULL((*iter)->tail);
            }
            delete (*iter);
        }
        _collision_boxes_Channel_copy.at(a).clear();
    }
    _collision_boxes_Channel.clear();




    guide_Total_Array_channel.clear();


    guide_Total_Array_channel_copy.clear();



    CCLog("aaa5");






    if(gameMode == SINGE_FREE)
    {
    	CC_SAFE_RELEASE_NULL(LoadBG);
		CC_SAFE_RELEASE_NULL(load_line);
		for(int i=0;i<17;i++)
		{
			CC_SAFE_RELEASE_NULL(load_timer_gaze[i]);
		}
		CC_SAFE_RELEASE_NULL(load_timer_gaze_tex[0]);
		CC_SAFE_RELEASE_NULL(load_timer_gaze_tex[1]);
		CC_SAFE_RELEASE_NULL(load_timer_gaze_tex[2]);
		CC_SAFE_RELEASE_NULL(load_timer_gaze_tex[3]);
        
        CC_SAFE_RELEASE_NULL(btn_key_yellow_press_1);
        CC_SAFE_RELEASE_NULL(btn_key_yellow_press_2);
        CC_SAFE_RELEASE_NULL(btn_key_yellow_press_3);
        CC_SAFE_RELEASE_NULL(btn_key_yellow_press_4);
        CC_SAFE_RELEASE_NULL(btn_black_key_press);


        CC_SAFE_RELEASE_NULL(LoadBG_Free);

        
        CC_SAFE_RELEASE_NULL(pianoBG);
        
        CC_SAFE_RELEASE_NULL(pianoBG_tex[0]);
        CC_SAFE_RELEASE_NULL(pianoBG_tex[1]);
        CC_SAFE_RELEASE_NULL(pianoBG_tex[2]);
        
        
        CC_SAFE_RELEASE_NULL(menu);
        
        
        
        for(int i=0;i<88;i++)
        {
            CC_SAFE_RELEASE_NULL(piano_press_sprite[i]);
            CC_SAFE_RELEASE_NULL(piano_rainbow_press_sprite[i]);
        }


    }
    if(gameMode == SINGE_GAME)
    {
        CC_SAFE_RELEASE_NULL(LoadBG);
		CC_SAFE_RELEASE_NULL(load_line);
		for(int i=0;i<17;i++)
		{
			CC_SAFE_RELEASE_NULL(load_timer_gaze[i]);
		}
		CC_SAFE_RELEASE_NULL(load_timer_gaze_tex[0]);
		CC_SAFE_RELEASE_NULL(load_timer_gaze_tex[1]);
		CC_SAFE_RELEASE_NULL(load_timer_gaze_tex[2]);
		CC_SAFE_RELEASE_NULL(load_timer_gaze_tex[3]);

        CC_SAFE_RELEASE_NULL(tutorial_bg);
        CC_SAFE_RELEASE_NULL(tutorial_piano[0]);
        CC_SAFE_RELEASE_NULL(tutorial_piano[1]);
        CC_SAFE_RELEASE_NULL(tutorial_piano[2]);
        CC_SAFE_RELEASE_NULL(tutorial_piano[3]);
        CC_SAFE_RELEASE_NULL(tutorial_piano[4]);
        CC_SAFE_RELEASE_NULL(tutorial_piano[5]);
        CC_SAFE_RELEASE_NULL(tutorial_piano[6]);

        CC_SAFE_RELEASE_NULL(tutorialMent1);
        CC_SAFE_RELEASE_NULL(tutorialMent2);
        CC_SAFE_RELEASE_NULL(tutorialMent3);
        CC_SAFE_RELEASE_NULL(tutorialMent4);
        CC_SAFE_RELEASE_NULL(tutorialMent5);
        CC_SAFE_RELEASE_NULL(tutorialMent6);
        CC_SAFE_RELEASE_NULL(tutorialMent7);
        CC_SAFE_RELEASE_NULL(tutorialMent8);

        CC_SAFE_RELEASE_NULL(blackcover);
        
        
        CC_SAFE_RELEASE_NULL(hitLine);
        CC_SAFE_RELEASE_NULL(hitLine_copy);
        
        
        CC_SAFE_RELEASE_NULL(GameBG);
        
        CC_SAFE_RELEASE_NULL(comboImg);
        CC_SAFE_RELEASE_NULL(comboBackImg1);
        CC_SAFE_RELEASE_NULL(comboBackImg2);
        CC_SAFE_RELEASE_NULL(comboBackImg3);
        
        CC_SAFE_RELEASE_NULL(spritebatch);
        CC_SAFE_RELEASE_NULL(hit_effect_animate);
        
        CC_SAFE_RELEASE_NULL(grade);
        
        CC_SAFE_RELEASE_NULL(hp_bar);
        
        CC_SAFE_RELEASE_NULL(energy_bar);
        
        CC_SAFE_RELEASE_NULL(combo_count_label);
        CC_SAFE_RELEASE_NULL(perfect_count_bottom_label);
        CC_SAFE_RELEASE_NULL(good_count_bottom_label);
        CC_SAFE_RELEASE_NULL(bad_count_bottom_label);
        CC_SAFE_RELEASE_NULL(miss_count_bottom_label);
        CC_SAFE_RELEASE_NULL(max_combo_label);
        CC_SAFE_RELEASE_NULL(total_score_label);
        /*
         CC_SAFE_RELEASE_NULL(combo_count_label_copy);
         CC_SAFE_RELEASE_NULL(perfect_count_bottom_label_copy);
         CC_SAFE_RELEASE_NULL(good_count_bottom_label_copy);
         CC_SAFE_RELEASE_NULL(bad_count_bottom_label_copy);
         CC_SAFE_RELEASE_NULL(miss_count_bottom_label_copy);
         CC_SAFE_RELEASE_NULL(max_combo_label_copy);
         CC_SAFE_RELEASE_NULL(total_score_label_copy);
         CC_SAFE_RELEASE_NULL(start_count);
         */
        CC_SAFE_RELEASE_NULL(coverLayer);
        CC_SAFE_RELEASE_NULL(GameScene);
        
        
        CCLog("fff2");
        CC_SAFE_RELEASE_NULL(btn_key_yellow_press_1);
        CC_SAFE_RELEASE_NULL(btn_key_yellow_press_2);
        CC_SAFE_RELEASE_NULL(btn_key_yellow_press_3);
        CC_SAFE_RELEASE_NULL(btn_key_yellow_press_4);
        CC_SAFE_RELEASE_NULL(btn_black_key_press);
        
        CC_SAFE_RELEASE_NULL(btn_key_guide_press_1);
        CC_SAFE_RELEASE_NULL(btn_key_guide_press_2);
        CC_SAFE_RELEASE_NULL(btn_key_guide_press_3);
        CC_SAFE_RELEASE_NULL(btn_key_guide_press_4);
        CC_SAFE_RELEASE_NULL(btn_black_key_guide_press);
        
        
        
        CC_SAFE_RELEASE_NULL(bar_blue);
        CC_SAFE_RELEASE_NULL(bar_blue_long);
        
        CC_SAFE_RELEASE_NULL(bar_yellow);
        CC_SAFE_RELEASE_NULL(bar_yellow_long);
        
        CC_SAFE_RELEASE_NULL(perfect);
        CC_SAFE_RELEASE_NULL(miss);
        CC_SAFE_RELEASE_NULL(good);
        CC_SAFE_RELEASE_NULL(bad);
        
        CCLog("fff3");
        for(int i=0;i<88;i++)
        {
            CC_SAFE_RELEASE_NULL(piano_guid_sprite[i]);
            CC_SAFE_RELEASE_NULL(piano_press_sprite[i]);
            CC_SAFE_RELEASE_NULL(piano_rainbow_press_sprite[i]);

            if(draw_line[i] != NULL)
            {
                CC_SAFE_RELEASE_NULL(draw_line[i]);
            }
            if(hit_yellow_effect[i] != NULL)
            {
                hit_yellow_effect[i]->stopAction(action);
                hit_yellow_effect[i]->stopAllActions();
                CC_SAFE_RELEASE_NULL(hit_yellow_effect[i]);
            }

        }
        CCLog("fff4");
        CC_SAFE_RELEASE_NULL(timer_gaze);
        CC_SAFE_RELEASE_NULL(stopButton);
        
        CC_SAFE_RELEASE_NULL(timeBar);
    }

    if(gameMode == EASY_GAME)
    {
    	CC_SAFE_RELEASE_NULL(LoadBG);
		CC_SAFE_RELEASE_NULL(load_line);
		for(int i=0;i<17;i++)
		{
			CC_SAFE_RELEASE_NULL(load_timer_gaze[i]);
		}
		CC_SAFE_RELEASE_NULL(load_timer_gaze_tex[0]);
		CC_SAFE_RELEASE_NULL(load_timer_gaze_tex[1]);
		CC_SAFE_RELEASE_NULL(load_timer_gaze_tex[2]);
		CC_SAFE_RELEASE_NULL(load_timer_gaze_tex[3]);
        
        CC_SAFE_RELEASE_NULL(image_do);
        CC_SAFE_RELEASE_NULL(image_fa);
        CC_SAFE_RELEASE_NULL(image_mi);
        CC_SAFE_RELEASE_NULL(image_ra);
        CC_SAFE_RELEASE_NULL(image_re);
        CC_SAFE_RELEASE_NULL(image_si);
        CC_SAFE_RELEASE_NULL(image_so);
        CC_SAFE_RELEASE_NULL(practice_bg);
        CC_SAFE_RELEASE_NULL(practice_btn_exit_over);
        CC_SAFE_RELEASE_NULL(practice_btn_exit_press);
        CC_SAFE_RELEASE_NULL(practice_frame);
        CC_SAFE_RELEASE_NULL(practice_logo);
        CC_SAFE_RELEASE_NULL(text_do);
        CC_SAFE_RELEASE_NULL(text_fa);
        CC_SAFE_RELEASE_NULL(text_la);
        CC_SAFE_RELEASE_NULL(text_mi);
        CC_SAFE_RELEASE_NULL(text_re);
        CC_SAFE_RELEASE_NULL(text_so);
        CC_SAFE_RELEASE_NULL(text_ti);
    }
    if(gameMode == NORMAL_GAME)
    {
        Singleton<GameManager>::GetInst()->npc_sprite->stopAction(action);
        Singleton<GameManager>::GetInst()->npc_sprite->stopAllActions();
        
        CC_SAFE_RELEASE_NULL(action);
        CC_SAFE_RELEASE_NULL(pianoKeyCode_a0);
        CC_SAFE_RELEASE_NULL(pianoKeyCode_do);

        CC_SAFE_RELEASE_NULL(beginner_syllable_names_bg);
        CC_SAFE_RELEASE_NULL(beginner_syllable_image);
        CC_SAFE_RELEASE_NULL(beginner_image_ti);
        CC_SAFE_RELEASE_NULL(beginner_image_sol);
        CC_SAFE_RELEASE_NULL(beginner_image_re);
        CC_SAFE_RELEASE_NULL(beginner_image_mi);
        CC_SAFE_RELEASE_NULL(beginner_image_la);
        CC_SAFE_RELEASE_NULL(beginner_image_fa);
        CC_SAFE_RELEASE_NULL(beginner_image_do);


        CC_SAFE_RELEASE_NULL(load_timeBar_gaze);
        
        CC_SAFE_RELEASE_NULL(normal_bg);
        
        CC_SAFE_RELEASE_NULL(note_do_nomal);
        CC_SAFE_RELEASE_NULL(note_do_smile);
        CC_SAFE_RELEASE_NULL(note_fa_nomal);
        CC_SAFE_RELEASE_NULL(note_fa_smile);
        CC_SAFE_RELEASE_NULL(note_la_nomal);
        CC_SAFE_RELEASE_NULL(note_la_smile);
        CC_SAFE_RELEASE_NULL(note_mi_nomal);
        
        
        CC_SAFE_RELEASE_NULL(note_mi_smile);
        CC_SAFE_RELEASE_NULL(note_re_nomal);
        CC_SAFE_RELEASE_NULL(note_re_smile);
        CC_SAFE_RELEASE_NULL(note_so_nomal);
        CC_SAFE_RELEASE_NULL(note_so_smile);
        CC_SAFE_RELEASE_NULL(note_ti_nomal);
        CC_SAFE_RELEASE_NULL(note_ti_smile);

        
        CC_SAFE_RELEASE_NULL(redBlock);
        CC_SAFE_RELEASE_NULL(yellowBlock);
        CC_SAFE_RELEASE_NULL(greenBlock);
        

        CC_SAFE_RELEASE_NULL(redBlock_Press);
        CC_SAFE_RELEASE_NULL(yellowBlock_Press);
        CC_SAFE_RELEASE_NULL(greenBlock_Press);

        CC_SAFE_RELEASE_NULL(block_way);

        if(copy_target != NULL)
        {
        	CC_SAFE_RELEASE_NULL(copy_target);
        }




 //aa
        CC_SAFE_RELEASE_NULL(npc_spritebatch);
        CC_SAFE_RELEASE_NULL(idle_animate);
        CC_SAFE_RELEASE_NULL(hurt_animate);
        CC_SAFE_RELEASE_NULL(cry_animate);
        
        

        CC_SAFE_RELEASE_NULL(npc_sprite_green);
        CC_SAFE_RELEASE_NULL(npc_spritebatch_green);
        CC_SAFE_RELEASE_NULL(idle_animate_green);
        
        
        CC_SAFE_RELEASE_NULL(npc_sprite_pink);
        CC_SAFE_RELEASE_NULL(npc_spritebatch_pink);
        CC_SAFE_RELEASE_NULL(idle_animate_pink);
        CC_SAFE_RELEASE_NULL(cry_animate_pink);
        
        CC_SAFE_RELEASE_NULL(bar_yellow);
        CC_SAFE_RELEASE_NULL(bar_yellow_long);
        CC_SAFE_RELEASE_NULL(bar_blue);
        CC_SAFE_RELEASE_NULL(bar_blue_long);
        
        
        CC_SAFE_RELEASE_NULL(stopButton);
        
        CC_SAFE_RELEASE_NULL(npc_sprite);
        CCLog("fff5");
        
        CC_SAFE_RELEASE_NULL(comboImg);
        CC_SAFE_RELEASE_NULL(comboBackImg1);
        CC_SAFE_RELEASE_NULL(comboBackImg2);
        CC_SAFE_RELEASE_NULL(comboBackImg3);
        
        
        
        
        CCLog("fff6");
        CC_SAFE_RELEASE_NULL(spritebatch);
        CC_SAFE_RELEASE_NULL(hit_effect_animate);
        
        CC_SAFE_RELEASE_NULL(grade);
        
        CC_SAFE_RELEASE_NULL(hp_bar);
        
        CC_SAFE_RELEASE_NULL(combo_count_label);
        CC_SAFE_RELEASE_NULL(perfect_count_bottom_label);
        CC_SAFE_RELEASE_NULL(good_count_bottom_label);
        CC_SAFE_RELEASE_NULL(bad_count_bottom_label);
        CC_SAFE_RELEASE_NULL(miss_count_bottom_label);
        CC_SAFE_RELEASE_NULL(max_combo_label);
        CC_SAFE_RELEASE_NULL(total_score_label);
        
        CC_SAFE_RELEASE_NULL(start_count);
        CCLog("fff7");
        
        
        CC_SAFE_RELEASE_NULL(perfect);
        CC_SAFE_RELEASE_NULL(miss);
        CC_SAFE_RELEASE_NULL(good);
        CC_SAFE_RELEASE_NULL(bad);
        
        
        
        CC_SAFE_RELEASE_NULL(timer_gaze);
        
        CC_SAFE_RELEASE_NULL(timeBar);

    }











}


void GameManager::all_Cleanup()
{
    CCLog("all_Cleanup()");
    this->resourceGameSceneClean();

    CCLog("all_Cleanup1()");
    cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->removeUnusedSpriteFrames();
    cocos2d::CCTextureCache::sharedTextureCache()->removeUnusedTextures();
    cocos2d::CCTextureCache::sharedTextureCache()->removeAllTextures();
    cocos2d::CCDirector::sharedDirector()->purgeCachedData();

}


void GameManager::key_inputSetting()
{
    CCLog("key_inputSetting");

    if(gameMode == ANG_FREE || gameMode == ANG_GAME) // ang
    {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        JniMethodInfo t;
        if (JniHelper::getMethodInfo(t
                                     , "com/shfactory/musicblood/solo/MultipleGame"
                                     , "javakeySwitcher"
                                     , "(I)V"))
        {
            ///< 占썩�ο옙 占쎈��占�
            //perfectSocre
            t.env->CallVoidMethod(Singleton<GameManager>::GetInst()->javaObj, t.methodID, 1);
            ///< Release
            t.env->DeleteLocalRef(t.classID);
        }
#endif
    }
    else
    {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        JniMethodInfo t;
        if (JniHelper::getMethodInfo(t
                                     , "com/shfactory/musicblood/solo/SimpleGame"
                                     , "javakeySwitcher"
                                     , "(I)V"))
        {
            ///< 占썩�ο옙 占쎈��占�
            //perfectSocre
            t.env->CallVoidMethod(Singleton<GameManager>::GetInst()->javaObj, t.methodID, 1);
            ///< Release
            t.env->DeleteLocalRef(t.classID);
        }
#endif
    }
}

void GameManager::runScene(int type)
{
    cocos2d::CCScene* scene = NULL;
    switch ((int)type)
    {
        case GAME_SCENE_STARTLOAD:
        {
            CCLOG("GAME_SCENE_STARTLOAD");
            this->resourceLoadSceneLoad();
            scene = LoadScene::create();
        }
            break;

        case GAME_NORMAL_SCENE_PLAY:
        {
            CCLOG("GAME_NORMAL_SCENE_PLAY");
            this->key_inputSetting();
            map< int, float >::iterator Iter_Pos;
            for( Iter_Pos = gameTotalTime.begin(); Iter_Pos != gameTotalTime.end(); ++Iter_Pos)
            {
                //  CCLog("Iter_Pos: %f",Iter_Pos->second);
                if(Iter_Pos->second > maxTime)
                {
                    maxTime = Iter_Pos->second;
                }
            }

            scene = GameScene;

        }
            break;

        case GAME_EASY_SCENE_PLAY:
        {
            CCLOG("GAME_EASY_SCENE_PLAY");
            this->key_inputSetting();
            scene = GameScene;
        }
            break;

        case GAME_SCENE_PLAY:
        {
            CCLOG("GAME_SCENE_PLAY");
        	this->key_inputSetting();
            if(gameMode == SINGE_GAME)
            {

                map< int, float >::iterator Iter_Pos;
                for( Iter_Pos = gameTotalTime.begin(); Iter_Pos != gameTotalTime.end(); ++Iter_Pos)
                {
                    //  CCLog("Iter_Pos: %f",Iter_Pos->second);
                    if(Iter_Pos->second > maxTime)
                    {
                        maxTime = Iter_Pos->second;
                    }
                }
            }
            else if(gameMode == ANG_GAME)
            {

                map< int, float >::iterator Iter_Pos;
                for( Iter_Pos = gameTotalTime.begin(); Iter_Pos != gameTotalTime.end(); ++Iter_Pos)
                {
                    //   CCLog("Iter_Pos: %f",Iter_Pos->second);
                    if(Iter_Pos->second > maxTime)
                    {
                        maxTime = Iter_Pos->second;
                    }
                }
            }
            scene = GameScene;
        }
            break;
    }

    cocos2d::CCDirector* director = cocos2d::CCDirector::sharedDirector();
    if (director->getRunningScene())
    {
        CCLOG("getRunningScene");
        director->replaceScene(scene);
    }
    else
    {
        CCLOG("no getRunningScene");
        director->runWithScene(scene);
    }
    CCDirector::sharedDirector()->resume();
}



int GameManager::checkCollisionBox(const char *keyCode)
{
    //keyCode ���愿�������...臾댁“嫄� 異⑸��留�...
    for(int i=0;i<_collision_boxes_Channel.size();i++)
    {
        std::vector<Block *> _collision_boxes = _collision_boxes_Channel.at(i);
        if(_collision_boxes.size() > 0 && _collision_boxes.size() > removeNodeCount.at(i))
        {
            //異���λ�� ��쇱�몃�� array ���以���� ��� ������ 留ㅼ묶��� �����댁��
            CCArray *line_block_collect = dynamic_cast<CCArray*>(line_block_collect_array->objectAtIndex(39));
            if(line_block_collect->count() > 0)
            {
                Block *target =  dynamic_cast<Block*>(line_block_collect->objectAtIndex(0));

                CCRect source = CCRect(hitLine->getPositionX(),hitLine->getPositionY()-110,hitLine->getContentSize().width,37);
                CCRect firstBlock = CCRect(target->body->getPositionX()-DownBlockEndPosX[0],target->body->getPositionY(),target->body->getContentSize().width,target->body->getContentSize().height);



                // if (source.intersectsRect(firstBlock))
                // {

                if(!target->col_check)
                {

                    /*
                     CCLOG("getMinY() : %f",firstBlock.getMinY());
                     CCLOG("getMaxY() : %f",firstBlock.getMaxY());
                     CCLOG("source getMinY() : %f",source.getMinY());
                     CCLOG("source getMaxY() : %f",source.getMaxY());
                     */

                    if(firstBlock.origin.y > (source.origin.y+source.size.height - 10.0f) &&  //perfect
                       firstBlock.origin.y < (source.origin.y+source.size.height + 10.0f))
                    {
                        CCLog("perfect");
                        target->col_check = true;
                        this->perfectMatch((int)keyCode,3);
                    }
                    else if(firstBlock.origin.y > (source.origin.y+source.size.height + 10.0f) &&  //good
                            firstBlock.origin.y < (source.origin.y+source.size.height + 20.0f))
                    {
                        CCLog("good");
                        target->col_check = true;
                        this->perfectMatch((int)keyCode,2);
                    }
                    else if(firstBlock.origin.y > (source.origin.y+source.size.height - 20.0f) &&  //bad
                            firstBlock.origin.y < (source.origin.y+source.size.height - 10.0f))
                    {
                        CCLog("bad");
                        target->col_check = true;
                        this->perfectMatch((int)keyCode,1);
                    }

                    else
                    {
                        this->missMatch();
                    }
                    /*
                     else
                     {
                     this->perfectMatch((int)keyCode,1);
                     }
                     */
                }

            }
            return 1;
        }
    }

    return 0;
}

//異⑸��
int GameManager::checkCollisionBox(int keycode)
{

	//exception of keyCode
    for(int i=0;i<_collision_boxes_Channel.size();i++)
    {
        std::vector<Block *> _collision_boxes = _collision_boxes_Channel.at(i);
        if(removeNodeCount.size() > 0)
        {
            if(_collision_boxes.size() > 0 && _collision_boxes.size() > removeNodeCount.at(i))
            {
                CCArray *line_block_collect = dynamic_cast<CCArray*>(line_block_collect_array->objectAtIndex(keycode));
                if(line_block_collect->count() > 0)
                {
                    CCLog("line_block_collect->count() : %d",line_block_collect->count());
                    Block *target =  dynamic_cast<Block*>(line_block_collect->objectAtIndex(0));

                    float blockPosY; // ��ㅼ�� 釉���� ���移�



                    CCRect source = CCRect(hitLine->getPositionX(),hitLine->getPositionY()-110,hitLine->getContentSize().width,37);
                    CCRect firstBlock;
                    if(target->body != NULL)
                    {
                        blockPosY = target->body->getPositionY() + Singleton<GameManager>::GetInst()->coverLayer->getPositionY(); // ��ㅼ�� 釉���� ���移�
                        firstBlock = CCRect(target->body->getPositionX()-DownBlockEndPosX[0],blockPosY,target->body->getContentSize().width,target->body->getContentSize().height);
                    }
                    else
                    {
                        blockPosY = target->tail->getPositionY() + Singleton<GameManager>::GetInst()->coverLayer->getPositionY(); // ��ㅼ�� 釉���� ���移�
                        firstBlock = CCRect(target->tail->getPositionX()-DownBlockEndPosX[0],blockPosY,target->tail->getContentSize().width,target->tail->getContentSize().height);
                    }
                    CCLog("source : %f   %f",source.origin.y,source.size.height);
                    CCLog("firstBlock : %f   %f",firstBlock.origin.y,firstBlock.size.height);


                    if(!target->col_check)
                    {
                        if(target->lineNum == keycode)
                        {
                            if(firstBlock.origin.y+firstBlock.size.height > (source.origin.y+source.size.height - 10.0f) &&  //perfect
                               firstBlock.origin.y < (source.origin.y+source.size.height + 10.0f))
                            {
                                CCLog("tail perfect");
                                this->collisionCheck(target,keycode);
                                this->perfectMatch(keycode,3);
                            }
                            else if(firstBlock.origin.y > (source.origin.y+source.size.height - 10.0f) &&  //perfect
                                    firstBlock.origin.y < (source.origin.y+source.size.height + 10.0f))
                            {
                                CCLog("perfect");
                                this->collisionCheck(target,keycode);
                                this->perfectMatch(keycode,3);
                            }
                            else if(firstBlock.origin.y > (source.origin.y+source.size.height + 10.0f) &&  //good
                                    firstBlock.origin.y < (source.origin.y+source.size.height + 20.0f))
                            {
                                CCLog("good");
                                if(Singleton<GameManager>::GetInst()->feverMode)
                                {
                                    CCLog("perfect fever");
                                    this->collisionCheck(target,keycode);
                                    this->perfectMatch(keycode,3);
                                }
                                else
                                {
                                    this->collisionCheck(target,keycode);
                                    this->perfectMatch(keycode,2);
                                }

                            }
                            else if(firstBlock.origin.y > (source.origin.y+source.size.height - 20.0f) &&  //bad
                                    firstBlock.origin.y < (source.origin.y+source.size.height - 10.0f))
                            {
                                CCLog("bad");
                                if(Singleton<GameManager>::GetInst()->feverMode)
                                {
                                    CCLog("perfect fever");
                                    this->collisionCheck(target,keycode);
                                    this->perfectMatch(keycode,3);
                                }
                                else
                                {
                                    this->collisionCheck(target,keycode);
                                    this->perfectMatch(keycode,1);
                                }
                            }

                            else
                            {
                                if(!Singleton<GameManager>::GetInst()->feverMode)
                                {
                                    this->missMatch();
                                }

                            }

                        }
                        else
                        {
                            if(!Singleton<GameManager>::GetInst()->feverMode)
                            {
                                this->missMatch();
                            }
                        }
                    }

                }
            }
        }
    }
    return 0;
}
int GameManager::checkNomalCollisionBox(int keycode)
{
    //this->perfectMatch(keycode,3);

     for(int i=0;i<_collision_boxes_Channel.size();i++)
     {
    	 std::vector<Block *> _collision_boxes = _collision_boxes_Channel.at(i);
    	 if(removeNodeCount.size() > 0)
    	 {
    		 if(_collision_boxes.size() > 0 && _collision_boxes.size() > removeNodeCount.at(i))
    		 {
    			 CCArray *line_block_collect = dynamic_cast<CCArray*>(line_block_collect_array->objectAtIndex(keycode));
    			 if(line_block_collect->count() > 0)
    			 {
    				 Block *target =  dynamic_cast<Block*>(line_block_collect->objectAtIndex(0));
    				 float blockPosX;

    				 if(!target->breaking)
    				 {
    					 CCRect firstBlock;
    					 if(target->body != NULL)
    					 {
    						 blockPosX = target->body->getPositionX() + Singleton<GameManager>::GetInst()->coverLayer->getPositionX()-200; // ��ㅼ�� 釉���� ���移�
    						 firstBlock = CCRect(target->body->getPositionX()-DownBlockEndPosX[0],blockPosX,target->body->getContentSize().width,target->body->getContentSize().height);
    					 }
    					 else
    					 {
    						 blockPosX = target->tail->getPositionY() - Singleton<GameManager>::GetInst()->coverLayer->getPositionX(); // ��ㅼ�� 釉���� ���移�
    						 firstBlock = CCRect(target->tail->getPositionX()-DownBlockEndPosX[0],blockPosX,target->tail->getContentSize().width,target->tail->getContentSize().height);
    					 }
    					 CCLog("firstBlock : %f   %f   %f",target->body->getPositionX(),Singleton<GameManager>::GetInst()->coverLayer->getPositionX(),blockPosX);
    					 if(!target->col_check)
    					 {
    						 if(target->doremipasolasi == keycode)
    						 {
    							 if(blockPosX > (yellowBlock->getPositionX()-110) &&  //good
    									 blockPosX < (yellowBlock->getPositionX()+110))
    							 {
    								 CCLog("good");
    								 this->collisionCheck(target,keycode);
    								 this->perfectMatch(keycode,2);
    							 }
    							 else if(blockPosX > (greenBlock->getPositionX()-110) &&  //perfect
    									 blockPosX < (greenBlock->getPositionX()+110))
    							 {
    								 CCLog("perfect");
    								 this->collisionCheck(target,keycode);
    								 this->perfectMatch(keycode,3);
    							 }
    							 else if(blockPosX > (redBlock->getPositionX()-110) &&  //bad
    									 blockPosX < (redBlock->getPositionX()+110))
    							 {
    								 CCLog("bad");
    								 this->collisionCheck(target,keycode);
    								 this->perfectMatch(keycode,1);
    							 }
    							 else
    							 {
    								 this->missMatch();
    							 }
    						 }
    						 else
    						 {
    							 this->missMatch();
    						 }
    					 }
    				 }
    			 }
    		 }
    	 }
     }

    return 0;
}
void GameManager::collisionCheck(Block *target,int keycode)
{
    if(gameMode != NORMAL_GAME)
    {
        if(!feverMode && !feverTimer)
        {
            if(energy_bar->getPercentage() < 55)
            {
                energy_bar->setPercentage(energy_bar->getPercentage()+1); // 25~55
            }
            if(energy_bar->getPercentage() >= 55)
            {
                feverTimer = true;
            }
        }


        this->hit_effect_visiable(keycode);
        //  hit_yellow_effect_rotate[keycode] += (hit_yellow_effect_rotate[keycode] + 1.0f);   //��댄����� ������????

        target->NowDurationMillis += 0.1f;
        // CCLog("hit_yellow_effect_rotate[keycode] : %f",hit_yellow_effect_rotate[keycode]);
        CCLog("target->NowDurationMillis : %f",target->NowDurationMillis);
        CCLog("target->durationMillis : %f",target->durationMillis);
        
        if(target->durationMillis <= target->NowDurationMillis)
        {
            CCLog("target->col_check : %d",target->col_check);

            target->col_check = true;
            if(target->body!=NULL)
            {
                this->MoveFinished(target);
            }
            else
            {
                this->_9Sprite_MoveFinished(target);
            }

        }
    }
    else
    {
        target->col_check = true;
        
        if(target->doremipasolasi == 0)
        {
            target->body->setTexture(note_do_smile);
        }
        else if(target->doremipasolasi == 1)
        {
            target->body->setTexture(note_re_smile);
        }
        else if(target->doremipasolasi == 2)
        {
            target->body->setTexture(note_mi_smile);
        }
        else if(target->doremipasolasi == 3)
        {
            target->body->setTexture(note_fa_smile);
        }
        else if(target->doremipasolasi == 4)
        {
            target->body->setTexture(note_so_smile);
        }
        else if(target->doremipasolasi == 5)
        {
            target->body->setTexture(note_la_smile);
        }
        else if(target->doremipasolasi == 6)
        {
            target->body->setTexture(note_ti_smile);
        }
        
        
        target->breaking = true;
        copy_target = CCSprite::createWithTexture(target->body->getTexture());
        
        target->print_layer->removeChild(target->body, true);
        this->normal_block_layer->addChild(copy_target);
        
        std::map< double, Block * >::iterator Iter_Erase_Pos = Singleton<GameManager>::GetInst()->_erase_print_blocks.begin();
        Singleton<GameManager>::GetInst()->_erase_print_blocks.erase(Iter_Erase_Pos);
        ++Singleton<GameManager>::GetInst()->eraseCount.at(0);
        
        ++removeNodeCount.at(0);
        
        
        
        
        copy_target->setRotation(0);
        copy_target->setPosition(ccp(600,CCDirector::sharedDirector()->getVisibleSize().height/2));
        CCActionInterval*  actionBy = CCScaleBy::create(0.3, 4);
        actionBy->retain();
        copy_target->runAction( CCSequence::create(actionBy, NULL));
        
        
        
        CCFiniteTimeAction* actionMove = CCMoveTo::create(0.3,ccp(CCDirector::sharedDirector()->getVisibleSize().width/2,CCDirector::sharedDirector()->getVisibleSize().height/2-target->body->getContentSize().height/2-10));
        actionMove->retain();
        CCFiniteTimeAction* actionMove1 = CCFadeOut::create(0.3);
        actionMove1->retain();
        CCFiniteTimeAction* actionMoveDone = CCCallFuncND::create(this, callfuncND_selector(GameManager::collision_target_ani_finish),(void*)keycode);
        actionMoveDone->retain();
        copy_target->runAction( CCSequence::create(actionMove,actionMove1,actionMoveDone, NULL) );
        
        
        
        
        
        CCArray *line_block_collect = dynamic_cast<CCArray*>(Singleton<GameManager>::GetInst()->line_block_collect_array->objectAtIndex(keycode));
        line_block_collect->removeObjectAtIndex(0);
        
        
        
        
        
        //this->MoveFinished(target);
    }
}



void GameManager::collision_target_ani_finish(CCNode* sender,int index)
{
    this->normal_block_layer->removeChild(copy_target, true);

}

int GameManager::checkCollisionBox_copy(int keycode)
{
	//exception of keyCode
    for(int i=0;i<_collision_boxes_Channel_copy.size();i++)
    {
        CCLog("here1");
        std::vector<Block *> _collision_boxes_copy = _collision_boxes_Channel_copy.at(i);
        CCLog("here2");
        if(_collision_boxes_copy.size() > 0 && _collision_boxes_copy.size() > removeNodeCount_copy.at(i))
        {
            CCLog("here3");
            CCArray *line_block_collect = dynamic_cast<CCArray*>(line_block_collect_array_copy->objectAtIndex(keycode));
            if(line_block_collect->count() > 0)
            {
                CCLog("line_block_collect->count() : %d",line_block_collect->count());
                Block *target =  dynamic_cast<Block*>(line_block_collect->objectAtIndex(0));

                CCRect source = CCRect(hitLine->getPositionX(),hitLine->getPositionY()+0,hitLine->getContentSize().width,hitLine->getContentSize().height);
                CCRect firstBlock = CCRect(target->body->getPositionX()-DownBlockEndPosX[0],target->body->getPositionY(),target->body->getContentSize().width,target->body->getContentSize().height);

                if (source.intersectsRect(firstBlock))
                {
                    if(!target->col_check)
                    {
                        if(target->lineNum == keycode)
                        {
                            CCLog("Collision");
                            target->col_check = true;

                            if(firstBlock.getMinY() > (source.getMinY() - 10.0f) &&  //perfect
                               firstBlock.getMinY() < (source.getMinY() + 10.0f))
                            {
                                this->perfectMatch_copy(keycode,3);
                            }
                            else if(firstBlock.getMinY() > (source.getMinY() + 10.0f) &&  //good
                                    firstBlock.getMinY() < (source.getMinY() + 30.0f))
                            {
                                this->perfectMatch_copy(keycode,2);
                            }
                            else if(firstBlock.getMinY() > (source.getMinY() - 30.0f) &&  //bad
                                    firstBlock.getMinY() < (source.getMinY() - 10.0f))
                            {
                                this->perfectMatch_copy(keycode,1);
                            }
                            else
                            {
                                this->perfectMatch_copy(keycode,1);
                            }
                        }
                        else
                        {
                            this->missMatch_copy();
                        }
                    }
                }
                else
                {
                    this->missMatch_copy();
                }
            }

        }
    }
    return 0;
}



void GameManager::piano_effect_hide(CCNode* sender)
{
    CCSprite *sprite = (CCSprite *)sender;
    sprite->setVisible(false);
}

void GameManager::pianoGuideVisible(int targetNum)
{
    draw_line[targetNum]->setOpacity(255);
    int pianoSpriteNum = this->pianoSpriteSwitch(targetNum);

    if(pianoSpriteNum == 1)
    {
        piano_guid_sprite[targetNum]->setTexture(btn_key_guide_press_1);
    }
    else if(pianoSpriteNum == 2)
    {
        piano_guid_sprite[targetNum]->setTexture(btn_key_guide_press_2);
    }
    else if(pianoSpriteNum == 3)
    {
        piano_guid_sprite[targetNum]->setTexture(btn_key_guide_press_3);
    }
    else if(pianoSpriteNum == 4)
    {
        piano_guid_sprite[targetNum]->setTexture(btn_key_guide_press_4);
    }
    else
    {
        piano_guid_sprite[targetNum]->setTexture(btn_black_key_guide_press);
    }
    piano_guid_sprite[targetNum]->setVisible(true);
}
void GameManager::pianoGuideVisible_copy(int targetNum)
{
    int pianoSpriteNum = this->pianoSpriteSwitch(targetNum);

    if(pianoSpriteNum == 1)
    {
        piano_guid_sprite_copy[targetNum]->setTexture(btn_key_guide_press_1);
    }
    else if(pianoSpriteNum == 2)
    {
        piano_guid_sprite_copy[targetNum]->setTexture(btn_key_guide_press_2);
    }
    else if(pianoSpriteNum == 3)
    {
        piano_guid_sprite_copy[targetNum]->setTexture(btn_key_guide_press_3);
    }
    else if(pianoSpriteNum == 4)
    {
        piano_guid_sprite_copy[targetNum]->setTexture(btn_key_guide_press_4);
    }
    else
    {
        piano_guid_sprite_copy[targetNum]->setTexture(btn_black_key_guide_press);
    }
    piano_guid_sprite_copy[targetNum]->setVisible(true);
}

void GameManager::perfectMatch(int keycode, int gradeValue)
{
    hp_bar->setPosition(ccp(hp_bar->getPositionX()+5,hp_bar->getPositionY()));
    hp_bar->setTextureRect(CCRect(0,0,hp_bar->getTextureRect().size.width+10,hp_bar->getTextureRect().size.height));

    if(gradeValue == 3)
    {
        ++combo_count;
    }
    else
    {
        combo_count = 0;
    }

    if(combo_count > max_combo_count)
    {
        max_combo_count = combo_count;
    }
    if(combo_count !=0)
    {
    	//asdf2
        combo_count_label->setVisible(true);
        comboImg->setVisible(true);

        if(Singleton<GameManager>::GetInst()->combo_count > 9)
      	{
      		if(Singleton<GameManager>::GetInst()->combo_count > 99)
      		{
      			Singleton<GameManager>::GetInst()->comboBackImg1->setVisible(false);
      			Singleton<GameManager>::GetInst()->comboBackImg2->setVisible(false);
      			Singleton<GameManager>::GetInst()->comboBackImg3->setVisible(true);

      			Singleton<GameManager>::GetInst()->combo_count_label->setPositionX(Singleton<GameManager>::GetInst()->comboBackImg3->getPositionX()-Singleton<GameManager>::GetInst()->combo_count_label->getContentSize().width/2);
      		}
      		else
      		{
      			Singleton<GameManager>::GetInst()->comboBackImg1->setVisible(false);
      			Singleton<GameManager>::GetInst()->comboBackImg2->setVisible(true);
      			Singleton<GameManager>::GetInst()->comboBackImg3->setVisible(false);

      			Singleton<GameManager>::GetInst()->combo_count_label->setPositionX(Singleton<GameManager>::GetInst()->comboBackImg2->getPositionX()-Singleton<GameManager>::GetInst()->combo_count_label->getContentSize().width/2);
      		}
      	}
      	else
      	{
      		Singleton<GameManager>::GetInst()->comboBackImg1->setVisible(true);
      		Singleton<GameManager>::GetInst()->comboBackImg2->setVisible(false);
      		Singleton<GameManager>::GetInst()->comboBackImg3->setVisible(false);

      		Singleton<GameManager>::GetInst()->combo_count_label->setPositionX(Singleton<GameManager>::GetInst()->comboBackImg1->getPositionX()-Singleton<GameManager>::GetInst()->combo_count_label->getContentSize().width/2);
      	}


    }
    grade->setVisible(true);
    if(gameMode == NORMAL_GAME)
    {
        if(gradeValue == 3) //perfect
        {
            redBlock->setVisible(true);
            redBlock_Press->setVisible(false);

            greenBlock->setVisible(false);
            greenBlock_Press->setVisible(true);

            yellowBlock->setVisible(true);
            yellowBlock_Press->setVisible(false);

            ++perfectSocre;
            maxScore += 100;
            grade->setTexture(perfect);
        }
        else if(gradeValue == 2) //good
        {
            redBlock->setVisible(true);
            redBlock_Press->setVisible(false);

            greenBlock->setVisible(true);
            greenBlock_Press->setVisible(false);

            yellowBlock->setVisible(false);
            yellowBlock_Press->setVisible(true);


            ++goodSocre;
            maxScore += 50;
            grade->setTexture(good);
        }
        else if(gradeValue == 1) //bad
        {
            redBlock->setVisible(false);
            redBlock_Press->setVisible(true);

            greenBlock->setVisible(true);
            greenBlock_Press->setVisible(false);

            yellowBlock->setVisible(true);
            yellowBlock_Press->setVisible(false);


            ++badSocre;
            maxScore += 10;
            grade->setTexture(bad);
        }
    }
    else
    {
        if(gradeValue == 3) //perfect
        {
            ++perfectSocre;
            maxScore += 100;
            grade->setTexture(perfect);
        }
        else if(gradeValue == 2) //good
        {
            ++goodSocre;
            maxScore += 50;
            grade->setTexture(good);
        }
        else if(gradeValue == 1) //bad
        {
            ++badSocre;
            maxScore += 10;
            grade->setTexture(bad);
        }
    }
    ++matchingNodeCount;


    //normal_block_layer->comboHidden();
}
void GameManager::perfectMatch_copy(int keycode, int gradeValue)
{
    hp_bar_copy->setPosition(ccp(hp_bar_copy->getPositionX()+5,hp_bar_copy->getPositionY()));
    hp_bar_copy->setTextureRect(CCRect(0,0,hp_bar_copy->getTextureRect().size.width+10,hp_bar_copy->getTextureRect().size.height));



    ++combo_count_copy;
    if(combo_count_copy > max_combo_count_copy)
    {
        max_combo_count_copy = combo_count_copy;
    }

    sprintf(str, "%d", combo_count_copy);
    combo_count_label_copy->setString(str);
    combo_count_label_copy->setVisible(true);
    comboImg_copy->setVisible(true);

    if(combo_count_copy > 9)
    {
        comboBackImg1_copy->setVisible(false);
        comboBackImg2_copy->setVisible(true);
        comboBackImg3_copy->setVisible(false);
    }
    else if(combo_count_copy > 99)
    {
        comboBackImg1_copy->setVisible(false);
        comboBackImg2_copy->setVisible(false);
        comboBackImg3_copy->setVisible(true);
    }
    else
    {
        comboBackImg1_copy->setVisible(true);
        comboBackImg2_copy->setVisible(false);
        comboBackImg3_copy->setVisible(false);
    }
    grade_copy->setVisible(true);
    if(gradeValue == 3) //perfect
    {
        ++perfectSocre_copy;
        maxScore_copy += 100;
        grade_copy->setTexture(perfect);
    }
    else if(gradeValue == 2) //good
    {
        ++goodSocre_copy;
        maxScore_copy += 50;
        grade_copy->setTexture(good);
    }
    else if(gradeValue == 1) //bad
    {
        ++badSocre_copy;
        maxScore_copy += 10;
        grade_copy->setTexture(bad);
    }

    ++matchingNodeCount_copy;
}

void GameManager::missMatch()
{
//asdf4
    if(Singleton<GameManager>::GetInst()->feverMode)
    {
        CCLog("fever no missMatch");
    }
    else
    {
        ++missSocre;
        // hp_bar->setPosition(ccp(hp_bar->getPositionX()-0.5f,hp_bar->getPositionY()));
        // hp_bar->setTextureRect(CCRect(0,0,hp_bar->getTextureRect().size.width-1,hp_bar->getTextureRect().size.height));

        grade->setVisible(true);
        grade->setTexture(miss);



        combo_count = 0;
        comboImg->setVisible(false);
        combo_count_label->setVisible(false);
        combo_count_label->setString("0");
        
        comboBackImg1->setVisible(false);
        comboBackImg2->setVisible(false);
        comboBackImg3->setVisible(false);
        
        if(gameMode == NORMAL_GAME)
        {
            this->replaceAnimation(Npc_STATE_CRY);
        }
    }
}
void GameManager::missMatch_copy()
{
    ++missSocre_copy;
    hp_bar_copy->setPosition(ccp(hp_bar_copy->getPositionX()-0.5f,hp_bar_copy->getPositionY()));
    hp_bar_copy->setTextureRect(CCRect(0,0,hp_bar_copy->getTextureRect().size.width-1,hp_bar_copy->getTextureRect().size.height));

    grade_copy->setVisible(true);
    grade_copy->setTexture(miss);



    combo_count_copy = 0;
    comboImg_copy->setVisible(false);
    combo_count_label_copy->setVisible(false);
    combo_count_label_copy->setString("0");

    comboBackImg1_copy->setVisible(false);
    comboBackImg2_copy->setVisible(false);
    comboBackImg3_copy->setVisible(false);
}

int GameManager::pianoSpriteSwitch(int i)
{
    if(i == 0  ||
       i == 3  ||
       i == 8  ||
       i == 15 ||
       i == 20 ||
       i == 27 ||
       i == 32 ||
       i == 39 ||
       i == 44 ||
       i == 51 ||
       i == 56 ||
       i == 63 ||
       i == 68 ||
       i == 75 ||
       i == 80)

    {
        return 1;
    }

    else if(i == 2  ||
            i == 7  ||
            i == 14 ||
            i == 19 ||
            i == 26 ||
            i == 31 ||
            i == 38 ||
            i == 43 ||
            i == 50 ||
            i == 55 ||
            i == 62 ||
            i == 67 ||
            i == 74 ||
            i == 79 ||
            i == 86)

    {
        return 2;
    }

    else if(i == 5  ||
            i == 10 ||
            i == 12 ||
            i == 17 ||
            i == 22 ||
            i == 24 ||
            i == 29 ||
            i == 34 ||
            i == 36 ||
            i == 41 ||
            i == 46 ||
            i == 48 ||
            i == 53 ||
            i == 58 ||
            i == 60 ||
            i == 65 ||
            i == 70 ||
            i == 72 ||
            i == 77 ||
            i == 82 ||
            i == 84)
    {
        return 3;
    }

    else if(i == 87)
    {
        return 4;
    }

    else
    {
        return 0;
    }
}
void GameManager::rainbowColorInit(int i)
{
    if(i < 15) //鍮④��  0~14
    {
        draw_line[i]->setColor(ccc3(144, 0, 1));
    }
    else if(i > 14 && i < 27)  //二쇳�� 15嫄대��~26嫄대�� = 12媛�
    {
        draw_line[i]->setColor(ccc3(255, 90, 0));
    }
    else if(i > 26 && i < 39)  //��몃�� 28嫄대��~39嫄대�� = 12媛�
    {
        draw_line[i]->setColor(ccc3(253, 186, 2));
    }
    else if(i > 38 && i < 51)  //珥�濡� 40嫄대��~51嫄대�� = 12媛�
    {
        draw_line[i]->setColor(ccc3(68, 141, 1));
    }
    else if(i > 50 && i < 63)  //������ 52嫄대��~63嫄대�� = 12媛�
    {
        draw_line[i]->setColor(ccc3(0, 133, 124));
    }
    else if(i > 62 && i < 75)  //��⑥�� 64嫄대��~75嫄대�� = 12媛�
    {
        draw_line[i]->setColor(ccc3(1, 59, 133));
    }
    else if(i > 74 && i < 88)  //蹂대�� 76嫄대��~87嫄대�� = 12媛�
    {
        draw_line[i]->setColor(ccc3(133, 0, 155));
    }

}
void GameManager::downBlockPosInit(int index)
{
    int i=index;
    if(piano_array[i])
    {
        int white_index = this->whiteInPos(i-1);
        effectPosX[i] = ((white_index+1) * SCREEN_SIZE_WHITE_BlockWidth) - SCREEN_SIZE_WHITE_BlockWidth / 2 + WinOrign.x;

        DownBlockEndPosX[i] = ((white_index+1) * SCREEN_2X_SIZE_WHITE_BlockWidth) - SCREEN_2X_SIZE_WHITE_BlockWidth / 2 + block_WinOrign.x;
    }
    else
    {
        int white_index = this->whiteInPos(i);
        effectPosX[i] = ((float)white_index * SCREEN_SIZE_WHITE_BlockWidth) + WinOrign.x;

        DownBlockEndPosX[i] = ((float)white_index * SCREEN_2X_SIZE_WHITE_BlockWidth) + block_WinOrign.x;
    }
}
void GameManager::pianoSpriteInit(int index)
{
    int i=index;
    if(gameMode != SINGE_FREE)
    {
        hit_yellow_effect[i] = CCSprite::createWithSpriteFrameName("hit_effect_yellow_1.png");
        hit_yellow_effect[i]->retain();
        hit_yellow_effect[i]->setVisible(false); // ������ ��댄����� 珥�湲고��
        spritebatch->addChild(hit_yellow_effect[i]);//hit_effect

        draw_line[i] = CCSprite::create("hd/line.png");
        draw_line[i]->retain();
        line_layer->addChild(draw_line[i],0);
        draw_line[i]->setOpacity(LINE_OPACITY);
    }

    //draw_line[i]->setScaleY(0.7f);
    if(piano_array[i])
    {
        int white_index = this->whiteInPos(i-1);
        effectPosX[i] = ((white_index+1) * SCREEN_SIZE_WHITE_BlockWidth) - SCREEN_SIZE_WHITE_BlockWidth / 2 + WinOrign.x;

        DownBlockEndPosX[i] = ((white_index+1) * SCREEN_2X_SIZE_WHITE_BlockWidth) - SCREEN_2X_SIZE_WHITE_BlockWidth / 2 + block_WinOrign.x;

        if(gameMode != SINGE_FREE)
        {
            draw_line[i]->setPosition(ccp(DownBlockEndPosX[i], startBlockPoint));
            draw_line[i]->setAnchorPoint(ccp(0.0f, 1.0f));
        }

        if(pianoMode == RAINBOW_MODE)
        {
            pianoBG->setTexture(pianoBG_tex[0]);
            if(gameMode != SINGE_FREE)
            {
                this->rainbowColorInit(index);
            }


        }
        else if(pianoMode == MARK_MODE)
        {
            pianoBG->setTexture(pianoBG_tex[1]);
            if(gameMode != SINGE_FREE)
            {
                draw_line[i]->setColor(ccc3(255, 255, 255));
            }
        }
        else
        {
            pianoBG->setTexture(pianoBG_tex[2]);
            if(gameMode != SINGE_FREE)
            {
                draw_line[i]->setColor(ccc3(255, 255, 255));
            }
        }
        
    }
    else
    {
        int white_index = this->whiteInPos(i);
        effectPosX[i] = ((float)white_index * SCREEN_SIZE_WHITE_BlockWidth) + WinOrign.x;
        
        DownBlockEndPosX[i] = ((float)white_index * SCREEN_2X_SIZE_WHITE_BlockWidth) + block_WinOrign.x;
        
        if(gameMode != SINGE_FREE)
        {
            draw_line[i]->setPosition(ccp(DownBlockEndPosX[i], startBlockPoint));
            draw_line[i]->setAnchorPoint(ccp(0.0f, 1.0f));
        }
        
        if(pianoMode == RAINBOW_MODE)
        {
            pianoBG->setTexture(pianoBG_tex[0]);
            if(gameMode != SINGE_FREE)
            {
                this->rainbowColorInit(index);
            }
        }
        else if(pianoMode == MARK_MODE)
        {
            pianoBG->setTexture(pianoBG_tex[1]);
            if(gameMode != SINGE_FREE)
            {
                draw_line[i]->setColor(ccc3(255, 255, 255));
            }
        }
        else
        {
            pianoBG->setTexture(pianoBG_tex[2]);
            if(gameMode != SINGE_FREE)
            {
                draw_line[i]->setColor(ccc3(255, 255, 255));
            }
        }
    }

    //this->pianoSpriteSwitch(i);

    if(i == 0  ||
       i == 3  ||
       i == 8  ||
       i == 15 ||
       i == 20 ||
       i == 27 ||
       i == 32 ||
       i == 39 ||
       i == 44 ||
       i == 51 ||
       i == 56 ||
       i == 63 ||
       i == 68 ||
       i == 75 ||
       i == 80)

    {
        piano_guid_sprite[i] =  new cocos2d::CCSprite();
        piano_guid_sprite[i]->retain();
        //piano_guid_sprite[i]->setTexture(btn_key_yellow_press_1);
        piano_guid_sprite[i]->initWithFile("hd/btn_key_guide_press_1.png");
        piano_guid_sprite[i]->setVisible(false);
        controll_layer->addChild( piano_guid_sprite[i],-1,i);

        piano_press_sprite[i] =  new cocos2d::CCSprite();
        piano_press_sprite[i]->retain();
        //piano_guid_sprite[i]->setTexture(btn_key_yellow_press_1);
        piano_press_sprite[i]->initWithFile("hd/btn_key_yellow_press_1.png");
        piano_press_sprite[i]->setVisible(false);
        controll_layer->addChild( piano_press_sprite[i],0,i);

        piano_rainbow_press_sprite[i] =  new cocos2d::CCSprite();
        piano_rainbow_press_sprite[i]->retain();
        piano_rainbow_press_sprite[i]->initWithFile("hd/btn_ColorKeyboard_press_1.png");
        piano_rainbow_press_sprite[i]->setVisible(false);
        controll_layer->addChild( piano_rainbow_press_sprite[i],0,i);



        //��쇱�����

    }

    else if(i == 2  ||
            i == 7  ||
            i == 14 ||
            i == 19 ||
            i == 26 ||
            i == 31 ||
            i == 38 ||
            i == 43 ||
            i == 50 ||
            i == 55 ||
            i == 62 ||
            i == 67 ||
            i == 74 ||
            i == 79 ||
            i == 86)

    {
        piano_guid_sprite[i] =  new cocos2d::CCSprite();
        piano_guid_sprite[i]->retain();
        //            piano_guid_sprite[i]->setTexture(btn_key_yellow_press_2);
        piano_guid_sprite[i]->initWithFile("hd/btn_key_guide_press_2.png");
        piano_guid_sprite[i]->setVisible(false);
        controll_layer->addChild( piano_guid_sprite[i],-1,i);
        
        
        piano_press_sprite[i] =  new cocos2d::CCSprite();
        piano_press_sprite[i]->retain();
        //piano_guid_sprite[i]->setTexture(btn_key_yellow_press_1);
        piano_press_sprite[i]->initWithFile("hd/btn_key_yellow_press_2.png");
        piano_press_sprite[i]->setVisible(false);
        controll_layer->addChild( piano_press_sprite[i],0,i);
        
        piano_rainbow_press_sprite[i] =  new cocos2d::CCSprite();
        piano_rainbow_press_sprite[i]->retain();
        piano_rainbow_press_sprite[i]->initWithFile("hd/btn_ColorKeyboard_press_2.png");
        piano_rainbow_press_sprite[i]->setVisible(false);
        controll_layer->addChild( piano_rainbow_press_sprite[i],0,i);
        
    }

    else if(i == 5  ||
            i == 10 ||
            i == 12 ||
            i == 17 ||
            i == 22 ||
            i == 24 ||
            i == 29 ||
            i == 34 ||
            i == 36 ||
            i == 41 ||
            i == 46 ||
            i == 48 ||
            i == 53 ||
            i == 58 ||
            i == 60 ||
            i == 65 ||
            i == 70 ||
            i == 72 ||
            i == 77 ||
            i == 82 ||
            i == 84)
    {
        piano_guid_sprite[i] =  new cocos2d::CCSprite();
        piano_guid_sprite[i]->retain();
        // piano_guid_sprite[i]->setTexture(btn_key_yellow_press_3);
        piano_guid_sprite[i]->initWithFile("hd/btn_key_guide_press_3.png");
        piano_guid_sprite[i]->setVisible(false);
        controll_layer->addChild( piano_guid_sprite[i],-1,i);
        
        piano_press_sprite[i] =  new cocos2d::CCSprite();
        piano_press_sprite[i]->retain();
        //piano_guid_sprite[i]->setTexture(btn_key_yellow_press_1);
        piano_press_sprite[i]->initWithFile("hd/btn_key_yellow_press_3.png");
        piano_press_sprite[i]->setVisible(false);
        controll_layer->addChild(piano_press_sprite[i],0,i);
        
        piano_rainbow_press_sprite[i] =  new cocos2d::CCSprite();
        piano_rainbow_press_sprite[i]->retain();
        piano_rainbow_press_sprite[i]->initWithFile("hd/btn_ColorKeyboard_press_3.png");
        piano_rainbow_press_sprite[i]->setVisible(false);
        controll_layer->addChild( piano_rainbow_press_sprite[i],0,i);
        
    }

    else if(i == 87)
    {
        piano_guid_sprite[i] =  new cocos2d::CCSprite();
        piano_guid_sprite[i]->retain();
        //piano_guid_sprite[i]->setTexture(btn_key_yellow_press_4);
        piano_guid_sprite[i]->initWithFile("hd/btn_key_guide_press_4.png");
        piano_guid_sprite[i]->setVisible(false);
        controll_layer->addChild( piano_guid_sprite[i],-1,i);
        
        piano_press_sprite[i] =  new cocos2d::CCSprite();
        piano_press_sprite[i]->retain();
        //piano_guid_sprite[i]->setTexture(btn_key_yellow_press_1);
        piano_press_sprite[i]->initWithFile("hd/btn_key_yellow_press_4.png");
        piano_press_sprite[i]->setVisible(false);
        controll_layer->addChild( piano_press_sprite[i],0,i);
        
        piano_rainbow_press_sprite[i] =  new cocos2d::CCSprite();
        piano_rainbow_press_sprite[i]->retain();
        piano_rainbow_press_sprite[i]->initWithFile("hd/btn_ColorKeyboard_press_4.png");
        piano_rainbow_press_sprite[i]->setVisible(false);
        controll_layer->addChild( piano_rainbow_press_sprite[i],0,i);
        
    }

    else
    {
        piano_guid_sprite[i] =  new cocos2d::CCSprite();
        piano_guid_sprite[i]->retain();
        //piano_guid_sprite[i]->setTexture(btn_black_key_press);
        piano_guid_sprite[i]->initWithFile("hd/btn_black_key_guide_press.png");
        piano_guid_sprite[i]->setVisible(false);
        controll_layer->addChild( piano_guid_sprite[i],-1,i);

        piano_press_sprite[i] =  new cocos2d::CCSprite();
        piano_press_sprite[i]->retain();
        //piano_guid_sprite[i]->setTexture(btn_key_yellow_press_1);
        piano_press_sprite[i]->initWithFile("hd/btn_black_key_press.png");
        piano_press_sprite[i]->setVisible(false);
        controll_layer->addChild( piano_press_sprite[i],0,i);

        piano_rainbow_press_sprite[i] =  new cocos2d::CCSprite();
        piano_rainbow_press_sprite[i]->retain();
        piano_rainbow_press_sprite[i]->initWithFile("hd/btn_black_key_press.png");
        piano_rainbow_press_sprite[i]->setVisible(false);
        controll_layer->addChild( piano_rainbow_press_sprite[i],0,i);

    }



}


void GameManager::pianoSpriteInit_copy(int index)
{
    int i=index;
    if(gameMode != SINGE_FREE)
    {
        hit_yellow_effect_copy[i] = CCSprite::createWithSpriteFrameName("hit_effect_yellow_1.png");
        hit_yellow_effect_copy[i]->setVisible(false); // ������ ��댄����� 珥�湲고��
        spritebatch->addChild(hit_yellow_effect_copy[i]);//hit_effect
    }
    if(piano_array[i])
    {
        int white_index = this->whiteInPos(i-1);
        effectPosX[i] = ((white_index+1) * SCREEN_SIZE_WHITE_BlockWidth) - SCREEN_SIZE_WHITE_BlockWidth / 2 + WinOrign.x;
        
        DownBlockEndPosX[i] = ((white_index+1) * SCREEN_2X_SIZE_WHITE_BlockWidth) - SCREEN_2X_SIZE_WHITE_BlockWidth / 2 + block_WinOrign.x;
        
    }
    else
    {
        int white_index = this->whiteInPos(i);
        effectPosX[i] = ((float)white_index * SCREEN_SIZE_WHITE_BlockWidth) + WinOrign.x;
        
        DownBlockEndPosX[i] = ((float)white_index * SCREEN_2X_SIZE_WHITE_BlockWidth) + block_WinOrign.x;
        
    }

    //this->pianoSpriteSwitch(i);

    if(i == 0  ||
       i == 3  ||
       i == 8  ||
       i == 15 ||
       i == 20 ||
       i == 27 ||
       i == 32 ||
       i == 39 ||
       i == 44 ||
       i == 51 ||
       i == 56 ||
       i == 63 ||
       i == 68 ||
       i == 75 ||
       i == 80)

    {
        piano_guid_sprite_copy[i] =  new cocos2d::CCSprite();
        piano_guid_sprite_copy[i]->retain();
        piano_guid_sprite_copy[i]->initWithFile("hd/btn_key_guide_press_1.png");
        piano_guid_sprite_copy[i]->setVisible(false);
        controll_layer_copy->addChild( piano_guid_sprite_copy[i],-1,i);
        
        piano_rainbow_press_sprite_copy[i] =  new cocos2d::CCSprite();
        piano_rainbow_press_sprite_copy[i]->retain();
        piano_press_sprite_copy[i]->initWithFile("hd/btn_key_yellow_press_1.png");
        piano_press_sprite_copy[i]->setVisible(false);
        controll_layer_copy->addChild( piano_press_sprite_copy[i],0,i);
        
        piano_rainbow_press_sprite_copy[i] =  new cocos2d::CCSprite();
        piano_rainbow_press_sprite_copy[i]->retain();
        piano_rainbow_press_sprite_copy[i]->initWithFile("hd/btn_ColorKeyboard_press_1.png");
        piano_rainbow_press_sprite_copy[i]->setVisible(false);
        controll_layer->addChild( piano_rainbow_press_sprite_copy[i],0,i);
        
        
    }

    else if(i == 2  ||
            i == 7  ||
            i == 14 ||
            i == 19 ||
            i == 26 ||
            i == 31 ||
            i == 38 ||
            i == 43 ||
            i == 50 ||
            i == 55 ||
            i == 62 ||
            i == 67 ||
            i == 74 ||
            i == 79 ||
            i == 86)

    {
        piano_guid_sprite_copy[i] =  new cocos2d::CCSprite();
        piano_guid_sprite_copy[i]->retain();
        //            piano_guid_sprite[i]->setTexture(btn_key_yellow_press_2);
        piano_guid_sprite_copy[i]->initWithFile("hd/btn_key_guide_press_2.png");
        piano_guid_sprite_copy[i]->setVisible(false);
        controll_layer_copy->addChild( piano_guid_sprite_copy[i],-1,i);


        piano_press_sprite_copy[i] =  new cocos2d::CCSprite();
        piano_press_sprite_copy[i]->retain();
        //piano_guid_sprite[i]->setTexture(btn_key_yellow_press_1);
        piano_press_sprite_copy[i]->initWithFile("hd/btn_key_yellow_press_2.png");
        piano_press_sprite_copy[i]->setVisible(false);
        controll_layer_copy->addChild( piano_press_sprite_copy[i],0,i);
        
        piano_rainbow_press_sprite_copy[i] =  new cocos2d::CCSprite();
        piano_rainbow_press_sprite_copy[i]->retain();
        piano_rainbow_press_sprite_copy[i]->initWithFile("hd/btn_ColorKeyboard_press_2.png");
        piano_rainbow_press_sprite_copy[i]->setVisible(false);
        controll_layer->addChild( piano_rainbow_press_sprite_copy[i],0,i);
    }

    else if(i == 5  ||
            i == 10 ||
            i == 12 ||
            i == 17 ||
            i == 22 ||
            i == 24 ||
            i == 29 ||
            i == 34 ||
            i == 36 ||
            i == 41 ||
            i == 46 ||
            i == 48 ||
            i == 53 ||
            i == 58 ||
            i == 60 ||
            i == 65 ||
            i == 70 ||
            i == 72 ||
            i == 77 ||
            i == 82 ||
            i == 84)
    {
        piano_guid_sprite_copy[i] =  new cocos2d::CCSprite();
        piano_guid_sprite_copy[i]->retain();
        // piano_guid_sprite[i]->setTexture(btn_key_yellow_press_3);
        piano_guid_sprite_copy[i]->initWithFile("hd/btn_key_guide_press_3.png");
        piano_guid_sprite_copy[i]->setVisible(false);
        controll_layer_copy->addChild( piano_guid_sprite_copy[i],-1,i);
        
        piano_press_sprite_copy[i] =  new cocos2d::CCSprite();
        piano_press_sprite_copy[i]->retain();
        //piano_guid_sprite[i]->setTexture(btn_key_yellow_press_1);
        piano_press_sprite_copy[i]->initWithFile("hd/btn_key_yellow_press_3.png");
        piano_press_sprite_copy[i]->setVisible(false);
        controll_layer_copy->addChild(piano_press_sprite_copy[i],0,i);
        
        piano_rainbow_press_sprite_copy[i] =  new cocos2d::CCSprite();
        piano_rainbow_press_sprite_copy[i]->retain();
        piano_rainbow_press_sprite_copy[i]->initWithFile("hd/btn_ColorKeyboard_press_3.png");
        piano_rainbow_press_sprite_copy[i]->setVisible(false);
        controll_layer->addChild( piano_rainbow_press_sprite_copy[i],0,i);
    }
    
    else if(i == 87)
    {
        piano_guid_sprite_copy[i] =  new cocos2d::CCSprite();
        piano_guid_sprite_copy[i]->retain();
        //piano_guid_sprite[i]->setTexture(btn_key_yellow_press_4);
        piano_guid_sprite_copy[i]->initWithFile("hd/btn_key_guide_press_4.png");
        piano_guid_sprite_copy[i]->setVisible(false);
        controll_layer_copy->addChild( piano_guid_sprite_copy[i],-1,i);

        piano_press_sprite_copy[i] =  new cocos2d::CCSprite();
        piano_press_sprite_copy[i]->retain();
        //piano_guid_sprite[i]->setTexture(btn_key_yellow_press_1);
        piano_press_sprite_copy[i]->initWithFile("hd/btn_key_yellow_press_4.png");
        piano_press_sprite_copy[i]->setVisible(false);
        controll_layer_copy->addChild( piano_press_sprite_copy[i],0,i);

        piano_rainbow_press_sprite_copy[i] =  new cocos2d::CCSprite();
        piano_rainbow_press_sprite_copy[i]->retain();
        piano_rainbow_press_sprite_copy[i]->initWithFile("hd/btn_ColorKeyboard_press_4.png");
        piano_rainbow_press_sprite_copy[i]->setVisible(false);
        controll_layer->addChild( piano_rainbow_press_sprite_copy[i],0,i);
    }
    
    else
    {
        piano_guid_sprite_copy[i] =  new cocos2d::CCSprite();
        piano_guid_sprite_copy[i]->retain();
        //piano_guid_sprite[i]->setTexture(btn_black_key_press);
        piano_guid_sprite_copy[i]->initWithFile("hd/btn_black_key_guide_press.png");
        piano_guid_sprite_copy[i]->setVisible(false);
        controll_layer_copy->addChild( piano_guid_sprite_copy[i],-1,i);

        piano_press_sprite_copy[i] =  new cocos2d::CCSprite();
        piano_press_sprite_copy[i]->retain();
        //piano_guid_sprite[i]->setTexture(btn_key_yellow_press_1);
        piano_press_sprite_copy[i]->initWithFile("hd/btn_black_key_press.png");
        piano_press_sprite_copy[i]->setVisible(false);
        controll_layer_copy->addChild( piano_press_sprite_copy[i],0,i);

        piano_rainbow_press_sprite_copy[i] =  new cocos2d::CCSprite();
        piano_rainbow_press_sprite_copy[i]->retain();
        piano_rainbow_press_sprite_copy[i]->initWithFile("hd/btn_black_key_press.png");
        piano_rainbow_press_sprite_copy[i]->setVisible(false);
        controll_layer->addChild( piano_rainbow_press_sprite_copy[i],0,i);
    }
    
    
    
}

void GameManager::pianoSpritePositionSet()
{
    piano_guid_sprite[0]->setPosition(CCPoint(WinOrign.x,EndLineStartPoint.y - piano_guid_sprite[0]->getContentSize().height/2));

    piano_guid_sprite[1]->setPosition(CCPoint((piano_guid_sprite[0]->getPositionX() + piano_guid_sprite[0]->getContentSize().width - piano_guid_sprite[0]->getContentSize().width/2),EndLineStartPoint.y - piano_guid_sprite[1]->getContentSize().height/2));

    piano_guid_sprite[2]->setPosition(CCPoint((piano_guid_sprite[0]->getPositionX() + piano_guid_sprite[0]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[2]->getContentSize().height/2));

    piano_guid_sprite[3]->setPosition(CCPoint((piano_guid_sprite[2]->getPositionX() + piano_guid_sprite[2]->getContentSize().width+1),EndLineStartPoint.y - piano_guid_sprite[3]->getContentSize().height/2));

    piano_guid_sprite[4]->setPosition(CCPoint((piano_guid_sprite[3]->getPositionX() + piano_guid_sprite[3]->getContentSize().width - piano_guid_sprite[3]->getContentSize().width/2),EndLineStartPoint.y - piano_guid_sprite[4]->getContentSize().height/2));

    piano_guid_sprite[5]->setPosition(CCPoint((piano_guid_sprite[3]->getPositionX() + piano_guid_sprite[3]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[5]->getContentSize().height/2));

    piano_guid_sprite[6]->setPosition(CCPoint((piano_guid_sprite[5]->getPositionX() + piano_guid_sprite[5]->getContentSize().width - piano_guid_sprite[5]->getContentSize().width/2),EndLineStartPoint.y - piano_guid_sprite[6]->getContentSize().height/2));

    piano_guid_sprite[7]->setPosition(CCPoint((piano_guid_sprite[5]->getPositionX() + piano_guid_sprite[5]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[7]->getContentSize().height/2));

    piano_guid_sprite[8]->setPosition(CCPoint((piano_guid_sprite[7]->getPositionX() + piano_guid_sprite[7]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[8]->getContentSize().height/2));

    piano_guid_sprite[9]->setPosition(CCPoint((piano_guid_sprite[8]->getPositionX() + piano_guid_sprite[8]->getContentSize().width - piano_guid_sprite[8]->getContentSize().width/2),EndLineStartPoint.y - piano_guid_sprite[9]->getContentSize().height/2));

    piano_guid_sprite[10]->setPosition(CCPoint((piano_guid_sprite[8]->getPositionX() + piano_guid_sprite[8]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[10]->getContentSize().height/2));

    piano_guid_sprite[11]->setPosition(CCPoint((piano_guid_sprite[10]->getPositionX() + piano_guid_sprite[10]->getContentSize().width - piano_guid_sprite[10]->getContentSize().width/2),EndLineStartPoint.y - piano_guid_sprite[11]->getContentSize().height/2));

    piano_guid_sprite[12]->setPosition(CCPoint((piano_guid_sprite[10]->getPositionX() + piano_guid_sprite[10]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[10]->getContentSize().height/2));

    piano_guid_sprite[13]->setPosition(CCPoint((piano_guid_sprite[12]->getPositionX() + piano_guid_sprite[12]->getContentSize().width - piano_guid_sprite[12]->getContentSize().width/2),EndLineStartPoint.y - piano_guid_sprite[13]->getContentSize().height/2));

    piano_guid_sprite[14]->setPosition(CCPoint((piano_guid_sprite[12]->getPositionX() + piano_guid_sprite[12]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[14]->getContentSize().height/2));

    piano_guid_sprite[15]->setPosition(CCPoint((piano_guid_sprite[14]->getPositionX() + piano_guid_sprite[14]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[15]->getContentSize().height/2));

    piano_guid_sprite[16]->setPosition(CCPoint((piano_guid_sprite[15]->getPositionX() + piano_guid_sprite[15]->getContentSize().width - piano_guid_sprite[15]->getContentSize().width/2),EndLineStartPoint.y - piano_guid_sprite[16]->getContentSize().height/2));

    piano_guid_sprite[17]->setPosition(CCPoint((piano_guid_sprite[15]->getPositionX() + piano_guid_sprite[15]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[17]->getContentSize().height/2));

    piano_guid_sprite[18]->setPosition(CCPoint((piano_guid_sprite[17]->getPositionX() + piano_guid_sprite[17]->getContentSize().width - piano_guid_sprite[17]->getContentSize().width/2),EndLineStartPoint.y - piano_guid_sprite[18]->getContentSize().height/2));

    piano_guid_sprite[19]->setPosition(CCPoint((piano_guid_sprite[17]->getPositionX() + piano_guid_sprite[17]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[19]->getContentSize().height/2));

    piano_guid_sprite[20]->setPosition(CCPoint((piano_guid_sprite[19]->getPositionX() + piano_guid_sprite[19]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[20]->getContentSize().height/2));

    piano_guid_sprite[21]->setPosition(CCPoint((piano_guid_sprite[20]->getPositionX() + piano_guid_sprite[20]->getContentSize().width - piano_guid_sprite[20]->getContentSize().width/2),EndLineStartPoint.y - piano_guid_sprite[21]->getContentSize().height/2));

    piano_guid_sprite[22]->setPosition(CCPoint((piano_guid_sprite[20]->getPositionX() + piano_guid_sprite[20]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[22]->getContentSize().height/2));

    piano_guid_sprite[23]->setPosition(CCPoint((piano_guid_sprite[22]->getPositionX() + piano_guid_sprite[22]->getContentSize().width - piano_guid_sprite[22]->getContentSize().width/2),EndLineStartPoint.y - piano_guid_sprite[23]->getContentSize().height/2));

    piano_guid_sprite[24]->setPosition(CCPoint((piano_guid_sprite[22]->getPositionX() + piano_guid_sprite[22]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[24]->getContentSize().height/2));

    piano_guid_sprite[25]->setPosition(CCPoint((piano_guid_sprite[24]->getPositionX() + piano_guid_sprite[24]->getContentSize().width - piano_guid_sprite[24]->getContentSize().width/2),EndLineStartPoint.y - piano_guid_sprite[25]->getContentSize().height/2));

    piano_guid_sprite[26]->setPosition(CCPoint((piano_guid_sprite[24]->getPositionX() + piano_guid_sprite[24]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[26]->getContentSize().height/2));

    piano_guid_sprite[27]->setPosition(CCPoint((piano_guid_sprite[26]->getPositionX() + piano_guid_sprite[26]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[27]->getContentSize().height/2));

    piano_guid_sprite[28]->setPosition(CCPoint((piano_guid_sprite[27]->getPositionX() + piano_guid_sprite[27]->getContentSize().width - piano_guid_sprite[27]->getContentSize().width/2),EndLineStartPoint.y - piano_guid_sprite[28]->getContentSize().height/2));

    piano_guid_sprite[29]->setPosition(CCPoint((piano_guid_sprite[27]->getPositionX() + piano_guid_sprite[27]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[29]->getContentSize().height/2));

    piano_guid_sprite[30]->setPosition(CCPoint((piano_guid_sprite[29]->getPositionX() + piano_guid_sprite[29]->getContentSize().width - piano_guid_sprite[29]->getContentSize().width/2),EndLineStartPoint.y - piano_guid_sprite[30]->getContentSize().height/2));

    piano_guid_sprite[31]->setPosition(CCPoint((piano_guid_sprite[29]->getPositionX() + piano_guid_sprite[29]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[31]->getContentSize().height/2));

    piano_guid_sprite[32]->setPosition(CCPoint((piano_guid_sprite[31]->getPositionX() + piano_guid_sprite[31]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[32]->getContentSize().height/2));

    piano_guid_sprite[33]->setPosition(CCPoint((piano_guid_sprite[32]->getPositionX() + piano_guid_sprite[32]->getContentSize().width - piano_guid_sprite[32]->getContentSize().width/2),EndLineStartPoint.y - piano_guid_sprite[33]->getContentSize().height/2));

    piano_guid_sprite[34]->setPosition(CCPoint((piano_guid_sprite[32]->getPositionX() + piano_guid_sprite[32]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[34]->getContentSize().height/2));

    piano_guid_sprite[35]->setPosition(CCPoint((piano_guid_sprite[34]->getPositionX() + piano_guid_sprite[34]->getContentSize().width - piano_guid_sprite[34]->getContentSize().width/2),EndLineStartPoint.y - piano_guid_sprite[35]->getContentSize().height/2));

    /////////////////////////////////
    //-1
    /////////////////////////////////
    piano_guid_sprite[36]->setPosition(CCPoint((piano_guid_sprite[34]->getPositionX() + piano_guid_sprite[34]->getContentSize().width-1),EndLineStartPoint.y - piano_guid_sprite[36]->getContentSize().height/2));

    piano_guid_sprite[37]->setPosition(CCPoint((piano_guid_sprite[36]->getPositionX() + piano_guid_sprite[36]->getContentSize().width - piano_guid_sprite[36]->getContentSize().width/2),EndLineStartPoint.y - piano_guid_sprite[37]->getContentSize().height/2));

    piano_guid_sprite[38]->setPosition(CCPoint((piano_guid_sprite[36]->getPositionX() + piano_guid_sprite[36]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[38]->getContentSize().height/2));

    /////////////////////////////////
    //+1
    /////////////////////////////////
    piano_guid_sprite[39]->setPosition(CCPoint((piano_guid_sprite[38]->getPositionX() + piano_guid_sprite[38]->getContentSize().width+1),EndLineStartPoint.y - piano_guid_sprite[39]->getContentSize().height/2));

    piano_guid_sprite[40]->setPosition(CCPoint((piano_guid_sprite[39]->getPositionX() + piano_guid_sprite[39]->getContentSize().width - piano_guid_sprite[39]->getContentSize().width/2),EndLineStartPoint.y - piano_guid_sprite[40]->getContentSize().height/2));

    piano_guid_sprite[41]->setPosition(CCPoint((piano_guid_sprite[39]->getPositionX() + piano_guid_sprite[39]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[41]->getContentSize().height/2));

    piano_guid_sprite[42]->setPosition(CCPoint((piano_guid_sprite[41]->getPositionX() + piano_guid_sprite[41]->getContentSize().width - piano_guid_sprite[41]->getContentSize().width/2),EndLineStartPoint.y - piano_guid_sprite[42]->getContentSize().height/2));

    piano_guid_sprite[43]->setPosition(CCPoint((piano_guid_sprite[41]->getPositionX() + piano_guid_sprite[41]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[43]->getContentSize().height/2));

    piano_guid_sprite[44]->setPosition(CCPoint((piano_guid_sprite[43]->getPositionX() + piano_guid_sprite[43]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[44]->getContentSize().height/2));

    piano_guid_sprite[45]->setPosition(CCPoint((piano_guid_sprite[44]->getPositionX() + piano_guid_sprite[44]->getContentSize().width - piano_guid_sprite[44]->getContentSize().width/2),EndLineStartPoint.y - piano_guid_sprite[45]->getContentSize().height/2));

    /////////////////////////////////
    //-1
    /////////////////////////////////
    piano_guid_sprite[46]->setPosition(CCPoint((piano_guid_sprite[44]->getPositionX() + piano_guid_sprite[44]->getContentSize().width-1),EndLineStartPoint.y - piano_guid_sprite[46]->getContentSize().height/2));

    piano_guid_sprite[47]->setPosition(CCPoint((piano_guid_sprite[46]->getPositionX() + piano_guid_sprite[46]->getContentSize().width - piano_guid_sprite[46]->getContentSize().width/2),EndLineStartPoint.y - piano_guid_sprite[47]->getContentSize().height/2));

    piano_guid_sprite[48]->setPosition(CCPoint((piano_guid_sprite[46]->getPositionX() + piano_guid_sprite[46]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[48]->getContentSize().height/2));

    piano_guid_sprite[49]->setPosition(CCPoint((piano_guid_sprite[48]->getPositionX() + piano_guid_sprite[48]->getContentSize().width - piano_guid_sprite[48]->getContentSize().width/2),EndLineStartPoint.y - piano_guid_sprite[49]->getContentSize().height/2));

    piano_guid_sprite[50]->setPosition(CCPoint((piano_guid_sprite[48]->getPositionX() + piano_guid_sprite[48]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[50]->getContentSize().height/2));

    /////////////////////////////////
    //+2
    /////////////////////////////////
    piano_guid_sprite[51]->setPosition(CCPoint((piano_guid_sprite[50]->getPositionX() + piano_guid_sprite[50]->getContentSize().width+2),EndLineStartPoint.y - piano_guid_sprite[51]->getContentSize().height/2));

    piano_guid_sprite[52]->setPosition(CCPoint((piano_guid_sprite[51]->getPositionX() + piano_guid_sprite[51]->getContentSize().width - piano_guid_sprite[51]->getContentSize().width/2),EndLineStartPoint.y - piano_guid_sprite[52]->getContentSize().height/2));


    piano_guid_sprite[53]->setPosition(CCPoint((piano_guid_sprite[51]->getPositionX() + piano_guid_sprite[51]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[53]->getContentSize().height/2));

    piano_guid_sprite[54]->setPosition(CCPoint((piano_guid_sprite[53]->getPositionX() + piano_guid_sprite[53]->getContentSize().width - piano_guid_sprite[53]->getContentSize().width/2),EndLineStartPoint.y - piano_guid_sprite[54]->getContentSize().height/2));

    piano_guid_sprite[55]->setPosition(CCPoint((piano_guid_sprite[53]->getPositionX() + piano_guid_sprite[53]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[55]->getContentSize().height/2));

    piano_guid_sprite[56]->setPosition(CCPoint((piano_guid_sprite[55]->getPositionX() + piano_guid_sprite[55]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[56]->getContentSize().height/2));

    piano_guid_sprite[57]->setPosition(CCPoint((piano_guid_sprite[56]->getPositionX() + piano_guid_sprite[56]->getContentSize().width - piano_guid_sprite[56]->getContentSize().width/2),EndLineStartPoint.y - piano_guid_sprite[57]->getContentSize().height/2));

    /////////////////////////////////
    //-1
    /////////////////////////////////
    piano_guid_sprite[58]->setPosition(CCPoint((piano_guid_sprite[56]->getPositionX() + piano_guid_sprite[56]->getContentSize().width-1),EndLineStartPoint.y - piano_guid_sprite[58]->getContentSize().height/2));

    piano_guid_sprite[59]->setPosition(CCPoint((piano_guid_sprite[58]->getPositionX() + piano_guid_sprite[58]->getContentSize().width - piano_guid_sprite[58]->getContentSize().width/2),EndLineStartPoint.y - piano_guid_sprite[59]->getContentSize().height/2));

    piano_guid_sprite[60]->setPosition(CCPoint((piano_guid_sprite[58]->getPositionX() + piano_guid_sprite[58]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[60]->getContentSize().height/2));

    piano_guid_sprite[61]->setPosition(CCPoint((piano_guid_sprite[60]->getPositionX() + piano_guid_sprite[60]->getContentSize().width - piano_guid_sprite[60]->getContentSize().width/2),EndLineStartPoint.y - piano_guid_sprite[61]->getContentSize().height/2));

    piano_guid_sprite[62]->setPosition(CCPoint((piano_guid_sprite[60]->getPositionX() + piano_guid_sprite[60]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[62]->getContentSize().height/2));

    /////////////////////////////////
    //+2
    /////////////////////////////////
    piano_guid_sprite[63]->setPosition(CCPoint((piano_guid_sprite[62]->getPositionX() + piano_guid_sprite[62]->getContentSize().width+2),EndLineStartPoint.y - piano_guid_sprite[63]->getContentSize().height/2));

    piano_guid_sprite[64]->setPosition(CCPoint((piano_guid_sprite[63]->getPositionX() + piano_guid_sprite[63]->getContentSize().width - piano_guid_sprite[63]->getContentSize().width/2),EndLineStartPoint.y - piano_guid_sprite[64]->getContentSize().height/2));

    piano_guid_sprite[65]->setPosition(CCPoint((piano_guid_sprite[63]->getPositionX() + piano_guid_sprite[63]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[65]->getContentSize().height/2));

    piano_guid_sprite[66]->setPosition(CCPoint((piano_guid_sprite[65]->getPositionX() + piano_guid_sprite[65]->getContentSize().width - piano_guid_sprite[65]->getContentSize().width/2),EndLineStartPoint.y - piano_guid_sprite[66]->getContentSize().height/2));

    piano_guid_sprite[67]->setPosition(CCPoint((piano_guid_sprite[65]->getPositionX() + piano_guid_sprite[65]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[67]->getContentSize().height/2));

    piano_guid_sprite[68]->setPosition(CCPoint((piano_guid_sprite[67]->getPositionX() + piano_guid_sprite[67]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[68]->getContentSize().height/2));

    piano_guid_sprite[69]->setPosition(CCPoint((piano_guid_sprite[68]->getPositionX() + piano_guid_sprite[68]->getContentSize().width - piano_guid_sprite[68]->getContentSize().width/2),EndLineStartPoint.y - piano_guid_sprite[69]->getContentSize().height/2));

    piano_guid_sprite[70]->setPosition(CCPoint((piano_guid_sprite[68]->getPositionX() + piano_guid_sprite[68]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[70]->getContentSize().height/2));

    piano_guid_sprite[71]->setPosition(CCPoint((piano_guid_sprite[70]->getPositionX() + piano_guid_sprite[70]->getContentSize().width - piano_guid_sprite[70]->getContentSize().width/2),EndLineStartPoint.y - piano_guid_sprite[71]->getContentSize().height/2));

    piano_guid_sprite[72]->setPosition(CCPoint((piano_guid_sprite[70]->getPositionX() + piano_guid_sprite[70]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[72]->getContentSize().height/2));

    piano_guid_sprite[73]->setPosition(CCPoint((piano_guid_sprite[72]->getPositionX() + piano_guid_sprite[72]->getContentSize().width - piano_guid_sprite[72]->getContentSize().width/2),EndLineStartPoint.y - piano_guid_sprite[73]->getContentSize().height/2));

    piano_guid_sprite[74]->setPosition(CCPoint((piano_guid_sprite[72]->getPositionX() + piano_guid_sprite[72]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[74]->getContentSize().height/2));

    piano_guid_sprite[75]->setPosition(CCPoint((piano_guid_sprite[74]->getPositionX() + piano_guid_sprite[74]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[75]->getContentSize().height/2));

    piano_guid_sprite[76]->setPosition(CCPoint((piano_guid_sprite[75]->getPositionX() + piano_guid_sprite[75]->getContentSize().width - piano_guid_sprite[75]->getContentSize().width/2),EndLineStartPoint.y - piano_guid_sprite[76]->getContentSize().height/2));

    piano_guid_sprite[77]->setPosition(CCPoint((piano_guid_sprite[75]->getPositionX() + piano_guid_sprite[75]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[77]->getContentSize().height/2));

    piano_guid_sprite[78]->setPosition(CCPoint((piano_guid_sprite[77]->getPositionX() + piano_guid_sprite[77]->getContentSize().width - piano_guid_sprite[77]->getContentSize().width/2),EndLineStartPoint.y - piano_guid_sprite[78]->getContentSize().height/2));

    piano_guid_sprite[79]->setPosition(CCPoint((piano_guid_sprite[77]->getPositionX() + piano_guid_sprite[77]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[79]->getContentSize().height/2));

    piano_guid_sprite[80]->setPosition(CCPoint((piano_guid_sprite[79]->getPositionX() + piano_guid_sprite[79]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[80]->getContentSize().height/2));

    piano_guid_sprite[81]->setPosition(CCPoint((piano_guid_sprite[80]->getPositionX() + piano_guid_sprite[80]->getContentSize().width - piano_guid_sprite[80]->getContentSize().width/2),EndLineStartPoint.y - piano_guid_sprite[81]->getContentSize().height/2));

    piano_guid_sprite[82]->setPosition(CCPoint((piano_guid_sprite[80]->getPositionX() + piano_guid_sprite[80]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[82]->getContentSize().height/2));

    piano_guid_sprite[83]->setPosition(CCPoint((piano_guid_sprite[82]->getPositionX() + piano_guid_sprite[82]->getContentSize().width - piano_guid_sprite[82]->getContentSize().width/2),EndLineStartPoint.y - piano_guid_sprite[83]->getContentSize().height/2));

    piano_guid_sprite[84]->setPosition(CCPoint((piano_guid_sprite[82]->getPositionX() + piano_guid_sprite[82]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[84]->getContentSize().height/2));

    piano_guid_sprite[85]->setPosition(CCPoint((piano_guid_sprite[84]->getPositionX() + piano_guid_sprite[84]->getContentSize().width - piano_guid_sprite[84]->getContentSize().width/2),EndLineStartPoint.y - piano_guid_sprite[85]->getContentSize().height/2));

    piano_guid_sprite[86]->setPosition(CCPoint((piano_guid_sprite[84]->getPositionX() + piano_guid_sprite[84]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[86]->getContentSize().height/2));

    piano_guid_sprite[87]->setPosition(CCPoint((piano_guid_sprite[86]->getPositionX() + piano_guid_sprite[86]->getContentSize().width),EndLineStartPoint.y - piano_guid_sprite[87]->getContentSize().height/2));


    for(int a=0;a<88;a++)
    {
        piano_press_sprite[a]->setPosition(piano_guid_sprite[a]->getPosition());
        piano_rainbow_press_sprite[a]->setPosition(piano_guid_sprite[a]->getPosition());
        if(gameMode != SINGE_FREE)
        {
            hit_yellow_effect[a]->setPosition(ccp(piano_press_sprite[a]->getPositionX(),piano_press_sprite[0]->getPositionY()+205));
        }
    }
    
}



void GameManager::pianoSpritePositionSet_copy()
{
    for(int a=0;a<88;a++)
    {
        piano_guid_sprite_copy[a]->setPosition(piano_guid_sprite[a]->getPosition());
        piano_press_sprite_copy[a]->setPosition(piano_guid_sprite_copy[a]->getPosition());
        piano_rainbow_press_sprite_copy[a]->setPosition(piano_guid_sprite_copy[a]->getPosition());
        if(gameMode != SINGE_FREE)
        {
            hit_yellow_effect_copy[a]->setPosition(ccp(piano_press_sprite_copy[a]->getPositionX(),piano_press_sprite_copy[0]->getPositionY()));
        }
    }
}



int GameManager::whiteInPos(int index)
{
    if(index > 85)
    {
        return index-36;
    }
    if(index > 83)
    {
        return index-35;
    }
    if(index > 81)
    {
        return index-34;
    }


    if(index > 78)
    {
        return index-33;
    }
    if(index > 76)
    {
        return index-32;
    }


    if(index > 73)
    {
        return index-31;
    }
    if(index > 71)
    {
        return index-30;
    }
    if(index > 69)
    {
        return index-29;
    }


    if(index > 66)
    {
        return index-28;
    }
    if(index > 64)
    {
        return index-27;
    }


    if(index > 61)
    {
        return index-26;
    }
    if(index > 59)
    {
        return index-25;
    }
    if(index > 57)
    {
        return index-24;
    }


    if(index > 54)
    {
        return index-23;
    }
    if(index > 52)
    {
        return index-22;
    }


    if(index > 49)
    {
        return index-21;
    }
    if(index > 47)
    {
        return index-20;
    }
    if(index > 45)
    {
        return index-19;
    }


    if(index > 42)
    {
        return index-18;
    }
    if(index > 40)
    {
        return index-17;
    }


    if(index > 37)
    {
        return index-16;
    }
    if(index > 35)
    {
        return index-15;
    }
    if(index > 33)
    {
        return index-14;
    }


    if(index > 30)
    {
        return index-13;
    }
    if(index > 28)
    {
        return index-12;
    }


    if(index > 25)
    {
        return index-11;
    }
    if(index > 23)
    {
        return index-10;
    }
    if(index > 21)
    {
        return index-9;
    }

    
    if(index > 18)
    {
        return index-8;
    }
    if(index > 16)
    {
        return index-7;
    }


    if(index > 13)
    {
        return index-6;
    }
    if(index > 11)
    {
        return index-5;
    }
    if(index > 9)
    {
        return index-4;
    }


    if(index > 6)
    {
        return index-3;
    }
    if(index > 4)
    {
        return index-2;
    }

    if(index > 1)
    {
        return index-1;
    }

    return 0;
}


CCSize GameManager::calSize(CCSize destSize)
{
    CCSize screenSize = CCEGLView::sharedOpenGLView()->getFrameSize();
    
    CCSize size = CCSize(screenSize.width * destSize.width / 1920,
                         screenSize.height * destSize.height / 1080);

    
    
    return size;
}


//誘몃��濡����
void GameManager::Midi_Load()
{
    CCLOG("Midi_Load Path : %s",midiPath);

#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    //Salut d'amour


    // char midiFileName[100] = "MoonLight Sonata.mid";
    char midiFileName[100] = "Jack and Jill.mid";
    //char midiFileName[100] = "haul.mid";
    //  char midiFileName[100] = "Totoro.mid";
    //    char midiFileName[100] = "Silent Night.mid";
    //    char midiFileName[100] = "Celebrated Chop Waltz.mid";
    //  char midiFileName[100] = "He is a pirate.mid";
    //  char midiFileName[100] = "No.12 Revolutionary.mid";
    //  char midiFileName[100] = "Celebrated Chop Waltz.mid";
    //char midiFileName[100] = "Puff the Magic Dragon.mid";
    //char midiFileName[100] = "Charming Snake.mid";
    //   char midiFileName[100] = "Twinkle twinkle little star.mid";
    //   char midiFileName[100] = "Salut d'amour.mid";
    MIDIFileLoader loader;
    CCFileUtils* fileUtils = CCFileUtils::sharedFileUtils();
    std::string fullPath = fileUtils->fullPathForFilename(midiFileName);

    loader.loadFile(fullPath);
#endif

#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

    CCFileUtils *fileUtils = CCFileUtils::sharedFileUtils();

    // long value that holds the file size in bytes
    unsigned long fileSize;
    unsigned char *fileData = fileUtils->getFileData(midiPath, "rb", &fileSize);

    // fetching the writable path
    std::string writablePath = fileUtils->getWritablePath();

    // char array to store the full path
    char path11[2048];
    //music/twinkle_twinkle.mid
    //    sprintf(path, "%s%s", writablePath.c_str(), "twinkle_twinkle.mid");
    sprintf(path11, "%s%s", writablePath.c_str(), Singleton<GameManager>::GetInst()->midiPath);
    FILE *wf = fopen(path11,"wb");
    if( wf && fileSize > 0 )
    {
        fwrite(fileData, 1, fileSize, wf);
    }

    fclose(wf);

    std::string strTemp = path11;

    MIDIFileLoader loader;
    loader.loadFile(strTemp);



#endif


    for(int a=0;a<_collision_boxes_Channel.size();a++)
    {
        std::vector<Block *> _collision_boxes = _collision_boxes_Channel.at(a);
        Block *target =  _collision_boxes.at(0);
        if(minTime > target->elapsedMillis)
        {
            minTime = target->elapsedMillis;
        }
    }
    if(minTime > 0)
    {
        minTime = 0;
    }
    CCLog("minTime : %f",minTime);


}

void GameManager::printNodeInit()
{
    CCLog("_guide_print_blocks : %d",_guide_print_blocks.size());
    Iter_Guide_Node_Pos = _guide_print_blocks.begin();
    Iter_Print_Node_Pos = _print_blocks.begin();
    //  Iter_Erase_Node_Pos = _erase_print_blocks.begin();
    nodePrintingCount = 0;

    
    Singleton<GameManager>::GetInst()->makeCollisinoBoxes_update(NULL,0); //媛���대����쇱�� 留���ㅺ린
    
    // nodePrintingCount = firstPrintNodeCount;
    //this->printNode(firstPrintNodeCount);
    this->printNode(1);
}

void GameManager::printNode(int count)
{
    if(totalNodeCount > nodePrintingCount && _print_blocks.size() != 0)
    {
        int index = 0;
        if(totalNodeCount > nodePrintingCount+5)
        {
            index = count;
        }
        else
        {
            index = totalNodeCount - nodePrintingCount;
        }

        while(index != 0)
        {
            --index;
            Iter_Print_Node_Pos = _print_blocks.begin();
            ++nodePrintingCount;
            if(Iter_Print_Node_Pos->second->body != NULL)
            {
                Iter_Print_Node_Pos->second->print_layer->addChild(Iter_Print_Node_Pos->second->body);
            }
            else
            {
                Iter_Print_Node_Pos->second->print_layer->addChild(Iter_Print_Node_Pos->second->tail);
            }
            _print_blocks.erase(Iter_Print_Node_Pos);
            
            if(_print_blocks.size() == 0)
            {
                break;
            }
        }
    }
}



std::string GameManager::keyCheck(int keyCode)
{
    if(keyCode == 0)
    {
        return "A-1";
    }
    else if(keyCode == 1)
    {
        return "A#1";
    }
    else if(keyCode == 2)
    {
        return "B-1";
    }
    else if(keyCode == 3)
    {
        return "C0";
    }
    else if(keyCode == 4)
    {
        return "C#0";
    }
    else if(keyCode == 5)
    {
        return "D0";
    }
    else if(keyCode == 6)
    {
        return "D#0";
    }
    else if(keyCode == 7)
    {
        return "E0";
    }
    else if(keyCode == 8)
    {
        return "F0";
    }
    else if(keyCode == 9)
    {
        return "F#0";
    }
    else if(keyCode == 10)
    {
        return "G0";
    }
    else if(keyCode == 11)
    {
        return "G#0";
    }
    else if(keyCode == 12)
    {
        return "A0";
    }
    else if(keyCode == 13)
    {
        return "A#0";
    }
    else if(keyCode == 14)
    {
        return "B0";
    }
    else if(keyCode == 15)
    {
        return "C1";
    }
    else if(keyCode == 16)
    {
        return "C#1";
    }
    else if(keyCode == 17)
    {
        return "D1";
    }
    else if(keyCode == 18)
    {
        return "D#1";
    }
    else if(keyCode == 19)
    {
        return "E1";
    }
    else if(keyCode == 20)
    {
        return "F1";
    }
    else if(keyCode == 21)
    {
        return "F#1";
    }
    else if(keyCode == 22)
    {
        return "G1";
    }
    else if(keyCode == 23)
    {
        return "G#1";
    }
    else if(keyCode == 24)
    {
        return "A1";
    }
    else if(keyCode == 25)
    {
        return "A#1";
    }
    else if(keyCode == 26)
    {
        return "B1";
    }
    else if(keyCode == 27)
    {
        return "C2";
    }
    else if(keyCode == 28)
    {
        return "C#2";
    }
    else if(keyCode == 29)
    {
        return "D2";
    }
    else if(keyCode == 30)
    {
        return "D#2";
    }
    else if(keyCode == 31)
    {
        return "E2";
    }
    else if(keyCode == 32)
    {
        return "F2";
    }
    else if(keyCode == 33)
    {
        return "F#2";
    }
    else if(keyCode == 34)
    {
        return "G2";
    }
    else if(keyCode == 35)
    {
        return "G#2";
    }
    else if(keyCode == 36)
    {
        return "A2";
    }
    else if(keyCode == 37)
    {
        return "A#2";
    }
    else if(keyCode == 38)
    {
        return "B2";
    }
    else if(keyCode == 39)
    {
        return "C3";
    }
    else if(keyCode == 40)
    {
        return "C#3";
    }
    else if(keyCode == 41)
    {
        return "D3";
    }
    else if(keyCode == 42)
    {
        return "D#3";
    }
    else if(keyCode == 43)
    {
        return "E3";
    }
    else if(keyCode == 44)
    {
        return "F3";
    }
    else if(keyCode == 45)
    {
        return "F#3";
    }
    else if(keyCode == 46)
    {
        return "G3";
    }
    else if(keyCode == 47)
    {
        return "G#3";
    }
    else if(keyCode == 48)
    {
        return "A3";
    }
    else if(keyCode == 49)
    {
        return "A#3";
    }
    else if(keyCode == 50)
    {
        return "B3";
    }
    else if(keyCode == 51)
    {
        return "C4";
    }
    else if(keyCode == 52)
    {
        return "C#4";
    }
    else if(keyCode == 53)
    {
        return "D4";
    }
    else if(keyCode == 54)
    {
        return "D#4";
    }
    else if(keyCode == 55)
    {
        return "E4";
    }
    else if(keyCode == 56)
    {
        return "F4";
    }
    else if(keyCode == 57)
    {
        return "F#4";
    }
    else if(keyCode == 58)
    {
        return "G4";
    }
    else if(keyCode == 59)
    {
        return "G#4";
    }
    else if(keyCode == 60)
    {
        return "A4";
    }
    else if(keyCode == 61)
    {
        return "A#4";
    }
    else if(keyCode == 62)
    {
        return "B4";
    }
    else if(keyCode == 63)
    {
        return "C5";
    }
    else if(keyCode == 64)
    {
        return "C#5";
    }
    else if(keyCode == 65)
    {
        return "D5";
    }
    else if(keyCode == 66)
    {
        return "D#5";
    }
    else if(keyCode == 67)
    {
        return "E5";
    }
    else if(keyCode == 68)
    {
        return "F5";
    }
    else if(keyCode == 69)
    {
        return "F#5";
    }
    else if(keyCode == 70)
    {
        return "G5";
    }
    else if(keyCode == 71)
    {
        return "G#5";
    }
    else if(keyCode == 72)
    {
        return "A5";
    }
    else if(keyCode == 73)
    {
        return "A#5";
    }
    else if(keyCode == 74)
    {
        return "B5";
    }
    else if(keyCode == 75)
    {
        return "C6";
    }
    else if(keyCode == 76)
    {
        return "C#6";
    }
    else if(keyCode == 77)
    {
        return "D6";
    }
    else if(keyCode == 78)
    {
        return "D#6";
    }
    else if(keyCode == 79)
    {
        return "E6";
    }
    else if(keyCode == 80)
    {
        return "F6";
    }
    else if(keyCode == 81)
    {
        return "F#6";
    }
    else if(keyCode == 82)
    {
        return "G6";
    }
    else if(keyCode == 83)
    {
        return "G#6";
    }
    else if(keyCode == 84)
    {
        return "A6";
    }
    else if(keyCode == 85)
    {
        return "A#6";
    }
    else if(keyCode == 86)
    {
        return "B6";
    }
    else if(keyCode == 87)
    {
        return "C7";
    }




    return "ERR";
}

int GameManager::doremipasolasi(int keyCode)
{
    if(keyCode == 3 ||
       keyCode == 15 ||
       keyCode == 27 ||
       keyCode == 39 ||
       keyCode == 51 ||
       keyCode == 63 ||
       keyCode == 75 ||
       keyCode == 87
       )
    {
        return 0;
    }
    else if(keyCode == 5 ||
            keyCode == 17 ||
            keyCode == 29 ||
            keyCode == 41 ||
            keyCode == 53 ||
            keyCode == 65 ||
            keyCode == 77
            )
    {
        return 1;
    }
    else if(keyCode == 7 ||
            keyCode == 19 ||
            keyCode == 31 ||
            keyCode == 43 ||
            keyCode == 55 ||
            keyCode == 67 ||
            keyCode == 79
            )
    {
        return 2;
    }
    else if(keyCode == 8 ||
            keyCode == 20 ||
            keyCode == 32 ||
            keyCode == 44 ||
            keyCode == 56 ||
            keyCode == 68 ||
            keyCode == 80
            )
    {
        return 3;
    }
    else if(keyCode == 10 ||
            keyCode == 22 ||
            keyCode == 34 ||
            keyCode == 46 ||
            keyCode == 58 ||
            keyCode == 70 ||
            keyCode == 82
            )
    {
        return 4;
    }
    else if(keyCode == 0 ||
            keyCode == 12 ||
            keyCode == 24 ||
            keyCode == 36 ||
            keyCode == 48 ||
            keyCode == 60 ||
            keyCode == 72 ||
            keyCode == 82
            )
    {
        return 5;
    }
    else if(keyCode == 2 ||
            keyCode == 14 ||
            keyCode == 26 ||
            keyCode == 38 ||
            keyCode == 50 ||
            keyCode == 62 ||
            keyCode == 74 ||
            keyCode == 86
            )
    {
        return 6;
    }

    return -1;
}

void GameManager::start_count_display()
{
    Singleton<GameManager>::GetInst()->tutorialMode = true;

    std::map<double, Block *>::iterator Iter_Pos = Singleton<GameManager>::GetInst()->_guide_print_blocks.begin();

    Block *target = Iter_Pos->second;
    
    double timeMillis = target->timeMillis;
    
    while (1)
    {
        ++Iter_Pos;
        Block *dest_target = Iter_Pos->second;

        if(timeMillis != dest_target->timeMillis)
        {
            Singleton<GameManager>::GetInst()->pianoGuideVisible(target->lineNum);
            break;
        }
        else
        {
            Singleton<GameManager>::GetInst()->pianoGuideVisible(target->lineNum);
            Singleton<GameManager>::GetInst()->pianoGuideVisible(dest_target->lineNum);
        }
    }
}

void GameManager::cry_end()
{
    npc_sprite->runAction( CCRepeatForever::create( idle_animate ) );
}
void GameManager::replaceAnimation(int ani)
{
    npc_state = ani;
    
    if (npc_sprite != NULL)
    {
    	npc_sprite->stopAllActions();
    }
    if(npc_state == Npc_STATE_CRY)
    {
    //	CCLog("Npc_STATE_CRY");
        action = CCSequence::create(
        								cry_animate,
        								CCCallFunc::create(this, callfunc_selector(GameManager::cry_end)),
                                                         NULL);
    	action->retain();
        npc_sprite->runAction( action );
    }
    /*
     else if(npc_state == Npc_STATE_HURT)
     {
     CCFiniteTimeAction*  action = CCSequence::create(
     hurt_animate,
     CCCallFunc::create(this, callfunc_selector(GameManager::attack_end)),
     NULL);

     npc_sprite->runAction( action  );

     }
     */
}

