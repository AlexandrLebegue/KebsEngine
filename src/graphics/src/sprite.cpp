#include "sprite.hpp"

#include <iostream>

Sprite::Sprite(const char* filepath) {
	m_Surface = SDL_LoadBMP(filepath);
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