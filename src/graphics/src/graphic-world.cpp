#include "graphic-world.hpp"

// Constructor
GraphicWorld::GraphicWorld(Screen* pScreen) : m_screen(pScreen) {}

// Adds a Sprite to the world
void GraphicWorld::addSprite(Sprite *pSprite) {
    m_sprites.push_back(pSprite);
    pSprite->prepareDraw(m_screen->getRenderer());
}

// Draws all Sprite objects in the world
void GraphicWorld::updateWorld() {
    for (Sprite* sprite : m_sprites) {
        sprite->draw(m_screen->getRenderer()); // Assuming Sprite has a draw method accepting SDL_Renderer*
    }
}


// Removes all sprites from the world
void GraphicWorld::clearSprites() {
    m_sprites.clear();
}

void GraphicWorld::removeSprite(Sprite *pTargetSprite) {
    for(int i = 0; i < m_sprites.size(); i++)
    {
        if (m_sprites.at(i) == pTargetSprite) 
        {
            m_sprites.erase(m_sprites.begin() + i - 1 );
            break;
        }
    }
}

