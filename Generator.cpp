#include "Generator.h"
#include "Renderer.h"
#include <iostream>

Generator::Generator() {
    Running = true;
    Display3D = false;
    win = SDL_CreateWindow("Mountain_Generator", 1000, 1000, SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(win, nullptr);
    event = new SDL_Event();
    }

Generator::~Generator()
{
    delete event;
    event = nullptr;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
}

void Generator::Run() {
    while (Running)
    {
        while (SDL_PollEvent(event))
        {
            switch (event->type)
            {
            case SDL_EVENT_QUIT:
                Running = false;
                break;
            case SDL_EVENT_KEY_DOWN:
                switch (event->key.key)
                {
            case SDLK_G:
                    //GenerateHeightMap();
                    break;
                }
            case SDLK_S:
                //Save();
                break;
            }
        }
        SDL_RenderClear(renderer);

        /* TODO: You know what must be done
        if (Display3D)
        {
            RenderSTL();
        }
        else
        */

        RenderPNG(renderer, "shime1.png");

        SDL_RenderPresent(renderer);
    }
}