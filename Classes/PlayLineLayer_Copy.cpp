#include "PlayLineLayer_copy.h"

PlayLineLayer_Copy::PlayLineLayer_Copy()
{
    
}

PlayLineLayer_Copy::~PlayLineLayer_Copy()
{

}




bool PlayLineLayer_Copy::init()
{
    Singleton<GameManager>::GetInst()->SetLineLayer_copy(this);
    /*
    float x=0, y=0, z=0;
    this->getCamera()->getCenterXYZ(&x, &y, &z);
    CCLOG("PlayLineLayer_Copy y = %f",y);
    this->getCamera()->setCenterXYZ(x, y+0.0000001, z);
*/
    
    return true;
}



void PlayLineLayer_Copy::update(float dt)
{
   
}

