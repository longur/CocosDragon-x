//
//  Coin.h
//  CocosDragon-x
//
//  Created by long on 2013-03-01.
//
//

#ifndef __CocosDragon_x__Coin__
#define __CocosDragon_x__Coin__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "GameObject.h"

class Coin : public GameObject, public cocos2d::extension::CCBMemberVariableAssigner
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(Coin, create);
    
    CC_SYNTHESIZE(bool, isEndCoin, IsEndCoin);
    
    virtual bool onAssignCCBMemberVariable(cocos2d::CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual bool onAssignCCBCustomProperty(cocos2d::CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    
    virtual float radius();
    virtual void update();
    virtual void handleCollisionWith(GameObject* gameObject);

    
};

#endif /* defined(__CocosDragon_x__Coin__) */
