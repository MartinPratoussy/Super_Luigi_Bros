#pragma once

#include "texture.h"

class Background
{
private:
	Surface* backgroundSurface;
	Texture* backgroundTexture;

public:
	Background(Renderer* renderer, Window* window, int x, int y);
	void GetEntity(Renderer* renderer);
	int x, y = 0;
	int w, h;
};

