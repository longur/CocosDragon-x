//
//  GameObject.h
//  CocosDragon-x
//
//  Created by long on 2013-03-01.
//
//

#ifndef __CocosDragon_x__GameObject__
#define __CocosDragon_x__GameObject__

#include "cocos2d.h"

class GameObject : public cocos2d::CCNode
{
    
public:
    CC_SYNTHESIZE(bool, isScheduledForRemove, IsScheduledForRemove);
    
    virtual float radius() = 0;
    virtual void update() = 0;
    virtual void handleCollisionWith(GameObject* gameObject) = 0;

};

#endif /* defined(__CocosDragon_x__GameObject__) */
