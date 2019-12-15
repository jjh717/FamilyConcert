#include "PlayBlockLayer_Copy.h"
#include "Block.h"


//Edited by AhnGun


 
PlayBlockLayer_Copy::PlayBlockLayer_Copy()
{
    
}

PlayBlockLayer_Copy::~PlayBlockLayer_Copy()
{
    
    
    
    
    
}




bool PlayBlockLayer_Copy::init()
{
//Edited by AhnGun
    
    
    float x=0, y=0, z=0;
    this->getCamera()->getCenterXYZ(&x, &y, &z);
    CCLOG("PlayBlockLayer_Copy y = %f",y);
    this->getCamera()->setCenterXYZ(x, y+0.0000001, z);
    
    
//    gluPerspective
    return true;
}



void PlayBlockLayer_Copy::update(float dt)
{
   
}
int PlayBlockLayer_Copy::blackInPos(int index)
{
    
    return 0;
}








float PlayBlockLayer_Copy::halfLineXPostion(int index)
{
    float pos = 550;
    //blueBlockWidth 32  16
    //yellowBlockWidth 38  19
    
    switch (index)
    {
        case 1:
            pos = 573;
            break;
        case 2:
            pos = 578;
            break;
        case 3:
            pos = 595;
            break;
        case 4:
            pos = 605;
            break;
        case 5:
            pos = 610;
            break;
        case 6:
            pos = 618;
            break;
        case 7:
            pos = 628;
            break;
        case 8:
            pos = 636;
            break;
        case 9:
            pos = 647;
            break;
        case 10:
            pos = 655;
            break;
        case 11:
            pos = 660;
            break;
        case 12:
            pos = 670;
            break;
        case 13:
            pos = 675;
            break;
        case 14:
            pos = 685;
            break;
        case 15:
            pos = 695;
            break;
        case 16:
            pos = 705;
            break;
        case 17:
            pos = 715;
            break;
        case 18:
            pos = 720;
            break;
        case 19:
            pos = 725;
            break;
        case 20:
            pos = 735;
            break;
        case 21:
            pos = 750;
            break;
        case 22:
            pos = 755;
            break;
        case 23:
            pos = 765;
            break;
        case 24:
            pos = 770;
            break;
        case 25:
            pos = 775;
            break;
        case 26:
            pos = 790;
            break;
        case 27:
            pos = 800;
            break;
        case 28:
            pos = 810;
            break;
        case 29:
            pos = 815;
            break;
        case 30:
            pos = 820;
            break;
        case 31:
            pos = 830;
            break;
        case 32:
            pos = 840;
            break;
        case 33:
            pos = 850;
            break;
        case 34:
            pos = 855;
            break;
        case 35:
            pos = 865;
            break;
        case 36:
            pos = 870;
            break;
        case 37:
            pos = 880;
            break;
        case 38:
            pos = 885;
            break;
        case 39:
            pos = 900;
            break;
        case 40:
            pos = 910;
            break;
        case 41:
            pos = 915;
            break;
        case 42:
            pos = 920;
            break;
        case 43:
            pos = 930;
            break;
        case 44:
            pos = 940;
            break;
        case 45:
            pos = 950;
            break;
        case 46:
            pos = 955;
            break;
        case 47:
            pos = 965;
            break;
        case 48:
            pos = 970;
            break;
        case 49:
            pos = 980;
            break;
        case 50:
            pos = 985;
            break;
        case 51:
            pos = 995;
            break;
        case 52:
            pos = 1010;
            break;
        case 53:
            pos = 1015;
            break;
        case 54:
            pos = 1025;
            break;
        case 55:
            pos = 1030;
            break;
        case 56:
            pos = 1040;
            break;
        case 57:
            pos = 1055;
            break;
        case 58:
            pos = 1060;
            break;
        case 59:
            pos = 1065;
            break;
        case 60:
            pos = 1070;
            break;
        case 61:
            pos = 1080;
            break;
        case 62:
            pos = 1085;
            break;
        case 63:
            pos = 1100;
            break;
        case 64:
            pos = 1110;
            break;
        case 65:
            pos = 1115;
            break;
        case 66:
            pos = 1125;
            break;
        case 67:
            pos = 1130;
            break;
        case 68:
            pos = 1140;
            break;
        case 69:
            pos = 1155;
            break;
        case 70:
            pos = 1160;
            break;
        case 71:
            pos = 1165;
            break;
        case 72:
            pos = 1170;
            break;
        case 73:
            pos = 1180;
            break;
        case 74:
            pos = 1185;
            break;
        case 75:
            pos = 1195;
            break;
        case 76:
            pos = 1205;
            break;
        case 77:
            pos = 1215;
            break;
        case 78:
            pos = 1220;
            break;
        case 79:
            pos = 1230;
            break;
        case 80:
            pos = 1240;
            break;
        case 81:
            pos = 1245;
            break;
        case 82:
            pos = 1255;
            break;
        case 83:
            pos = 1265;
            break;
        case 84:
            pos = 1270;
            break;
        case 85:
            pos = 1280;
            break;
        case 86:
            pos = 1290;
            break;
        case 87:
            pos = 1305;
            break;
        default:
            pos = 550;
            break;
    }
    return pos;
}
