#include "ground.h"

Ground::Ground(Renderer* renderer, Window* window, int x, int y)
{
	this->groundSurface = new Surface("Ressources/ground.png");
	this->groundTexture = new Texture(renderer, this->groundSurface);

	this->groundRect = new SDL_Rect();
	this->groundRect->x = x;
	this->groundRect->y = y;
	this->groundRect->w = window->windowSurface->w;
	this->groundRect->h = 50;
}

void Ground::GetEntity(Renderer* renderer)
{
	SDL_RenderCopy(renderer->renderer, this->groundTexture->texture, NULL, this->groundRect);
}
