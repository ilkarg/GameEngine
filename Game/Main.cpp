#include <SDL.h>
#include "Window.h"
#include "Player.h"
#include "Sprite.h"

int main(int argc, char** args) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        return 1;

    Window window = Window(800, 600, "My Window");

    window.Show();
    window.RendererInit();

    Sprite hero = Sprite("hero.bmp");

    Player player1 = Player(150, 150, 300, 200, SDL_LoadBMP(hero.Path), window.Renderer);
    Player player2 = Player(500, 500, 200, 200, SDL_LoadBMP(hero.Path), window.Renderer);

    SDL_Texture* texture[] = { player1.Sprite, player2.Sprite };
    SDL_Rect size[] = { player1.Size, player2.Size };
    SDL_Rect properties[] = { player1.Properties, player2.Properties };
    Player player[] = { player1, player2 };

    window.AddObjects(texture, size, properties);

    while (true) {
        while (SDL_PollEvent(&window.Event) != 0) {
            if (window.Event.type == SDL_QUIT) {
                window.DestroyAll(player);
                return 0;
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