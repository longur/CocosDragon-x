//
//  LevelLoader.cpp
//  CocosDragon-x
//
//  Created by long on 2013-03-01.
//
//

#include "LevelLoader.h"

#include "DragonLoader.h"
#include "CoinLoader.h"
#include "BombLoader.h"

USING_NS_CC;
USING_NS_CC_EXT;

CCNode* LevelLoader::load()
{
    cocos2d::extension::CCNodeLoaderLibrary * ccNodeLoaderLibrary = cocos2d::extension::CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    
    ccNodeLoaderLibrary->registerCCNodeLoader("Level", LevelLoader::loader());
    ccNodeLoaderLibrary->registerCCNodeLoader("Dragon", DragonLoader::loader());
    ccNodeLoaderLibrary->registerCCNodeLoader("Coin", CoinLoader::loader());
    ccNodeLoaderLibrary->registerCCNodeLoader("Bomb", BombLoader::loader());
    
    
    /* Create an autorelease CCBReader. */
    cocos2d::extension::CCBReader * ccbReader = new cocos2d::extension::CCBReader(ccNodeLoaderLibrary);
    ccbReader->autorelease();
    
    /* Read a ccbi file. */
    cocos2d::CCNode * node = ccbReader->readNodeGraphFromFile("Level.ccbi");

    return node;
}