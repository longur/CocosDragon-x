//
//  Bomb.cpp
//  CocosDragon-x
//
//  Created by long on 2013-03-01.
//
//

#include "Bomb.h"

#include "Dragon.h"
#include "ExplosionLoader.h"

USING_NS_CC;
USING_NS_CC_EXT;


void Bomb::update()
{
    return;
}

void Bomb::handleCollisionWith(GameObject *gameObject)
{
    Dragon* dragon = dynamic_cast<Dragon*>(gameObject);
    
    if (dragon != NULL);
    {
        // Collided with the dragon, remove object and add an explosion instead
        this->isScheduledForRemove = true;

        cocos2d::CCNode * explosion = ExplosionLoader::load();

        explosion->setPosition(this->getPosition());
        this->getParent()->addChild(explosion);
    }
}

float Bomb::radius()
{
    return 15.0f;
}