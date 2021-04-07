#include "player.h"

Player::Player(Renderer* renderer, int x, int y)
{
	this->playerSurface = new Surface("Ressources/Louigi.png");
	this->playerTexture = new Texture(renderer, this->playerSurface);
	this->x = x;
	this->y = y;
	this->w = 40;
	this->h = 70;
}

void Player::GetEntity(Renderer* renderer, SDL_RendererFlip flip)
{
	SDL_Rect* entity = new SDL_Rect();

	entity->x = this->x;
	entity->y = this->y;
	entity->w = this->w;
	entity->h = this->h;
	SDL_RenderCopyEx(renderer->renderer, this->playerTexture->texture, NULL, entity, NULL, NULL, flip);
}