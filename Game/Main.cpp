#pragma comment(lib, "SDLLib/SDL2_mixer.lib")

#include <SDL.h>
#include <SDL_audio.h>
#include <SDL_mixer.h>
#include "Window.h"
#include "Player.h"
#include "Sprite.h"
#include "MainSystem.h"
#include "Sound.h"

int main(int argc, char** args) {
    MainSystem().InitEngine();

    Window window = Window(800, 600, "My Window");

    window.Show();
    window.RendererInit();

    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096);


    Sprite hero = Sprite("hero.bmp");

    Player player = Player(150, 150, 300, 200, SDL_LoadBMP(hero.Path), window.Renderer);

    window.AddObject(player.Sprite, player.Size, player.Properties);

    while (true) {
        while (SDL_PollEvent(&window.Event) != 0) {
            if (window.Event.type == SDL_QUIT) {
                MainSystem().ExitFromEngine(window, player);
            }
            else if (window.Event.type == SDL_KEYDOWN) {
                if (window.Event.key.keysym.sym == SDLK_w) printf("W pressed\n");
                if (window.Event.key.keysym.sym == SDLK_d) printf("D pressed\n");
                if (window.Event.key.keysym.sym == SDLK_s) printf("S pressed\n");
                if (window.Event.key.keysym.sym == SDLK_a) printf("A pressed\n");
            }
        }
    }

    return 0;
};