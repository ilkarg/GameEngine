#include "Sound.h"
#include <iostream>

Sound::Sound(const char* path, int channel) {
	File = Mix_LoadMUS(path);
	Channel = channel;
}

void Sound::Play() {
	Mix_PlayMusic(File, Channel);
}

void Sound::Pause() {
	Mix_Pause(Channel);
}

void Sound::Resume() {
	Mix_Resume(Channel);
}

void Sound::Remove() {
	Mix_FreeMusic(File);
}

void Sound::SetVolume(int volume) {
	Mix_Volume(Channel, volume);
}