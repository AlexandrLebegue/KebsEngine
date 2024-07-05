#include "collision-box.hpp"

CollisionBox::CollisionBox(float x, float y, float width, float height)
    : PhysicObject(x, y, width, height), pCollisionCallback(nullptr) {}

bool CollisionBox::isColliding(CollisionBox* other) {
    if (!(m_x + m_width < other->getX() ||
             m_x > other->getX() + other->getWidth() ||
             m_y + m_height < other->getY() ||
             m_y > other->getY() + other->getHeight()))
    {
        if (pCollisionCallback)
        {
            pCollisionCallback(this);
        }

        return true;
    }
    return false;
}



void CollisionBox::setCollisionCallback(void (*callback)(CollisionBox*)) {
    pCollisionCallback = callback;
}
