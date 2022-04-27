#pragma once

#include "SDL.h"

class Player {
public:
	SDL_Texture* Sprite;
	SDL_Rect Size;
	SDL_Rect Properties;

	Player(int x, int y, int width, int height, SDL_Surface* sprite, SDL_Renderer* renderer);

	void MoveToUp();
	void MoveToRight();
	void MoveToDown();
	void MoveToLeft();
};