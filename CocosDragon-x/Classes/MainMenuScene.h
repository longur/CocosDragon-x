//
//  MainMenuScene.h
//  CocosDragon-x
//
//  Created by long on 2013-03-01.
//
//

#ifndef __CocosDragon_x__MainMenuScene__
#define __CocosDragon_x__MainMenuScene__

#include "cocos2d.h"
#include "cocos-ext.h"

class MainMenuScene : public cocos2d::CCLayer, public cocos2d::extension::CCBSelectorResolver
{
public:
    static cocos2d::CCScene* scene();
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(MainMenuScene, create);
    
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName);
    
    void pressedPlay(cocos2d::CCObject * pSender);
};

#endif /* defined(__CocosDragon_x__MainMenuScene__) */
