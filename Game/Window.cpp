#include <SDL.h>
#include "Window.h"
#include "Player.h"
#include <iostream>

Window::Window(int width, int height, const char* title) {
	Width = width;
	Height = height;
	Title = title;
}

int Window::Show() {
	Window_ = SDL_CreateWindow(Title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Width, Height, SDL_WINDOW_SHOWN);

	if (Window_ == NULL)
		return 1;

	Screen_Surface = SDL_GetWindowSurface(Window_);
}

void Window::Update() {
	SDL_UpdateWindowSurface(Window_);
}

void Window::Close() {
	SDL_DestroyWindow(Window_);
	SDL_Quit();
}

void Window::Delay(int time) {
	SDL_Delay(time);
}

void Window::RendererInit() {
	Renderer = SDL_CreateRenderer(Window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(Renderer, 0xFF, 0xFF, 0xFF, 0xFF);
}

void Window::DestroyAll(Player player[]) {
	Window::Close();

	for (size_t i = 0; i < sizeof(player) / sizeof(*player); i++)
		SDL_DestroyTexture(player[i].Sprite);

	SDL_DestroyWindow(Window_);
	SDL_DestroyRenderer(Renderer);

	SDL_Quit();
}

void Window::AddObject(SDL_Texture* sprite, SDL_Rect size, SDL_Rect properties) {
	SDL_RenderClear(Renderer);
	QueryTexture(sprite, size);
	RenderCopy(sprite, properties);
	SDL_RenderPresent(Renderer);
}

void Window::AddObjects(SDL_Texture* sprite[], SDL_Rect size[], SDL_Rect properties[]) {
	if (sizeof(sprite) == sizeof(size) && sizeof(size) == sizeof(properties)) {
		SDL_RenderClear(Renderer);

		for (size_t i = 0; i < sizeof(sprite) / sizeof(*sprite); i++) {
			QueryTexture(sprite[i], size[i]);
			RenderCopy(sprite[i], properties[i]);
		}

		SDL_RenderPresent(Renderer);
	}
}

void Window::Redraw(SDL_Texture* object[], SDL_Rect object_size[], SDL_Rect object_properties[]) {
	if (sizeof(object) == sizeof(object_size) && sizeof(object_size) == sizeof(object_properties)) {
		for (size_t i = 0; i < sizeof(object) / sizeof(*object); i++)
			SDL_DestroyTexture(object[i]);

		AddObjects(object, object_size, object_properties);
	}

}

void Window::QueryTexture(SDL_Texture* texture, SDL_Rect size) {
	SDL_QueryTexture(texture, NULL, NULL, &size.w, &size.h);
}

void Window::RenderCopy(SDL_Texture* texture, SDL_Rect properties) {
	SDL_RenderCopy(Renderer, texture, NULL, &properties);
}