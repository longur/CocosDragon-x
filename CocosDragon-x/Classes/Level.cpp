//
//  Level.cpp
//  CocosDragon-x
//
//  Created by long on 2013-03-01.
//
//

#include "Level.h"

#include "GameObject.h"
#include "Dragon.h"

#define kCJScrollFilterFactor 0.1
#define kCJDragonTargetOffset 80

USING_NS_CC;
USING_NS_CC_EXT;

void Level::onEnter()
{
    CCLayer::onEnter();
    
    // Schedule a selector that is called every frame
    this->scheduleUpdate();
    
    // Make sure touches are enabled
    this->setTouchEnabled(true);
}

void Level::onExit()
{
    // Remove the scheduled selector
    this->unscheduleAllSelectors();

    CCLayer::onExit();
}

bool Level::onAssignCCBCustomProperty(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::extension::CCBValue *pCCBValue)
{
    return false;
}

bool Level::onAssignCCBMemberVariable(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::CCNode *pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "dragon", Dragon*, this->dragon);
    return false;
}

void Level::update(float delta)
{
    // Iterate through all objects in the level layer
    CCObject* child = NULL;
    CCARRAY_FOREACH(this->m_pChildren, child)
    {
        GameObject* gameObject = dynamic_cast<GameObject*>(child);
        // Check if the child is a game object
        if (gameObject != NULL)
        {
            
            // Update all game objects
            gameObject->update();
            
            // Check for collisions with dragon
            if (gameObject != dragon)
            {
                if (ccpDistance(gameObject->getPosition(), dragon->getPosition()) < gameObject->radius() + dragon->radius())
                {
                    // Notify the game objects that they have collided
                    gameObject->handleCollisionWith(dragon);
                    dragon->handleCollisionWith(gameObject);
                }
            }
        }
    }
    
    // Check for objects to remove
    CCArray* gameObjectsToRemove = CCArray::create();
    CCARRAY_FOREACH(this->m_pChildren, child)
    {
        GameObject* gameObject = dynamic_cast<GameObject*>(child);
        if (gameObject != NULL)
        {
            
            if (gameObject->getIsScheduledForRemove())
            {
                gameObjectsToRemove->addObject(gameObject); 
            }
        }
    }
    
    GameObject* gameObject = NULL;
    for(int i = 0; i < gameObjectsToRemove->count(); i++)
    {
        gameObject = dynamic_cast<GameObject*>(gameObjectsToRemove->objectAtIndex(i));
        this->removeChild(gameObject, true);
    }
    
    // Adjust the position of the layer so dragon is visible
    float yTarget = kCJDragonTargetOffset - dragon->getPosition().y;
    CCPoint oldLayerPosition = this->getPosition();
    
    float xNew = oldLayerPosition.x;
    float yNew = yTarget * kCJScrollFilterFactor + oldLayerPosition.y * (1.0f - kCJScrollFilterFactor);
    
    this->setPosition(ccp(xNew, yNew));
}

void Level::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    CCTouch* touch = (CCTouch*)pTouches->anyObject();
    CCPoint touchLocation = touch->getLocationInView();
    
    dragon->setXTarget(touchLocation.x);
}

void Level::ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    CCTouch* touch = (CCTouch*)pTouches->anyObject();
    CCPoint touchLocation = touch->getLocationInView();
    
    dragon->setXTarget(touchLocation.x);
}
