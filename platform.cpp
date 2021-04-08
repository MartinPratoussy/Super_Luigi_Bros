#include "platform.h"

Platform::Platform(Renderer* renderer, int x, int y)
{
	this->platformSurface = new Surface("Ressources/brickPlatform.png");
	this->platformTexture = new Texture(renderer, this->platformSurface);
	this->platformRect = new SDL_Rect();
	this->platformRect->x = x;
	this->platformRect->y = y;
	this->platformRect->w = 100;
	this->platformRect->h = 25;
}

void Platform::GetEntity(Renderer* renderer)
{
	SDL_RenderCopy(renderer->renderer, this->platformTexture->texture, NULL, this->platformRect);
}
