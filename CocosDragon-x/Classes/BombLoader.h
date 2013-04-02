//
//  BombLoader.h
//  CocosDragon-x
//
//  Created by long on 2013-03-01.
//
//

#ifndef CocosDragon_x_BombLoader_h
#define CocosDragon_x_BombLoader_h

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Bomb.h"

class BombLoader : public cocos2d::extension::CCNodeLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(BombLoader, loader);

protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Bomb);
};

#endif
