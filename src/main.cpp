// CMakeProject3.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <random>
#include <SDL.h>
#include "graphics/include/screen.hpp"
#include "graphics/include/graphic-world.hpp"
#include "graphics/include/animated-sprite.hpp"
#include "physics/include/collision-box.hpp"
#include "physics/include/physic-world.hpp"
#include "graphics/include/tilemap.hpp"
using namespace std;

int main(int argc, char *argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		return 1;
	}

	Screen screen = Screen(600, 600);
	GraphicWorld graphWorld = GraphicWorld(&screen);
	PhysicWorld physicWorld = PhysicWorld();

	Sprite sprite = Sprite("ressources/one_sprite.bmp");
	Sprite sprite2 = Sprite("ressources/one_sprite.bmp");
	Sprite sprite3 = Sprite("ressources/sprite_01_png.png");
	AnimatedSprite animatedSprite = AnimatedSprite("ressources/lepruchum.png", 8, 8, 10, 200);

	Tilemap tilemap = Tilemap(0, 0, 0);
	CollisionBox collisionbox1 = CollisionBox(0, 0, 8 * 6, 8 * 6);
	CollisionBox collisionbox2 = CollisionBox(0, 0, 8 * 6, 8 * 6);

	tilemap.loadTilemap("ressources/map.json");

	// std::cout << "Tile Size: " << tilemap.tileSize << std::endl;
	// std::cout << "Map Width: " << tilemap.mapWidth << std::endl;
	// std::cout << "Map Height: " << tilemap.mapHeight << std::endl;

	// for (const auto &layer : tilemap.layers)
	// {
	// 	std::cout << "Layer Name: " << layer.name << std::endl;
	// 	std::cout << "Collider: " << (layer.collider ? "true" : "false") << std::endl;
	// 	for (const auto &tile : layer.tiles)
	// 	{
	// 		std::cout << "Tile ID: " << tile.id << ", X: " << tile.x << ", Y: " << tile.y << std::endl;
	// 	}
	// }
	physicWorld.addCollisionBox(&collisionbox1);
	physicWorld.addCollisionBox(&collisionbox2);

	graphWorld.addSprite(&sprite);
	graphWorld.addSprite(&sprite2);
	graphWorld.addSprite(&sprite3);
	graphWorld.addSprite((Sprite *)&animatedSprite);
	sprite.setPosition(0, 100);
	sprite2.setPosition(0, 400);
	animatedSprite.setPosition(200, 200);

	screen.setBackgroundColor(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);

	int x = 200, y = 200;
	bool isOn = true;
	bool activate_posture = true;
	while (isOn)
	{
		// input handling
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				isOn = false;
			}
			// Update the object's position based on key press
			switch (event.key.keysym.sym)
			{
			case SDLK_UP:
				y -= 10;
				break;
			case SDLK_DOWN:
				y += 10;
				break;
			case SDLK_LEFT:
				x -= 10;
				break;
			case SDLK_RIGHT:
				x += 10;
				break;
			case SDLK_g:
				activate_posture = !activate_posture;
				break;
			case SDLK_f:
				std::cout << "collisionbox1 " << collisionbox1.getX() << ", "
						  << collisionbox1.getY() << collisionbox1.getWidth() << ", " << collisionbox1.getHeight()
						  << " vs "
						  << " Box2 " << collisionbox2.getX() << ", "
						  << collisionbox2.getY() << collisionbox2.getWidth() << ", " << collisionbox2.getHeight() << std::endl;
			}
		}
		screen.clearScreen();
		graphWorld.updateWorld();
		physicWorld.updateCollisionBoxes();
		screen.display();
		if (activate_posture)
		{
			sprite.setPosition((sprite.m_x + 1) % screen.getScreenWidth(), sprite.m_y);
			sprite2.setPosition((sprite2.m_x + 1) % screen.getScreenWidth(), sprite2.m_y);
			sprite3.setPosition((sprite3.m_x + 1) % screen.getScreenWidth(), sprite3.m_y);
		}
		animatedSprite.setPosition(x, y);

		collisionbox1.setPosition((float)animatedSprite.m_x, (float)animatedSprite.m_y);
		collisionbox2.setPosition((float)sprite.m_x, (float)sprite.m_y);
	}

	SDL_Quit();

	return 0;
}
