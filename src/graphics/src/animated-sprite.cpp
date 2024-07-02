#include "animated-sprite.hpp"

#include <iostream>

AnimatedSprite::AnimatedSprite(const char* filepath, int frameWidth, int frameHeight, int numFrames, unsigned int frameTime)
    : Sprite(filepath), m_frameWidth(frameWidth), m_frameHeight(frameHeight), m_numFrames(numFrames), m_currentFrame(0), m_frameTime(frameTime), m_lastUpdateTime(0) {
    if (m_Surface == NULL) {
        std::cout << "Unable to load image " << filepath << " SDL_image Error: " << IMG_GetError() << std::endl;
    }

}


void AnimatedSprite::draw(SDL_Renderer* pRenderer) 
{

    unsigned int currentTime = SDL_GetTicks();
    if (currentTime - m_lastUpdateTime > m_frameTime) {
        m_currentFrame = (m_currentFrame + 1) % m_numFrames;
        m_lastUpdateTime = currentTime;
    }

    SDL_Rect srcRect = { m_currentFrame * m_frameWidth, 0, m_frameWidth, m_frameHeight };

    SDL_Rect destRect = { m_x, m_y, m_frameWidth * m_size, m_frameHeight * m_size };

    if (m_CurrentTexture == NULL) {
        m_CurrentTexture = SDL_CreateTextureFromSurface(pRenderer, m_Surface); // Prepare the sprite
    }

    SDL_RenderCopy(pRenderer, m_CurrentTexture, &srcRect, &destRect); // Copy the sprite using the SDL_Renderer
}

