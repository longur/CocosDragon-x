//
//  GameScene.h
//  CocosDragon-x
//
//  Created by long on 2013-03-01.
//
//

#ifndef __CocosDragon_x__GameScene__
#define __CocosDragon_x__GameScene__

#include "cocos2d.h"
#include "cocos-ext.h"

class GameScene : public cocos2d::CCLayer, public cocos2d::extension::CCBMemberVariableAssigner
{
private:
    cocos2d::CCLayer* levelLayer;
    cocos2d::CCLabelTTF* scoreLabel;
    cocos2d::CCNode* level;
    
    int score;
    
public:
    static GameScene* sharedInstance;
    
    static GameScene* sharedScene();
    
    static cocos2d::CCScene* scene();
    
    virtual void onEnter();
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(GameScene, create);
    
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    
    void handleGameOver();
    void handleLevelComplete();
    
    int getScore();
    void setScore(int s);
    
};

#endif /* defined(__CocosDragon_x__GameScene__) */
