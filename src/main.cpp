// CMakeProject3.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <random>
#include <SDL.h>
#include "graphics/include/screen.hpp"
using namespace std;

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		return 1;
	}


	Screen screen = Screen(600, 600);
	screen.setBackgroundColor( rand() % 255 + 1,  rand() % 255 + 1, rand() % 255 + 1);


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
		screen.display();
		SDL_Delay(1);
	}

	SDL_Quit();

	return 0;
}
