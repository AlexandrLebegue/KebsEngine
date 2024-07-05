#ifndef COLLISIONBOX_HPP
#define COLLISIONBOX_HPP

#include "physic-object.hpp"

class CollisionBox : public PhysicObject {
public:
    CollisionBox(float x, float y, float width, float height);

    bool isColliding(CollisionBox* other);

    void setCollisionCallback(void (*callback)(CollisionBox*));
    void callback(); 
private:
    void (*pCollisionCallback)(CollisionBox*);
};

#endif // COLLISIONBOX_HPP
