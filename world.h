#pragma once

#include "player.h"

class World
{
private:
	Player* player;

	void CreatePlayer(Renderer* renderer);
	void RenderBackground(Renderer* renderer, Texture* backgroundTexture, SDL_Rect* destRect);
	void MovePlayer(Player* player);
public:
	void StartWorld(Renderer* renderer, Window* window);
};

