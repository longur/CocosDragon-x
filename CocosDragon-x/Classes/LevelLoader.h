//
//  LevelLoader.h
//  CocosDragon-x
//
//  Created by long on 2013-03-01.
//
//

#ifndef __CocosDragon_x__LevelLoader__
#define __CocosDragon_x__LevelLoader__

#include "Level.h"

#include "cocos2d.h"
#include "cocos-ext.h"

class LevelLoader : public cocos2d::extension::CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(LevelLoader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Level);
    
};

#endif /* defined(__CocosDragon_x__LevelLoader__) */
