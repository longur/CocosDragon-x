//
//  GameScene.cpp
//  CocosDragon-x
//
//  Created by long on 2013-03-01.
//
//

#include "GameScene.h"

#include "cocos2d.h"
#include "MainMenuSceneLoader.h"
#include "GameSceneLoader.h"
#include "LevelLoader.h"

USING_NS_CC;
USING_NS_CC_EXT;

GameScene* GameScene::sharedInstance = NULL;

GameScene* GameScene::sharedScene()
{
    return sharedInstance;
}

CCScene* GameScene::scene()
{
    CCScene* scene = CCScene::create();
    sharedInstance = GameSceneLoader::load();
    
    scene->addChild(sharedInstance);
    
    return scene;
}

void GameScene::onEnter()
{
    CCLayer::onEnter();
    level = LevelLoader::load();
    this->addChild(level);
}

bool GameScene::onAssignCCBCustomProperty(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::extension::CCBValue *pCCBValue)
{
    return false;
}

bool GameScene::onAssignCCBMemberVariable(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::CCNode *pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "levelLayer", CCLayer*, this->levelLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "scoreLabel", CCLabelTTF*, this->scoreLabel);
    return false;
}

int GameScene::getScore()
{
    return score;
}

void GameScene::setScore(int s)
{
    score = s;
    
    CCString* newScore = CCString::createWithFormat("%d", score);
    scoreLabel->setString(newScore->getCString());
}

void GameScene::handleGameOver()
{
    CCDirector::sharedDirector()->replaceScene(MainMenuScene::scene());
}

void GameScene::handleLevelComplete()
{
    CCDirector::sharedDirector()->replaceScene(MainMenuScene::scene());
}