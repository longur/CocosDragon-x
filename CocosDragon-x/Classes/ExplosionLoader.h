//
//  ExplosionLoader.h
//  CocosDragon-x
//
//  Created by long on 2013-03-01.
//
//

#ifndef __CocosDragon_x__ExplosionLoader__
#define __CocosDragon_x__ExplosionLoader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Explosion.h"

class ExplosionLoader : public cocos2d::extension::CCNodeLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ExplosionLoader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Explosion);
};

#endif /* defined(__CocosDragon_x__ExplosionLoader__) */
