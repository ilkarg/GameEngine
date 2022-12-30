#pragma once

#include "SDL.h"

class Player 
{
public:
	SDL_Texture* Sprite;
	SDL_Rect Size;
	SDL_Rect Properties;
	int Speed;

	Player(int x, int y, int width, int height, SDL_Surface* sprite, SDL_Renderer* renderer, int speed);

	void MoveToUp();
	void MoveToRight();
	void MoveToDown();
	void MoveToLeft();
};