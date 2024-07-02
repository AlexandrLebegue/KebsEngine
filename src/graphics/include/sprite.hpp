#pragma once

#include "SDL.h"
#include <string>
#include <vector>


class Sprite {

public:
	SDL_Surface* m_Surface;
	SDL_Texture* m_CurrentTexture;
    int m_x, m_y, m_size;

	Sprite(const char* pFilepath);
    Sprite(SDL_Surface* pSurface);
    
    void setPosition(int x, int y); // New method to set the position
    void Sprite::prepareDraw(SDL_Renderer* pRenderer);
    void draw(SDL_Renderer* pRenderer);


};