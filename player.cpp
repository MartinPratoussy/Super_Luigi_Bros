#include "player.h"

Player::Player(Renderer* renderer, int x, int y)
{
	this->playerSurface = new Surface("Ressources/Louigi.png");
	this->playerTexture = new Texture(renderer, this->playerSurface);

	this->playerRect = new SDL_Rect();
	this->playerRect->x = x;
	this->playerRect->y = y;
	this->playerRect->w = 40;
	this->playerRect->h = 70;
}

void Player::GetEntity(Renderer* renderer, SDL_RendererFlip flip)
{
	SDL_RenderCopyEx(renderer->renderer, this->playerTexture->texture, NULL, this->playerRect, NULL, NULL, flip);
}