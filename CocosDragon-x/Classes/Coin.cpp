//
//  Coin.cpp
//  CocosDragon-x
//
//  Created by long on 2013-03-01.
//
//

#include "Coin.h"

#include "GameScene.h"
#include "Dragon.h"

USING_NS_CC;
USING_NS_CC_EXT;

bool Coin::onAssignCCBMemberVariable(cocos2d::CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    return false;
}

bool Coin::onAssignCCBCustomProperty(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::extension::CCBValue *pCCBValue)
{
    bool ret = false;
    if (pTarget == this)
    {
        if ( 0  == strcmp(pMemberVariableName, "isEndCoin"))
        {
            this->isEndCoin = pCCBValue->getBoolValue();
            ret = true;
        }
    }
    return false;
}

void Coin::handleCollisionWith(GameObject* gameObject)
{
    Dragon* dragon = dynamic_cast<Dragon*>(gameObject);
    
    if (dragon != NULL)
    {
        if (isEndCoin)
        {
            // Level is complete!
            GameScene::sharedScene()->handleLevelComplete();
        }
        this->isScheduledForRemove = true;
    }
    return;
}

void Coin::update()
{
    return;
}

float Coin::radius()
{
    return 15.0f;
}