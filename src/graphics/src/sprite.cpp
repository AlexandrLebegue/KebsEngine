﻿#include "sprite.hpp"

#include <iostream>

Sprite::Sprite(const char* filepath, SDL_Renderer* renderer) {
	m_Sprite = SDL_LoadBMP(filepath);
	m_Renderer = renderer;
	if (!m_Sprite)
		std::cout << "Erreur chargement file" << std::endl;
	m_CurrentTexture = SDL_CreateTextureFromSurface(m_Renderer, m_Sprite); // Préparation du sprite
}

Sprite::Sprite(SDL_Renderer* renderer) {
	m_Renderer = renderer;
}

void Sprite::updateTexture() {
	m_CurrentTexture = m_Textures.at(m_CurrentTextureIndex + 1);
}