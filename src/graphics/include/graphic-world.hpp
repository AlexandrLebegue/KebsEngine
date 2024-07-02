/**
 * @file GraphicWorld.hpp
 * @brief Defines the GraphicWorld class for managing and rendering sprites using SDL.
 *
 * The GraphicWorld class provides functionality to manage a collection of Sprite objects,
 * including adding, updating, drawing, and removing sprites. It utilizes SDL for rendering.
 */

#ifndef GRAPHICWORLD_HPP
#define GRAPHICWORLD_HPP

#include "SDL.h"
#include "sprite.hpp"
#include "screen.hpp"
#include <vector>

class GraphicWorld {
public:
    /**
     * @brief Constructs a GraphicWorld object with a given SDL_Renderer.
     * @param pScreen A pointer to an SDL_Renderer used for drawing sprites. Must not be nullptr.
     */
    GraphicWorld(Screen* pScreen);

    /**
     * @brief Adds a Sprite to the world.
     * @param sprite The Sprite object to be added. It is copied into the world's sprite list.
     */
    void addSprite(Sprite *pSprite);

    /**
     * @brief Draws all Sprite objects in the world.
     * This function iterates through all stored Sprite objects and calls their draw method.
     */
    void updateWorld();

    /**
     * @brief Removes all sprites from the world.
     * Clears the internal list of Sprite objects.
     */
    void clearSprites();

    /**
     * @brief Find and remove a specific sprite from the world.
     * @param targetSprite The Sprite to be removed. The first matching instance in the list is removed.
     */
    void removeSprite(Sprite *ptargetSprite);

private:
    std::vector<Sprite*> m_sprites; ///< A list to store Sprite objects.
    Screen* m_screen; ///< SDL_Renderer shared by all sprites for drawing.
};

#endif // GRAPHICWORLD_HPP

