#ifndef PHYSICOBJECT_HPP
#define PHYSICOBJECT_HPP

class PhysicObject {
public:
    PhysicObject(float x, float y, float width, float height);

    virtual ~PhysicObject() = default;

    float getX() const;
    float getY() const;
    float getWidth() const;
    float getHeight() const;

    void setPosition(float x, float y);
    

protected:
    float m_x;
    float m_y;
    float m_width;
    float m_height;
};

#endif // PHYSICOBJECT_HPP
