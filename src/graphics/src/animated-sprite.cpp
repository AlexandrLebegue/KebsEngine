#include "animated-sprite.hpp"

#include <iostream>

AnimatedSprite::AnimatedSprite(const char* filepath, SDL_Renderer* renderer) {
	m_AnimatedSprite = SDL_LoadBMP(filepath);
	m_Renderer = renderer;
	if (!m_AnimatedSprite)
		std::cout << "Erreur chargement file" << std::endl;
	m_CurrentTexture = SDL_CreateTextureFromSurface(m_Renderer, m_AnimatedSprite); // Préparation du AnimatedSprite
}

AnimatedSprite::AnimatedSprite(SDL_Surface* pSurface, SDL_Renderer* renderer) {
	m_AnimatedSprite = pSurface;
	m_Renderer = renderer;
	if (!m_AnimatedSprite)
		std::cout << "Erreur chargement surface" << std::endl;
	m_CurrentTexture = SDL_CreateTextureFromSurface(m_Renderer, m_AnimatedSprite); // Préparation du AnimatedSprite
}

AnimatedSprite::AnimatedSprite(SDL_Renderer* renderer) {
	m_Renderer = renderer;
}

void AnimatedSprite::updateTexture() {
	m_CurrentTexture = m_Textures.at(m_CurrentTextureIndex + 1);
}