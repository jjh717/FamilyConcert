#include "AppDelegate.h"
#include "GameManager.h"
USING_NS_CC;


AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
    CCLog("~AppDelegate()");
    //delete Singleton<GameManager>::destroyer();
   // Singleton<GameManager>::destroyer();
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    CCDirector *pDirector = CCDirector::sharedDirector();
    pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());
    
    CCSize screenSize = CCEGLView::sharedOpenGLView()->getFrameSize();
    CCLOG("screenSize : %f    %f",screenSize.width,screenSize.height );
    CCSize designSize = CCSizeMake(1920, 1080);
    //std::vector<std::string> searchPaths;
    
   // if (screenSize.height > 320)
   // {
        //searchPaths.push_back("hd");
        //searchPaths.push_back("sd");
     //   pDirector->setContentScaleFactor(screenSize.height/designSize.height);

        
   // }
  //  else
  //  {
    //    searchPaths.push_back("sd");
    ///    pDirector->setContentScaleFactor(320.0f/designSize.height);
   // }
    
    //CCFileUtils::sharedFileUtils()->setSearchPaths(searchPaths);
    
    CCEGLView::sharedOpenGLView()->setDesignResolutionSize(designSize.width, designSize.height, kResolutionExactFit);

    
    
    
    /*
    CCDirector *pDirector = CCDirector::sharedDirector();
    
    pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());
    
    CCSize screenSize = CCEGLView::sharedOpenGLView()->getFrameSize();
    CCSize designSize = CCSizeMake(480, 320);
    std::vector<std::string> searchPaths;
    
    if (screenSize.height > 320)
    {
        searchPaths.push_back("hd");
        searchPaths.push_back("sd");
        pDirector->setContentScaleFactor(640.0f/designSize.height);
    }
    else
    {
        searchPaths.push_back("sd");
        pDirector->setContentScaleFactor(320.0f/designSize.height);
    }
    
    CCFileUtils::sharedFileUtils()->setSearchPaths(searchPaths);
    
    CCEGLView::sharedOpenGLView()->setDesignResolutionSize(designSize.width, designSize.height, kResolutionNoBorder);
*/
    /*
    
    CCDirector *pDirector = CCDirector::sharedDirector();
	CCEGLView *pEGLView = CCEGLView::sharedOpenGLView();
    pDirector->setOpenGLView(pEGLView);
    
     */
     
    
    // turn on display FPS
    pDirector->setDisplayStats(false);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);
  
    Singleton<GameManager>::GetInst()->init();
    Singleton<GameManager>::GetInst()->runScene(GAME_SCENE_STARTLOAD);
    
 
    return true;
}


// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // CocosDenshion::SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
