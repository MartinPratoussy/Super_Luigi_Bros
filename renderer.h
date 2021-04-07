#pragma once

#include "window.h"

class Renderer
{
public:
	Renderer(Window* window);
	~Renderer();
	SDL_Renderer* renderer;
};

