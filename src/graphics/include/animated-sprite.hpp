#include "sprite.hpp"
#include <SDL_image.h>
#include <iostream>
#include <vector>

class AnimatedSprite : public Sprite {
public:
    AnimatedSprite(const char* filepath, int frameWidth, int frameHeight, int numFrames, unsigned int frameTime);
    void update();
    void draw(SDL_Renderer* pRenderer) override;

private:
    int m_frameWidth;
    int m_frameHeight;
    int m_numFrames;
    int m_currentFrame;
    unsigned int m_frameTime;  // Time per frame in milliseconds
    unsigned int m_lastUpdateTime;  // Time of last frame update
};
