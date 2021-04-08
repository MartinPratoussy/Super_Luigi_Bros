#pragma once

#include "texture.h"

class Platform
{
private:
	Surface* platformSurface;
	Texture* platformTexture;

public:
	Platform(Renderer* renderer, int x, int y);
	void GetEntity(Renderer* renderer);
	SDL_Rect* platformRect;
};

