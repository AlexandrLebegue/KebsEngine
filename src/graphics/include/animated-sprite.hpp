#include "SDL.h"
#include <string>
#include <vector>
#include "sprite.hpp"


class AnimatedSprite extends Sprite {

public:
	SDL_Surface* m_Sprite;
	SDL_Texture* m_CurrentTexture;
	SDL_Renderer* m_Renderer;
	int m_CurrentTextureIndex;
	std::vector<SDL_Texture*> m_Textures;

	AnimatedSprite(const char* pFilepath, SDL_Renderer* pRenderer, int to_cut_x, int to_cut_y );
    AnimatedSprite(SDL_Surface* pListSurface, int nbSurface,  SDL_Renderer* renderer);
	AnimatedSprite(SDL_Renderer* pRenderer);
    
    
    /**
     * Updates the texture of the sprite to the next texture in the sequence.
     *
     * This function updates the current texture of the sprite to the next one in its texture sequence.
     * If the current texture is the last one in the sequence, this function does nothing.
     * Exceptions:
     *  - This function does not explicitly throw exceptions but can result in undefined behavior
     *    if the sprite's texture vector is empty or if there are issues with the SDL_Texture objects it contains.
     */
	void updateTexture();



};