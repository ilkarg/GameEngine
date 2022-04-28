#include <SDL.h>
#include <SDL_mixer.h>
#include "MainSystem.h"

void MainSystem::InitEngine() {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		exit(3);

	Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096);
	std::cout << Mix_GetError() << std::endl;
}

void MainSystem::ExitFromEngine(Window window, Player player) {
	window.DestroyAll(&player);
	Mix_CloseAudio();
	std::cout << Mix_GetError() << std::endl;
	exit(0);
}