#pragma once

#include "texture.h"

#define IMG_WALK "Ressources/Louigi.png"
#define IMG_FLY "Ressources/LouigiHangGliding.png"


#define JUMP_RANGE_MAX 140
#define UP "up"
#define DOWN "down"
#define RIGHT "right"
#define LEFT "left"

class Player
{
private:
	Surface* playerSurface;
	Texture* playerTexture;

	Surface* playerFlyingSurface;
	Texture* playerFlyingTexture;

public:
	Player(Renderer* renderer, int x, int y);
	void GetEntity(Renderer* renderer, SDL_RendererFlip flip);

	void GoLeft();
	void GoRight();
	void GoUp();
	void GoDown();

	SDL_Rect* playerRect;
	SDL_Rect* playerFlyingRect;
	int jumpRange = 70;
	bool isFalling = false;
	const char* direction = DOWN;
};

