#include "physic-world.hpp"
#include <algorithm>
#include <iostream>
PhysicWorld::PhysicWorld() : m_collisionBoxTickRates(0) {}

void PhysicWorld::addCollisionBox(CollisionBox * pCollisionBox) {
    m_CollisionBoxes.push_back(pCollisionBox);
}

void PhysicWorld::updateCollisionBoxes() {
    for (CollisionBox* box : m_CollisionBoxes) {
        for (CollisionBox* otherBox : m_CollisionBoxes) {
            if (box != otherBox && box->isColliding(otherBox)) {
                std::cout<<"BOX COLLIDING " << box << " vs " << otherBox << std::endl;
                std::cout<<"Box1 " << box->getX() << ", "<< box->getY() << " vs " << " Box2 " << otherBox->getX() << ", "<< otherBox->getY() << std::endl;

            }
        }
    }
}

void PhysicWorld::updateMovableObjects() {
    for (auto& obj : m_MovableObjects) {
        // Update logic for movable objects
        // Example: Move objects based on velocity or other physics
        obj->move(1.0f, 0.0f); // Move all objects to the right
    }
}

void PhysicWorld::updateWorld() {
    updateCollisionBoxes();
    updateMovableObjects();
}

void PhysicWorld::clearCollisionBoxes() {
    m_CollisionBoxes.clear();
}

void PhysicWorld::clearMovableObjects() {
    m_MovableObjects.clear();
}

void PhysicWorld::clearWorld() {
    clearCollisionBoxes();
    clearMovableObjects();
}

// void PhysicWorld::removeMovableObject(std::shared_ptr<CollisionBox> pTargetCollisionBox) {
//     auto it = std::remove_if(m_MovableObjects.begin(), m_MovableObjects.end(),
//         [&pTargetCollisionBox](const std::shared_ptr<MovableObject>& obj) {
//             return obj == pTargetCollisionBox;
//         });
//     m_MovableObjects.erase(it, m_MovableObjects.end());
// }

// void PhysicWorld::removeCollisionBox(std::shared_ptr<CollisionBox> pTargetCollisionBox) {
//     auto it = std::remove_if(m_CollisionBoxes.begin(), m_CollisionBoxes.end(),
//         [&pTargetCollisionBox](const std::shared_ptr<CollisionBox>& box) {
//             return box == pTargetCollisionBox;
//         });
//     m_CollisionBoxes.erase(it, m_CollisionBoxes.end());
// }

