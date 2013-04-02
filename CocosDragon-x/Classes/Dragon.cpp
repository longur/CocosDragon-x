//
//  Dragon.cpp
//  CocosDragon-x
//
//  Created by long on 2013-03-01.
//
//

#include "Dragon.h"

#include "Coin.h"
#include "Bomb.h"
#include "GameScene.h"


#define kCJStartSpeed 8
#define kCJCoinSpeed 8
#define kCJStartTarget 160

#define kCJTargetFilterFactor 0.05
#define kCJSlowDownFactor 0.995
#define kCJGravitySpeed 0.1
#define kCJGameOverSpeed -10
#define kCJDeltaToRotationFactor 5

USING_NS_CC;
USING_NS_CC_EXT;


bool Dragon::init()
{
    xTarget = kCJStartTarget;
    ySpeed = kCJStartSpeed;
    
    return true;
}

void Dragon::update()
{
    // Calculate new position
    CCPoint oldPosition = this->getPosition();
    
    float xNew = xTarget * kCJTargetFilterFactor + oldPosition.x * (1-kCJTargetFilterFactor);
    float yNew = oldPosition.y + ySpeed;
    this->setPosition(ccp(xNew,yNew));
    
    // Update the vertical speed
    ySpeed = (ySpeed - kCJGravitySpeed) * kCJSlowDownFactor;
    
    // Tilt the dragon depending on horizontal speed
    float xDelta = xNew - oldPosition.x;
    this->setRotation(xDelta * kCJDeltaToRotationFactor);
    
    // Check for game over
    if (ySpeed < kCJGameOverSpeed)
    {
        GameScene::sharedScene()->handleGameOver();
    }
}

void Dragon::handleCollisionWith(GameObject* gameObject)
{
    Coin* coin = dynamic_cast<Coin*>(gameObject);
    Bomb* bomb = dynamic_cast<Bomb*>(gameObject);
    
    if (coin != NULL)
    {
        // Took a coin
        ySpeed = kCJCoinSpeed;
        
        GameScene::sharedScene()->setScore(GameScene::sharedScene()->getScore() + 1);
    }
    else if (bomb != NULL)
    {
        // Hit a bomb
        if (ySpeed > 0) ySpeed = 0;
        
        CCBAnimationManager* animationManager = dynamic_cast<CCBAnimationManager*>(this->getUserObject());
        animationManager->runAnimationsForSequenceNamed("Hit");
    }
}

float Dragon::radius()
{
    return 25.0f;
}

