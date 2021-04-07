#pragma once

#include "texture.h"

class Player
{
private:
	Surface* playerSurface;
	Texture* playerTexture;

public:
	Player(Renderer* renderer, int x, int y);
	void GetEntity(Renderer* renderer, SDL_RendererFlip flip);
	int x, y;
	int w, h;
};

