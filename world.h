#pragma once

#include <vector>

#include "player.h"
#include "platform.h"
#include "background.h"
#include "ground.h"

class World
{
private:
	Background* background;
	Player* player;
	Ground* ground;
	std::vector<Platform*> platforms;
	Uint8 previousInput = SDL_SCANCODE_RIGHT;

	void CreateBackground(Renderer* renderer, Window* window);
	void CreatePlayer(Renderer* renderer);
	void CreateGround(Renderer* renderer, Window* window);
	void CreatePlatforms(Renderer* renderer);

	SDL_RendererFlip MovePlayer();
	void CheckCollision();

public:
	void StartWorld(Renderer* renderer, Window* window);
};

