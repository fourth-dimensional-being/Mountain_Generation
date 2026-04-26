#ifndef MOUNTAIN_GENERATOR_RENDERER_H
#define MOUNTAIN_GENERATOR_RENDERER_H
#include <string>
#include <fstream>
#include <iostream>
#include <istream>
#include <iomanip>
#include <SDL3/SDL.h>
#include "Dependencies/SDL3_Image/include/SDL3_image/SDL_image.h" //TODO: FIX THIS SHIT


bool RenderPNG(SDL_Renderer* renderer, const std::string &file, const std::string &filePath = "."); //return 0 on Fail and 1 on Success

#endif //MOUNTAIN_GENERATOR_RENDERER_H