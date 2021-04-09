#include "world.h"

void World::CreateBackground(Renderer* renderer, Window* window) {
	this->background = new Background(renderer, window, 0, 0);
}

void World::CreatePlayer(Renderer* renderer)
{
	this->player = new Player(renderer, 50, 50);
}

void World::CreateGround(Renderer* renderer, Window* window)
{
	this->ground = new Ground(renderer, window, 0, window->windowSurface->h - 50);
}

void World::CreatePlatforms(Renderer* renderer)
{
	for (int i = 0; i < 3; i++)
	{
		int x = rand() % 400+100;
		int y = rand() % 300+200;
		platforms.push_back(new Platform(renderer, x, y));
	}
}

SDL_RendererFlip World::MovePlayer()
{
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	// Vertical deplacement
	if (currentKeyStates[SDL_SCANCODE_UP] && player->jumpRange > 0) {
		this->player->GoUp();
	}
	// Horizontal deplacement
	else if (currentKeyStates[SDL_SCANCODE_LEFT]) {
		flip = SDL_FLIP_HORIZONTAL;
		this->player->GoLeft();
	}
	else if (currentKeyStates[SDL_SCANCODE_RIGHT]) {
		this->player->GoRight();
	}
	else {
		if (this->player->direction == LEFT) flip = SDL_FLIP_HORIZONTAL;
		this->player->GoDown();
	}
	return flip;
}

void World::CheckCollision()
{
	// Collision with ground
	if ((SDL_HasIntersection(this->ground->groundRect, this->player->playerRect) && !this->player->isFalling)
		| (SDL_HasIntersection(this->ground->groundRect, this->player->playerFlyingRect) && this->player->isFalling)) {
		this->player->playerRect->y--;
		this->player->playerFlyingRect->y--;
		this->player->jumpRange = JUMP_RANGE_MAX;
		this->player->isFalling = false;
	}
	// Collision with platform
	for (Platform* platform : this->platforms) {
		if ((SDL_HasIntersection(platform->platformRect, this->player->playerRect) && !this->player->isFalling)
			| (SDL_HasIntersection(platform->platformRect, this->player->playerFlyingRect) && this->player->isFalling)) {
			switch (*this->player->direction)
			{
			case* UP: 
				this->player->GoDown();
				break;
				break;
			case* LEFT:
				this->player->GoRight();
				break;
			case* RIGHT:
				this->player->GoLeft();
				break;
			default:
				this->player->GoUp();
				this->player->jumpRange = JUMP_RANGE_MAX;
				this->player->isFalling = false;
				break;
			}
		}
	}
	if (this->player->jumpRange == 0) this->player->isFalling = true;
}

void World::StartWorld(Renderer* renderer, Window* window)
{
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
	Surface* ico = new Surface("Ressources/LouigiIcon.bmp");
	SDL_SetWindowIcon(window->window, ico->surface);

	// Declare elements of the game
	CreateBackground(renderer, window);
	CreatePlayer(renderer);
	CreateGround(renderer, window);
	CreatePlatforms(renderer);

	// Events loop
	SDL_Event events;
	bool isOpen = true;
	while (isOpen) {
		while (SDL_PollEvent(&events))
			switch (events.type)
			{
			case SDL_QUIT:
				isOpen = false;
				break;
			}
		SDL_RenderClear(renderer->renderer);

		/* Here comes the code */
		this->background->GetEntity(renderer);
		this->ground->GetEntity(renderer);
		for (Platform* platform : this->platforms) {
			platform->GetEntity(renderer);
		}
		this->player->GetEntity(renderer, MovePlayer());
		CheckCollision();

		SDL_Delay(8);
		SDL_RenderPresent(renderer->renderer);
	}
	delete renderer;
	delete window;
	SDL_Quit();
}
