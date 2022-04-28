#include "Sound.h"
#include <iostream>

Sound::Sound(const char* path, int channel) {
	File = Mix_LoadMUS(path);
	Channel = channel;
	std::cout << Mix_GetError() << std::endl;
}

void Sound::Play() {
	Mix_PlayMusic(File, Channel);
	std::cout << Mix_GetError() << std::endl;
}

void Sound::Pause() {
	Mix_Pause(Channel);
	std::cout << Mix_GetError() << std::endl;
}

void Sound::Resume() {
	Mix_Resume(Channel);
	std::cout << Mix_GetError() << std::endl;
}

void Sound::Remove() {
	Mix_FreeMusic(File);
	std::cout << Mix_GetError() << std::endl;
}

void Sound::SetVolume(int volume) {
	Mix_Volume(Channel, volume);
	std::cout << Mix_GetError() << std::endl;
}