//
//  Explosion.cpp
//  CocosDragon-x
//
//  Created by long on 2013-03-01.
//
//

#include "Explosion.h"

USING_NS_CC;
USING_NS_CC_EXT;

void Explosion::completedAnimationSequenceNamed(const char *name)
{
    // use the name to differentiate between animations but we only have one
    
    this->isScheduledForRemove = true;
}

void Explosion::onEnter()
{
    CCNode::onEnter();
    
    CCBAnimationManager* animationManager = dynamic_cast<CCBAnimationManager*>(this->getUserObject());
    
    animationManager->setDelegate(this);
}

void Explosion::onExit()
{
    CCBAnimationManager* animationManager = dynamic_cast<CCBAnimationManager*>(this->getUserObject());
    
    animationManager->setDelegate(NULL);
    
    CCNode::onExit();

}

void Explosion::update()
{
    return;
}

void Explosion::handleCollisionWith(GameObject *gameObject)
{
    return;
}

float Explosion::radius()
{
    return 0.0f;
}