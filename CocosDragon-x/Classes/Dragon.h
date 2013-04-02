//
//  Dragon.h
//  CocosDragon-x
//
//  Created by long on 2013-03-01.
//
//

#ifndef __CocosDragon_x__Dragon__
#define __CocosDragon_x__Dragon__

#include "GameObject.h"

#include "cocos2d.h"
#include "cocos-ext.h"

class Dragon : public GameObject
{
  
private:
    float ySpeed;
    
    bool init();
public:
    CC_SYNTHESIZE(float, xTarget, XTarget);
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Dragon, create);
    
    
    virtual void update();
    virtual void handleCollisionWith(GameObject* gameObject);
    virtual float radius();
    
};

#endif /* defined(__CocosDragon_x__Dragon__) */
