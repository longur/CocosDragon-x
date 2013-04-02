//
//  Level.h
//  CocosDragon-x
//
//  Created by long on 2013-03-01.
//
//

#ifndef __CocosDragon_x__Level__
#define __CocosDragon_x__Level__

#include "cocos2d.h"
#include "cocos-ext.h"

// forward declarations
class Dragon;

class Level : public cocos2d::CCLayer, public cocos2d::extension::CCBMemberVariableAssigner
{
  
private:
    Dragon* dragon;
    
public:
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Level, create);
    
    virtual void onEnter();
    virtual void onExit();
    
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);

    
    virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    virtual void ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);

    
    void update(float delta);
};

#endif /* defined(__CocosDragon_x__Level__) */
