#ifndef PHYSICWORLD_HPP
#define PHYSICWORLD_HPP

#include "collision-box.hpp"
#include "movable-object.hpp"
#include <vector>
#include <memory>

class PhysicWorld {
public:
    /**
     * @brief Constructs a PhysicWorld object with a given Screen.
     * @param pScreen A pointer to a Screen used for drawing CollisionBoxes. Must not be nullptr.
     */
    PhysicWorld();

    /**
     * @brief Adds a CollisionBox to the world.
     * @param pCollisionBox The CollisionBox object to be added. It is stored in the world's CollisionBox list.
     */
    void addCollisionBox(CollisionBox* pCollisionBox);

    /**
     * @brief Updates all CollisionBoxes.
     */
    void updateCollisionBoxes();

    /**
     * @brief Updates all movable objects in the world.
     */
    void updateMovableObjects();

    /**
     * @brief Updates the entire world, including CollisionBoxes and movable objects.
     */
    void updateWorld();

    /**
     * @brief Removes all CollisionBoxes from the world.
     */
    void clearCollisionBoxes();

    /**
     * @brief Clears all movable objects from the world.
     */
    void clearMovableObjects();

    /**
     * @brief Clears the entire world, including CollisionBoxes and movable objects.
     */
    void clearWorld();

    // /**
    //  * @brief Removes a specific movable object from the world.
    //  * @param pTargetCollisionBox The movable object to be removed.
    //  */
    // void removeMovableObject(std::shared_ptr<CollisionBox> pTargetCollisionBox);

    // /**
    //  * @brief Removes a specific CollisionBox from the world.
    //  * @param pTargetCollisionBox The CollisionBox to be removed.
    //  */
    // void removeCollisionBox(std::shared_ptr<CollisionBox> pTargetCollisionBox);


   

private:
    std::vector<CollisionBox*> m_CollisionBoxes; ///< A list to store CollisionBox objects.
    std::vector<std::shared_ptr<MovableObject>> m_MovableObjects; ///< A list to store MovableObject objects.
    int m_collisionBoxTickRates;
};

#endif // PHYSICWORLD_HPP
