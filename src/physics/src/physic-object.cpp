#include "physic-object.hpp"

PhysicObject::PhysicObject(float x, float y, float width, float height)
    : m_x(x), m_y(y), m_width(width), m_height(height) {}

float PhysicObject::getX() const { return m_x; }
float PhysicObject::getY() const { return m_y; }
float PhysicObject::getWidth() const { return m_width; }
float PhysicObject::getHeight() const { return m_height; }
void PhysicObject::setPosition(float x, float y) { m_x = x; m_y = y; }
