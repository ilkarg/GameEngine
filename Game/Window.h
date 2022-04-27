#pragma once

#include "Player.h"
#include <iostream>

class Window {
public:
	int Width, Height;
	const char* Title;
	SDL_Window* Window_;
	SDL_Surface* Screen_Surface;
	SDL_Renderer* Renderer;
	SDL_Event Event;

	Window(int width, int height, const char* title);

	int Show();
	void Update();
	void Close();

	void Delay(int time);

	void RendererInit();

	void DestroyAll(Player player[]);

	void AddObject(SDL_Texture* sprite, SDL_Rect size, SDL_Rect properties);
	void AddObjects(SDL_Texture* sprite[], SDL_Rect position[], SDL_Rect size[]);

	void QueryTexture(SDL_Texture* texture, SDL_Rect size);
	void RenderCopy(SDL_Texture* texture, SDL_Rect properties);

	void Redraw(SDL_Texture* object[], SDL_Rect object_size[], SDL_Rect object_properties[]);
};