#include "Sound.h"
#include <iostream>

Sound::Sound(const char* path, int channel) 
{
	this->File = Mix_LoadMUS(path);
	this->Channel = channel;
}

void Sound::Play() 
{
	Mix_PlayMusic(this->File, this->Channel);
}

void Sound::Pause() 
{
	Mix_Pause(this->Channel);
}

void Sound::Resume() 
{
	Mix_Resume(this->Channel);
}

void Sound::Remove() 
{
	Mix_FreeMusic(this->File);
}

void Sound::SetVolume(int volume) 
{
	Mix_Volume(this->Channel, volume);
}