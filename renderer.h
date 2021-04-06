#pragma once

#include "window.h"

class Renderer
{
public:
	Renderer(Window* window);
	SDL_Renderer* renderer;
};

