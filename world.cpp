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
		int x = rand() % 400;
		int y = rand() % 300;
		platforms.push_back(new Platform(renderer, x, y));
	}
}

SDL_RendererFlip World::MovePlayer()
{
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	// Vertical deplacement
	if (currentKeyStates[SDL_SCANCODE_UP] && player->jumpRange > 0) {
		this->player->direction = UP;
		this->player->playerRect->y--;
		this->player->jumpRange--;
		this->previousInput = SDL_SCANCODE_UP;
	}
	// Horizontal deplacement
	else if (currentKeyStates[SDL_SCANCODE_LEFT]) {
		this->player->direction = LEFT;
		this->player->playerRect->x--;
		flip = (previousInput == SDL_SCANCODE_RIGHT) ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
		this->previousInput = SDL_SCANCODE_LEFT;
	}
	else if (currentKeyStates[SDL_SCANCODE_RIGHT]) {
		this->player->direction = RIGHT;
		this->player->playerRect->x++;
		flip = (previousInput == SDL_SCANCODE_LEFT) ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
		this->previousInput = SDL_SCANCODE_RIGHT;
	}
	// Diagonal deplacement Up
	else if (currentKeyStates[SDL_SCANCODE_UP] && currentKeyStates[SDL_SCANCODE_LEFT]) {
		this->player->playerRect->y--;
		this->player->playerRect->x--;
	}
	else if (currentKeyStates[SDL_SCANCODE_UP] && currentKeyStates[SDL_SCANCODE_RIGHT]) {
		this->player->playerRect->y--;
		this->player->playerRect->x++;
	}
	// Diagonal deplacement Down
	else if (currentKeyStates[SDL_SCANCODE_DOWN] && currentKeyStates[SDL_SCANCODE_LEFT]) {
		this->player->playerRect->y++;
		this->player->playerRect->x--;
	}
	else if (currentKeyStates[SDL_SCANCODE_DOWN] && currentKeyStates[SDL_SCANCODE_RIGHT]) {
		this->player->playerRect->y++;
		this->player->playerRect->x++;
	}
	else {
		this->player->direction = DOWN;
		this->player->playerRect->y++;
		this->previousInput = SDL_SCANCODE_DOWN;
	}
	return flip;
}

void World::CheckCollision()
{
	// Collision with ground
	if (SDL_HasIntersection(this->ground->groundRect, this->player->playerRect)) {
		this->player->playerRect->y--;
		this->player->jumpRange = JUMP_RANGE_MAX;
	}
	// Collision with platform
	for (Platform* platform : this->platforms) {
		if (SDL_HasIntersection(platform->platformRect, this->player->playerRect)) {
			switch (*this->player->direction)
			{
			case* UP: 
				this->player->direction = DOWN;
				this->player->playerRect->y++;
				break;
			case* DOWN:
				this->player->direction = UP;
				this->player->playerRect->y--;
				this->player->jumpRange = JUMP_RANGE_MAX;
				break;
			case* LEFT:
				this->player->direction = RIGHT;
				this->player->playerRect->x++;
				break;
			case* RIGHT:
				this->player->direction = LEFT;
				this->player->playerRect->x--;
				break;
			default:
				break;
			}
		}
	}
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
