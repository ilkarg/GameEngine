#include <SDL.h>
#include "Window.h"
#include "Player.h"
#include <iostream>

Window::Window(int width, int height, const char* title) 
{
	this->Width = width;
	this->Height = height;
	this->Title = title;
}

int Window::Show() 
{
	this->SDLWin = SDL_CreateWindow(this->Title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->Width, this->Height, SDL_WINDOW_SHOWN);

	if (this->SDLWin == NULL) 
	{
		return 1;
	}

	this->ScreenSurface = SDL_GetWindowSurface(this->SDLWin);
}

void Window::Update() 
{
	SDL_UpdateWindowSurface(this->SDLWin);
}

void Window::Close() 
{
	SDL_DestroyWindow(this->SDLWin);
	SDL_Quit();
}

void Window::Delay(int time) 
{
	SDL_Delay(time);
}

void Window::RendererInit() 
{
	this->Renderer = SDL_CreateRenderer(this->SDLWin, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(this->Renderer, 0xFF, 0xFF, 0xFF, 0xFF);
}

void Window::DestroyAll(Player player[]) 
{
	Window::Close();

	for (size_t i = 0; i < sizeof(player) / sizeof(*player); i++) 
	{
		SDL_DestroyTexture(player[i].Sprite);
	}

	SDL_DestroyWindow(this->SDLWin);
	SDL_DestroyRenderer(this->Renderer);

	SDL_Quit();
}

void Window::AddObject(SDL_Texture* sprite, SDL_Rect size, SDL_Rect properties) 
{
	SDL_RenderClear(this->Renderer);
	QueryTexture(sprite, size);
	RenderCopy(sprite, properties);
	SDL_RenderPresent(this->Renderer);
}

void Window::AddObjects(SDL_Texture* sprite[], SDL_Rect size[], SDL_Rect properties[]) {
	if (sizeof(sprite) == sizeof(size) && sizeof(size) == sizeof(properties)) {
		SDL_RenderClear(this->Renderer);

		for (size_t i = 0; i < sizeof(sprite) / sizeof(*sprite); i++) {
			QueryTexture(sprite[i], size[i]);
			RenderCopy(sprite[i], properties[i]);
		}

		SDL_RenderPresent(this->Renderer);
	}
}

void Window::Redraw(SDL_Texture* object[], SDL_Rect object_size[], SDL_Rect object_properties[]) 
{
	if (sizeof(object) == sizeof(object_size) && sizeof(object_size) == sizeof(object_properties)) 
	{
		for (size_t i = 0; i < sizeof(object) / sizeof(*object); i++) 
		{
			SDL_DestroyTexture(object[i]);
		}

		AddObjects(object, object_size, object_properties);
	}

}

void Window::QueryTexture(SDL_Texture* texture, SDL_Rect size) 
{
	SDL_QueryTexture(texture, NULL, NULL, &size.w, &size.h);
}

void Window::RenderCopy(SDL_Texture* texture, SDL_Rect properties) 
{
	SDL_RenderCopy(this->Renderer, texture, NULL, &properties);
}