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

	void CreateBackground(Renderer* renderer, Window* window);
	void CreatePlayer(Renderer* renderer);
	void CreateGround(Renderer* renderer, Window* window);
	void CreatePlatforms(Renderer* renderer);
	SDL_RendererFlip MovePlayer(Player* player, const Uint8 previousInput);

public:
	void StartWorld(Renderer* renderer, Window* window);
};

