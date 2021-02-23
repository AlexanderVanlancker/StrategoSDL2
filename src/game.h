#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <utility>
#include "Util.h"
#include "Sprite.h"
#include "Singleton.h"

#ifndef GAME_H
#define GAME_H

class Game{
    public:
        ~Game();
        void Init(const char* title, int width, int height, int bpp);
        void Quit();
        void HandleEvents();
        void Update();
        void Draw();
        void MouseHover();
        void Clean();
        bool Running();
        SDL_Surface* GetScreen() { return screen; }

        void testClass();
        void DrawBackground();

    private:
        Game(){};
        friend class Singleton<Game>;

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

typedef Singleton<Game> GameInst;

#endif