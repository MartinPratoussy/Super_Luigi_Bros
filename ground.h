#pragma once

#include "texture.h"

class Ground
{
private:
	Surface* groundSurface;
	Texture* groundTexture;

public:
	Ground(Renderer* renderer, Window* window, int x, int y);
	void GetEntity(Renderer* renderer);
	int x, y;
	int w, h;
};

