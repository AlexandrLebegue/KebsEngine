#ifndef MOVABLEOBJECT_HPP
#define MOVABLEOBJECT_HPP

#include "physic-object.hpp"

class MovableObject : public PhysicObject {
public:
    MovableObject(float x, float y, float width, float height);

    void move(float deltaX, float deltaY);
};

#endif // MOVABLEOBJECT_HPP
