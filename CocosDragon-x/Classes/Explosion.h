//
//  Explosion.h
//  CocosDragon-x
//
//  Created by long on 2013-03-01.
//
//

#ifndef __CocosDragon_x__Explosion__
#define __CocosDragon_x__Explosion__

#include "GameObject.h"

#include "cocos2d.h"
#include "cocos-ext.h"

class Explosion : public GameObject, public cocos2d::extension::CCBAnimationManagerDelegate
{
public:
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(Explosion, create);
    
    virtual void completedAnimationSequenceNamed(const char *name);
    
    virtual float radius();
    virtual void update();
    virtual void handleCollisionWith(GameObject* gameObject);
    
    
    virtual void onEnter();
    virtual void onExit();
};

#endif /* defined(__CocosDragon_x__Explosion__) */
