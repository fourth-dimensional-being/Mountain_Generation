#include "Renderer.h"

bool RenderPNG(SDL_Renderer* renderer, const std::string &file ,const std::string &filePath)
{
    //Find File
    std::string path = filePath + "/" + file;
    std::ifstream Image(path);
    if (!Image.is_open())
    {
        std::cerr<<"Could not find " << file << std::endl;
        return false;
    }

    SDL_Texture* texture = IMG_LoadTexture(renderer, path.c_str());

    SDL_RenderTexture(renderer, texture, nullptr, nullptr);

    return true;
}