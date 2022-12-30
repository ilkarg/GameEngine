#include "SDL.h"
#include "Player.h"
#include <iostream>

Player::Player(int x, int y, int width, int height, SDL_Surface* sprite, SDL_Renderer* renderer, int speed) 
{
	this->Size.w = width;
	this->Size.h = height;

	this->Properties.x = x;
	this->Properties.y = y;
	this->Properties.w = width;
	this->Properties.h = height;

	this->Speed = speed;

	this->Sprite = SDL_CreateTextureFromSurface(renderer, sprite);
	SDL_FreeSurface(sprite);
}

void Player::MoveToUp() 
{
	this->Properties.y -= this->Speed;
}

void Player::MoveToDown() 
{
	this->Properties.y += this->Speed;
}

void Player::MoveToRight() 
{
	this->Properties.x += this->Speed;
}

void Player::MoveToLeft() 
{
	this->Properties.x -= this->Speed;
}