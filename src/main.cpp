// CMakeProject3.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <random>
#include <SDL.h>
#include "graphics/include/screen.hpp"
#include "graphics/include/graphic-world.hpp"
using namespace std;

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		return 1;
	}


	Screen screen = Screen(600, 600);
	GraphicWorld graphWorld = GraphicWorld(&screen);
	
	Sprite sprite = Sprite("ressources/one_sprite.bmp");
	Sprite sprite2 = Sprite("ressources/one_sprite.bmp");

	graphWorld.addSprite(&sprite);
	graphWorld.addSprite(&sprite2);

	sprite.setPosition(2000, 5000);
	sprite2.setPosition(4000, 50);

	bool isOn = true;
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
		}
		screen.setBackgroundColor( rand() % 255 + 1,  rand() % 255 + 1, rand() % 255 + 1);
		graphWorld.updateWorld();
		screen.display();
		sprite.setPosition( rand() % screen.getScreenWidth() + 1,   rand() % screen.getScreenHeight() + 1);
		sprite2.setPosition( rand() % screen.getScreenWidth() + 1,  rand() % screen.getScreenHeight() + 1);

		SDL_Delay(550);
	}

	SDL_Quit();

	return 0;
}
