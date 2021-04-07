#include "background.h"

Background::Background(Renderer* renderer, Window* window, int x, int y)
{
	this->backgroundSurface = new Surface("Ressources/background.png");
	this->backgroundTexture = new Texture(renderer, this->backgroundSurface);
	this->w = backgroundSurface->surface->w;
	this->h = window->windowSurface->h;
}

void Background::GetEntity(Renderer* renderer)
{
	SDL_Rect* backgroundRect = new SDL_Rect();
	backgroundRect->w = this->w;
	backgroundRect->h = this->h;
	SDL_RenderCopy(renderer->renderer, backgroundTexture->texture, NULL, backgroundRect);
}
