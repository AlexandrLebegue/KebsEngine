#include "sprite.hpp"
#include <SDL_image.h>
#include <iostream>

Sprite::Sprite(const char* filepath) {
	 // Initialize SDL_image with PNG loading
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        std::cout << "SDL_image could not initialize! SDL_image Error:" << IMG_GetError() << std::endl;
    }
	m_Surface =  IMG_Load(filepath);
    if (m_Surface == NULL) {
        std::cout << "Unable to load image  " << filepath <<  IMG_GetError() << std::endl;
    }
    m_CurrentTexture = NULL;
    m_x = 0;
    m_y = 0;
    m_size = 6;
	if (!m_Surface)
		std::cout << "Erreur chargement file" << std::endl;
}

Sprite::Sprite(SDL_Surface* pSurface) {
	m_Surface = pSurface;
    m_CurrentTexture = NULL;

	if (!m_Surface)
		std::cout << "Erreur chargement surface" << std::endl;
}


void Sprite::setPosition(int x, int y) {
    m_x = x;
    m_y = y;
}
void Sprite::prepareDraw(SDL_Renderer* pRenderer) {
    	m_CurrentTexture = SDL_CreateTextureFromSurface(pRenderer, m_Surface); // Préparation du sprite
}
void Sprite::draw(SDL_Renderer* pRenderer) {
    SDL_Rect dest = {m_x,m_y, m_Surface->w * m_size, m_Surface->h * m_size };
    if (m_CurrentTexture== NULL)
    {
        m_CurrentTexture = SDL_CreateTextureFromSurface(pRenderer, m_Surface); // Préparation du sprite
    }

	SDL_RenderCopy(pRenderer, m_CurrentTexture, NULL, &dest); // Copie du sprite grâce au SDL_Renderer
}