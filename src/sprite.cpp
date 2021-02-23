#include "Sprite.h"
Sprite::Sprite(){

}

SDL_Texture* Sprite::Load(char* File){
    SDL_Texture* temp;
    //add
    return temp;
}

SDL_Texture* Sprite::Load(SDL_Renderer *renderer, char* File)
{

    SDL_Texture *texture = IMG_LoadTexture(renderer, File);

	if((texture) == NULL)
	{
        printf("SDL_Init failed: %s\n", SDL_GetError());
		return NULL;
	}

	return texture;
}

bool Sprite::Draw(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y, int w, int h)
{
    if(renderer == NULL || texture == NULL)
    {
        return false;
    }

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);

    SDL_Rect rec;
    rec.x = x;
    rec.y = y;
    rec.w = w;
    rec.h = h;

    SDL_RenderCopy(renderer, texture, NULL, &rec);


    return true;
}

