#include <iostream>
#include <vector>

#include "gameobjects/Floor.h"
#include "gameobjects/GameObject.h"
#include "gameobjects/Square.h"
#include "SDL3/SDL.h"


constexpr int SCREEN_WIDTH = 800;
constexpr int SCREEN_HEIGHT = 600;
constexpr float DELTA_TIME = 1.0f/60.0f;

int main(int argc, char* argv[]) {

    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cerr << "Couldn't initialize SDL: %s\n" << SDL_GetError() << std::endl;
        return 1;
    }

    bool running = true;

    SDL_Window* window = SDL_CreateWindow("Game Engine",SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_RESIZABLE);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);

    auto* floor = new Floor(0, 550, 800, 50);
    std::vector<GameObject*> game_objects = { floor };
    game_objects.push_back(new Square(100, 100, 50, 50, floor));

    SDL_Event event;
    while (running) {

        // This waits till user presses close
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }


        for (auto* obj : game_objects) {
            obj->update(DELTA_TIME);

        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        for (auto* obj : game_objects) {
            obj->render(renderer);
        }

        SDL_RenderPresent(renderer); // Refresh window with updated objects

        SDL_Delay(16); //
    }
    for (const auto* obj : game_objects) {
        delete obj;
    }


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;

    }

