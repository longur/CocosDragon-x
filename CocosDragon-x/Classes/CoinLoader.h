//
//  CoinLoader.h
//  CocosDragon-x
//
//  Created by long on 2013-03-01.
//
//

#ifndef CocosDragon_x_CoinLoader_h
#define CocosDragon_x_CoinLoader_h

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Coin.h"

class CoinLoader : public cocos2d::extension::CCNodeLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(CoinLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Coin);
    
};

#endif
