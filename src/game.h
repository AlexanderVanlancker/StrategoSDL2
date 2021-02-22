#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <utility>
#include "util.h"
#include "sprite.h"

#ifndef GAME_H
#define GAME_H

class Game{
    public:
        Game();

        void Init(const char* title, int width, int height, int bpp);
        void Quit();
        void HandleEvents(Game*);
        void Update();
        void Draw();
        void MouseHover();
        void Clean();
        bool Running();

        void testClass();
        void DrawBackground();

    private:
        bool running;
        SDL_Texture* testSprite;
        SDL_Texture* background;
        SDL_Surface* screen;
        SDL_Window *window;
        SDL_Renderer *renderer;

        TTF_Font* font;
        
        int gameGrid[10][10] = {0};
        int cellSize = 50;
        std::pair<int, int> selected;
};



#endif