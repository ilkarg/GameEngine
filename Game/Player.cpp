#include "SDL.h"
#include "Player.h"
#include <iostream>

Player::Player(int x, int y, int width, int height, SDL_Surface* sprite, SDL_Renderer* renderer) {
	Size.w = width;
	Size.h = height;

	Properties.x = x;
	Properties.y = y;
	Properties.w = width;
	Properties.h = height;

	Sprite = SDL_CreateTextureFromSurface(renderer, sprite);
	SDL_FreeSurface(sprite);
}

void Player::MoveToUp() {
	Properties.y -= 10;
}