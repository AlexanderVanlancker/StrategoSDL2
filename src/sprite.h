#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <zlib.h>
#include <libpng16/png.h>
class Sprite{
    public: 
        Sprite();
        static SDL_Texture* Load(SDL_Renderer *renderer, char* File);
        static SDL_Texture* Load(char* File);
        static bool Draw(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y, int w, int h);
        static bool Draw(SDL_Surface *dest, SDL_Surface *src, int x, int y, int x2, int y2, int width, int height);
};