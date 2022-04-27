#include "Sound.h"

Sound::Sound(const char* path, int channel) {
	File = Mix_LoadWAV(path);
	Channel = channel;
}

void Sound::Play() {
	Mix_PlayChannel(Channel, File, 0);
}

void Sound::Pause() {
	Mix_Pause(Channel);
}

void Sound::Resume() {
	Mix_Resume(Channel);
}

void Sound::Remove() {
	Mix_FreeChunk(File);
}

void Sound::SetVolume(int volume) {
	Mix_Volume(Channel, volume);
}