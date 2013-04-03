//
//  MainMenuScene.cpp
//  CocosDragon-x
//
//  Created by long on 2013-03-01.
//
//

#include "MainMenuScene.h"

#include "MainMenuSceneLoader.h"
#include "GameSceneLoader.h"

USING_NS_CC;
USING_NS_CC_EXT;

CCScene* MainMenuScene::scene()
{
    CCScene* scene = CCScene::create();
    scene->addChild(MainMenuSceneLoader::load());
    
    return scene;
}

SEL_MenuHandler MainMenuScene::onResolveCCBCCMenuItemSelector(cocos2d::CCObject *pTarget, const char *pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "pressedPlay:", MainMenuScene::pressedPlay);
    return NULL;
}

SEL_CCControlHandler MainMenuScene::onResolveCCBCCControlSelector(cocos2d::CCObject *pTarget, const char *pSelectorName)
{
    return NULL;
}

void MainMenuScene::pressedPlay(cocos2d::CCObject *pSender)
{
    CCDirector::sharedDirector()->replaceScene(GameScene::scene());
}