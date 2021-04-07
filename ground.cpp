#include "ground.h"

Ground::Ground(Renderer* renderer, Window* window, int x, int y)
{
	this->groundSurface = new Surface("Ressources/ground.png");
	this->groundTexture = new Texture(renderer, this->groundSurface);
	this->x = x;
	this->y = y;
	this->w = window->windowSurface->w;
	this->h = 50;
}

void Ground::GetEntity(Renderer* renderer)
{
	SDL_Rect* entity = new SDL_Rect();

	entity->x = this->x;
	entity->y = this->y;
	entity->w = this->w;
	entity->h = this->h;
	SDL_RenderCopy(renderer->renderer, this->groundTexture->texture, NULL, entity);
}
