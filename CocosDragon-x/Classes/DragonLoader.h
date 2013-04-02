//
//  DragonLoader.h
//  CocosDragon-x
//
//  Created by long on 2013-03-01.
//
//

#ifndef CocosDragon_x_DragonLoader_h
#define CocosDragon_x_DragonLoader_h

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Dragon.h"

class DragonLoader : public cocos2d::extension::CCNodeLoader
{

public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(DragonLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Dragon);
    
};

#endif
