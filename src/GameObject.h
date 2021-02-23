#pragma once
#include "Sprite.h"
#include "Game.h"

class GameObject{
    public:
        GameObject(){};
        ~GameObject(){};
        void Load(char *file);
        void Draw();
        void Update();
        void Clean();
    private:
        SDL_Texture* sprite;
};