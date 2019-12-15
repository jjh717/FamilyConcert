//
//  CRectObject.h
//  HelloCpp
//
//  Created by iLab on 13. 2. 26..
//
//

#ifndef __HelloCpp__CRectObject__
#define __HelloCpp__CRectObject__

#include <cocos2d.h>

using namespace cocos2d;



class CRectObject : public CCObject
{
    private:
        CCRect m_sRect;
        
    public:
        CRectObject(CCRect rect) {m_sRect=rect;}
        CCRect getRect() {return this->m_sRect;}

};
#endif /* defined(__HelloCpp__CRectObject__) */
