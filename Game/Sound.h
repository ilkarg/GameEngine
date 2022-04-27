#pragma once

#include <SDL.h>
#include <SDL_audio.h>
#include <SDL_mixer.h>

class Sound {
public:
	Mix_Chunk* File;
	int Channel;

	Sound(const char* path, int channel);
	void Play();
	void Pause();
	void Resume();
	void SetVolume(int volume);
	void Remove();
};