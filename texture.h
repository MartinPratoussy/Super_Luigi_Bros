#pragma once

#include "surface.h"

class Texture
{
public:
	SDL_Texture* texture;

	Texture(Renderer* renderer, Surface* surface);
};

