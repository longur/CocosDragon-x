//
//  Bomb.h
//  CocosDragon-x
//
//  Created by long on 2013-03-01.
//
//

#ifndef __CocosDragon_x__Bomb__
#define __CocosDragon_x__Bomb__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "GameObject.h"

class Bomb : public GameObject
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(Bomb, create);
    
    virtual float radius();
    virtual void update();
    virtual void handleCollisionWith(GameObject* gameObject);
};

#endif /* defined(__CocosDragon_x__Bomb__) */
