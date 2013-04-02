//
//  MainMenuSceneLoader.h
//  CocosDragon-x
//
//  Created by long on 2013-03-01.
//
//

#ifndef CocosDragon_x_MainMenuSceneLoader_h
#define CocosDragon_x_MainMenuSceneLoader_h

#include "cocos2d.h"
#include "cocos-ext.h"

#include "MainMenuScene.h"

class MainMenuSceneLoader : public cocos2d::extension::CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(MainMenuSceneLoader, loader);
    static MainMenuScene* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(MainMenuScene);

};


#endif
