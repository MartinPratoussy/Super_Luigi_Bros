#pragma once

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>

class Window
{
public:
	Window();
	~Window();

	SDL_Window* window;
	SDL_Surface* windowSurface;
};

