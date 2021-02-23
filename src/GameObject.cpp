#include "GameObject.h"

void GameObject::Load(char *file){
    sprite = Sprite::Load(file);
}


void GameObject::Update()
{
    
}

void GameObject::Draw()
{

}

void GameObject::Clean()
{
    SDL_FreeSurface(sprite);
}

