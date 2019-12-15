#include "iCadeManager.h"

#import "iCadeReaderView.h"
#include "cocos2d.h"
#import "EAGLView.h" 
USING_NS_CC;

static iCadeReaderView *_icrv = nil;

@interface iCadeReaderViewDelegateWrapper : NSObject <iCadeEventDelegate> {
@public
    BOOL _isUpPressed;
    BOOL _isDownPressed;
    BOOL _isAnyButtonPressed;
    
    struct {
        BOOL moveUp = YES;
        BOOL moveDown = YES;
        BOOL stopMoving = YES;
        BOOL fireWeapon = YES;
        BOOL iCadeActive = YES;
    } _delegateFlags;
}
- (void)buttonDown:(const char*)button;
- (void)buttonUp:(const char*)button;
@end

@implementation iCadeReaderViewDelegateWrapper

#pragma mark - iCadeReaderView callbacks

-(void)buttonDown:(const char*)button
{
    CCDirector::sharedDirector()->getKeypadDispatcher()->dispatchKeypadTouch(button,true);

    
    //CCDirector::sharedDirector()->getKeypadDispatcher()->dispatchKeypadMSG(kTypeBackClicked);
    /*
    if (button == iCadeJoystickUp) {
        //        CCLOG(@"pressing up");
        _isUpPressed = TRUE;
    } else if (button == iCadeJoystickDown) {
        //        CCLOG(@"pressing down");
        _isDownPressed = TRUE;
    } else if (button == iCadeButtonA ||
               button == iCadeButtonB ||
               button == iCadeButtonC ||
               button == iCadeButtonD ||
               button == iCadeButtonE ||
               button == iCadeButtonF ||
               button == iCadeButtonG ||
               button == iCadeButtonH) {
        //        CCLOG(@"pressing button");
        _isAnyButtonPressed = TRUE;
    }
    */
    
    /*
    if (button == iCadeJoystickUpRight) {
        CCDirector::sharedDirector()->getKeypadDispatcher()->dispatchKeypadMSG(kTypeKeyDown, iCadeManager::sharediCadeManager()->remapToKey(iCadeJoystickUp));
        CCDirector::sharedDirector()->getKeypadDispatcher()->dispatchKeypadMSG(kTypeKeyDown, iCadeManager::sharediCadeManager()->remapToKey(iCadeJoystickRight));
    } else if (button == iCadeJoystickDownRight) {
        CCDirector::sharedDirector()->getKeypadDispatcher()->dispatchKeypadMSG(kTypeKeyDown, iCadeManager::sharediCadeManager()->remapToKey(iCadeJoystickDown));
        CCDirector::sharedDirector()->getKeypadDispatcher()->dispatchKeypadMSG(kTypeKeyDown, iCadeManager::sharediCadeManager()->remapToKey(iCadeJoystickRight));
    } else if (button == iCadeJoystickUpLeft) {
        CCDirector::sharedDirector()->getKeypadDispatcher()->dispatchKeypadMSG(kTypeKeyDown, iCadeManager::sharediCadeManager()->remapToKey(iCadeJoystickUp));
        CCDirector::sharedDirector()->getKeypadDispatcher()->dispatchKeypadMSG(kTypeKeyDown, iCadeManager::sharediCadeManager()->remapToKey(iCadeJoystickLeft));
    } else if (button == iCadeJoystickDownLeft) {
        CCDirector::sharedDirector()->getKeypadDispatcher()->dispatchKeypadMSG(kTypeKeyDown, iCadeManager::sharediCadeManager()->remapToKey(iCadeJoystickDown));
        CCDirector::sharedDirector()->getKeypadDispatcher()->dispatchKeypadMSG(kTypeKeyDown, iCadeManager::sharediCadeManager()->remapToKey(iCadeJoystickLeft));
    } else {
        CCDirector::sharedDirector()->getKeypadDispatcher()->dispatchKeypadMSG(kTypeKeyDown, iCadeManager::sharediCadeManager()->remapToKey(button));
    }
     */
}

-(void)buttonUp:(const char*)button
{
    //NSLog(@"released up");
    CCDirector::sharedDirector()->getKeypadDispatcher()->dispatchKeypadTouch(button,false);
    /*
    if (button == iCadeJoystickUp) {
        //        CCLOG(@"released up");
        _isUpPressed = FALSE;
    } else if (button == iCadeJoystickDown) {
        //        CCLOG(@"released down");
        _isDownPressed = FALSE;
    } else if (button == iCadeButtonA ||
               button == iCadeButtonB ||
               button == iCadeButtonC ||
               button == iCadeButtonD ||
               button == iCadeButtonE ||
               button == iCadeButtonF ||
               button == iCadeButtonG ||
               button == iCadeButtonH) {
        //        CCLOG(@"released button");
        _isAnyButtonPressed = FALSE;
    }
     */
    /*
    if (button == iCadeJoystickUpRight) {
        CCDirector::sharedDirector()->getKeypadDispatcher()->dispatchKeypadMSG(kTypeKeyUp, iCadeManager::sharediCadeManager()->remapToKey(iCadeJoystickUp));
        CCDirector::sharedDirector()->getKeypadDispatcher()->dispatchKeypadMSG(kTypeKeyUp, iCadeManager::sharediCadeManager()->remapToKey(iCadeJoystickRight));
    } else if (button == iCadeJoystickDownRight) {
        CCDirector::sharedDirector()->getKeypadDispatcher()->dispatchKeypadMSG(kTypeKeyUp, iCadeManager::sharediCadeManager()->remapToKey(iCadeJoystickDown));
        CCDirector::sharedDirector()->getKeypadDispatcher()->dispatchKeypadMSG(kTypeKeyUp, iCadeManager::sharediCadeManager()->remapToKey(iCadeJoystickRight));
    } else if (button == iCadeJoystickUpLeft) {
        CCDirector::sharedDirector()->getKeypadDispatcher()->dispatchKeypadMSG(kTypeKeyUp, iCadeManager::sharediCadeManager()->remapToKey(iCadeJoystickUp));
        CCDirector::sharedDirector()->getKeypadDispatcher()->dispatchKeypadMSG(kTypeKeyUp, iCadeManager::sharediCadeManager()->remapToKey(iCadeJoystickLeft));
    } else if (button == iCadeJoystickDownLeft) {
        CCDirector::sharedDirector()->getKeypadDispatcher()->dispatchKeypadMSG(kTypeKeyUp, iCadeManager::sharediCadeManager()->remapToKey(iCadeJoystickDown));
        CCDirector::sharedDirector()->getKeypadDispatcher()->dispatchKeypadMSG(kTypeKeyUp, iCadeManager::sharediCadeManager()->remapToKey(iCadeJoystickLeft));
    } else {
        CCDirector::sharedDirector()->getKeypadDispatcher()->dispatchKeypadMSG(kTypeKeyUp, iCadeManager::sharediCadeManager()->remapToKey(button));
    }
     */
}
@end

static iCadeManager *_sharediCadeManager = NULL;

iCadeManager *iCadeManager::sharediCadeManager() {
    
    if (_sharediCadeManager == nil) {
        _sharediCadeManager = iCadeManager::create();
        CC_SAFE_RETAIN(_sharediCadeManager);
    }
    
    return _sharediCadeManager;
}

bool iCadeManager::init() {
    
     // iCade
    _icrv = [[iCadeReaderView alloc] initWithFrame:CGRectZero];
    _icrv.active = NO;
    _icrv.delegate = [[iCadeReaderViewDelegateWrapper alloc] init];
    
    return true;
}

iCadeManager::~iCadeManager() {
    id<iCadeEventDelegate> temp = _icrv.delegate;
    _icrv.delegate = nil;
    [_icrv release];
    _icrv = nil;
    [temp release];
}

void iCadeManager::enableUsingScheduler(float dt) {
    enable();
}

void iCadeManager::enable()
{
    EAGLView *root = [EAGLView sharedEGLView];
    
    // if we are adding a delegate when there was none before we need removed the keyboard listeners for the eagl view
    [[NSNotificationCenter defaultCenter] removeObserver:root
                                                    name:UIKeyboardWillShowNotification object:nil];
    
    [[NSNotificationCenter defaultCenter] removeObserver:root
                                                    name:UIKeyboardDidShowNotification object:nil];
    
    [[NSNotificationCenter defaultCenter] removeObserver:root
                                                    name:UIKeyboardWillHideNotification object:nil];
    
    [[NSNotificationCenter defaultCenter] removeObserver:root
                                                    name:UIKeyboardDidHideNotification object:nil];
    
    //    if (![[root subviews] containsObject:_icrv]) {
    [root addSubview:_icrv];
    //    }
    
    _icrv.active = YES;
}

void iCadeManager::disable() {
    EAGLView *root = [EAGLView sharedEGLView];
    
    // if we are removing the delegate then we need to get keyboard events in the eagl view
    [[NSNotificationCenter defaultCenter] addObserver:root
                                             selector:@selector(onUIKeyboardNotification:)
                                                 name:UIKeyboardWillShowNotification object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:root
                                             selector:@selector(onUIKeyboardNotification:)
                                                 name:UIKeyboardDidShowNotification object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:root
                                             selector:@selector(onUIKeyboardNotification:)
                                                 name:UIKeyboardWillHideNotification object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:root
                                             selector:@selector(onUIKeyboardNotification:)
                                                 name:UIKeyboardDidHideNotification object:nil];
    //    if ([[root subviews] containsObject:_icrv]) {
    [_icrv removeFromSuperview];
    //    }
    
    _icrv.active = NO;
}

ccKeypadKeycode iCadeManager::remapToKey(short state) {
    ccKeypadKeycode key = kKeycodeUNKNOWN;
    switch (state) {
        case iCadeJoystickUp:
            key = kKeycodeDPAD_UP;
            break;
        case iCadeJoystickRight:
            key = kKeycodeDPAD_RIGHT;
            break;
        case iCadeJoystickDown:
            key = kKeycodeDPAD_DOWN;
            break;
        case iCadeJoystickLeft:
            key = kKeycodeDPAD_LEFT;
            break;
        case iCadeButtonA:
            key = kKeycodeBUTTON_A;
            break;
        case iCadeButtonB:
            key = kKeycodeBUTTON_B;
            break;
        case iCadeButtonC:
            key = kKeycodeBUTTON_C;
            break;
        case iCadeButtonD:
            key = kKeycodeBUTTON_X;
            break;
        case iCadeButtonE:
            key = kKeycodeBUTTON_Y;
            break;
        case iCadeButtonF:
            key = kKeycodeBUTTON_Z;
            break;
        case iCadeButtonG:
            key = kKeycodeBUTTON_SELECT;
            break;
        case iCadeButtonH:
            key = kKeycodeBUTTON_START;
            break;
        case iCadeJoystickNone:
        default:
            break;
    }
    
    return key;
}