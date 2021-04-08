#pragma once

#include "texture.h"

#define JUMP_RANGE_MAX 70
#define UP "up"
#define DOWN "down"
#define RIGHT "right"
#define LEFT "left"

class Player
{
private:
	Surface* playerSurface;
	Texture* playerTexture;

public:
	Player(Renderer* renderer, int x, int y);
	void GetEntity(Renderer* renderer, SDL_RendererFlip flip);

	SDL_Rect* playerRect;
	int jumpRange = 70;
	bool isFalling = false;
	const char* direction = DOWN;
};

