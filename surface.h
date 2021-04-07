#pragma once

#include "renderer.h"

class Surface
{
public:
	Surface(const char* path);
	SDL_Surface* surface;
};

