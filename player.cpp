#include "player.h"

Player::Player(Renderer* renderer, int x, int y)
{
	this->playerSurface = new Surface(IMG_WALK);
	this->playerTexture = new Texture(renderer, this->playerSurface);

	this->playerFlyingSurface = new Surface(IMG_FLY);
	this->playerFlyingTexture = new Texture(renderer, this->playerFlyingSurface);

	this->playerRect = new SDL_Rect();
	this->playerFlyingRect = new SDL_Rect();
	this->playerRect->x, this->playerFlyingRect->x = x;
	this->playerRect->y, this->playerFlyingRect->y = y;

	this->playerRect->w = 40;
	this->playerRect->h = 70;
	this->playerFlyingRect->w = 80;
	this->playerFlyingRect->h = 50;
}

void Player::GetEntity(Renderer* renderer, SDL_RendererFlip flip)
{
	switch (this->isFalling)
	{
	case true: 
		SDL_RenderCopyEx(renderer->renderer, this->playerFlyingTexture->texture, NULL, this->playerFlyingRect, NULL, NULL, flip);
		break;
	case false: 
		SDL_RenderCopyEx(renderer->renderer, this->playerTexture->texture, NULL, this->playerRect, NULL, NULL, flip);
		break;
	}	
}

void Player::GoLeft()
{
	this->playerRect->x--;
	this->playerFlyingRect->x--;
	this->direction = LEFT;
}

void Player::GoRight()
{
	this->playerRect->x++;
	this->playerFlyingRect->x++;
	this->direction = RIGHT;
}

void Player::GoUp()
{
	this->playerRect->y--;
	this->playerFlyingRect->y--;
	this->direction = UP;
	this->jumpRange--;
}

void Player::GoDown()
{
	this->playerRect->y++;
	this->playerFlyingRect->y++;
	this->direction = DOWN;
}
