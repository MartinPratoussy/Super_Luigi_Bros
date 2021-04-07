#include "platform.h"

Platform::Platform(Renderer* renderer, int x, int y)
{
	this->platformSurface = new Surface("Ressources/brickPlatform.png");
	this->platformTexture = new Texture(renderer, this->platformSurface);
	this->x = x;
	this->y = y;
	this->w = 100;
	this->h = 25;
}

void Platform::GetEntity(Renderer* renderer)
{
	SDL_Rect* entity = new SDL_Rect();

	entity->x = this->x;
	entity->y = this->y;
	entity->w = this->w;
	entity->h = this->h;
	SDL_RenderCopy(renderer->renderer, this->platformTexture->texture, NULL, entity);
}
