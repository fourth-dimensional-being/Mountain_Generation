#ifndef GENERATOR_H
#define GENERATOR_H
#include <SDL3/SDL.h>
#include "Renderer.h"



class Generator {
    public:
    Generator();
    ~Generator();

    void Run();
    

    private:
    bool Running;
    bool Display3D; //Currently does nothing, will add 3D support eventually.

    //SDL3
    SDL_Window* win;
    SDL_Renderer* renderer;
    SDL_Event* event;
};
#endif